/*
 * In The Name Of God
 * ========================================
 * [] File Name : init-vehicle.sql
 *
 * [] Creation Date : 13-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
CREATE SEQUENCE airplanes_id_seq
	start with 1
	increment by 1
	no minvalue
	no maxvalue
	cache 1;

CREATE SEQUENCE trains_id_seq
	start with 1
	increment by 1
	no minvalue
	no maxvalue
	cache 1;

CREATE TABLE IF NOT EXISTS airplanes (
	id integer primary key default nextval('airplanes_id_seq'),
	model integer not null,
	vendor varchar(255) not null,
	company integer not null refrences companies(id)
);

CREATE TABLE IF NOT EXISTS trains (
	id integer primary key default nextval('trains_id_seq'),
	model integer not null,
	vendor varchar(255) not null,
	company integer not null refrences companies(id)
);
