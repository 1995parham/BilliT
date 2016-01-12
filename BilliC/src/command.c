/*
 * In The Name Of God
 * ========================================
 * [] File Name : command.c
 *
 * [] Creation Date : 10-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#include "command.h"
#include "auth.h"
#include "company.h"
#include "user.h"
#include "company_db.h"
#include "user_db.h"
#include "db.h"

/*
 * Commands in this program have the following foramt:
 * VERB [1] [2] ...
 * ** len(VERB) <= 1024
 * ** [1] [2] were arguments and passed into function.
 * every VERB have handler in following format
 * void VERB_command([1], [2], [3], ..)
*/


void quit_command(void)
{
	exit(0);
}

void query_command(void)
{
	int buff_size = 1000 * 1000;
	int index = 0;
	char command[buff_size];
	
	printf("Please enter desired query [ctrl + D to end :)]:\n");

	while (fgets(command + index, buff_size - index, stdin) != NULL)
		index += strlen(command + index);
	command[strlen(command) - 1] = 0;
	
	pq_run_and_show(command);
}

void create_company_command(void)
{
	int manager;

	char name[255];
	
	int driver;

	int pilot;

	int bus;
	
	printf("Please enter company.manager:\n");
	scanf("%d", &manager);
	getchar();
	
	printf("Please enter company.name:\n");
	fgets(name, 255, stdin);
	name[strlen(name) - 1] = 0;

	printf("Please enter company.driver:\n");
	scanf("%d", &driver);
	
	printf("Please enter company.pilot:\n");
	scanf("%d", &pilot);

	printf("Please enter company.bus:\n");
	scanf("%d", &bus);

	const struct company *c = company_new(0, manager, name,
			driver, pilot, bus);

	if (!company_db_insert(c))
		printf("INSERT was successful\n");

	company_print(c, stdout);
	company_delete(c);

}

void create_user_command(void)
{
	int s_id;
	
	char username[255];
	
	char password[255];
	
	char name[255];
	
	char family[255];
	
	char hometown[255];
	
	char career[255];
	
	time_t birthday;
	int mm, dd, yy;
	struct tm birthday_t = {};

	printf("Please enter user.s_id:\n");
	scanf("%d", &s_id);
	
	printf("Please enter user.username:\n");
	scanf("%s", username);
	getchar();
	
	printf("Please enter user.password:\n");
	scanf("%s", password);
	getchar();
	
	printf("Please enter user.name:\n");
	fgets(name, 255, stdin);
	name[strlen(name) - 1] = 0;

	printf("Please enter user.family:\n");
	fgets(family, 255, stdin);
	family[strlen(family) - 1] = 0;

	printf("Please enter user.hometown:\n");
	fgets(hometown, 255, stdin);
	hometown[strlen(hometown) - 1] = 0;

	printf("Please enter user.career:\n");
	fgets(career, 255, stdin);
	career[strlen(career) - 1] = 0;

	printf("Please enter user.birthday mm dd yyyy:\n");
	scanf("%d %d %d",&mm, &dd, &yy);
	birthday_t.tm_year = yy - 1900;
	birthday_t.tm_mon = mm - 1;
	birthday_t.tm_mday = dd;
	birthday = mktime(&birthday_t);

	const struct user *u = user_new(s_id, username, password,
			name, family, hometown, career, birthday);

	if (!user_db_insert(u))
		printf("INSERT was successful\n");

	user_print(u, stdout);
	user_delete(u);
}

void show_command(char c)
{
	switch (c) {
	case 'w':
		printf("BilliC is a simple interactive ticket seller\n");

		printf("Copyright (C) 2016 ");
		printf("Parham Alvani(parham.alvani@gmail.com)\n");

		printf("This program is free software: ");
		printf("you can redistribute it and/or modify\n");

		printf("it under the terms of the ");
		printf("GNU General Public License as published by\n");

		printf("the Free Software Foundation, ");
		printf("either version 3 of the License, or\n");

		printf("(at your option) any later version.\n");

		printf("This program is distributed in the hope");
		printf(" that it will be useful,\n");

		printf("but WITHOUT ANY WARRANTY; ");
		printf("without even the implied warranty of\n");

		printf("MERCHANTABILITY or FITNESS FOR A ");
		printf("PARTICULAR PURPOSE.  See the\n");

		printf("GNU General Public License for more details.\n");

		printf("You should have received a copy of the ");
		printf("GNU General Public License\n");

		printf("along with this program.  ");
		printf("If not, see <http://www.gnu.org/licenses/>.\n");
		break;
	case 'c':
		printf("BilliC is a simple interactive ticket seller\n");

		printf("Copyright (C) 2016 ");
		printf("Parham Alvani(parham.alvani@gmail.com)\n");

		printf("This program is free software: ");
		printf("you can redistribute it and/or modify\n");

		printf("it under the terms of the ");
		printf("GNU General Public License as published by\n");

		printf("the Free Software Foundation, ");
		printf("either version 3 of the License, or\n");

		printf("(at your option) any later version.\n");

		printf("This program is distributed in the hope");
		printf(" that it will be useful,\n");

		printf("but WITHOUT ANY WARRANTY; ");
		printf("without even the implied warranty of\n");

		printf("MERCHANTABILITY or FITNESS FOR A ");
		printf("PARTICULAR PURPOSE.  See the\n");

		printf("GNU General Public License for more details.\n");

		printf("You should have received a copy of the ");
		printf("GNU General Public License\n");

		printf("along with this program.  ");
		printf("If not, see <http://www.gnu.org/licenses/>.\n");
		break;
	}
}

void command_dispatcher(const char *command)
{
	if (!command)
		quit_command();

	char verb[1024];
	int len;

	len = sscanf(command, "%s", verb);
	if (len < 1)
		return;

	if (!strcmp(verb, "quit")) {
		quit_command();
	} else if (!strcmp(verb, "create_user")) {
		if (auth_get_s_id() > 0)
			return;
		create_user_command();
	} else if (!strcmp(verb, "create_company")) {
		if (auth_get_s_id() < 0)
			return;
		create_company_command();
	} else if (!strcmp(verb, "query")) {
		query_command();
	} else {
		printf("404 Not Found :D\n");
	}
}
