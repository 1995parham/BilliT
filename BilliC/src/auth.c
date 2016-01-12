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
#include "user_db.h"

static char username[255];
static char company[255];
static int s_id;

void auth_login_procedure(void)
{
	char password[255];

	printf("Please enter username:\n");
	scanf("%s", username);
	getchar();
	printf("Plase enter password:\n");
	plib_fgetpass(password, 255, stdin);
	
	if (!strcmp(username, "admin") && !strcmp(password, "admin\n")) {
		s_id = 0;
		printf("Welcome Admin ... you are the god of system\n");
	} else if (!strcmp(username, "geust")) {
		s_id = -1;
	} else {
		const struct user *u = user_db_get_with_username(username);
		if (!u) {
			plib_udie("Authentication failed");
		} else {
			s_id = u->s_id;
			user_print(u, stdin);
			user_delete(u);
		}
	}

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
