/**
 *
 *@file IfResponseService.h
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-01
 *
 */

#ifndef IFRESPONSESERVICE_H_ 
#define IFRESPONSESERVICE_H_

#include <IfMessageService.h>

class IfResponseService
    : public IfMessageService
{
public:
	  /**
     * @brief default constructor
     */
    IfResponseService() : IfMessageService()
    {
        
    }
    
    /**
     * @brief desconstructor
     */
    virtual ~IfResponseService()
    {
        
    }
    
    /**
		 * @brief package.
		 * @param[in] void
		 * @return int
		 */  
    virtual int Package()
		{
		    LOG_DEBUG("%s","Package");
		    
		    return 0;
		}
		
		/**
		 * @brief Unpackage.
		 * @param[in] void
		 * @return int
		 */  
		virtual int Unpackage()
		{
			  LOG_DEBUG("%s","Unpackage");
			  
			  ParseMsgHeader();
		    
		    ParseMsgBody();
		    
		    return 0;
		}
		
		/**
		 * @brief DoMessage.
		 * @param[in] ByteStream& mByteStream
		 * @return int
		 */ 
		virtual int DoMessage(ByteStream& mByteStream)
		{
			  LOG_DEBUG("%s","DoMessage");
			  
			  bs << mByteStream;
			  
			  Unpackage();
			  
			  return DoBusiness();
		} 
    
    /**
	   * @brief parse message head.
	   * @param[in] void
	   * @return int
	   */
    virtual int ParseMsgHeader()
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
    
    /**
	   * @brief parse message body.
	   * @param[in] void
	   * @return int
	   */
    virtual int ParseMsgBody()
    {
        return 0;
    }
    
    /**
	   * @brief deal with business.
	   * @param[in] void
	   * @return int
	   */
    virtual int DoBusiness()
    {
        return 0;
    }
};

#endif
