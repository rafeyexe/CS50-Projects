select title from movies where id in
(select movie_id from stars where person_id in (select id from people where name is "Helena Bonham Carter")
intersect
select movie_id from stars where person_id in (select id from people where name is "Johnny Depp"))