/**
 *
 *@file ReceiveMessageDAO.cpp
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-07
 *
 */
 
#include <ReceiveMessageDAO.h>

/**
 * @brief  set entity.\n
 * @param[in] entity transcation.\n
 */
void ReceiveMessageDAO::SetEntity(ReceiveMessage& obj)
{
    LOG_DEBUG("%s","Set ReceiveMessage Entity");
    	
    this->sMsgId   = obj.sMsgId;
    this->sPhone   = obj.sPhone;
    this->sContent = obj.sContent;
    this->sRcvTime = obj.sRcvTime;
    this->sDone    = obj.sDone;
}

int ReceiveMessageDAO::Save(DAO* pDAO)
{
    LOG_DEBUG("%s","Save ReceiveMessage Entity");
    
    stringstream ss;
    
    ss << "INSERT INTO receive_message(msg_id,phone,content,rcvtime,done) values('";
    ss << sMsgId;
    ss << "','";
    ss << sPhone;
    ss << "','";
    ss << sContent;
    ss << "',";
    ss << sRcvTime;
    ss << ",'";
    ss << sDone;
    ss << "')";
    
    LOG_DEBUG("%s",ss.str().c_str());
    
    return pDAO->Update(ss.str());
}

