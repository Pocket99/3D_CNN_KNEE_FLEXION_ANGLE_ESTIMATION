create database mydatabase;

use mydatabase;
create table doctor(
  username varchar(16) not null primary key,
  password varchar(16) not null
)charset utf8;

create table patiant(
  name varchar(16) not null primary key,
  birth date
)charset utf8;