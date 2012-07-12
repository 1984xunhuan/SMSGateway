/**
 *
 *@file ActiveTestService.cpp
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-01
 *
 */

#include <ActiveTestService.h>

#include <errno.h>//for errno

/**
 * @brief init message header.
 * @param[in] void
 * @return int
 */
int ActiveTestService::InitMessageHeader()
{
    LOG_DEBUG("%s","ActiveTestService: Init message header!");
    
    bs.Clear();
      
    total_length = 12;
    
		command_id = CMPP_ACTIVE_TEST;
			  
    return 0;
}

/**
 * @brief deal with business.
 * @param[in] ByteStream& mByteStream
 * @return int
 */
int ActiveTestService::DoBusiness(ByteStream& mByteStream)
{
    LOG_DEBUG_DATA((const char*)(bs[0]), bs.GetSize(), "%s", "ActiveTestService::DoBusiness: send message to ismg!");
	  
	  if(write(sockfd, bs[0], bs.GetSize()) == -1)
	  {
		    LOG_DEBUG("Write Error: %s\n",strerror(errno));
	  }
	  
    return 0;
}

int ActiveTestService::Unpackage()
{
    LOG_DEBUG("%s","Unpackage");
    
    //parse message header
    ParseMsgHeader();
		
		//response active test response package.
		CreateActiveTestRspPkg();
			  
		return 0;
}

int ActiveTestService::ParseMsgHeader()
{
    unsigned char byte_buf[4];

    memset(byte_buf, 0, 4); 

    bs.GetBytes(0, 4, byte_buf);
    total_length = byte4_to_int(byte_buf);

    bs.GetBytes(4, 4, byte_buf);
    command_id = byte4_to_int(byte_buf);

    bs.GetBytes(8, 4, byte_buf);
    sequence_id = byte4_to_int(byte_buf);

    LOG_DEBUG("[total_length: %u, command_id: %u, sequence_id: %u]",total_length, command_id, sequence_id);

    return 0;
}

int ActiveTestService::CreateActiveTestRspPkg()
{
	  unsigned char byte_buf[4];
	  
	  bs.Clear();
	  
	  //
	  total_length = 13;

	  //
    command_id = CMPP_ACTIVE_TEST_RESP;

    int_to_4byte(total_length,byte_buf);
    bs.Append(byte_buf,4);

    int_to_4byte(command_id,byte_buf);
    bs.Append(byte_buf,4);

    int_to_4byte(sequence_id,byte_buf);
    bs.Append(byte_buf,4);
    
    bs<<(char)0;
    
    return 0;
}
