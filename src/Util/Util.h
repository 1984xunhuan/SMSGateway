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

//��־д����־�ļ�
extern int sms_log(char * msg);
//ϵͳ��־
extern void sys_log(const char *fmt, ...);
//��¼���Ž���id
extern int sms_pid(int pid);
//������ת��Ϊ4���ֽڵ������ֽ�������������
//void static int_to_4byte(int n,unsigned char *buf);
extern void int_to_4byte(int n,unsigned char *buf);
//��4���ֽڵ������ֽ�����װ��Ϊ�޷��ŵ�����
extern unsigned int byte4_to_int(unsigned char * buf);
//������ת��Ϊ8���ֽڵ������ֽ�������������
extern void int_to_8byte(unsigned long long n,unsigned char *buf);
//��8���ֽڵ������ֽ�����ת��Ϊ�޷��ŵĳ�����
extern unsigned long long byte8_to_long(unsigned char *buf);
//ȡ����ʱ�䣨��ʽ:MMDDHHmmss 10λ��
extern void getlocaltime(unsigned char *buf);
//ȡ��ˮ��
extern int getsequenceid();
//��ȡ����
extern unsigned int getcommandid(unsigned char * buf,int nbytes);
//
extern int ucs2Count(const unsigned char *pSrc);
//����ת��
extern int code_convert(char *from_charset,char *to_charset,char *inbuf,size_t inlen,char *outbuf,size_t outlen);
//UCS2ת��ΪUTF8
extern int ucs2_to_utf8(char *inbuf,int inlen,char *outbuf,int outlen);
//UCS2ת��ΪUTF8
extern int utf8_to_ucs2(char *inbuf,int inlen,char *outbuf,int outlen);
//UCS2ת��ΪGB2312
extern int u2g(char *inbuf,int inlen,char *outbuf,int outlen);
//GB2312ת��ΪUCS2
extern int g2u(char *inbuf,unsigned int inlen,char *outbuf,unsigned int outlen);
//GB2312ת��ΪUTF8
extern int g2utf8(char *inbuf,unsigned int inlen,char *outbuf,unsigned int outlen);
//GB2312ת��ΪUTF-16BE
extern int gb2312_to_utf16be(char *inbuf,unsigned int inlen,char *outbuf,unsigned int outlen);
//UCS2ת��ΪUTF-16BE
extern int ucs2_to_utf16be(char *inbuf,unsigned int inlen,char *outbuf,unsigned int outlen);
//UTF8ת��ΪGB2312
extern int utf8_to_gb2312(char *inbuf,unsigned int inlen,char *outbuf,unsigned int outlen);
//UTF8ת��ΪUTF-16BE
extern int utf8_to_utf16be(char *inbuf,unsigned int inlen,char *outbuf,unsigned int outlen);

extern void dec_to_hex(char* p, unsigned int n);

#endif
