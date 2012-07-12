/**
 *
 *@file PreDef.hpp
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-02
 *
 */

#ifndef PREDEF_H_
#define PREDEF_H_

#include <iostream>

using namespace std;

namespace predef
{
		extern unsigned int CMPP_CONNECT;                   // ��������
		extern unsigned int CMPP_CONNECT_RESP;              // ��������Ӧ��
		extern unsigned int CMPP_TERMINATE;	                //	��ֹ����
		extern unsigned int CMPP_TERMINATE_RESP;            //	��ֹ����Ӧ��
		extern unsigned int CMPP_SUBMIT;                    //	�ύ����
		extern unsigned int CMPP_SUBMIT_RESP;               //	�ύ����Ӧ��
		extern unsigned int CMPP_DELIVER;                   //	�����·�
		extern unsigned int CMPP_DELIVER_RESP;              //	�·�����Ӧ��
		extern unsigned int CMPP_QUERY;	                    //	���Ͷ���״̬��ѯ
		extern unsigned int CMPP_QUERY_RESP;	              //	���Ͷ���״̬��ѯӦ��
		extern unsigned int CMPP_CANCEL;		                //	ɾ������
		extern unsigned int CMPP_CANCEL_RESP;	              //	ɾ������Ӧ��
		extern unsigned int CMPP_ACTIVE_TEST;	              //	�������
		extern unsigned int CMPP_ACTIVE_TEST_RESP;          //	�������Ӧ��
		extern unsigned int CMPP_FWD;	                      //	��Ϣǰת
		extern unsigned int CMPP_FWD_RESP;	                //	��ϢǰתӦ��
		extern unsigned int CMPP_MT_ROUTE;	                //	MT·������
		extern unsigned int CMPP_MT_ROUTE_RESP;	            //	MT·������Ӧ��
		extern unsigned int CMPP_MO_ROUTE;	                //	MO·������
		extern unsigned int CMPP_MO_ROUTE_RESP;	            //	MO·������Ӧ��
		extern unsigned int CMPP_GET_ROUTE;	                //	��ȡ·������
		extern unsigned int CMPP_GET_ROUTE_RESP; 	          //	��ȡ·������Ӧ��
		extern unsigned int CMPP_MT_ROUTE_UPDATE;	          //	MT·�ɸ���
		extern unsigned int CMPP_MT_ROUTE_UPDATE_RESP;      //	MT·�ɸ���Ӧ��
		extern unsigned int CMPP_MO_ROUTE_UPDATE;	          //	MO·�ɸ���
		extern unsigned int CMPP_MO_ROUTE_UPDATE_RESP;	    //	MO·�ɸ���Ӧ��
		extern unsigned int CMPP_PUSH_MT_ROUTE_UPDATE;	    //	MT·�ɸ���
		extern unsigned int CMPP_PUSH_MT_ROUTE_UPDATE_RESP;	//	MT·�ɸ���Ӧ��
		extern unsigned int CMPP_PUSH_MO_ROUTE_UPDATE;	    //	MO·�ɸ���
		extern unsigned int CMPP_PUSH_MO_ROUTE_UPDATE_RESP; //	MO·�ɸ���Ӧ��
		
		extern string sIPAddr;
		extern string sPort;
    extern string sSpId;
    extern string sSpPwd;
    extern string sSpServiceId;
    extern string sSpConnNo;
    extern string sVersion;
    
    extern int    iMaxLoginCount ;
    
    extern string sDBUser;
    extern string sDBPwd;
    extern string sDBConnStr;
};

#endif
