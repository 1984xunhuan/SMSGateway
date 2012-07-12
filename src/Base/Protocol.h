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

//请求连接数据包
struct cmpp_connect_packet
{
	//消息头(12byte)
	unsigned char total_length[4];
	unsigned char command_id[4];
	unsigned char sequence_id[4];
	//消息体(27byte)
	unsigned char source_addr[6];
	unsigned char authenticator_source[16];
	unsigned char version[1];
	unsigned char timestamp[4];
};

//请求连接相应数据包
struct cmpp_connect_resp_packet
{
	//消息头(12byte)
	unsigned char total_length[4];
	unsigned char command_id[4];
	unsigned char sequence_id[4];
	//消息体(18byte)
	unsigned char status[1];
	unsigned char authenticator_ismg[16];
	unsigned char version[1];
};

//提交短信数据包
struct cmpp_submit_packet
{
	//消息头(12byte)
	unsigned char total_length[4];
	unsigned char command_id[4];
	unsigned char sequence_id[4];
	//消息体
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

//提交短信数据包
struct cmpp_submit_resp_packet
{
	//消息头(12byte)
	unsigned char total_length[4];
	unsigned char command_id[4];
	unsigned char sequence_id[4];
	//消息体
	unsigned char msg_id[8];
	unsigned char result[1];
};

//下发短信数据包
struct cmpp_deliver_packet
{
	//消息头(12byte)
	unsigned char total_length[4];
	unsigned char command_id[4];
	unsigned char sequence_id[4];
	//消息体
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

//状态报告数据报
struct deliver_status_report_packet
{
	unsigned char msg_id[8];
	unsigned char stat[7];
	unsigned char submit_time[10];
	unsigned char done_time[10];
	unsigned char dest_terminal_id[21];
	unsigned char smsc_sequence[4];
};

//下发短信响应数据包
struct cmpp_deliver_resp_packet
{
	//消息头(12byte)
	unsigned char total_length[4];
	unsigned char command_id[4];
	unsigned char sequence_id[4];
	//消息体
	unsigned char msg_id[8];
	unsigned char result[1];
};

//激活测试数据包
struct cmpp_active_test_packet
{
	//消息头(12byte)
	unsigned char total_length[4];
	unsigned char command_id[4];
	unsigned char sequence_id[4];
};

//激活测试响应数据包
struct cmpp_active_test_resp_packet
{
	//消息头(12byte)
	unsigned char total_length[4];
	unsigned char command_id[4];
	unsigned char sequence_id[4];
	//消息体
	unsigned char reserved[1];
};

//终止连接数据包
struct cmpp_terminate_packet
{
	//消息头(12byte)
	unsigned char total_length[4];
	unsigned char command_id[4];
	unsigned char sequence_id[4];
};

//终止连接响应数据包
struct cmpp_terminate_resp_packet
{
	//消息头(12byte)
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


/*********************函数声明**************************/
//关闭postgresql
//static void exit_nicely(PGconn *conn);
//登录子模块
int cmpp_login_module(int sockfd);
//提交模块
void * cmpp_submit_module(void *data);
//激活测试模块
void * cmpp_active_test_module(void *data);
//激活测试响应模块
int cmpp_active_test_resp_module(int sockfd,unsigned char *active_test_buf);
//下发短息响应模块
/*
ISMG发送过来的短信消息，分为两种：
1.短信消息
	把接受到的数据保存到ReceiveMessage表中。
	向ISMG发送应答报文
2.状态报告
	把接受到的状态报告保存到StatusReport表中。
	向ISMG发送应答报文
*/
void cmpp_deliver_resp_module(int sockfd,unsigned char *deliver_buf,int nbytes);
//终止连接模块
int cmpp_terminate_module(int sockfd);
//终止连接应答模块
int cmpp_terminate_resp_module(int sockfd,unsigned char* terminate_buf);

#endif
