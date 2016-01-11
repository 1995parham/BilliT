/*
 * In The Name Of God
 * ========================================
 * [] File Name : init-company.sql
 *
 * [] Creation Date : 11-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
CREATE SEQUENCE companies_id_seq
	start with 1
	increment by 1
	no minvalue
	no maxvalue
	cache 1;

CREATE TABLE IF NOT EXISTS companies (
	id integer not null primary key default nextval('companies_id_seq'),
	manager integer not null references users(s_id),
	name varchar(255) not null
	driver integer not null CHECK (driver > 4),
	pilot integer not null CHECK (pilot > 6),
	bus integer not null CHECK (bus > 5)
);

