/*
 * In The Name Of God
 * ========================================
 * [] File Name : init-2.sql
 *
 * [] Creation Date : 10-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
CREATE TABLE users (
	s_id integer,
	username varchar(255),
	name varchar(255),
	family varchar(255),
	hometown varchar(255),
	career varchar(255),
	birthday date,
	PRIMARY KEY (s_id),
	UNIQUE (username)
);
