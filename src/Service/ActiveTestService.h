/**
 *
 *@file ActiveTestService.h
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-01
 *
 */

#ifndef ACTIVETESTSERVICE_H_ 
#define ACTIVETESTSERVICE_H_

#include <IfRequestService.h>

class ActiveTestService
    : public IfRequestService
{
public:
	  /**
     * @brief default constructor
     */
    ActiveTestService() : IfRequestService()
    {
    }
    
    /**
     * @brief desconstructor
     */
    virtual ~ActiveTestService()
    {
    }
    
    /**
	   * @brief create object.
	   * @param[in] void
	   * @return Point of IfMessageService
	   */
    static IfMessageService* CreateObject()
    {
        return new ActiveTestService();
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
    
    virtual int Unpackage();
    
    virtual int CreateActiveTestRspPkg();
    
    virtual int ParseMsgHeader();
};

#endif
