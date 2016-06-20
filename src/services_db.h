/*
 * In The Name Of God
 * ========================================
 * [] File Name : services_db.h
 *
 * [] Creation Date : 13-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/

#ifndef SERVICES_DB_H
#define SERVICES_DB_H

#include "services.h"

int bus_service_db_insert(const struct bus_service *s);

int train_service_db_insert(const struct train_service *s);

int airplane_service_db_insert(const struct airplane_service *s);

#endif
