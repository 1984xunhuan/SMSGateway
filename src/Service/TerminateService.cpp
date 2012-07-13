/**
 *
 *@file TerminateService.cpp
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-01
 *
 */

#include <TerminateService.h>

#include <errno.h>//for errno

/**
 * @brief init message header.
 * @param[in] void
 * @return int
 */
int TerminateService::InitMessageHeader()
{
    LOG_DEBUG("%s","Init message header!");
    
    total_length = 12;
    command_id   = CMPP_TERMINATE;
    
    return 0;
}

/**
 * @brief deal with business.
 * @param[in] ByteStream& mByteStream
 * @return int
 */
int TerminateService::DoBusiness(ByteStream& mByteStream)
{
    LOG_DEBUG_DATA((const char*)(bs[0]), bs.GetSize(), "%s", "TerminateService::DoBusiness: send message to ismg!");
	  
	  if(write(sockfd, bs[0], bs.GetSize()) == -1)
	  {
		    LOG_DEBUG("Write Error: %s\n",strerror(errno));
	  }
	  
    return 0;
}
