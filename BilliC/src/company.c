/*
 * In The Name Of God
 * ========================================
 * [] File Name : company.c
 *
 * [] Creation Date : 10-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "company.h"

const struct company *company_new(
		int id,
		int manager,
		const char *name,
		int driver,
		int pilot,
		int bus)
{
	struct company *c = malloc(sizeof(struct company));
	
	c->id = id;

	c->manager = manager;

	strncpy(c->name, name, 254);
	c->name[255] = 0;
	
	c->driver = driver;

	c->pilot = pilot;

	c->bus = bus;

	return c;
}

void user_delete(const struct company *c)
{
	free((void *)c);
}

void user_print(const struct company *c, FILE *fp)
{
	fprintf(fp, "Company %s - %d {\n", c->name, c->manager);
	
	fprintf(fp, "	driver: %d\n", c->driver);
	
	fprintf(fp, "	pilot: %d\n", c->pilot);
	
	fprintf(fp, "	bus: %d\n", c->bus);
	
	fprintf(fp, "}\n");
}
