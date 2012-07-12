
--create tablespace
prompt oms and tms data tablespace
create tablespace sms_data datafile '/data1/sms_data.ora' size 10M autoextend on next 10M maxsize unlimited default storage(initial 128K next 128K minextents 5 maxextents unlimited);

--create user
create user sms identified by sms default tablespace sms_data;

--grant to user
grant dba,connect,resource,select any table,delete any table,update any table,insert any table to sms;
