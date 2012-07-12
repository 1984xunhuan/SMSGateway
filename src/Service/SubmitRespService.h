/**
 *
 *@file SubmitRespService.h
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-01
 *
 */

#ifndef SUBMITRESPSERVICE_H_ 
#define SUBMITRESPSERVICE_H_

#include <IfResponseService.h>

class SubmitRespService
    : public IfResponseService
{
public:
	  /**
     * @brief default constructor
     */
    SubmitRespService() : IfResponseService()
    {
        
    }
    
    /**
     * @brief desconstructor
     */
    virtual ~SubmitRespService()
    {
        
    }
    
    /**
	   * @brief create object.
	   * @param[in] void
	   * @return Point of IfMessageService
	   */
    static IfMessageService* CreateObject()
    {
        return new SubmitRespService();
    }
    
    /**
	   * @brief parse message body.
	   * @param[in] void
	   * @return int
	   */
    virtual int ParseMsgBody();
    
private:
	  string msg_id;
    unsigned int result;
};

#endif
