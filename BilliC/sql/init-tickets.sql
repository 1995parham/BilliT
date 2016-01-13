/*
 * In The Name Of God
 * ========================================
 * [] File Name : init-tickets.sql
 *
 * [] Creation Date : 13-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/

CREATE SEQUENCE bus_tickets_id_seq
	start with 1
	increment by 3
	no minvalue
	no maxvalue
	cache 1;

CREATE SEQUENCE airplane_tickets_id_seq
	start with 2
	increment by 3
	no minvalue
	no maxvalue
	cache 1;

CREATE SEQUENCE train_tickets_id_seq
	start with 3
	increment by 3
	no minvalue
	no maxvalue
	cache 1;

CREATE TABLE IF NOT EXISTS bus_tickets (
	id integer primary key default nextval('bus_ticket_id_seq'),
	buyer integer not null references users(s_id) on delete cascade,
	count integer not null,
	service integer not null refrences bus_services(id) on delete cascade,
	price integer not null
);

CREATE TABLE IF NOT EXISTS airplane_tickets (
	id integer primary key default nextval('airplane_ticket_id_seq'),
	buyer integer not null references users(s_id) on delete cascade,
	count integer not null,
	service integer not null refrences airplane_services(id) on delete cascade,
	price integer not null
);

CREATE TABLE IF NOT EXISTS train_tickets (
	id integer primary key default nextval('train_ticket_id_seq'),
	buyer integer not null references users(s_id) on delete cascade,
	count integer not null,
	service integer not null refrences train_services(id) on delete cascade,
	price integer not null
);

CREATE OR REPLACE VIEW tickets AS
	SELECT id, buyer, count, service, price 'bus' AS vehicle
	FROM bus_tickets
	UNION
	SELECT id, buyer, count, service, price 'airplane' AS vehicle
	FROM airplane_tickets
	UNION
	SELECT id, buyer, count, service, price 'train' AS vehicle
	FROM train_tickets;

CREATE OR REPLACE FUNCTION bus_tickets_insert() RETURNS trigger AS $bus_tickets_insert$
	BEGIN
		-- Check that we have enough ticket in target service
		IF NEW.count > (SELECT (total - sell) FROM bus_services WHERE id = NEW.service) THEN
			RAISE EXCEPTION 'we donot have enough bus ticket for you';
		END IF;
		-- Update target service sell column
		UPDATE bus_services SET sell = sell + NEW.count WHERE id = NEW.service;
		-- Calculate final price
		NEW.price := NEW.count * (SELECT fi FROM bus_services WHERE id = NEW.service);
		RETURN NEW;
	END;
$bus_tickets_insert$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER bus_tickets_insert BEFORE INSERT ON bus_tickets
	FOR EACH ROW EXECUTE PROCEDURE bus_tickets_insert();

CREATE OR REPLACE FUNCTION train_tickets_insert() RETURNS trigger AS $train_tickets_insert$
	BEGIN
		-- Check that we have enough ticket in target service
		IF NEW.count > (SELECT (total - sell) FROM train_services WHERE id = NEW.service) THEN
			RAISE EXCEPTION 'we donot have enough train ticket for you';
		END IF;
		-- Update target service sell column
		UPDATE train_services SET sell = sell + NEW.count WHERE id = NEW.service;
		-- Calculate final price
		NEW.price := NEW.count * (SELECT fi FROM train_services WHERE id = NEW.service);
		RETURN NEW;
	END;
$train_tickets_insert$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER train_tickets_insert BEFORE INSERT ON train_tickets
	FOR EACH ROW EXECUTE PROCEDURE train_tickets_insert();

CREATE OR REPLACE FUNCTION airplane_tickets_insert() RETURNS trigger AS $airplane_tickets_insert$
	BEGIN
		-- Check that we have enough ticket in target service
		IF NEW.count > (SELECT (total - sell) FROM airplane_services WHERE id = NEW.service) THEN
			RAISE EXCEPTION 'we donot have enough airplane ticket for you';
		END IF;
		-- Update target service sell column
		UPDATE airplane_services SET sell = sell + NEW.count WHERE id = NEW.service;
		-- Calculate final price
		NEW.price := NEW.count * (SELECT fi FROM airplane_services WHERE id = NEW.service);
		RETURN NEW;
	END;
$airplane_tickets_insert$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER airplane_tickets_insert BEFORE INSERT ON airplane_tickets
	FOR EACH ROW EXECUTE PROCEDURE airplane_tickets_insert();
