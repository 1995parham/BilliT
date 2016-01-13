/*
 * In The Name Of God
 * ========================================
 * [] File Name : build.sql
 *
 * [] Creation Date : 13-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/


\copy users FROM 'data/users.txt';

\copy companies FROM 'data/companies.txt';

\copy bus_services (src_town, dst_town, dispatch_time, company, fi, total) FROM 'data/bus_services.txt';
