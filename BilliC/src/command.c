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
#include "user.h"
#include "user_db.h"

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

void create_user_command(void)
{
	int s_id;
	char username[255];
	char name[255];
	char family[255];
	char hometown[255];
	char career[255];
	time_t birthday;
	struct tm birthday_t;

	printf("Please enter user.s_id:\n");
	scanf("%d", &s_id);
	
	printf("Please enter user.username:\n");
	scanf("%s", username);
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
	scanf("%d %d %d",&birthday_t.tm_mon, &birthday_t.tm_mday, &birthday_t.tm_year);
	birthday_t.tm_year -= 1900;
	birthday_t.tm_mon -= 1;
	birthday = mktime(&birthday_t);

	const struct user *u = user_new(s_id, username, name,
			family, hometown, career, birthday);

	if (user_db_insert(u) == 0)
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
	char verb[1024];
	int len;

	len = sscanf(command, "%s", verb);
	if (len < 1)
		return;

	if (!strcmp(verb, "quit"))
		quit_command();
	else if (!strcmp(verb, "create_user"))
		create_user_command();
}
