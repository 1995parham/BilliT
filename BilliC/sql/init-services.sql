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
CREATE SEQUENCE bus_services_id_seq
	start with 1
	increment by 3
	no minvalue
	no maxvalue
	cache 1;

CREATE SEQUENCE airplane_services_id_seq
	start with 2
	increment by 3
	no minvalue
	no maxvalue
	cache 1;

CREATE SEQUENCE train_services_id_seq
	start with 3
	increment by 3
	no minvalue
	no maxvalue
	cache 1;

CREATE TABLE IF NOT EXISTS bus_services (
	id integer primary key default nextval('bus_services_id_seq'),
	src_town varchar(255) not null,
	dst_town varchar(255) not null,
	dispatch_time timestamp not null,
	company integer not null references companies(id) on delete restrict,
	fi integer not null,
	total integer not null,
	sell integer not null default 0
);

CREATE TABLE IF NOT EXISTS airplane_services (
	id integer primary key default nextval('airplane_services_id_seq'),
	src_town varchar(255) not null,
	dst_town varchar(255) not null,
	dispatch_time timestamp not null,
	company integer not null references companies(id) on delete restrict,
	fi integer not null,
	total integer not null,
	sell integer not null default 0,
	airplane_id integer not null
);

CREATE TABLE IF NOT EXISTS train_services (
	id integer primary key default nextval('train_services_id_seq'),
	src_town varchar(255) not null,
	dst_town varchar(255) not null,
	dispatch_time timestamp not null,
	company integer not null references companies(id) on delete restrict,
	fi integer not null,
	total integer not null,
	sell integer not null default 0,
	train_id integer not null
);

CREATE OR REPLACE VIEW services AS
	SELECT id, src_town, dst_town, dispatch_time, company, fi, total, sell, 'bus' AS vehicle
	FROM bus_services
	UNION
	SELECT id, src_town, dst_town, dispatch_time, company, fi, total, sell, 'train' AS vehicle
	FROM train_services
	UNION
	SELECT id, src_town, dst_town, dispatch_time, company, fi, total, sell, 'airplane' AS vehicle
	FROM airplane_services;

