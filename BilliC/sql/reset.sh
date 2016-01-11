#!/bin/sh
# In The Name Of God
# ========================================
# [] File Name : reset.sh
#
# [] Creation Date : 10-01-2016
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
# Database reseting :)
sudo -u postgres psql -f reset.sql
