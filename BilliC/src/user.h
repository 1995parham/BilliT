/*
 * In The Name Of God
 * ========================================
 * [] File Name : user.h
 *
 * [] Creation Date : 10-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#ifndef USER_H
#define USER_H

#include <time.h>
#include <stdio.h>

struct user {
	int s_id;
	char username[255];
	char name[255];
	char family[255];
	char hometown[255];
	char career[255];
	time_t birthday;
};

const struct user *user_new(
		int s_id,
		const char *username,
		const char *name,
		const char *family,
		const char *hometown,
		const char *career,
		time_t birthday
);

void user_delete(const struct user *u);

void user_print(const struct user *u, FILE *fp);

#endif
