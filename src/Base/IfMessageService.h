/**
 *
 *@file IfMessageService.h
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-01
 *
 */

#ifndef IFMESSAGESERVICE_H_ 
#define IFMESSAGESERVICE_H_

#include <Log.h>
#include <PreDef.h>
#include <Util.h>
#include <Protocol.h>
#include <ByteStream.hpp>

using namespace predef;

class IfMessageService
{
public:
	  /**
     * @brief default constructor
     */
    IfMessageService()
    {
        bMsgFromISMG = false;
    }
    
    /**
     * @brief desconstructor
     */
    virtual ~IfMessageService()
    {
    }
    
    /**
	   * @brief init.
	   * @param[in] socket description
	   * @return int
	   */
    int Init(int sockfd, ByteStream bs)
    {
        this->sockfd = sockfd;
        this->bs     = bs;
        
        return 0;
    }
    
    virtual int Package() = 0;
    
    virtual int Unpackage() = 0;
    
    virtual int DoMessage(ByteStream& mByteStream) = 0;
    
    void SetSocket(int sockfd)
    {
        this->sockfd = sockfd;
    }
    
    int GetSocket()
    {
        return this->sockfd;
    }
    
    ByteStream GetByteStream()
    {
        return this->bs;
    }
    
    bool IsMsgFormISMG()
    {
        return bMsgFromISMG;
    }
    
    void SetMsgFormISMG(bool flag)
    {
       bMsgFromISMG = flag;
    }
    
    void SetSequenceId(unsigned int seq)
    {
        sequence_id = seq;
    }
    
protected:
    int sockfd;
    ByteStream bs;
    
    unsigned int total_length;
    unsigned int command_id;
    unsigned int sequence_id;
    bool bMsgFromISMG;
};

#endif
