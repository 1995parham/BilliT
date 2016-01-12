/*
 * In The Name Of God
 * ========================================
 * [] File Name : services.h
 *
 * [] Creation Date : 12-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#ifndef SERVICES_H
#define SERVICES_H

#include <time.h>

struct service {
	int id;
	char src_town[255];
	char dst_town[255];
	time_t dispatch_time;
	int company;
	int fi;
	int total;
	int sell;
};

struct bus_service {
	struct service s;
};

struct train_service {
	struct service s;
	int train_id;
};

struct airplane_service {
	struct service s;
	int airplane_id;
};

const struct bus_service *service_bus_new(
		int id,
		const char *src_town,
		const char *dst_town,
		time_t dispatch_time,
		int company,
		int fi,
		int total,
		int sell
);

const struct train_service *service_train_new(
		int id,
		const char *src_town,
		const char *dst_town,
		time_t dispatch_time,
		int company,
		int fi,
		int total,
		int sell,
		int train_id
);

const struct airplane_service *service_airplane_new(
		int id,
		const char *src_town,
		const char *dst_town,
		time_t dispatch_time,
		int company,
		int fi,
		int total,
		int sell,
		int airplane_id
);

void service_bus_print(const struct bus_service *s, FILE *fp);

void service_train_print(const struct train_service *s, FILE *fp);

void service_airplane_print(const struct airplane_service *s, FILE *fp);

void serivce_bus_delete(const struct bus_service *s);

void service_train_delete(const struct train_service *s);

void service_airplane_delete(const struct airplane_service *s);

#endif
