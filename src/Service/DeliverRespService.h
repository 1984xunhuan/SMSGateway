/**
 *
 *@file DeliverRespService.h
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-06
 *
 */
 
#ifndef DELIVERRESPSERVICE_H_
#define DELIVERRESPSERVICE_H_

#include <IfRequestService.h>

class DeliverRespService
    : public IfRequestService
{
public:
		/**
     * @brief default constructor
     */
    DeliverRespService() : IfRequestService()
    {
        
    }
    
    /**
     * @brief desconstructor
     */
    virtual ~DeliverRespService()
    {
        	
    }
    
    /**
	   * @brief create object.
	   * @param[in] void
	   * @return Point of IfMessageService
	   */
    static IfMessageService* CreateObject()
    {
        return new DeliverRespService();
    }
    
    /**
	   * @brief Init Message Header.
	   * @param[in] void
	   * @return int
	   */
    virtual int InitMessageHeader();
    
    /**
	   * @brief create message body.
	   * @param[in] void
	   * @return int
	   */
    virtual int CreateMsgBody();
    
    /**
	   * @brief deal with business.
	   * @param[in] ByteStream& mByteStream
	   * @return int
	   */
    virtual int DoBusiness(ByteStream& mByteStream);
    
    /**
	   * @brief set message id.
	   * @param[in] unsigned long long msg_id.
	   * @return int
	   */
    void SetMsgId(unsigned long long msg_id)
    {
        this->msg_id = msg_id;
    }
    
    /**
	   * @brief set result.
	   * @param[in] unsigned int result.
	   * @return int
	   */
    void SetResult(unsigned int result)
    {
        this->result = result;
    }
private:
    unsigned long long msg_id;
    unsigned int       result;
};

#endif
