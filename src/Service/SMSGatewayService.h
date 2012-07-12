/**
 *
 *@file SMSGatewayService.h
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-01
 *
 */

#ifndef SMSGATEWAYSERVICE_H_ 
#define SMSGATEWAYSERVICE_H_

#include <IfGatewayService.h>
#include <SubmitService.h>

class SMSGatewayService
    : public IfGatewayService
{
public:
	  /**
     * @brief default constructor
     */
    SMSGatewayService() : IfGatewayService()
    {
    }
    
    /**
     * @brief desconstructor
     */
    virtual ~SMSGatewayService()
    {
    }
     
    /**
	   * @brief receive message.
	   * @param[in] void
	   * @return int
	   */
    virtual int ReceiveMessage(ByteStream& bs);
    
    /**
	   * @brief parse message.
	   * @param[in] void
	   * @return int
	   */
    virtual unsigned int ParseMessage();
    
private:
    /**
     * @brief get message from database.
     * @param[in] void
     * @return int
     */
    int GetMessageFromDB();
    
private:
	  int nbytes;
    unsigned char buf[1024];
    unsigned int type;
};

#endif
