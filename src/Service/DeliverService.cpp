/**
 *
 *@file DeliverService.cpp
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-06
 *
 */

#include <DeliverService.h>

#include <sstream>
#include <ReceiveMessageDAO.h>
#include <StatusReportDAO.h>

#include <DeliverRespService.h>

using namespace std;

/**
 * @brief parse message body.
 * @param[in] void
 * @return int
 */
int DeliverService::ParseMsgBody()
{
    LOG_DEBUG("%s","parse message body!");     
		
		unsigned char byte_buf[22];
    
    memset(byte_buf, 0, 22); 
    bs.GetBytes(12, 8, byte_buf);
    msg_id = byte8_to_long(byte_buf);
    
    memset(byte_buf, 0, 22); 
    bs.GetBytes(20, 21, byte_buf);
	  dest_id = string((const char*)byte_buf);
	  
	  memset(byte_buf, 0, 22); 
    bs.GetBytes(41, 10, byte_buf);
	  service_id = string((const char*)byte_buf);
	  
	  memset(byte_buf, 0, 22); 
    bs.GetBytes(51, 1, byte_buf);
	  tp_pid = (unsigned int)byte_buf[0];
	  
	  memset(byte_buf, 0, 22); 
    bs.GetBytes(52, 1, byte_buf);
	  tp_udhi = (unsigned int)byte_buf[0];
	  
	  memset(byte_buf, 0, 22); 
    bs.GetBytes(53, 1, byte_buf);
	  msg_fmt = (unsigned int)byte_buf[0];
	  
	  memset(byte_buf, 0, 22); 
    bs.GetBytes(54, 21, byte_buf);
	  src_terminal_id = string((const char*)byte_buf);
	  
	  memset(byte_buf, 0, 22); 
    bs.GetBytes(75, 1, byte_buf);
	  registered_delivery = (unsigned int)byte_buf[0];
	  
	  memset(byte_buf, 0, 22); 
    bs.GetBytes(76, 1, byte_buf);
	  msg_length = (unsigned int)byte_buf[0];
	  
	  
	  LOG_DEBUG("[msg_id: %llu, registered_delivery: %d, msg_length: %d, src_terminal_id: %s, dest_id: %s, service_id: %s]", msg_id, registered_delivery, msg_length, src_terminal_id.c_str(), dest_id.c_str(), service_id.c_str()); 
	  
	  if(registered_delivery == 0)
	  {
			  unsigned char* pBuf = new unsigned char[msg_length + 1];
			  
			  if(pBuf != NULL)
			  {
			      memset(pBuf, 0, msg_length + 1); 
		        bs.GetBytes(77, msg_length, pBuf);
			      msg_content = string((const char*)pBuf);
			      
			      LOG_DEBUG("[msg_content: %s]", msg_content.c_str());
			      
			      delete pBuf;
			      pBuf = NULL;
			  }
			  else
			  {
			      LOG_ERROR("%s","new buffer error!");
			  }
	  }
	  else if(registered_delivery == 1)
	  {
	       memset(byte_buf, 0, 22); 
         bs.GetBytes(77, 8, byte_buf);
	       mStatusReport.msg_id = byte8_to_long(byte_buf);
	       
	       memset(byte_buf, 0, 22); 
         bs.GetBytes(85, 7, byte_buf);
         mStatusReport.stat = string((const char*)byte_buf);
         
         memset(byte_buf, 0, 22); 
         bs.GetBytes(92, 10, byte_buf);
         mStatusReport.submit_time = string((const char*)byte_buf);
         
         memset(byte_buf, 0, 22);
         bs.GetBytes(102, 10, byte_buf);
         mStatusReport.done_time = string((const char*)byte_buf);
         
         memset(byte_buf, 0, 22); 
         bs.GetBytes(112, 21, byte_buf);
         mStatusReport.dest_terminal_id = string((const char*)byte_buf);
         
         memset(byte_buf, 0, 22); 
         bs.GetBytes(133, 4, byte_buf);
         mStatusReport.smsc_sequence = byte4_to_int(byte_buf);
         
         LOG_DEBUG("[msg_id: %llu, stat: %s, submit_time: %s, done_time: %s, dest_terminal_id: %s, smsc_sequence: %d]", mStatusReport.msg_id, mStatusReport.stat.c_str(),  mStatusReport.submit_time.c_str(), mStatusReport.done_time.c_str(), mStatusReport.dest_terminal_id.c_str(), mStatusReport.smsc_sequence); 
	  }
	  else
	  {
			   LOG_ERROR("%s","registered delivery error!");
	  }
	  
	  memset(byte_buf, 0, 22); 
    bs.GetBytes(77 + msg_length, 8, byte_buf);
	  reserved = string((const char*)byte_buf);
	  
	  //LOG_DEBUG("[msg_id: %s, result: %u]", msg_id.c_str(), result);

    return 0;
}

/**
 * @brief deal with business.
 * @param[in] void
 * @return int
 */
int DeliverService::DoBusiness()
{
    LOG_DEBUG("%s", "do business...");
    
    LOG_DEBUG("%s", "storage data to database.");
    
    result = 0;
    
    try
    {  
    	  DAO dao(true, sDBUser, sDBPwd, sDBConnStr);
    	  
    	  if(registered_delivery == 0)
    	  {
    	  	  ReceiveMessage    mRcvMsg;
    	      
    	      stringstream ss;
    	      ss << msg_id;
    	      
    	      mRcvMsg.sMsgId   = ss.str();
    	      mRcvMsg.sPhone   = src_terminal_id;
    	      mRcvMsg.sContent = msg_content;
    	      mRcvMsg.sRcvTime = "sysdate";
    	      mRcvMsg.sDone    = "0";
    	      
    	      ReceiveMessageDAO mRcvMsgDAO;
    	      
    	      mRcvMsgDAO.SetEntity(mRcvMsg);
    	      
    	      mRcvMsgDAO.Save(&dao);
    	  }
    	  else if(registered_delivery == 1)
    	  {
    	      StatusReport    mStatusRpt;
    	      
    	      stringstream ss;
    	      ss << mStatusReport.msg_id;
    	      
    	      mStatusRpt.sMsgId          = ss.str();
    	      mStatusRpt.sStat           = mStatusReport.stat;
    	      mStatusRpt.sSubmitTime     = mStatusReport.submit_time;
    	      mStatusRpt.sDoneTime       = mStatusReport.done_time;
    	      mStatusRpt.sDestTerminalId = mStatusReport.dest_terminal_id;
    	      
    	      ss.clear(); 
    	      ss.str("");
    	      ss << mStatusReport.smsc_sequence;
    	  
    	      mStatusRpt.sSmscSequence = ss.str();
    	      mStatusRpt.sOptime       = "sysdate";
    	      
    	      StatusReportDAO mStatusRptDAO;
    	      
    	      mStatusRptDAO.SetEntity(mStatusRpt);
    	      
    	      mStatusRptDAO.Save(&dao);
    	  }
    }
    catch(SQLException ex)
    { 
        LOG_ERROR("[error_code: %d, error_message: %s]", ex.getErrorCode(), ex.getMessage().c_str());
        
        if(ex.getErrorCode() == 1)
        {
            result = 3;
        }
    }
    
    LOG_DEBUG("%s", "Response CMMP_Deliver_REP");
    
    ByteStream bs;
    DeliverRespService mDeliverRespService;
    
    mDeliverRespService.SetSocket(sockfd); 	  
	  mDeliverRespService.SetMsgFormISMG(false);	  
	  mDeliverRespService.SetMsgId(msg_id);
	  mDeliverRespService.SetSequenceId(sequence_id);
	  mDeliverRespService.SetResult(result);
    
    mDeliverRespService.DoMessage(bs);
    
    return 0;
}

