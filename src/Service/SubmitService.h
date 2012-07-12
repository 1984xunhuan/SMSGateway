/**
 *
 *@file SubmitService.h
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-01
 *
 */

#ifndef SUBMITSERVICE_H_ 
#define SUBMITSERVICE_H_

#include <IfRequestService.h>
#include <DAO.h>

class SubmitService
    : public IfRequestService
{
public:
	  /**
     * @brief default constructor
     */
    SubmitService() : IfRequestService()
    {
    }
    
    /**
     * @brief desconstructor
     */
    virtual ~SubmitService()
    {
    }
    
    /**
	   * @brief create object.
	   * @param[in] void
	   * @return Point of IfMessageService
	   */
    static IfMessageService* CreateObject()
    {
        return new SubmitService();
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
    
    void InitParam(unsigned int iSmsType,unsigned int iTotal, unsigned int iNum,
	                 unsigned int iStatusRpt,unsigned int iMsgLevel, unsigned int iDestNum,
	                 string sPhone,unsigned int iMsgLength, string sMsgContent,
	                 unsigned int iPid,unsigned int iUdhi, unsigned int iMsgFmt);
    
private:
	  /**
	   * @brief fill data.
	   * @param[in] data
	   * @param[in] data length
	   * @return void
	   */
    void FillData(string sData,unsigned int iDataLen);
    
private:
    string msg_id;
    unsigned int pk_total;
    unsigned int pk_number;
    unsigned int registered_delivery;
    unsigned int msg_level;
    string service_id;
    unsigned int fee_usertype;
    string fee_terminal_id;
    unsigned int tp_pid;
    unsigned int tp_udhi;
    unsigned int msg_fmt;
    string msg_src;
    string feetype;
    string feecode;
    string valid_time;
    string at_time;
    string src_id;
    unsigned int destusr_tl;
    string dest_terminal_id;
    unsigned int msg_length;
    string msg_content;
    string reserve;
    
    unsigned int iSmsType;
};

#endif
