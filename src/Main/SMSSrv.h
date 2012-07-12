/**
 *
 *@file SMSSrv.h
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-01
 *
 */

#ifndef SMSSRV_H_ 
#define SMSSRV_H_

//input output
#include<iostream>
//interface
#include <IfGatewayService.h>
#include <IfMessageService.h>

#include <stdio.h>//for printf
#include <stdlib.h>//for exit
#include <errno.h>//for errno
#include <string.h>//for bzero
#include <netdb.h>//for
#include <netinet/in.h>//for sockaddr_in
#include <sys/types.h>//for socket
#include <sys/socket.h>//for socket

#include <PreDef.h>
#include <Config.h>

using namespace std;
using namespace predef;

class SMSSrv
{
public:
	  /**
     * @brief default constructor
     */
    SMSSrv() : pGWService(NULL), pMsgService(NULL)
    {
    }
    
    /**
     * @brief desconstructor
     */
    ~SMSSrv()
    {
    }
    
    /**
	   * @brief int
	   * @param[in] void
	   * @return int 
	   */
    int Init();
    
    
    /**
     * @brief InitSocket
     * @param[in] void
     * @return int 
     */
    int InitSocket();
    
    /**
     * @brief read config
     * @param[in] void
     * @return int 
     */
    int ReadConfig();
    
    /**
	   * @brief login
	   * @param[in] void
	   * @return int 
	   */
    int Login();
    
    /**
	   * @brief run
	   * @param[in] void
	   * @return int
	   */
    int Run();
    
    /**
	   * @brief logout
	   * @param[in] void
	   * @return int
	   */
    int Logout();
    
private:
	  IfGatewayService* pGWService;
    IfMessageService* pMsgService;
    int sockfd;
};

#endif
