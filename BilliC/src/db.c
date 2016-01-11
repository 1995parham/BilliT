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

PGconn *pq_connection(void) {
	if (!connection)
		pq_connect();
	return connection;
}
