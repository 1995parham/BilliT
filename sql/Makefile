# In The Name Of God
# ========================================
# [] File Name : Makefile
#
# [] Creation Date : 13-01-2016
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

all: init users companies services vehicle tickets build
# Database initiation
init:
	sudo -u postgres psql -f init.sql
# User table creation
users: init
	psql -U billit -W -d billit -h 127.0.0.1 -f init-users.sql
# Companies table creation
companies: init users
	psql -U billit -W -d billit -h 127.0.0.1 -f init-companies.sql
# Services table creation
services: init companies
	psql -U billit -W -d billit -h 127.0.0.1 -f init-services.sql
# Vehicles table creation
vehicle: init companies
	psql -U billit -W -d billit -h 127.0.0.1 -f init-vehicle.sql
# Tickets table creation
tickets: init companies users
	psql -U billit -W -d billit -h 127.0.0.1 -f init-tickets.sql
# Fill tables with some data
build: init companies users
	sudo -u postgres psql -d billit -f build.sql
# Database reseting :)
clean:
	sudo -u postgres psql -f reset.sql
