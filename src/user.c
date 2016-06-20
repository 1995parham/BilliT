/*
 * In The Name Of God
 * ========================================
 * [] File Name : user.c
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

#include "user.h"

const struct user *user_new(
		int s_id,
		const char *username,
		const char *password,
		const char *name,
		const char *family,
		const char *hometown,
		const char *career,
		time_t birthday)
{
	struct user *u = malloc(sizeof(struct user));
	
	u->s_id = s_id;

	strncpy(u->username, username, 254);
	u->username[255] = 0;

	strncpy(u->password, password, 254);
	u->password[255] = 0;

	strncpy(u->name, name, 254);
	u->name[255] = 0;
	
	strncpy(u->family, family, 254);
	u->family[255] = 0;
	
	strncpy(u->hometown, hometown, 254);
	u->hometown[255] = 0;
	
	strncpy(u->career, career, 254);
	u->career[255] = 0;

	u->birthday = birthday;

	return u;
}

void user_delete(const struct user *u)
{
	free((void *)u);
}

void user_print(const struct user *u, FILE *fp)
{
	fprintf(fp, "User %s - %d {\n", u->username, u->s_id);
	
	fprintf(fp, "	name: %s\n", u->name);
	
	fprintf(fp, "	family: %s\n", u->family);
	
	fprintf(fp, "	hometown: %s\n", u->hometown);
	
	fprintf(fp, "	career: %s\n", u->career);
	
	char birthday_s[1024];
	struct tm birthday_t;
	localtime_r(&(u->birthday), &birthday_t);
	strftime(birthday_s, 1024, "%m-%d-%Y", &birthday_t);
	fprintf(fp, "	birthday: %s\n", birthday_s);

	fprintf(fp, "}\n");
}
