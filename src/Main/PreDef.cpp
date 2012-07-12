/**
 *
 *@file PreDef.cpp
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-02
 *
 */

#include "PreDef.h"

namespace predef
{
		unsigned int CMPP_CONNECT                   = 0x00000001;	//  ��������
		unsigned int CMPP_CONNECT_RESP              = 0x80000001;	//  ��������Ӧ��
		unsigned int CMPP_TERMINATE	                = 0x00000002;	//	��ֹ����
		unsigned int CMPP_TERMINATE_RESP            = 0x80000002;	//	��ֹ����Ӧ��
		unsigned int CMPP_SUBMIT                    = 0x00000004;	//	�ύ����
		unsigned int CMPP_SUBMIT_RESP               = 0x80000004;	//	�ύ����Ӧ��
		unsigned int CMPP_DELIVER                   = 0x00000005;	//	�����·�
		unsigned int CMPP_DELIVER_RESP              = 0x80000005;	//	�·�����Ӧ��
		unsigned int CMPP_QUERY	                    = 0x00000006;	//	���Ͷ���״̬��ѯ
		unsigned int CMPP_QUERY_RESP	              = 0x80000006;	//	���Ͷ���״̬��ѯӦ��
		unsigned int CMPP_CANCEL		                = 0x00000007;	//	ɾ������
		unsigned int CMPP_CANCEL_RESP	              = 0x80000007;	//	ɾ������Ӧ��
		unsigned int CMPP_ACTIVE_TEST	              = 0x00000008;	//	�������
		unsigned int CMPP_ACTIVE_TEST_RESP          = 0x80000008;	//	�������Ӧ��
		unsigned int CMPP_FWD	                      = 0x00000009;	//	��Ϣǰת
		unsigned int CMPP_FWD_RESP	                = 0x80000009;	//	��ϢǰתӦ��
		unsigned int CMPP_MT_ROUTE	                = 0x00000010;	//	MT·������
		unsigned int CMPP_MT_ROUTE_RESP	            = 0x80000010;	//	MT·������Ӧ��
		unsigned int CMPP_MO_ROUTE	                = 0x00000011;	//	MO·������
		unsigned int CMPP_MO_ROUTE_RESP	            = 0x80000011;	//	MO·������Ӧ��
		unsigned int CMPP_GET_ROUTE	                = 0x00000012;	//	��ȡ·������
		unsigned int CMPP_GET_ROUTE_RESP 	          = 0x80000012;	//	��ȡ·������Ӧ��
		unsigned int CMPP_MT_ROUTE_UPDATE	          = 0x00000013;	//	MT·�ɸ���
		unsigned int CMPP_MT_ROUTE_UPDATE_RESP      = 0x80000013;	//	MT·�ɸ���Ӧ��
		unsigned int CMPP_MO_ROUTE_UPDATE	          = 0x00000014;	//	MO·�ɸ���
		unsigned int CMPP_MO_ROUTE_UPDATE_RESP	    = 0x80000014;	//	MO·�ɸ���Ӧ��
		unsigned int CMPP_PUSH_MT_ROUTE_UPDATE	    = 0x00000015;	//	MT·�ɸ���
		unsigned int CMPP_PUSH_MT_ROUTE_UPDATE_RESP	= 0x80000015;	//	MT·�ɸ���Ӧ��
		unsigned int CMPP_PUSH_MO_ROUTE_UPDATE	    = 0x00000016;	//	MO·�ɸ���
		unsigned int CMPP_PUSH_MO_ROUTE_UPDATE_RESP =	0x80000016;	//	MO·�ɸ���Ӧ��
		
		string sIPAddr      = "";
		string sPort        = "";
		string sSpId        = "";
    string sSpPwd       = "";
    string sSpServiceId = "";
    string sSpConnNo    = "";
    string sVersion     = "";
    
    int    iMaxLoginCount = 1;
    
    string sDBUser      = "";
    string sDBPwd       = "";
    string sDBConnStr   = "";
};

