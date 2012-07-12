/**
 *
 *@file StatusReportDAO.h
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-07
 *
 */

#ifndef STATUSREPORTDAO_H_
#define STATUSREPORTDAO_H_

#include <StatusReport.hpp>
#include <sstream>
#include <DAO.h>
#include <Log.h>

using namespace std;

class StatusReportDAO
    : public StatusReport
{
public:
	  /**
     * @brief desconstructor
     */
    StatusReportDAO() : StatusReport()
    {
    }
    
    /**
     * @brief desconstructor
     */
    virtual ~StatusReportDAO()
    {
    }
    
    /**
     * @brief  set entity.\n
     * @param[in] ReceiveMessage entity.\n
     */
    void SetEntity(StatusReport& obj);
    
    /**
     * @brief storage to database  .\n
     * @param[int] the point of dao.\n
     * @return   int .\n
     */
    int Save(DAO* pDAO);
};

#endif
