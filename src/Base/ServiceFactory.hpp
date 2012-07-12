/**
 *
 *@file ServiceFactory.hpp
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-02
 *
 */
 
#ifndef SERVICEFACTORY_H_
#define SERVICEFACTORY_H_

#include <map>
#include <PreDef.h>
#include <IfMessageService.h>
#include <ActiveTestService.h>
#include <ActiveTestRespService.h>
#include <ConnectService.h>
#include <ConnectRespService.h>
#include <TerminateService.h>
#include <TerminateRespService.h>
#include <SubmitService.h>
#include <SubmitRespService.h>
#include <DeliverService.h>
#include <DeliverRespService.h>

using namespace std;
using namespace predef;

typedef IfMessageService*(*pFun)();  
typedef map<int, pFun> MESSAGE_FACTORY;
typedef MESSAGE_FACTORY::iterator MESSAGE_FACTORY_ITERATOR;
	
class ServiceFactory
{
public:
	 
	
    ServiceFactory()
    {
    }
    
    ~ServiceFactory()
    {
    }
    
    static void InitFactory()
    {
    	  AddElement(CMPP_CONNECT, ConnectService::CreateObject);
    	  AddElement(CMPP_CONNECT_RESP, ConnectRespService::CreateObject);
        AddElement(CMPP_ACTIVE_TEST, ActiveTestService::CreateObject);
        AddElement(CMPP_ACTIVE_TEST_RESP, ActiveTestRespService::CreateObject);
        AddElement(CMPP_TERMINATE, TerminateService::CreateObject);	
        AddElement(CMPP_TERMINATE_RESP, TerminateRespService::CreateObject);	
        AddElement(CMPP_SUBMIT, SubmitService::CreateObject);
        AddElement(CMPP_SUBMIT_RESP, SubmitRespService::CreateObject);
        AddElement(CMPP_DELIVER, DeliverService::CreateObject);
        AddElement(CMPP_DELIVER_RESP, DeliverRespService::CreateObject);
    }
    
    static IfMessageService* GetMessageService(int type)
    {
        MESSAGE_FACTORY_ITERATOR it= mMsgFactory.find(type); 
        
        if(it == mMsgFactory.end()) 
        {
            return NULL;
        }
        else 
        {
            pFun pf = it->second;
            
            return pf();
        }
    }
    
    static void AddElement(int type, pFun pf)
    {
        mMsgFactory.insert(MESSAGE_FACTORY::value_type(type, pf)); 
    }
    
private:
	  static MESSAGE_FACTORY mMsgFactory;
};

MESSAGE_FACTORY ServiceFactory::mMsgFactory;

#endif

