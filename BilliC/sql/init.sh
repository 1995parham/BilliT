#!/bin/sh
# In The Name Of God
# ========================================
# [] File Name : init.sh
#
# [] Creation Date : 10-01-2016
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
# Database initiation
sudo -u postgres psql -f init.sql
# User table creation
psql -U billit -W -d billit -h 127.0.0.1 -f init-users.sql
# Companies table creation
psql -U billit -W -d billit -h 127.0.0.1 -f init-companies.sql
# Services table creation
psql -U billit -W -d billit -h 127.0.0.1 -f init-services.sql
# Fill tables with some data
sudo -u postgres psql -d billit -f build.sql
