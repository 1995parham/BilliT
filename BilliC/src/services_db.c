/*
 * In The Name Of God
 * ========================================
 * [] File Name : services_db.c
 *
 * [] Creation Date : 13-01-2016
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
#include "services.h"
#include "services_db.h"


int bus_service_db_insert(const struct bus_service *s)
{
	PGresult *res;

	char dispatch_time_s[1024];
	struct tm dispatch_time_t;
	localtime_r(&(s->s.dispatch_time), &dispatch_time_t);
	strftime(dispatch_time_s, 1024, "%Y-%m-%d %H:%M:%S", &dispatch_time_t);

	char company_s[1024];
	sprintf(company_s, "%d", s->s.company);

	char fi_s[1024];
	sprintf(fi_s, "%d", s->s.fi);

	char total_s[1024];
	sprintf(total_s, "%d", s->s.total);

	res = PQexecParams(pq_connection(),
			"INSERT INTO bus_services (src_town, dst_town, dispatch_time, company, fi, total) \
			VALUES ($1, $2, $3, $4, $5, $6) RETURNING id;",
			6,
			NULL,
			(const char* []) {s->s.src_town, s->s.dst_town, dispatch_time_s, company_s, fi_s, total_s},
			NULL, NULL, 0);

	if (PQresultStatus(res) == PGRES_TUPLES_OK) {
		int id;
		sscanf(PQgetvalue(res, 0, 0), "%d", &id);
		return id;
	} else {
		plib_udie("insert query error: %s", PQresultErrorMessage(res));
		return -1;
	}
}

int train_service_db_insert(const struct train_service *s)
{
	PGresult *res;

	char dispatch_time_s[1024];
	struct tm dispatch_time_t;
	localtime_r(&(s->s.dispatch_time), &dispatch_time_t);
	strftime(dispatch_time_s, 1024, "%Y-%m-%d %H:%M:%S", &dispatch_time_t);

	char company_s[1024];
	sprintf(company_s, "%d", s->s.company);

	char fi_s[1024];
	sprintf(fi_s, "%d", s->s.fi);

	char total_s[1024];
	sprintf(total_s, "%d", s->s.total);

	char train_id_s[1024];
	sprintf(train_id_s, "%d", s->train_id);

	res = PQexecParams(pq_connection(),
			"INSERT INTO train_services (src_town, dst_town, dispatch_time, company, fi, total, train_id) \
			VALUES ($1, $2, $3, $4, $5, $6, $7) RETURNING id;",
			7,
			NULL,
			(const char* []) {s->s.src_town, s->s.dst_town, dispatch_time_s, company_s, fi_s, total_s, train_id_s},
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

int airplane_service_db_insert(const struct airplane_service *s)
{
	PGresult *res;

	char dispatch_time_s[1024];
	struct tm dispatch_time_t;
	localtime_r(&(s->s.dispatch_time), &dispatch_time_t);
	strftime(dispatch_time_s, 1024, "%Y-%m-%d %H:%M:%S", &dispatch_time_t);

	char company_s[1024];
	sprintf(company_s, "%d", s->s.company);

	char fi_s[1024];
	sprintf(fi_s, "%d", s->s.fi);

	char total_s[1024];
	sprintf(total_s, "%d", s->s.total);

	char airplane_id_s[1024];
	sprintf(airplane_id_s, "%d", s->airplane_id);

	res = PQexecParams(pq_connection(),
			"INSERT INTO airplane_services (src_town, dst_town, dispatch_time, company, fi, total, airplane_id) \
			VALUES ($1, $2, $3, $4, $5, $6, $7) RETURNING id;",
			7,
			NULL,
			(const char* []) {s->s.src_town, s->s.dst_town, dispatch_time_s, company_s, fi_s, total_s, airplane_id_s},
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
