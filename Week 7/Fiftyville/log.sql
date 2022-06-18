-- Keep a log of any SQL queries you execute as you solve the mystery.

--Check all crimes that took place in the given day
select description from crime_scene_reports where day = 28 and month = 7 and year = 2020 and street like "%Chamberlin%";
description 

--Check all interviews which mention a thief
select transcript from interviews where day is 28 and month is 7 and year is 2020 and transcript like "%thief%";

--Check courthouse logs for activity. One of the results has to be the thief
select * from courthouse_security_logs where day is 28 and month is 7 and year is 2020 and hour is 10 and minute>14 and minute<26;

--Check details of everyone that was exiting the courthouse in the given time frame
select license_plate,name,id from people where license_plate in (select license_plate from courthouse_security_logs where day is 28 and month is 7 and year is 2020 and hour is 10 and minute>14 and minute<26);

--Check for phone calls within 10 minutes of theft. One of the pair has to be the thief & accomplice
select caller, receiver from phone_calls where duration<60 and day is 28 and month is 7 and year is 2020;

--Check names of people who called. One of them is the thief
select name from people where phone_number in (select caller from phone_calls where duration<60 and day is 28 and month is 7 and year is 2020);

--Check account numbers of potential suspects who called during the timeframe and also made a transaction
select account_number from bank_accounts where person_id in (select id from people where phone_number in (select caller from phone_calls where duration<60 and day is 28 and month is 7 and year is 2020))
INTERSECT
select account_number from atm_transactions where atm_location like "%Fifer Street%" and transaction_type like "withdraw" and day is 28 and month is 7 and year is 2020;

--List of IDs of suspects
select person_id from bank_accounts where account_number in (select account_number from bank_accounts where person_id in (select id from people where phone_number in (select caller from phone_calls where duration<60 and day is 28 and month is 7 and year is 2020))
INTERSECT
select account_number from atm_transactions where atm_location like "%Fifer Street%" and transaction_type like "withdraw" and day is 28 and month is 7 and year is 2020);

--Earliest flight out of fiftyville the next day
select * from flights where day is 29 and month is 7 and year is 2020 order by hour;

--Names of people who have the earliest flight out of fiftyville, made calls, and transactions
select name from people where passport_number in (select passport_number from passengers where flight_id is 36
INTERSECT
select passport_number from people where id in (select person_id from bank_accounts where account_number in (select account_number from bank_accounts where person_id in (select id from people where phone_number in (select caller from phone_calls where duration<60 and day is 28 and month is 7 and year is 2020))
INTERSECT
select account_number from atm_transactions where atm_location like "%Fifer Street%" and transaction_type like "withdraw" and day is 28 and month is 7 and year is 2020)));

--Cross check all earliest flight passengers with people whose license plates were seen at the courthouse. The thief is Ernest!
select name from people where passport_number in (select passport_number from passengers where flight_id in (select flight_id from passengers where passport_number in(select passport_number from people where passport_number in (select passport_number from passengers where flight_id is 36
INTERSECT
select passport_number from people where id in (select person_id from bank_accounts where account_number in (select account_number from bank_accounts where person_id in (select id from people where phone_number in (select caller from phone_calls where duration<60 and day is 28 and month is 7 and year is 2020))
INTERSECT
select account_number from atm_transactions where atm_location like "%Fifer Street%" and transaction_type like "withdraw" and day is 28 and month is 7 and year is 2020)))))
INTERSECT
select passport_number from people where id in (select person_id from bank_accounts where account_number in (select account_number from bank_accounts where person_id in (select id from people where phone_number in (select caller from phone_calls where duration<60 and day is 28 and month is 7 and year is 2020))
INTERSECT
select account_number from atm_transactions where atm_location like "%Fifer Street%" and transaction_type like "withdraw" and day is 28 and month is 7 and year is 2020)))
INTERSECT
select name from people where license_plate in (select license_plate from courthouse_security_logs where day is 28 and month is 7 and year is 2020 and hour is 10 and minute>14 and minute<26);

--Check all calls less than a minute long that were made from Ernest's number to anyone during the given time frame. Accomplice is Berthold!
select name from people where phone_number is (select receiver from phone_calls where caller is '(367) 555-5533' and day is 28 and month is 7 and year is 2020 and duration <= 60);


--Identify flight id that Ernest was on
select flight_id from passengers where passport_number is (select passport_number from people where name like "%Ernest%");

--Check where the earliest flight from fiftyville is going, which is london
select city from airports where id is (select destination_airport_id from flights where hour is 8 and minute is 20 and origin_airport_id in (select origin_airport_id from flights where id is (select flight_id from passengers where passport_number is (select passport_number from people where name like "%Ernest%"))));























