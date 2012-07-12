/**
 *
 *@file ConnectRespService.h
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-01
 *
 */

#ifndef CONNECTRESPSERVICE_H_ 
#define CONNECTRESPSERVICE_H_

#include <IfResponseService.h>

class ConnectRespService
    : public IfResponseService
{
public:
	  /**
     * @brief default constructor
     */
    ConnectRespService() : IfResponseService()
    {
        
    }
    
    /**
     * @brief desconstructor
     */
    virtual ~ConnectRespService()
    {
        
    }
    
    /**
	   * @brief create object.
	   * @param[in] void
	   * @return Point of IfMessageService
	   */
    static IfMessageService* CreateObject()
    {
        return new ConnectRespService();
    }
    
    /**
	   * @brief parse message body.
	   * @param[in] void
	   * @return int
	   */
    virtual int ParseMsgBody();
    
    /**
	   * @brief deal with business.
	   * @param[in] void
	   * @return int
	   */
    virtual int DoBusiness();
    
private:
    struct cmpp_connect_resp_packet* connect_resp_packet;
    
    unsigned int status;
    string       authenticator_ismg;
    unsigned int version;
};

#endif
