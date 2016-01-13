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

CREATE OR REPLACE FUNCTION services_insert() RETURNS trigger AS $services_insert$
	BEGIN
		-- Check that we have 3 service with equal fi between src_town and dst_town.
		IF (SELECT COUNT(id) FROM services
			WHERE fi = NEW.fi AND src_town = NEW.src_town AND dst_town = NEW.dst_town) = 3 THEN
				IF NEW.fi > 0.9 * (SELECT fi FROM services 
					WHERE fi = NEW.fi AND src_town = NEW.src_town
					AND dst_town = NEW.dst_town LIMIT 1) THEN
						RAISE EXCEPTION 'Invalid service condition :(';
				END IF;
		END IF;
		RETURN NEW;
	END;
$services_insert$ LANGUAGE plpgsql;

CREATE TRIGGER services_insert BEFORE INSERT ON bus_services
	FOR EACH ROW EXECUTE PROCEDURE services_insert();

CREATE TRIGGER services_insert BEFORE INSERT ON airplane_services
	FOR EACH ROW EXECUTE PROCEDURE services_insert();

CREATE TRIGGER services_insert BEFORE INSERT ON train_services
	FOR EACH ROW EXECUTE PROCEDURE services_insert();
