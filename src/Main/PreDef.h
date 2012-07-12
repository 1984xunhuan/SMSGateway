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
		extern unsigned int CMPP_CONNECT;                   // 请求连接
		extern unsigned int CMPP_CONNECT_RESP;              // 请求连接应答
		extern unsigned int CMPP_TERMINATE;	                //	终止连接
		extern unsigned int CMPP_TERMINATE_RESP;            //	终止连接应答
		extern unsigned int CMPP_SUBMIT;                    //	提交短信
		extern unsigned int CMPP_SUBMIT_RESP;               //	提交短信应答
		extern unsigned int CMPP_DELIVER;                   //	短信下发
		extern unsigned int CMPP_DELIVER_RESP;              //	下发短信应答
		extern unsigned int CMPP_QUERY;	                    //	发送短信状态查询
		extern unsigned int CMPP_QUERY_RESP;	              //	发送短信状态查询应答
		extern unsigned int CMPP_CANCEL;		                //	删除短信
		extern unsigned int CMPP_CANCEL_RESP;	              //	删除短信应答
		extern unsigned int CMPP_ACTIVE_TEST;	              //	激活测试
		extern unsigned int CMPP_ACTIVE_TEST_RESP;          //	激活测试应答
		extern unsigned int CMPP_FWD;	                      //	消息前转
		extern unsigned int CMPP_FWD_RESP;	                //	消息前转应答
		extern unsigned int CMPP_MT_ROUTE;	                //	MT路由请求
		extern unsigned int CMPP_MT_ROUTE_RESP;	            //	MT路由请求应答
		extern unsigned int CMPP_MO_ROUTE;	                //	MO路由请求
		extern unsigned int CMPP_MO_ROUTE_RESP;	            //	MO路由请求应答
		extern unsigned int CMPP_GET_ROUTE;	                //	获取路由请求
		extern unsigned int CMPP_GET_ROUTE_RESP; 	          //	获取路由请求应答
		extern unsigned int CMPP_MT_ROUTE_UPDATE;	          //	MT路由更新
		extern unsigned int CMPP_MT_ROUTE_UPDATE_RESP;      //	MT路由更新应答
		extern unsigned int CMPP_MO_ROUTE_UPDATE;	          //	MO路由更新
		extern unsigned int CMPP_MO_ROUTE_UPDATE_RESP;	    //	MO路由更新应答
		extern unsigned int CMPP_PUSH_MT_ROUTE_UPDATE;	    //	MT路由更新
		extern unsigned int CMPP_PUSH_MT_ROUTE_UPDATE_RESP;	//	MT路由更新应答
		extern unsigned int CMPP_PUSH_MO_ROUTE_UPDATE;	    //	MO路由更新
		extern unsigned int CMPP_PUSH_MO_ROUTE_UPDATE_RESP; //	MO路由更新应答
		
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
