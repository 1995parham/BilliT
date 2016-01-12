/*
 * In The Name Of God
 * ========================================
 * [] File Name : company_db.h
 *
 * [] Creation Date : 10-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/

#ifndef COMPANY_DB_H
#define COMPANY_DB_H

#include "company.h"

int company_db_insert(const struct company *c);

const struct company *company_db_get_with_name(const char *name_i);

#endif
