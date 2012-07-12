/**
 *
 *@file Util.h
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-02
 *
 */
 
#ifndef UTIL_H_
#define UTIL_H_

#include <sys/types.h>

//日志写入日志文件
extern int sms_log(char * msg);
//系统日志
extern void sys_log(const char *fmt, ...);
//记录短信进程id
extern int sms_pid(int pid);
//把整数转化为4个字节的网络字节流，倒序排列
//void static int_to_4byte(int n,unsigned char *buf);
extern void int_to_4byte(int n,unsigned char *buf);
//把4个字节的网络字节流，装化为无符号的整型
extern unsigned int byte4_to_int(unsigned char * buf);
//把整数转化为8个字节的网络字节流，倒序排列
extern void int_to_8byte(unsigned long long n,unsigned char *buf);
//把8个字节的网络字节流，转化为无符号的长整型
extern unsigned long long byte8_to_long(unsigned char *buf);
//取当地时间（格式:MMDDHHmmss 10位）
extern void getlocaltime(unsigned char *buf);
//取流水号
extern int getsequenceid();
//获取命令
extern unsigned int getcommandid(unsigned char * buf,int nbytes);
//
extern int ucs2Count(const unsigned char *pSrc);
//编码转换
extern int code_convert(char *from_charset,char *to_charset,char *inbuf,size_t inlen,char *outbuf,size_t outlen);
//UCS2转化为UTF8
extern int ucs2_to_utf8(char *inbuf,int inlen,char *outbuf,int outlen);
//UCS2转化为UTF8
extern int utf8_to_ucs2(char *inbuf,int inlen,char *outbuf,int outlen);
//UCS2转化为GB2312
extern int u2g(char *inbuf,int inlen,char *outbuf,int outlen);
//GB2312转化为UCS2
extern int g2u(char *inbuf,unsigned int inlen,char *outbuf,unsigned int outlen);
//GB2312转化为UTF8
extern int g2utf8(char *inbuf,unsigned int inlen,char *outbuf,unsigned int outlen);
//GB2312转化为UTF-16BE
extern int gb2312_to_utf16be(char *inbuf,unsigned int inlen,char *outbuf,unsigned int outlen);
//UCS2转化为UTF-16BE
extern int ucs2_to_utf16be(char *inbuf,unsigned int inlen,char *outbuf,unsigned int outlen);
//UTF8转化为GB2312
extern int utf8_to_gb2312(char *inbuf,unsigned int inlen,char *outbuf,unsigned int outlen);
//UTF8转化为UTF-16BE
extern int utf8_to_utf16be(char *inbuf,unsigned int inlen,char *outbuf,unsigned int outlen);

extern void dec_to_hex(char* p, unsigned int n);

#endif
