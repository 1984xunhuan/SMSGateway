/**
 *
 *@file StatusReport.hpp
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-07
 *
 */
 
#ifndef STATUSREPORT_H_
#define STATUSREPORT_H_

#include <iostream>

using namespace std;

class StatusReport
{
public:
    StatusReport() : sMsgId(""), sStat(""), sSubmitTime(""), sDoneTime(""), sDestTerminalId(""), sSmscSequence(""), sOptime("")
    {
    
    }
    
    virtual ~StatusReport()
    {
    
    }
    
public:
    string sMsgId;
    string sStat;
    string sSubmitTime;
    string sDoneTime;
    string sDestTerminalId;
    string sSmscSequence;
    string sOptime;
};

#endif
