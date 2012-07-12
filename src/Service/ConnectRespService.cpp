/**
 *
 *@file ConnectRespService.cpp
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-01
 *
 */

#include <ConnectRespService.h>

/**
 * @brief Parse message body.
 * @param[in] void
 * @return int
 */
int ConnectRespService::ParseMsgBody()
{
    LOG_DEBUG("%s","parse message body!");     
		
		unsigned char byte_buf[17];
    
    memset(byte_buf, 0, 17); 
    bs.GetBytes(12, 1, byte_buf);
	  status = (unsigned int)(byte_buf[0]);
	  
	  memset(byte_buf, 0, 17);
    bs.GetBytes(13, 16, byte_buf);
	  authenticator_ismg = string((const char*)byte_buf);
	  
	  memset(byte_buf, 0, 17);
    bs.GetBytes(29, 1, byte_buf);
	  version = (unsigned int)(byte_buf[0]);
	  
	  LOG_DEBUG("[status: %u, authenticator_ismg: %s, version: %u]",status, authenticator_ismg.c_str(), version);

    return 0;
}

/**
 * @brief deal with business.
 * @param[in] void
 * @return int
 */
int ConnectRespService::DoBusiness()
{
	  //≤‚ ‘
	  //status = 0;
	  
    return status;
}

