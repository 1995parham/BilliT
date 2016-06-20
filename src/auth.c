/*
 * In The Name Of God
 * ========================================
 * [] File Name : auth.c
 *
 * [] Creation Date : 11-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#include <stdio.h>
#include <string.h>
#include <PString.h>
#include <PLog.h>

#include "auth.h"
#include "user.h"
#include "company.h"
#include "user_db.h"
#include "company_db.h"

static char username[255];
static char company[255];
static int s_id;
static int c_id;

void auth_login_procedure(void)
{
	char password[255];

	printf("Please enter username:\n");
	scanf("%s", username);
	getchar();
	printf("Plase enter password:\n");
	plib_fgetpass(password, 255, stdin);
	password[strlen(password) - 1] = 0;
	
	if (!strcmp(username, "admin") && !strcmp(password, "admin")) {
		s_id = 0;
		printf("Welcome Admin ... you are the god of system\n");
	} else if (!strcmp(username, "geust")) {
		s_id = -1;
	} else {
		const struct user *u = user_db_get_with_username(username);
		if (!u) {
			plib_udie("Authentication failed");
		} else {
			if (!strcmp(password, u->password)) {
				s_id = u->s_id;
				user_print(u, stdout);
			} else {
				s_id = -1;
				strcpy(username, "guest");
			}
			user_delete(u);
		}
	}

	printf("Please enter company name if applicable:\n");
	fgets(company, 255, stdin);
	company[strlen(company) - 1] = 0;

	if (strlen(company)) {
		const struct company *c = company_db_get_with_name(company);
		if (!c) {
			printf("%s not found\n", company);
			c_id = 0;
		} else {
			if (c->manager != s_id) {
				printf("%s is not yours ...\n", company);
				c_id = 0;
			} else {
				c_id = c->id;
				company_print(c, stdout);
			}
			company_delete(c);
		}
	}
	if (!c_id)
		strcpy(company, "None");

}

const char *auth_get_username(void)
{
	return username;
}

const char *auth_get_company(void)
{
	return company;
}

int auth_get_s_id(void)
{
	return s_id;
}

int auth_get_c_id(void)
{
	return c_id;
}
