/**
 *
 *@file SMSGatewayService.cpp
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-01
 *
 */

#include <SMSGatewayService.h>
#include <Log.h>
#include <PreDef.h>
#include <DAO.h>
#include <Util.h>

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>//for errno

#include <sstream>

using namespace std;
using namespace predef;

/**
 * @brief receive message.
 * @param[in] void
 * @return int
 */
int SMSGatewayService::ReceiveMessage(ByteStream& bs)
{
	  LOG_DEBUG("%s","recevie message...");
	  
	  nbytes = 0; 
	  
	  fd_set rdfds; 
    
    struct timeval tv;
    int ret; 
    
    FD_ZERO(&rdfds);
    FD_SET(sockfd, &rdfds); 
    
    tv.tv_sec = 0;
    tv.tv_usec = 500; 
    
    ret = select(sockfd + 1, &rdfds, NULL, NULL, &tv); 
    
    type = 0;
    
    if(ret < 0) 
    {
        LOG_DEBUG("%s","select");
    }
    else if(ret == 0)
    {
        LOG_DEBUG("%s","查询需要下发的短信"); 
        
        if(GetMessageFromDB() == -1)
        {
            //type = CMPP_ACTIVE_TEST;
        }
    }
    else 
    { 
        LOG_DEBUG("ret=%d\n", ret);
    
        if(FD_ISSET(sockfd, &rdfds)) 
        {
            /* 读取socket句柄里的数据 */
            memset(buf,0,1024);
	          
	          if((nbytes=read(sockfd,buf,1024)) == -1)
	          {
		            LOG_DEBUG("Read Error: %s\n",strerror(errno));
		            
		            return -1;
	          }
	          
	          if(nbytes <= 0)
	          {
	              return -1;
	          }

	          buf[nbytes]='\0';

            LOG_DEBUG_DATA((const char*)buf, nbytes, "%s", "receive message from ismg!");
            
            bs.Append(buf,nbytes);
            
            //解析命令
            type = getcommandid(buf,nbytes);
            
            SetMsgFormISMG(true);
        }
    }
	  
    return 0;
}
    
/**
 * @brief parse message.
 * @param[in] void
 * @return int
 */
unsigned int SMSGatewayService::ParseMessage()
{
	  LOG_DEBUG("%s","parse message...");
	  
	  char hex[9];
    
    dec_to_hex(hex, type);
    
    LOG_DEBUG("dec_type=%u, hex_type= %s",type, hex);
    
    return type;
}

/**
 * @brief get message from database.
 * @param[in] void
 * @return int
 */
int SMSGatewayService::GetMessageFromDB()
{
	  int iRet = -1;
    try
    {
    	  /**
    	  create table send_message
				(
				   send_id      varchar2(20) not null,--信息 id
				   phone        varchar2(20) not null,--电话
				   msg_level    number(1) default 9,
				   content      varchar2(1000),--内容
				   valid_time   date,--存活有效期
				   at_time      date,--定时发送时间 
				   wap_push_url varchar2(1000),--wappush地址
				   sms_type     number(1) default 0,--短信 类型
				   send_time    date,--发送 时间
				   optime       date,--添加时间
				   done         varchar2(2) --处理状态 
				);
    	  */
    	  
    	  DAO dao(true, sDBUser, sDBPwd, sDBConnStr);
    	  
        string sSql = "SELECT send_id, phone, sms_type, msg_level, content, wap_push_url, status_report, valid_time, at_time FROM send_message where done=0 order by msg_level desc";
        
        LOG_DEBUG("%s",sSql.c_str());
        
    	  ResultSet* rs = dao.Query(sSql);
        
        while(rs != NULL && rs->next())
        {
        	  string sSendId     = rs->getString(1);
            string sPhone      = rs->getString(2);
            int    iSmsType    = rs->getInt(3);
            int    iMsgLevel   = rs->getInt(4);      
            string sContent    = rs->getString(5);
            string sWapPushUrl = rs->getString(6);
            int    iStatusRpt  = rs->getInt(7);  
            
            cout<<"===========================*****************================================"<<endl;
            
            cout<<"[send_id: "<<sSendId<<", phone: "<<sPhone<<", sms_type: "<<iSmsType;
            cout<<", msg_level: "<<iMsgLevel<<", content: "<<sContent<<", wap_push_url: ";
            cout<<sWapPushUrl<<", status_report: ";
            cout<<iStatusRpt<<"]"<<endl;
            cout<<"===========================*****************================================"<<endl;
                   
            LOG_DEBUG_DATA(sContent.c_str(),sContent.length(),"content=%s", sContent.c_str());
            
            if(sContent.empty())
            {
                sContent = "";
            }        
            
            int iMaxSMSLen = 134;
            int iTotal     = 1;
            int iLastLen   = 0;
               
            int iCntLen = sContent.length();
            
            if(iSmsType == 0)
            {
                iMaxSMSLen = 130;
            }
            
            if(iCntLen > 140)
            {
		            iTotal   = (iCntLen + iMaxSMSLen - 1) / iMaxSMSLen;
				        iLastLen = iCntLen % iMaxSMSLen;
		        }
            
            SubmitService mSubmitService;
            ByteStream bs;
            mSubmitService.SetSocket(sockfd); 
            
            unsigned int iUdhi = 0;
            
            if(iTotal > 1)
            {
            	  if(iSmsType == 1 || iSmsType == 3)
            	  {
                    iUdhi = 1;
                }
                
                for(int i=1; i <= iTotal; i++)
		            { 
		            	  string sCnt = "";
		            	  
		            	  if(iLastLen > 0 && i == iTotal)
		            	  {
		            	      sCnt = sContent.substr((i-1)*iMaxSMSLen,iLastLen);
		            	  }
		            	  else
		            	  {
		            	      sCnt = sContent.substr((i-1)*iMaxSMSLen,iMaxSMSLen);
		            	  }
		            	 
		            	  //common sms
		            	  if(iSmsType == 0)
		            	  { 
		            	  	   stringstream ss;
                         ss<<"[";
                         ss<<i;
                         ss<<"/";
                         ss<<iTotal;
                         ss<<"]";
                         
		            	       sCnt += ss.str();
		            	  }
		            	  
		            	  LOG_DEBUG("sCnt = %s", sCnt.c_str());
		            	  
		                mSubmitService.InitParam(iSmsType, iTotal, i, iStatusRpt, iMsgLevel, 1, sPhone, sCnt.length(), sCnt, 0, iUdhi, 15);
			              mSubmitService.DoMessage(bs);
			          }
            }
            else
            {
                mSubmitService.InitParam(iSmsType, iTotal, 1, iStatusRpt, iMsgLevel, 1, sPhone, sContent.length(), sContent, 0, iUdhi, 15);
	              mSubmitService.DoMessage(bs);
            }
            
	          sSql = "UPDATE send_message SET done='1', send_time=sysdate WHERE send_id='"+ sSendId + "'";
	          
	          dao.Update(sSql);
	          
            iRet = 0;
        }
        
        dao.CloseResultSet(rs);
        //dao.Close();
    }
    catch(SQLException ex)
    {
        LOG_ERROR("[error_code: %d, error_message: %s]", ex.getErrorCode(), ex.getMessage().c_str());
    }
    
    return iRet;
}
