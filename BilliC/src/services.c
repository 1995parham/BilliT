/*
 * In The Name Of God
 * ========================================
 * [] File Name : services.c
 *
 * [] Creation Date : 12-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "services.h"

static void service_builder(struct service *s,
		int id,
		const char *src_town,
		const char *dst_town,
		time_t dispatch_time,
		int company,
		int fi,
		int total,
		int sell
)
{
	s->id = id;

	strncpy(s->src_town, src_town, 254);
	s->src_town[255] = 0;

	strncpy(s->dst_town, dst_town, 254);
	s->dst_town[255] = 0;

	s->dispatch_time = dispatch_time;

	s->company = company;

	s->fi = fi;

	s->total = total;

	s->sell = sell;
}


const struct bus_service *service_bus_new(
		int id,
		const char *src_town,
		const char *dst_town,
		time_t dispatch_time,
		int company,
		int fi,
		int total,
		int sell
)
{
	struct bus_service *s = malloc(sizeof(struct bus_service));

	service_builder(&s->s, id, src_town, dst_town, dispatch_time, company, fi, total, sell);
	
	return s;

}

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
)
{
	struct train_service *s = malloc(sizeof(struct train_service));

	service_builder(&s->s, id, src_town, dst_town, dispatch_time, company, fi, total, sell);

	s->train_id = train_id;
	
	return s;

}

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
)
{
	struct airplane_service *s = malloc(sizeof(struct airplane_service));

	service_builder(&s->s, id, src_town, dst_town, dispatch_time, company, fi, total, sell);

	s->airplane_id = airplane_id;
	
	return s;

}

static void service_print(const struct service *s, FILE *fp)
{		
	fprintf(fp, "	src_town: %s\n", s->src_town);
	
	fprintf(fp, "	dst_town: %s\n", s->dst_town);
		
	char dispatch_time_s[1024];
	struct tm dispatch_time_t;
	localtime_r(&(s->dispatch_time), &dispatch_time_t);
	strftime(dispatch_time_s, 1024, "%m-%d-%Y", &dispatch_time_t);
	fprintf(fp, "	dispatch_time: %s\n", dispatch_time_s);

	fprintf(fp, "	company: %d\n", s->company);

	fprintf(fp, "	fi: %d\n", s->fi);
	
	fprintf(fp, "	total: %d\n", s->total);
	
	fprintf(fp, "	sell: %d\n", s->sell);

}

void service_bus_print(const struct bus_service *s, FILE *fp)
{
	fprintf(fp, "Bus Service {\n");

	service_print(&s->s, fp);

	fprintf(fp, "}\n");
}

void service_train_print(const struct train_service *s, FILE *fp)
{
	fprintf(fp, "Train Service {\n");

	service_print(&s->s, fp);

	fprintf(fp, "	train_id: %d\n", s->train_id);

	fprintf(fp, "}\n");
}

void service_airplane_print(const struct airplane_service *s, FILE *fp)
{
	fprintf(fp, "Airplane Service {\n");

	service_print(&s->s, fp);

	fprintf(fp, "	airplane_id: %d\n", s->airplane_id);
	
	fprintf(fp, "}\n");
}

void serivce_bus_delete(const struct bus_service *s)
{
	free((void *)s);
}

void service_train_delete(const struct train_service *s)
{
	free((void *)s);
}

void service_airplane_delete(const struct airplane_service *s)
{
	free((void *)s);
}
