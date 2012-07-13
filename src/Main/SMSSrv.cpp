/**
 *
 *@file SMSSrv.cpp
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-01
 *
 */

#include "SMSSrv.h"

//implement
#include <SMSGatewayService.h>
#include <ServiceFactory.hpp>

/**
 * @brief int
 * @param[in] void
 * @return int 
 */
int SMSSrv::Init()
{
    LOG_DEBUG("%s","init");
    
    ReadConfig();
    
    InitSocket();
    
    ServiceFactory::InitFactory();
    
    return 0;
}

/**
 * @brief read config
 * @param[in] void
 * @return int 
 */
int SMSSrv::ReadConfig()
{
    Config mCfg;
    
    mCfg.config_init("../etc/config.xml");
    
    string sValue = "";
    
    //read system item information.
    if(mCfg.get_value("/config/system/maxlogincount", sValue) == -1)
    {
    	  LOG_ERROR("%s","read /config/system/maxlogincount failure!");
    	  
        exit(1);
    }
    
    iMaxLoginCount = atoi((const char*)sValue.c_str());
    
    //read database item information.
    if(mCfg.get_value("/config/database/username", sValue) == -1)
    {
    	  LOG_ERROR("%s","read /config/database/username failure!");
    	  
        exit(1);
    }
    
    sDBUser = sValue;
    
    if(mCfg.get_value("/config/database/password", sValue) == -1)
    {
    	  LOG_ERROR("%s","read /config/database/password failure!");
    	  
        exit(1);
    }
    
    sDBPwd = sValue;
    
    if(mCfg.get_value("/config/database/connstr", sValue) == -1)
    {
    	  LOG_ERROR("%s","read /config/database/connstr failure!");
    	  
        exit(1);
    }
    
    sDBConnStr = sValue;
    
    LOG_DEBUG("[username: %s, password: %s, connstr: %s]",sDBUser.c_str(), sDBPwd.c_str(), sDBConnStr.c_str());
    
    
    //read gateway item information.
    if(mCfg.get_value("/config/gateway/ipaddr", sValue) == -1)
    {
    	  LOG_ERROR("%s","read /config/gateway/ipaddr failure!");
    	  
        exit(1);
    }
    
    sIPAddr = sValue;
    
    if(mCfg.get_value("/config/gateway/port", sValue) == -1)
    {
    	  LOG_ERROR("%s","read /config/gateway/port failure!");
    	  
        exit(1);
    }
    
    sPort = sValue;
    
    if(mCfg.get_value("/config/gateway/spid", sValue) == -1)
    {
    	  LOG_ERROR("%s","read /config/gateway/spid failure!");
    	  
        exit(1);
    }
    
    sSpId = sValue;
    
    if(mCfg.get_value("/config/gateway/password", sValue) == -1)
    {
    	  LOG_ERROR("%s","read /config/gateway/password failure!");
    	  
        exit(1);
    }
    
    sSpPwd = sValue;
    
    if(mCfg.get_value("/config/gateway/serviceid", sValue) == -1)
    {
    	  LOG_ERROR("%s","read /config/gateway/serviceid failure!");
    	  
        exit(1);
    }
    
    sSpServiceId = sValue;
    
    if(mCfg.get_value("/config/gateway/spno", sValue) == -1)
    {
    	  LOG_ERROR("%s","read /config/gateway/spno failure!");
    	  
        exit(1);
    }
    
    sSpConnNo = sValue;
    
     if(mCfg.get_value("/config/gateway/version", sValue) == -1)
    {
    	  LOG_ERROR("%s","read /config/gateway/version failure!");
    	  
        exit(1);
    }
    
    sVersion = sValue;
    
    LOG_DEBUG("[ipaddr:%s, port:%s, spid: %s, password: %s, serviceid: %s, spno: %s, version: %s]", sIPAddr.c_str(), sPort.c_str(), sSpId.c_str(), sSpPwd.c_str(), sSpServiceId.c_str(), sSpConnNo.c_str(), sVersion.c_str());
    
    return 0;
}

/**
 * @brief InitSocket
 * @param[in] void
 * @return int 
 */
int SMSSrv::InitSocket()
{
    LOG_DEBUG("%s","init socket");

    struct sockaddr_in server_addr;
    struct hostent *host = gethostbyname((const char*)sIPAddr.c_str());
    int portnumber = atoi((const char*)sPort.c_str());
    
    //建立socket
	  if((sockfd=socket(AF_INET,SOCK_STREAM,0)) == -1)
	  {
		    LOG_ERROR("Socket Error: %s\a\n",strerror(errno));
		    
		    exit(1);
	  }

	  //初始化socket
	  bzero(&server_addr,sizeof(server_addr));
	  server_addr.sin_family = AF_INET;
	  server_addr.sin_port = htons(portnumber);
	  server_addr.sin_addr=*((struct in_addr *)host->h_addr);

	  //创建连接connect 
	  if(connect(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr)) == -1)
	  {
		    LOG_ERROR("%s","Connect Error");
		  
		    exit(1);
	  }

    return 0;
} 

/**
 * @brief login
 * @param[in] void
 * @return int 
 */
int SMSSrv::Login()
{
	  LOG_DEBUG("%s","login");
	  
	  static int iLoginCount = 0;
	  
	  iLoginCount ++;
	  
	  pMsgService = ServiceFactory::GetMessageService(CMPP_CONNECT);
	  
	  if(pMsgService != NULL)
	  {
	  	  ByteStream bs;
	      pMsgService->SetSocket(sockfd);
	      
	      if(pMsgService->DoMessage(bs) == -1)
	      {
	    	  close(sockfd);
	    	  
	          InitSocket();
	          
	          Login();
	          
	          return -1;
	      }
	      
	      delete pMsgService;
	      pMsgService = NULL;
	      
	      //
	      pMsgService = ServiceFactory::GetMessageService(CMPP_CONNECT_RESP);
	      
	      if(pMsgService != NULL)
	      {
	          pMsgService->SetSocket(sockfd);
	      
	          if(pMsgService->DoMessage(bs) != 0)
	          {
	      	      if(iLoginCount >= iMaxLoginCount)
	      	      {
	      	          LOG_DEBUG("%s","Exceed the maximum number of times landing !!!");
	      	          exit(1);
	      	      }
	      	  
	              Login();
	              
	              return -1;
	          }
	      
	          delete pMsgService;
	          pMsgService = NULL;
	      }
	  }
    
    return 0;
}

/**
 * @brief run
 * @param[in] void
 * @return int
 */
int SMSSrv::Run()
{
	  LOG_DEBUG("%s","run");
	  
	  SMSGatewayService mGWService;
	  pGWService = &mGWService;
	  
	  ByteStream bs;
	  
	  pGWService->Init(sockfd);
	  
	  int type = pGWService->Receive(bs);
	  
	  if(type == 0)
	  {
	      return -1;
	  }
	  else if(type == -1)
	  {
	       close(sockfd);
	       
	       InitSocket();
	          
	       Login();
	       
	       return -1;
	  }
	  
	  pMsgService = ServiceFactory::GetMessageService(type);
	  
	  if(pMsgService != NULL)
	  {
	  	  pMsgService->SetSocket(sockfd); 	  
	  	  pMsgService->SetMsgFormISMG(pGWService->GetMsgFormISMG());
	  	  
	      pMsgService->DoMessage(bs);
	      
	      delete pMsgService;
	      
	      pMsgService = NULL;
	  }
	  
    return 0;
}

/**
 * @brief logout
 * @param[in] void
 * @return int
 */
int SMSSrv::Logout()
{
    LOG_DEBUG("%s","logout");
	  
    close(sockfd);
	  
    return 0;
}

