select name from people where name is not "Kevin Bacon" and id in (select distinct person_id from stars where movie_id in (select movie_id from stars where person_id in (select id from people where name is "Kevin Bacon" and birth is 1958)));