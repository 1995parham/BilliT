/*
 * In The Name Of God
 * ========================================
 * [] File Name : init-services.sql
 *
 * [] Creation Date : 12-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
CREATE SEQUENCE services_id_seq
	start with 1
	increment by 1
	no minvalue
	no maxvalue
	cache 1;

CREATE TABLE IF NOT EXISTS services (
	id integer primary key default nextval('services_id_seq'),
	src_town varchar(255) not null,
	dst_town varchar(255) not null,
	dispatch_time timestamp not null,
	company integer not null references companies(id) on delete restrict,
	fi integer not null,
	total integer not null,
	sell integer not null default 0
);

CREATE TABLE IF NOT EXISTS bus_services (
) INHERITS (services);

CREATE TABLE IF NOT EXISTS airplane_services (
	airplane_id integer
) INHERITS (services);

CREATE TABLE IF NOT EXISTS train_services (
	train_id integer
) INHERITS (services);

