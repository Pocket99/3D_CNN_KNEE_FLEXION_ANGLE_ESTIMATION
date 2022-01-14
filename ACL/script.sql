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

insert into doctor value ("Tom","123456");

ALTER TABLE patiant
ADD doctor_name varchar(16) not null;

ALTER TABLE patiant
ADD FOREIGN KEY (doctor_name) REFERENCES doctor(username);

insert into patiant value ("Jerry","1989/12/15","Tom");