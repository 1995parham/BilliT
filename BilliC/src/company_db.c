/*
 * In The Name Of God
 * ========================================
 * [] File Name : company_db.c
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
#include "company_db.h"
#include "company.h"

int company_db_insert(const struct company *c)
{
	PGresult *res;

	char manager_s[1024];
	sprintf(manager, "%d", c->manager);

	res = PQexecParams(pq_connection(),
			"INSERT INTO users (manager, name, driver, pilot, bus) \
			VALUES ($1, $2, $3, $4, $5) RETURNING id;",
			5,
			NULL,
			(const char* []) {manager_s, c->name, driver_s, pilot_s, bus_s},
			NULL, NULL, 0);

	if (PQresultStatus(res) == PGRES_TUPLES_OK) {
		int id;
		sscanf(PQgetvalue(res, 0, 0), "%d", &id);
		return id;
	} else {
		plib_ulog("insert query error: %s", PQresultErrorMessage(res));
		return -1;
	}
}

const struct company *company_db_get_with_name(const char *name_i)
{
	PGresult *res;

	int id;

	int manager;

	char name[255];
	
	int driver;
	
	int pilot;

	int bus;

	res = PQexecParams(pq_connection(),
			"SELECT (id, manager, name, driver, pilot, bus) FROM users \
			WHERE name = $1",
			1,
			NULL,
			(const char* []) {name_i},
			NULL, NULL, 0);

	if (PQresultStatus(res) == PGRES_TUPLES_OK && PQntuples(res) == 1) {
		sscanf(PQgetvalue(res, 0, 0), "%d", &id);
		
		sscanf(PQgetvalue(res, 0, 1), "%d", &manager);

		strcpy(name, PQgetvalue(res, 0, 2));

		sscanf(PQgetvalue(res, 0, 3), "%d", &driver);
		
		sscanf(PQgetvalue(res, 0, 4), "%d", &pilot);
		
		sscanf(PQgetvalue(res, 0, 5), "%d", &bus);

		const struct company *c = company_new(id, manager, name, driver, pilot, bus);

		return c;
	} else {
		plib_ulog("select query error: %s", PQresultErrorMessage(res));
		return NULL;
	}

}
