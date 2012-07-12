/**
 *
 *@file StatusReportDAO.cpp
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-07
 *
 */
 
#include <StatusReportDAO.h>

/**
 * @brief  set entity.\n
 * @param[in] entity transcation.\n
 */
void StatusReportDAO::SetEntity(StatusReport& obj)
{
    LOG_DEBUG("%s","Set StatusReport Entity");
    	
    this->sMsgId          = obj.sMsgId;
    this->sStat           = obj.sStat;
    this->sSubmitTime     = obj.sSubmitTime;
    this->sDoneTime       = obj.sDoneTime;
    this->sDestTerminalId = obj.sDestTerminalId;
    this->sSmscSequence   = obj.sSmscSequence;
    this->sOptime         = obj.sOptime;
}

int StatusReportDAO::Save(DAO* pDAO)
{
    LOG_DEBUG("%s","Save StatusReport Entity");
    
    stringstream ss;

    ss << "INSERT INTO status_report(msg_id,stat,submit_time,done_time,dest_terminal_id,smsc_sequence,optime) values('";
    ss << sMsgId;
    ss << "','";
    ss << sStat;
    ss << "','";
    ss << sSubmitTime;
    ss << "','";
    ss << sDoneTime;
    ss << "','";
    ss << sDestTerminalId;
    ss << "','";
    ss << sSmscSequence;
    ss << "',";
    ss << sOptime;
    ss << ")";
    
    LOG_DEBUG("%s",ss.str().c_str());
    
    return pDAO->Update(ss.str());
}

