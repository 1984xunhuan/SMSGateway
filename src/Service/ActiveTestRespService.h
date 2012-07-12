/**
 *
 *@file ActiveTestRespService.h
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-01
 *
 */

#ifndef ACTIVETESTRESPSERVICE_H_ 
#define ACTIVETESTRESPSERVICE_H_

#include <IfResponseService.h>

class ActiveTestRespService
    : public IfResponseService
{
public:
	  /**
     * @brief default constructor
     */
    ActiveTestRespService() : IfResponseService()
    {
        
    }
    
    /**
     * @brief desconstructor
     */
    virtual ~ActiveTestRespService()
    {
        
    }
    
    /**
	   * @brief create object.
	   * @param[in] void
	   * @return Point of IfMessageService
	   */
    static IfMessageService* CreateObject()
    {
        return new ActiveTestRespService();
    }
    
    /**
	   * @brief parse message body.
	   * @param[in] void
	   * @return int
	   */
    virtual int ParseMsgBody();
    
private:
    unsigned int reserved;
};

#endif
