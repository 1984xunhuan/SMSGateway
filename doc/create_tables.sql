create table send_message
(
   send_id       varchar2(20) not null, --信息 id
   phone         varchar2(20) not null, --电话
   msg_level     number(1) default 9,   --优先级
   content       varchar2(2000),        --内容
   valid_time    date,                  --存活有效期
   at_time       date,                  --定时发送时间 
   wap_push_url  varchar2(1000),        --wappush地址
   sms_type      number(1) default 0,   --短信 类型
   status_report number(1) default 0,   --短信 类型
   send_time     date,                  --发送 时间
   optime        date,                  --添加时间
   done          varchar2(2)            --处理状态 
);

alter table send_message add constraint pk_send_message primary key(send_id);

insert into send_message(send_id, phone, msg_level, content, valid_time, 
at_time, wap_push_url, sms_type, status_report, send_time, optime, done)
values('20100907131400000001','15902755770',9,'test',sysdate,sysdate, '', 0, 1, sysdate,sysdate,0);

create table submit_message
(
   send_id          varchar2(20) not null,
   sequence_id      number(9),
   msg_id           number(9),
   result           varchar2(2),
   sms_type         number(1),
   phone            varchar2(22) not null,
   msg_level    number(1) default 9,
   msg_content      varchar2(1000),
   wap_push_url     varchar2(1000),
   valid_time       date,--存活有效期
   at_time          date,--定时发送时间
   response_time    date,
   optime           date,
   done             varchar2(2)
);


create table receive_message
(
   msg_id   number(20)      not null,
   phone    varchar2(22)   not null,
   content  varchar2(2000),
   rcvtime  date,
   done     varchar2(2)
);

alter table receive_message add constraint pk_receive_message primary key(msg_id);

create table status_report
(
   msg_id           number(20),
   stat             varchar2(8),
   submit_time      varchar2(11),
   done_time        varchar2(11),
   dest_terminal_id varchar2(22),
   smsc_sequence    number(5),
   optime           date
);

--alter table status_report add constraint pk_status_report primary key(msg_id);

