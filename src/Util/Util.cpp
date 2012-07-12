/**
 *
 *@file Util.cpp
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-02
 *
 */

#include <stdio.h>//for printf
#include <stdlib.h> 
#include <sys/types.h>
#include <string.h>//for bzero
#include <time.h>//for time
#include <iconv.h>//for iconv
#include <stdarg.h>//vnstat

#ifndef MAXLINE
#define MAXLINE 4096
#endif

//日志模块
int sms_log(char * msg)
{
	FILE *fp;
	int result;

	fp=fopen("/var/log/sms.log","a+");

	if(fp==NULL)return -1;

	result = fwrite(msg,sizeof(char),strlen(msg),fp);

	fclose(fp);

	return result;
}

void sys_log(const char *fmt, ...)
{
	char buf[MAXLINE+1];
	va_list ap;

	va_start(ap, fmt);

	vsnprintf(buf, MAXLINE, fmt, ap);

	sms_log(buf);

	va_end(ap);
	//exit(1);
}

int sms_pid(int pid)
{
	FILE *fp;
	int result;

	char msg[32];

	memset(msg,32,0);

	sprintf(msg,"%d",pid);


	fp=fopen("/var/log/sms.pid","w");

	if(fp==NULL)return -1;

	result = fwrite(msg,sizeof(char),strlen(msg),fp);

	fclose(fp);

	return result;
}

//把整数转化为4个字节的网络字节流，倒序排列
//void static int_to_4byte(int n,unsigned char *buf)
void int_to_4byte(int n,unsigned char *buf)
{
	memset(buf,0,4);
	buf[0]=(unsigned char)(n>>24);
	buf[1]=(unsigned char)(n>>16);
	buf[2]=(unsigned char)(n>>8);
	buf[3]=(unsigned char)n;
}

//把4个字节的网络字节流，装化为无符号的整型
unsigned int byte4_to_int(unsigned char * buf)
{
	unsigned int n;

	n= (unsigned int)((((unsigned int)buf[0])<<24)|(((unsigned int)buf[1])<<16)|(((unsigned int)buf[2])<<8)|(unsigned int)buf[3]);
	//n= (unsigned int)((int)(buf[0]<<24)|(int)(buf[1]<<16)|(int)(buf[2]<<8)|(int)buf[3]);
	
	return n;
}

//把整数转化为8个字节的网络字节流，倒序排列
//void static int_to_8byte(unsigned long long n,unsigned char *buf)
void int_to_8byte(unsigned long long n,unsigned char *buf)
{
	memset(buf,0,8);
	buf[0]=(unsigned char)(n>>56);
	buf[1]=(unsigned char)(n>>48);
	buf[2]=(unsigned char)(n>>40);
	buf[3]=(unsigned char)(n>>32);
	buf[4]=(unsigned char)(n>>24);
	buf[5]=(unsigned char)(n>>16);
	buf[6]=(unsigned char)(n>>8);
	buf[7]=(unsigned char)n;
}

//把8个字节的网络字节流，转化为无符号的长整型
unsigned long long byte8_to_long(unsigned char *buf)
{
	unsigned long long n;

	n= (unsigned long long)((((unsigned long long)buf[0])<<56)|(((unsigned long long)buf[1])<<48)|(((unsigned long long)buf[2])<<40)|(((unsigned long long)buf[3])<<32)|(((unsigned long long)buf[4])<<24)|(((unsigned long long)buf[5])<<16)|(((unsigned long long)buf[6])<<8)|(unsigned long long)buf[7]);
	//n= (unsigned long long)(buf[0]<<56 | buf[1]<<48 | buf[2]<<40 | buf[3]<<32 | buf[4]<<24 | buf[5]<<16 | buf[6]<<8 | buf[7]);
	
	//n= (unsigned long long)((((unsigned int)buf[0])<<56)|(((unsigned int)buf[1])<<48)|(((unsigned int)buf[2])<<40)|(((unsigned int)buf[3])<<32)|(((unsigned int)buf[4])<<24)|(((unsigned int)buf[5])<<16)|(((unsigned int)buf[6])<<8)|(unsigned int)buf[7]);
	
	return n;
}

//取当地时间（格式:MMDDHHmmss 10位）
void getlocaltime(unsigned char *buf)
{
	time_t time_p;
	struct tm *tm_p;

	memset(buf,0x00,10);
	time(&time_p);
	tm_p=localtime(&time_p);
	
	sprintf((char*)buf, (const char*)"%02d%02d%02d%02d%02d", tm_p->tm_mon+1,tm_p->tm_mday,tm_p->tm_hour,tm_p->tm_min,tm_p->tm_sec);
}

//取流水号
//int static getsequenceid()
int getsequenceid()
{
	static int sequence_id=0;

	if(sequence_id == 0x7FFFFFFF)
	{
		sequence_id = 0;
	}
	else
	{
		sequence_id ++ ;
	}

	sys_log("sequence_id=%d\n",sequence_id);

	return sequence_id;
}

//获取命令
unsigned int getcommandid(unsigned char * buf,int nbytes)
{
	unsigned int command_id=0;

	command_id= (unsigned int)((((unsigned int)buf[4])<<24)|(((unsigned int)buf[5])<<16)|(((unsigned int)buf[6])<<8)|(unsigned int)buf[7]);	
	//command_id = (int)((int)(buf[4]<<24)|(int)(buf[5]<<16)|(int)(buf[6]<<8)|(int)buf[7]);
	
	return command_id;
}

int ucs2Count(const unsigned char *pSrc)
{
    int i;
    for (i = 0; pSrc[i]+pSrc[i+1] != 0; i += 2);
    //注意上面有个";"
    return i;
}


//编码转换
int code_convert(char *from_charset,char *to_charset,char *inbuf,size_t inlen,char *outbuf,size_t outlen)
{
	iconv_t cd;
	char **pin = &inbuf;
	char **pout = &outbuf;

	cd = iconv_open(to_charset,from_charset);

	if(cd == 0) return -1;

	memset(outbuf,0,outlen);

	if(iconv(cd, pin, &inlen, pout, &outlen) != 0) return -1;

	iconv_close(cd);

	return 0;
}

//UCS2转化为UTF8
int ucs2_to_utf8(char *inbuf,int inlen,char *outbuf,int outlen)
{
	return code_convert("UCS-2","UTF-8",inbuf,inlen,outbuf,outlen);
}

//UCS2转化为UTF8
int utf8_to_ucs2(char *inbuf,int inlen,char *outbuf,int outlen)
{
	return code_convert("UTF8","UCS2",inbuf,inlen,outbuf,outlen);
}

//UCS2转化为GB2312
int u2g(char *inbuf,int inlen,char *outbuf,int outlen)
{
	return code_convert("UCS2","GB2312",inbuf,inlen,outbuf,outlen);
}
//GB2312转化为UCS2
int g2u(char *inbuf,unsigned int inlen,char *outbuf,unsigned int outlen)
{
	return code_convert("GB2312","UCS2",inbuf,inlen,outbuf,outlen);
}

//GB2312转化为UTF8
int g2utf8(char *inbuf,unsigned int inlen,char *outbuf,unsigned int outlen)
{
	return code_convert("GB2312","UTF8",inbuf,inlen,outbuf,outlen);
}
//GB2312转化为UTF-16BE
int gb2312_to_utf16be(char *inbuf,unsigned int inlen,char *outbuf,unsigned int outlen)
{
	return code_convert("GB2312","UTF-16BE",inbuf,inlen,outbuf,outlen);
}

int ucs2_to_utf16be(char *inbuf,unsigned int inlen,char *outbuf,unsigned int outlen)
{
	return code_convert("UCS2","UTF-16BE",inbuf,inlen,outbuf,outlen);
}

//UTF8转化为GB2312
int utf8_to_gb2312(char *inbuf,unsigned int inlen,char *outbuf,unsigned int outlen)
{
	return code_convert("UTF8","GB2312",inbuf,inlen,outbuf,outlen);
}

//UTF8转化为UTF-16BE
int utf8_to_utf16be(char *inbuf,unsigned int inlen,char *outbuf,unsigned int outlen)
{
	return code_convert("UTF8","UTF-16BE",inbuf,inlen,outbuf,outlen);
}

void dec_to_hex(char* p, unsigned int n) 
{ 
    int   i;
    
    if(p == NULL)
        return ; 
  
    for(i=0;i <8;i++) 
    {
        p[i]= '0'; 
    }
          
    p[8]=0; 
  
    i=7; 
  
    while(n> 0) 
    { 
        unsigned int m=n%16; 
        
        if(m <=9) 
              p[i]=m+48; 
        else     
              p[i]=m+55; 
        n/=16; 
        
        i--;
    }
}

void get_msg_id(unsigned char* buf, char* p)
{
	  /*
    buf[63] buf[62] buf[61] buf[60] //month
    buf[59] buf[58] buf[57] buf[56] //day
    buf[55] buf[54] buf[53] buf[52] //hour
    buf[51] buf[50] buf[49] buf[48] //minute
    buf[47] buf[46] buf[45] buf[44] //second  
    
    buf[43] buf[42] buf[41] buf[40]
    */
    
    unsigned int month  = byte4_to_int(buf);
    unsigned int day    = byte4_to_int(buf+4);
    unsigned int hour   = byte4_to_int(buf+8);
    unsigned int minute = byte4_to_int(buf+16);
    unsigned int second = byte4_to_int(buf+20);
    
    printf("%02u-%02u %02u:%02u:%02u", month, day, hour, minute, second);  
}



