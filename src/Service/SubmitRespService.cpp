/**
 *
 *@file SubmitRespService.cpp
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-01
 *
 */

#include <SubmitRespService.h>

/**
 * @brief Parse message body.
 * @param[in] void
 * @return int
 */
int SubmitRespService::ParseMsgBody()
{
    LOG_DEBUG("%s","parse message body!");     
		
		unsigned char byte_buf[9];
    
    memset(byte_buf, 0, 9); 
    bs.GetBytes(12, 8, byte_buf);
    msg_id = string((const char*)byte_buf);
    
    memset(byte_buf, 0, 9); 
    bs.GetBytes(20, 1, byte_buf);
	  result = (unsigned int)(byte_buf[0]);
	  
	  LOG_DEBUG("[msg_id: %s, result: %u]", msg_id.c_str(), result);

    return 0;
}
