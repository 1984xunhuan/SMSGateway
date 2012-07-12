/**
 *
 *@file SubmitService.cpp
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-01
 *
 */

#include <SubmitService.h>

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>//for errno

/**
 * @brief deal with business.
 * @param[in] ByteStream& mByteStream
 * @return int
 */
int SubmitService::DoBusiness(ByteStream& mByteStream)
{
	  LOG_DEBUG("%s","DoBusiness");
	   
	  LOG_DEBUG_DATA((const char*)(bs[0]), bs.GetSize(), "%s", "submit message!");
	  
	  if(write(sockfd, bs[0], bs.GetSize()) == -1)
	  {
		    LOG_DEBUG("Write Error: %s\n",strerror(errno));
	  }
	  
    return 0;
}

/**
 * @brief init message header.
 * @param[in] void
 * @return int
 */
int SubmitService::InitMessageHeader()
{
    LOG_DEBUG("%s","Init message header!");
    
    bs.Clear();

    total_length = 159 + msg_length;
    command_id   = CMPP_SUBMIT;
    
    return 0;
}

/**
 * @brief create message body.
 * @param[in] void
 * @return int
 */
int SubmitService::CreateMsgBody()
{
    LOG_DEBUG("%s","create message body!");
    
    //
    service_id          = sSpServiceId;
    fee_usertype        = 0;
    fee_terminal_id     = "";
    msg_src             = sSpId;
    feetype             = "01";
    feecode             = "";
    valid_time          = "";
    at_time             = "";
    src_id              = sSpConnNo;
    reserve             = "";
    
    //
    FillData(msg_id, 8);
    
    bs << (char)pk_total;
    bs << (char)pk_number;
    bs << (char)registered_delivery;
    bs << (char)msg_level;
    
    FillData(service_id, 10);
    
    bs << (char)fee_usertype;

    FillData(fee_terminal_id, 21);
    
    bs << (char)tp_pid;
    bs << (char)tp_udhi;
    bs << (char)msg_fmt;
    
    FillData(msg_src, 6);
    
    FillData(feetype, 2);

    FillData(feecode, 6);
 
    FillData(valid_time, 17);
    
    FillData(at_time, 17);
    
    FillData(src_id, 21);
    
    bs << (char)destusr_tl;
    
    FillData(dest_terminal_id, 21);
    
    if(iSmsType == 1 && tp_udhi == 1)
    {
    	  bs << (char)(msg_length + 6);
    	  
    	  unsigned char long_sms_six_header[6]={0x05,0x00,0x03,0x00,0x00,0x00};
        
        bs.Append((unsigned char*)long_sms_six_header,3);
        
        bs << (char)pk_number;
        bs << (char)pk_total;
        bs << (char)pk_number;
    }
    else
    {
        bs << (char)msg_length;
    }
    
    bs.Append((unsigned char*)msg_content.c_str(),msg_length);
    
    FillData(reserve, 8);
    
    return 0;
}

void SubmitService::InitParam(unsigned int iSmsType,unsigned int iTotal, unsigned int iNum,
	                            unsigned int iStatusRpt,unsigned int iMsgLevel, unsigned int iDestNum,
	                            string sPhone,unsigned int iMsgLength, string sMsgContent,
	                            unsigned int iPid,unsigned int iUdhi, unsigned int iMsgFmt)
{
	  this->iSmsType            = iSmsType;
    this->pk_total            = iTotal;
    this->pk_number           = iNum;
    this->registered_delivery = iStatusRpt;
    this->msg_level           = iMsgLevel;
    this->destusr_tl          = iDestNum;
    this->dest_terminal_id    = sPhone;
    this->msg_length          = iMsgLength;
    this->msg_content         = sMsgContent;
    
    this->tp_pid              = iPid;
    this->tp_udhi             = iUdhi;
    this->msg_fmt             = iMsgFmt;
}

/**
 * @brief fill data.
 * @param[in] data
 * @param[in] data length
 * @return void
 */
void SubmitService::FillData(string sData,unsigned int iDataLen)
{
	  unsigned int buf_len = 0;
    unsigned char tmpbuf[22];
    memset(tmpbuf,0,22);
    
    buf_len = sData.length();
    
    if(buf_len > iDataLen)
    {
        buf_len = iDataLen;
    }
    
    if(buf_len > 0)
    {  
        bs.Append((unsigned char*)sData.c_str(), buf_len);
    }
    
    if(buf_len < iDataLen)
    {
        bs.Append(tmpbuf,iDataLen-buf_len);
    }
    
}
