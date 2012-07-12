/**
 *
 *@file TerminateRespService.h
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-01
 *
 */

#ifndef TERMINATERESPSERVICE_H_ 
#define TERMINATERESPSERVICE_H_

#include <IfResponseService.h>

class TerminateRespService
    : public IfResponseService
{
public:
	  /**
     * @brief default constructor
     */
    TerminateRespService() : IfResponseService()
    {
        
    }
    
    /**
     * @brief desconstructor
     */
    virtual ~TerminateRespService()
    {
        
    }
    
    /**
	   * @brief create object.
	   * @param[in] void
	   * @return Point of IfMessageService
	   */
    static IfMessageService* CreateObject()
    {
        return new TerminateRespService();
    }
};

#endif
