/**
 *
 *@file ActiveTestRespService.cpp
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-01
 *
 */

#include <ActiveTestRespService.h>

/**
 * @brief Parse message body.
 * @param[in] void
 * @return int
 */
int ActiveTestRespService::ParseMsgBody()
{
    LOG_DEBUG("%s","ActiveTestRespService: parse message body!");     
		
		unsigned char byte_buf[2];
    
    memset(byte_buf, 0, 2); 
    bs.GetBytes(12, 1, byte_buf);
	  reserved = (unsigned int)(byte_buf[0]);
	  
	  LOG_DEBUG("[reserved: %u]", reserved);

    return 0;
}
