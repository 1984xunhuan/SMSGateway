/**
 *
 *@file ConnectService.cpp
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-01
 *
 */

#include <ConnectService.h>

#include <PreDef.h>

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>//for errno
#include <openssl/md5.h>//for md5

/**
 * @brief deal with business.
 * @param[in] ByteStream& mByteStream
 * @return int
 */
int ConnectService::DoBusiness(ByteStream& mByteStream)
{
	  LOG_DEBUG("%s","DoBusiness");
	   
	  LOG_DEBUG_DATA((const char*)(bs[0]), bs.GetSize(), "%s", "connect message!");
	  
	  if(write(sockfd, bs[0], bs.GetSize()) == -1)
	  {
		    LOG_DEBUG("Write Error: %s\n",strerror(errno));
		    
		    return -1;
	  }
	  
	  unsigned char buf[1024];
	  int nbytes = 0;
	  
	  memset(buf,0,1024);
	          
	  if((nbytes=read(sockfd,buf,1024)) == -1)
	  {
		    LOG_DEBUG("Read Error: %s\n",strerror(errno));
	  }
	  
	  if(nbytes <= 0)
	  {
	      return -1;
	  }

	  buf[nbytes]='\0';

    LOG_DEBUG_DATA((const char*)buf, nbytes, "%s", "receive message from ismg!");
            
    mByteStream.Append(buf,nbytes);
	  
    return 0;
}    


/**
 * @brief init message header.
 * @param[in] void
 * @return int
 */
int ConnectService::InitMessageHeader()
{
    LOG_DEBUG("%s","Init message header!");
    
    total_length = 39;
    command_id   = CMPP_CONNECT;
    
    return 0;
}

/**
 * @brief create message body.
 * @param[in] void
 * @return int
 */
int ConnectService::CreateMsgBody()
{
    LOG_DEBUG("%s","create message body!");
    
    int ispid_len = strlen(sSpId.c_str());
		int isppwd_len = strlen(sSpPwd.c_str());
		
		LOG_DEBUG("[ spid: %s, len: %d ], [ password: %s, len: %d ]", sSpId.c_str(), ispid_len, sSpPwd.c_str(), isppwd_len);

		bs.Append((unsigned char*)sSpId.c_str(),6);
		
		unsigned char timestamp[10];
		memset(timestamp,'\0',10);
		getlocaltime(timestamp);
		
		unsigned char md5source[100];
		
		int md5_len = ispid_len + 9 + isppwd_len + 10;
		
		memset(md5source,0,100);		
		
		memcpy(md5source,sSpId.c_str(),ispid_len);
		
		memcpy(md5source + ispid_len + 9, sSpPwd.c_str(), isppwd_len);
		
		memcpy(md5source + ispid_len + isppwd_len + 9, timestamp, 10);
		
		unsigned char dest[40];
		
		memset(dest,0x00,40);
		MD5_CTX ctx;
		MD5_Init(&ctx);
		MD5_Update(&ctx,md5source,md5_len);
		MD5_Final(dest,&ctx);
		
		bs.Append(dest,16);
		bs<<(char)(atoi((const char*)sVersion.c_str()));
		
		unsigned char byte_buf[5];
	  memset(byte_buf, 0, 5);
	  
		int_to_4byte(atoi((const char*)timestamp), byte_buf);
		bs.Append(byte_buf, 4);
		
    return 0;
}

