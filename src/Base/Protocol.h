/**
 *
 *@file Protocol.h
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-01
 *
 */

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#pragma pack(1)

//�����������ݰ�
struct cmpp_connect_packet
{
	//��Ϣͷ(12byte)
	unsigned char total_length[4];
	unsigned char command_id[4];
	unsigned char sequence_id[4];
	//��Ϣ��(27byte)
	unsigned char source_addr[6];
	unsigned char authenticator_source[16];
	unsigned char version[1];
	unsigned char timestamp[4];
};

//����������Ӧ���ݰ�
struct cmpp_connect_resp_packet
{
	//��Ϣͷ(12byte)
	unsigned char total_length[4];
	unsigned char command_id[4];
	unsigned char sequence_id[4];
	//��Ϣ��(18byte)
	unsigned char status[1];
	unsigned char authenticator_ismg[16];
	unsigned char version[1];
};

//�ύ�������ݰ�
struct cmpp_submit_packet
{
	//��Ϣͷ(12byte)
	unsigned char total_length[4];
	unsigned char command_id[4];
	unsigned char sequence_id[4];
	//��Ϣ��
	unsigned char msg_id[8];
	unsigned char pk_total[1];
	unsigned char pk_number[1];
	unsigned char registered_delivery[1];
	unsigned char msg_level[1];
	unsigned char service_id[10];
	unsigned char fee_userType[1];
	unsigned char fee_terminal_id[21];
	unsigned char tp_pid[1];
	unsigned char tp_udhi[1];
	unsigned char msg_fmt[1];
	unsigned char msg_src[6];
	unsigned char feeType[2];
	unsigned char feeCode[6];
	unsigned char valId_time[17];
	unsigned char at_time[17];
	unsigned char src_id[21];
	unsigned char destUsr_tl[1];
	unsigned char dest_terminal_id[21];
	unsigned char msg_length[1];
	unsigned char msg_content[160];
	unsigned char reserved[8];
};

//�ύ�������ݰ�
struct cmpp_submit_resp_packet
{
	//��Ϣͷ(12byte)
	unsigned char total_length[4];
	unsigned char command_id[4];
	unsigned char sequence_id[4];
	//��Ϣ��
	unsigned char msg_id[8];
	unsigned char result[1];
};

//�·��������ݰ�
struct cmpp_deliver_packet
{
	//��Ϣͷ(12byte)
	unsigned char total_length[4];
	unsigned char command_id[4];
	unsigned char sequence_id[4];
	//��Ϣ��
	unsigned char msg_id[8];
	unsigned char dest_id[21];
	unsigned char service_id[10];
	unsigned char tp_pid[1];
	unsigned char tp_udhi[1];
	unsigned char msg_fmt[1];
	unsigned char src_terminal_id[21];
	unsigned char registered_delivery[1];
	unsigned char msg_length[1];
	unsigned char msg_content[160];
	unsigned char reserved[8];
};

//״̬�������ݱ�
struct deliver_status_report_packet
{
	unsigned char msg_id[8];
	unsigned char stat[7];
	unsigned char submit_time[10];
	unsigned char done_time[10];
	unsigned char dest_terminal_id[21];
	unsigned char smsc_sequence[4];
};

//�·�������Ӧ���ݰ�
struct cmpp_deliver_resp_packet
{
	//��Ϣͷ(12byte)
	unsigned char total_length[4];
	unsigned char command_id[4];
	unsigned char sequence_id[4];
	//��Ϣ��
	unsigned char msg_id[8];
	unsigned char result[1];
};

//����������ݰ�
struct cmpp_active_test_packet
{
	//��Ϣͷ(12byte)
	unsigned char total_length[4];
	unsigned char command_id[4];
	unsigned char sequence_id[4];
};

//���������Ӧ���ݰ�
struct cmpp_active_test_resp_packet
{
	//��Ϣͷ(12byte)
	unsigned char total_length[4];
	unsigned char command_id[4];
	unsigned char sequence_id[4];
	//��Ϣ��
	unsigned char reserved[1];
};

//��ֹ�������ݰ�
struct cmpp_terminate_packet
{
	//��Ϣͷ(12byte)
	unsigned char total_length[4];
	unsigned char command_id[4];
	unsigned char sequence_id[4];
};

//��ֹ������Ӧ���ݰ�
struct cmpp_terminate_resp_packet
{
	//��Ϣͷ(12byte)
	unsigned char total_length[4];
	unsigned char command_id[4];
	unsigned char sequence_id[4];
};

//
struct long_message
{
	int key;
	int count;
	int num;
	int msg_length;
	unsigned char msg_content[162];
	struct long_message *next;
};


/***********************************************/


/*********************��������**************************/
//�ر�postgresql
//static void exit_nicely(PGconn *conn);
//��¼��ģ��
int cmpp_login_module(int sockfd);
//�ύģ��
void * cmpp_submit_module(void *data);
//�������ģ��
void * cmpp_active_test_module(void *data);
//���������Ӧģ��
int cmpp_active_test_resp_module(int sockfd,unsigned char *active_test_buf);
//�·���Ϣ��Ӧģ��
/*
ISMG���͹����Ķ�����Ϣ����Ϊ���֣�
1.������Ϣ
	�ѽ��ܵ������ݱ��浽ReceiveMessage���С�
	��ISMG����Ӧ����
2.״̬����
	�ѽ��ܵ���״̬���汣�浽StatusReport���С�
	��ISMG����Ӧ����
*/
void cmpp_deliver_resp_module(int sockfd,unsigned char *deliver_buf,int nbytes);
//��ֹ����ģ��
int cmpp_terminate_module(int sockfd);
//��ֹ����Ӧ��ģ��
int cmpp_terminate_resp_module(int sockfd,unsigned char* terminate_buf);

#endif
