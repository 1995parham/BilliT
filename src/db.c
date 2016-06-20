/*
 * In The Name Of God
 * ========================================
 * [] File Name : db.c
 *
 * [] Creation Date : 10-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#include <PLog.h>
#include <libpq-fe.h>
#include <stdio.h>

static PGconn *connection;

void pq_exit_handler(void *connection)
{
	if (connection)
		PQfinish((PGconn *)connection);
}

void pq_connect(void)
{
	if (!connection) {
		plib_register_exit_handler(pq_exit_handler, connection, 0);
		connection = PQconnectdb("postgresql://billit:1234@127.0.0.1/billit");
		if (PQstatus(connection) != CONNECTION_OK) {
			plib_udie("Connection to database failed: %s", PQerrorMessage(connection));
		}
	}
}

PGconn *pq_connection(void)
{
	if (!connection)
		pq_connect();
	return connection;
}

int pq_run_and_show(const char *command)
{
	PGresult *res;
	PQprintOpt opt = {
		.header = 1,
		.align = 1,
		.standard = 1,
		.html3 = 0,
		.expanded = 0,
		.pager = 0,
		.fieldSep = " ",
		.tableOpt = NULL,
		.caption = NULL,
		.fieldName = NULL,
	};
	
	res = PQexec(pq_connection(), command);
	
	if (PQresultStatus(res) == PGRES_TUPLES_OK) {
		PQprint(stdout, res, &opt);
		return 0;
	} else if (PQresultStatus(res) == PGRES_COMMAND_OK) {
		printf("Query OK !\n");
		return 0;
	} else {
		printf("Query Not OK: %s\n", PQresultErrorMessage(res));
		return -1;
	}
}
