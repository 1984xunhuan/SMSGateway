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
		unsigned int CMPP_CONNECT                   = 0x00000001;	//  请求连接
		unsigned int CMPP_CONNECT_RESP              = 0x80000001;	//  请求连接应答
		unsigned int CMPP_TERMINATE	                = 0x00000002;	//	终止连接
		unsigned int CMPP_TERMINATE_RESP            = 0x80000002;	//	终止连接应答
		unsigned int CMPP_SUBMIT                    = 0x00000004;	//	提交短信
		unsigned int CMPP_SUBMIT_RESP               = 0x80000004;	//	提交短信应答
		unsigned int CMPP_DELIVER                   = 0x00000005;	//	短信下发
		unsigned int CMPP_DELIVER_RESP              = 0x80000005;	//	下发短信应答
		unsigned int CMPP_QUERY	                    = 0x00000006;	//	发送短信状态查询
		unsigned int CMPP_QUERY_RESP	              = 0x80000006;	//	发送短信状态查询应答
		unsigned int CMPP_CANCEL		                = 0x00000007;	//	删除短信
		unsigned int CMPP_CANCEL_RESP	              = 0x80000007;	//	删除短信应答
		unsigned int CMPP_ACTIVE_TEST	              = 0x00000008;	//	激活测试
		unsigned int CMPP_ACTIVE_TEST_RESP          = 0x80000008;	//	激活测试应答
		unsigned int CMPP_FWD	                      = 0x00000009;	//	消息前转
		unsigned int CMPP_FWD_RESP	                = 0x80000009;	//	消息前转应答
		unsigned int CMPP_MT_ROUTE	                = 0x00000010;	//	MT路由请求
		unsigned int CMPP_MT_ROUTE_RESP	            = 0x80000010;	//	MT路由请求应答
		unsigned int CMPP_MO_ROUTE	                = 0x00000011;	//	MO路由请求
		unsigned int CMPP_MO_ROUTE_RESP	            = 0x80000011;	//	MO路由请求应答
		unsigned int CMPP_GET_ROUTE	                = 0x00000012;	//	获取路由请求
		unsigned int CMPP_GET_ROUTE_RESP 	          = 0x80000012;	//	获取路由请求应答
		unsigned int CMPP_MT_ROUTE_UPDATE	          = 0x00000013;	//	MT路由更新
		unsigned int CMPP_MT_ROUTE_UPDATE_RESP      = 0x80000013;	//	MT路由更新应答
		unsigned int CMPP_MO_ROUTE_UPDATE	          = 0x00000014;	//	MO路由更新
		unsigned int CMPP_MO_ROUTE_UPDATE_RESP	    = 0x80000014;	//	MO路由更新应答
		unsigned int CMPP_PUSH_MT_ROUTE_UPDATE	    = 0x00000015;	//	MT路由更新
		unsigned int CMPP_PUSH_MT_ROUTE_UPDATE_RESP	= 0x80000015;	//	MT路由更新应答
		unsigned int CMPP_PUSH_MO_ROUTE_UPDATE	    = 0x00000016;	//	MO路由更新
		unsigned int CMPP_PUSH_MO_ROUTE_UPDATE_RESP =	0x80000016;	//	MO路由更新应答
		
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

