/**
 *
 *@file TerminateService.h
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-01
 *
 */

#ifndef TERMINATESERVICE_H_ 
#define TERMINATESERVICE_H_

#include <IfRequestService.h>

class TerminateService
    : public IfRequestService
{
public:
	  /**
     * @brief default constructor
     */
    TerminateService() : IfRequestService()
    {
    }
    
    /**
     * @brief desconstructor
     */
    virtual ~TerminateService()
    {
    }
    
    /**
	   * @brief create object.
	   * @param[in] void
	   * @return Point of IfMessageService
	   */
    static IfMessageService* CreateObject()
    {
        return new TerminateService();
    }
    
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
};

#endif
