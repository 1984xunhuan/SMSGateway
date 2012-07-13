begin
FOR i IN 1..10000 LOOP
insert into send_message(send_id, phone, msg_level, content, valid_time, 
at_time, wap_push_url, sms_type, status_report, send_time, optime, done)
values(lpad(i,8,'0'),'159'||lpad(i,8,'0'),9,'The new conservation zone said to be Australias largest - encompasses deserts and savannas.The designation follows four years of discussions between the government, Aboriginal organisations and environmentalists',sysdate,sysdate, '', 0, 1, sysdate,sysdate,0);
END LOOP;
end;