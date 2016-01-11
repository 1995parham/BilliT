/*
 * In The Name Of God
 * ========================================
 * [] File Name : db.h
 *
 * [] Creation Date : 10-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#ifndef DB_H
#define DB_H

#include <libpq-fe.h>

PGconn *pq_connection(void);

#endif
