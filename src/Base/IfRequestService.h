/**
 *
 *@file IfRequestService.h
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-01
 *
 */

#ifndef IFREQUESTSERVICE_H_ 
#define IFREQUESTSERVICE_H_

#include <IfMessageService.h>

class IfRequestService
    : public IfMessageService
{
public:
	  /**
     * @brief default constructor
     */
    IfRequestService() : IfMessageService()
    {
        
    }
    
    /**
     * @brief desconstructor
     */
    virtual ~IfRequestService()
    {
        
    }
		    
		/**
		 * @brief Package.
		 * @param[in] void
		 * @return int
		 */
		virtual int Package()
		{
		    LOG_DEBUG("%s","Package");
		    
		    CreateMsgHeader();
		    
		    CreateMsgBody();
		
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
			  
			  if(!IsMsgFormISMG())
			  {
			      Package();
			  }
			  else 
			  {
			  	  bs << mByteStream;
			  	  
			      Unpackage();
			  }
			      
		    return DoBusiness(mByteStream);
		}    

    
    /**
	   * @brief create message head.
	   * @param[in] void
	   * @return int
	   */
    virtual int CreateMsgHeader()
    {
    	  //
    	  InitMessageHeader();
    	  //
    	  if(!IsMsgFormISMG())
			  {
            sequence_id  = getsequenceid();
        }
    
        unsigned char byte_buf[4];
    
	      int_to_4byte(total_length,byte_buf);
        bs.Append(byte_buf,4);
    
        int_to_4byte(command_id,byte_buf);
        bs.Append(byte_buf,4);
    
        int_to_4byte(sequence_id,byte_buf);
        bs.Append(byte_buf,4);
        
        return 0;
    }
    
    /**
	   * @brief create message body.
	   * @param[in] void
	   * @return int
	   */
    virtual int CreateMsgBody()
    {
        return 0;
    }
    
    /**
	   * @brief Init Message Header.
	   * @param[in] void
	   * @return int
	   */
    virtual int InitMessageHeader() = 0;
    
    /**
	   * @brief deal with business.
	   * @param[in] ByteStream& mByteStream
	   * @return int
	   */
    virtual int DoBusiness(ByteStream& mByteStream)
    {
        return 0;
    }
    
};

#endif
