/*
 * In The Name Of God
 * ========================================
 * [] File Name : company.h
 *
 * [] Creation Date : 12-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/

#ifndef COMPANY_H
#define COMPANY_H

struct company {
	int id;
	int manager;
	char name[255];
	int driver;
	int pilot;
	int bus;
};

const struct company *company_new(
		int id,
		int manager,
		const char *name,
		int driver;
		int pilot;
		int bus;
);

void company_delete(const struct company *c);

void company_print(const struct company *c, FILE *fp);


#endif
