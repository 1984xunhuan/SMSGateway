/**
 *
 *@file ReceiveMessage.hpp
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-07
 *
 */
 
#ifndef RECEIVEMESSAGE_H_
#define RECEIVEMESSAGE_H_

#include <iostream>

using namespace std;

class ReceiveMessage
{
public:
    ReceiveMessage() : sMsgId(""), sPhone(""), sContent(""), sRcvTime(""), sDone("")
    {
    
    }
    
    virtual ~ReceiveMessage()
    {
    
    }
    
public:
    string sMsgId;
    string sPhone;
    string sContent;
    string sRcvTime;
    string sDone;
};

#endif
