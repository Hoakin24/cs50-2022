-- Keep a log of any SQL queries you execute as you solve the mystery.

.schema -- to know the tables inside the database

SELECT description FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street = 'Humphrey Street';
-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
-- Interviews were conducted today with three witnesses who were present at
-- the time – each of their interview transcripts mentions the bakery. Littering took place at 16:36. No known witnesses.

SELECT * FROM interviews WHERE transcript LIKE '%bakery%';
-- transcripts/interviews with the word bakery

SELECT * FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 26);
-- license plates of people who were within 10 minutes after the crime

SELECT * FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street';
-- atm transaction of thief

SELECT * FROM flights WHERE year = 2021 AND month = 7 AND day = 29 and origin_airport_id = (SELECT id FROM airports WHERE city = 'Fiftyville');
-- flights for july 29, 2021

SELECT * FROM passengers WHERE flight_id = 36;
-- earliest flight on july 29, 2021

SELECT * FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36);
-- details of passengers of earliest flight

SELECT * FROM airports WHERE id = 4;
-- destination of thief, which is new york city

SELECT * FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 26) AND passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36);
-- details of people

SELECT * FROM people WHERE id = (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street'));
-- gets the details of person who did a transaction at leggett street on july 28, 2021, which is bruce

SELECT * FROM phone_calls WHERE caller IN (SELECT phone_number FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 26) AND passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36)) AND day = 28 and duration < 60;
-- luca is out as he didnt make any phone call during the timeframe
-- get name of accomplice by cross referencing phone number to receiver
-- receiver is accomplice, which is robin



