/**
 *
 *@file DeliverService.h
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-06
 *
 */

#ifndef DELIVERSERVICE_H_
#define DELIVERSERVICE_H_

#include <IfResponseService.h>
#include <DAO.h>

class StatusRpt
{
public:
    unsigned long long msg_id;
    string             stat;
    string             submit_time;
    string             done_time;
    string             dest_terminal_id;
    unsigned int       smsc_sequence;
};

class DeliverService
    : public IfResponseService
{
public:
		/**
     * @brief default constructor
     */
    DeliverService() : IfResponseService()
    {
        	
    }
    
    /**
     * @brief desconstructor
     */
    virtual ~DeliverService()
    {
        
    }
    
    /**
	   * @brief create object.
	   * @param[in] void
	   * @return Point of IfMessageService
	   */
    static IfMessageService* CreateObject()
    {
        return new DeliverService();
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
    unsigned long long msg_id;
    string             dest_id;
    string             service_id;
    string             tp_pid;
    string             tp_udhi;
    unsigned int       msg_fmt;
    string             src_terminal_id;
    unsigned int       registered_delivery;
    unsigned int       msg_length;
    string             msg_content;
    string             reserved;
    StatusRpt          mStatusReport;
    
    unsigned int       result;
};

#endif

