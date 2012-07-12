/**
 *
 *@file DeliverRespService.cpp
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-06
 *
 */

#include <DeliverRespService.h>

#include <errno.h>//for errno

/**
 * @brief Init Message Header.
 * @param[in] void
 * @return int
 */
int DeliverRespService::InitMessageHeader()
{
	  LOG_DEBUG("%s","Init message header!");
    
    total_length = 21;
    command_id   = CMPP_DELIVER_RESP;
    
    return 0;
}

/**
 * @brief create message body.
 * @param[in] void
 * @return int
 */
int DeliverRespService::CreateMsgBody()
{
	  unsigned char byte_buf[9];
    
    memset(byte_buf, 0, 9); 
	  int_to_8byte(msg_id,byte_buf);
	  bs.Append(byte_buf, 8);
	  
	  bs << (char)result;
	  
    return 0;
}

/**
 * @brief deal with business.
 * @param[in] ByteStream& mByteStream
 * @return int
 */
int DeliverRespService::DoBusiness(ByteStream& mByteStream)
{
	  LOG_DEBUG("%s","DoBusiness");
	   
	  LOG_DEBUG_DATA((const char*)(bs[0]), bs.GetSize(), "%s", "delive resp message!");
	  
	  if(write(sockfd, bs[0], bs.GetSize()) == -1)
	  {
		    LOG_DEBUG("Write Error: %s\n",strerror(errno));
	  }
	  
    return 0;
}

