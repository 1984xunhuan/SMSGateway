/**
 *
 *@file IfGatewayService.h
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-01
 *
 */

#ifndef IFGATEWAYSERVICE_H_ 
#define IFGATEWAYSERVICE_H_

#include <Log.h>
#include <Util.h>
#include <iostream>
#include <ByteStream.hpp>

using namespace std;

class IfGatewayService
{
public:
	  /**
     * @brief default constructor
     */
    IfGatewayService()
    {
    }
    
    /**
     * @brief desconstructor
     */
    virtual ~IfGatewayService()
    {
    }
    
    /**
	   * @brief init.
	   * @param[in] socket description
	   * @return int
	   */
    int Init(int sockfd)
    {
        this->sockfd = sockfd;
        
        return 0;
    }
    
    /**
	   * @brief create message head.
	   * @param[in] void
	   * @return int
	   */
    int Receive(ByteStream& bs)
    {
    	  bMsgFromISMG = false;
    	  
    	  //
        if(ReceiveMessage(bs) == 0)
        {
            //
            return ParseMessage();
        }
        else
        {
            return -1;
        }
    }
    
    /**
	   * @brief receive message.
	   * @param[in] void
	   * @return int
	   */
    virtual int ReceiveMessage(ByteStream& bs) = 0;
    
    /**
	   * @brief parse message.
	   * @param[in] void
	   * @return int
	   */
    virtual unsigned int ParseMessage() = 0;
    
    bool GetMsgFormISMG()
    {
        return bMsgFromISMG;
    }
    
    void SetMsgFormISMG(bool flag)
    {
       bMsgFromISMG = flag;
    }
 
protected:
    int sockfd;
private:
    bool bMsgFromISMG;
};

#endif
