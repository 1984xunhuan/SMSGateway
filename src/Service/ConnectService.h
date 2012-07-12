/**
 *
 *@file ConnectService.h
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-01
 *
 */

#ifndef CONNECTSERVICE_H_ 
#define CONNECTSERVICE_H_

#include <IfRequestService.h>

class ConnectService
    : public IfRequestService
{
public:
	  /**
     * @brief default constructor
     */
    ConnectService() : IfRequestService()
    {
    }
    
    /**
     * @brief desconstructor
     */
    virtual ~ConnectService()
    {
    }
    
    /**
	   * @brief create object.
	   * @param[in] void
	   * @return Point of IfMessageService
	   */
    static IfMessageService* CreateObject()
    {
        return new ConnectService();
    }
    
    /**
	   * @brief create message body.
	   * @param[in] void
	   * @return int
	   */
    virtual int CreateMsgBody();
    
    /**
	   * @brief Init Message Header.
	   * @param[in] void
	   * @return int
	   */
    virtual int InitMessageHeader();
    
    /**
	   * @brief deal with business.
	   * @param[in] ByteStream& mByteStream
	   * @return int
	   */
    virtual int DoBusiness(ByteStream& mByteStream);
    
private:
    struct cmpp_connect_packet* connect_packet;
};

#endif
