create table send_message
(
   send_id       varchar2(20) not null, --��Ϣ id
   phone         varchar2(20) not null, --�绰
   msg_level     number(1) default 9,   --���ȼ�
   content       varchar2(2000),        --����
   valid_time    date,                  --�����Ч��
   at_time       date,                  --��ʱ����ʱ�� 
   wap_push_url  varchar2(1000),        --wappush��ַ
   sms_type      number(1) default 0,   --���� ����
   status_report number(1) default 0,   --���� ����
   send_time     date,                  --���� ʱ��
   optime        date,                  --���ʱ��
   done          varchar2(2)            --����״̬ 
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
   valid_time       date,--�����Ч��
   at_time          date,--��ʱ����ʱ��
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

