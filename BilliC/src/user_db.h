/*
 * In The Name Of God
 * ========================================
 * [] File Name : user_db.h
 *
 * [] Creation Date : 10-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/

#ifndef USER_DB_H
#define USER_DB_H

#include "user.h"

int user_db_insert(const struct user *u);

const struct user *user_db_get_with_username(const char *username_i);

#endif
