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

struct user {
	const char *username;
	const char *name;
	const char *family;
	const char *hometown;
	const char *career;
	time_t birthday;
}

#endif
