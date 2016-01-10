/*
 * In The Name Of God
 * ========================================
 * [] File Name : prl.c
 *
 * [] Creation Date : 10-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#include "prl.h"

#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

static char *line_read;
static char prompt[1024] = "BilliC >";

void prl_set_prompt(const char *p)
{
	strcpy(prompt, p);
}

const char *prl_get_prompt(void)
{
	return prompt;
}

char *prl_gets(void)
{
	if (line_read) {
		free(line_read);
		line_read = NULL;
	}

	line_read = readline(prompt);
	if (line_read && *line_read)
		add_history(line_read);

	return line_read;
}
