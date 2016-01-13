/*
 * In The Name Of God
 * ========================================
 * [] File Name : user_db.c
 *
 * [] Creation Date : 11-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#include <string.h>
#include <PLog.h>
#include <libpq-fe.h>

#include "db.h"
#include "user_db.h"

int user_db_insert(const struct user *u)
{
	PGresult *res;

	char birthday_s[1024];
	struct tm birthday_t;
	localtime_r(&(u->birthday), &birthday_t);
	strftime(birthday_s, 1024, "%Y-%m-%d", &birthday_t);

	char s_id_s[1024];
	sprintf(s_id_s, "%d", u->s_id);

	res = PQexecParams(pq_connection(),
			"INSERT INTO users (s_id, username, password, name, family, hometown, career, birthday) \
			VALUES ($1, $2, $3, $4, $5, $6, $7, $8);",
			8,
			NULL,
			(const char* []) {s_id_s, u->username, u->password, u->name, u->family, u->hometown, u->career, birthday_s},
			NULL, NULL, 0);

	if (PQresultStatus(res) == PGRES_COMMAND_OK) {
		return 0;
	} else {
		plib_ulog("insert query error: %s", PQresultErrorMessage(res));
		return -1;
	}
}

const struct user *user_db_get_with_username(const char *username_i)
{
	PGresult *res;

	int s_id;
	
	char username[255];

	char password[255];

	char name[255];

	char family[255];

	char hometown[255];

	char career[255];

	time_t birthday;
	int mm, dd, yy;
	struct tm birthday_t = {};

	res = PQexecParams(pq_connection(),
			"SELECT s_id, username, password, name, family, hometown, career, birthday FROM users \
			WHERE username = $1",
			1,
			NULL,
			(const char* []) {username_i},
			NULL, NULL, 0);

	if (PQresultStatus(res) == PGRES_TUPLES_OK && PQntuples(res) == 1) {
		sscanf(PQgetvalue(res, 0, 0), "%d", &s_id);

		strcpy(username, PQgetvalue(res, 0, 1));

		strcpy(password, PQgetvalue(res, 0, 2));

		strcpy(name, PQgetvalue(res, 0, 3));

		strcpy(family, PQgetvalue(res, 0, 4));

		strcpy(hometown, PQgetvalue(res, 0, 5));

		strcpy(career, PQgetvalue(res, 0, 6));

		sscanf(PQgetvalue(res, 0, 7), "%d-%d-%d",&yy, &mm, &dd);
		birthday_t.tm_year = yy - 1900;
		birthday_t.tm_mon = mm - 1;
		birthday_t.tm_mday = dd;
		birthday = mktime(&birthday_t);

		const struct user *u = user_new(s_id, username, password,
			name, family, hometown, career, birthday);

		return u;
	} else {
		plib_ulog("select query error: %s", PQresultErrorMessage(res));
		return NULL;
	}

}
