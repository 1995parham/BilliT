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
			"INSERT INTO users VALUES ($1, $2, $3, $4, $5, $6);",
			6,
			NULL,
			(const char* []) {s_id_s, u->username, u->name, u->family, u->hometown, u->career, birthday_s},
			NULL, NULL, 0);

	if (PQresultStatus(res) == PGRES_COMMAND_OK) {
		return 0;
	} else {
		plib_ulog("insert query error: %s", PQresultErrorMessage(res));
		return -1;
	}
}
