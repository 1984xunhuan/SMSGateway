/**
 *
 *@file Log.cpp
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-02
 *
 */

#include <stdarg.h> 
#include <iostream>
#include <sstream>

using namespace std;

typedef enum
{
    TYPE_DEBUG,
    TYPE_INFO,
    TYPE_ERROR,
    TYPE_WARN
}LOG_TYPE;

int write_file(char* msg)
{
	FILE *fp;
	int result;

	fp=fopen("../log/SMSSrv.log","a+");

	if(fp==NULL)return -1;

	result = fwrite(msg,sizeof(char),strlen(msg),fp);

	fclose(fp);

	return result;
}



void HexData(std::ostream& os, const char* p, const unsigned int len)
{
	  char buf[3];
	  memset(buf, 0 , 3);
	  
	  os<<"\n\n-----------------------["<<len<<"]-----------------------\n";
	  
    for(unsigned int i=0; i<len; i++)
    {
    	  memset(buf, 0 , 3);
    	  
    	  snprintf(buf, 3, (const char*)"%02X", (unsigned char)p[i]);
        
        os<<buf;
    }	
    
    os<<'\n';
    os<<"--------------------------------------------------"<<endl;
    os<<std::endl;
}
    
void do_log(LOG_TYPE type, const char* buf, unsigned int len, const char* file, 
            unsigned int line, const char* format, va_list va)
{
    char log_buf[1024];
    memset(log_buf, 0, 1024);
    vsnprintf(log_buf, 1024, format, va);

    stringstream ss;
    ss<<"[";
    ss<<__DATE__;
    ss<<" ";
    ss<<__TIME__;
    ss<<" ";
    ss<<file;
    ss<<":";
    ss<<line;
    ss<<"] - ";
    ss<<log_buf;
    ss<<"\n";

    if(buf != NULL && len > 0)
    {
        HexData(ss, buf, len);
    }

    ss.flush();

    switch (type)
    {
        case TYPE_INFO:
        {
            cout<<ss.str();
            write_file((char*)ss.str().c_str());
            
            break;
        }
        case TYPE_ERROR:
        {
            cout<<ss.str();
            write_file((char*)ss.str().c_str());
            
            break;
        }
        case TYPE_WARN:
        {
            cout<<ss.str();
            write_file((char*)ss.str().c_str());
            
            break;
        }
        case TYPE_DEBUG:
        {
            cout<<ss.str();
            write_file((char*)ss.str().c_str());
            
            break;
        }
    }
}

#define DO_LOG(type, buf, len, file, line, format) \
    do {\
        va_list log_init_v;\
        va_start(log_init_v, (format));\
        do_log((type), (buf), (len), (file), (line), (format), log_init_v);\
        va_end(log_init_v);\
    } while(0)
    
/**
 * @brief record debug level log
 * @param[in] instance the log instance name in configure
 * @param[in] format the log format string
 */
void log_debug(const char* file, unsigned int line, const char* format, ...)
{
    DO_LOG(TYPE_DEBUG, NULL, 0, file, line, format);
}

/**
 * @brief record info level log
 * @param[in] instance the log instance name in configure
 * @param[in] format the log format stirng
 */
void log_info(const char* file, unsigned int line, const char* format, ...)
{
    DO_LOG(TYPE_INFO, NULL, 0, file, line, format);
}

/**
 * @brief record error level log
 * @param[in] instance the log instance name in configure
 * @param[in] format the log format stirng
 */
void log_error(const char* file, unsigned int line, const char* format, ...)
{
    DO_LOG(TYPE_ERROR, NULL, 0, file, line, format);
}

/**
 * @brief record warn level log
 * @param[in] instance the log instance name in configure
 * @param[in] format the log format stirng
 */

void log_warn(const char* file, unsigned int line, const char* format, ...)
{
    DO_LOG(TYPE_WARN, NULL, 0, file, line, format);
}

/**
 * @brief record debug level log in hex style
 * @param[in] instance the log instance name in configure
 * @param[in] buf the data to log in hex style
 * @param[in] len the data length
 * @param[in] format the hex title format string
 */
void log_debug_hex(const char* buf, unsigned int len, const char* file, unsigned int line, const char* format, ...)
{
    DO_LOG(TYPE_DEBUG, buf, len, file, line, format);
}

/**
 * @brief record info level log in hex style
 * @param[in] instance the log instance name in configure
 * @param[in] buf the data to log in hex style
 * @param[in] len the data length
 * @param[in] format the hex title format string
 */
void log_info_hex(const char* buf, unsigned int len, const char* file, unsigned int line, const char* format, ...)
{
    DO_LOG(TYPE_DEBUG, buf, len, file, line, format);
}

/**
 * @brief record error level log in hex style
 * @param[in] instance the log instance name in configure
 * @param[in] buf the data to log in hex style
 * @param[in] len the data length
 * @param[in] format the hex title format string
 */
void log_error_hex(const char* buf, unsigned int len,const char* file,  unsigned int line, const char* format, ...)
{
    DO_LOG(TYPE_ERROR, buf, len, file, line, format);
}

/**
 * @brief record warn error level log in hex style
 * @param[in] instance the log instance name in configure
 * @param[in] buf the data to log in hex style
 * @param[in] len the data length
 * @param[in] format the hex title format string
 */
void log_warn_hex(const char* buf, unsigned int len, const char* file, unsigned int line, const char* format, ...)
{
    DO_LOG(TYPE_WARN, buf, len, file, line, format);
}

