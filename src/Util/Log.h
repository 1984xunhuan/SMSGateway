/**
 *
 *@file Log.h
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-02
 *
 */
 
#ifndef LOG_H_
#define LOG_H_

#define LOG_DEBUG(format, ...) \
        do {\
            log_debug( __FILE__, __LINE__, (format), __VA_ARGS__);\
        } while(0)

#define LOG_ERROR(format, ...) \
        do {\
            log_error(__FILE__, __LINE__, (format), __VA_ARGS__);\
        } while(0)

#define LOG_INFO(format, ...) \
        do {\
            log_info(__FILE__,  __LINE__, (format), __VA_ARGS__);\
        } while(0)

#define LOG_WARN(format, ...) \
        do {\
            log_warn( __FILE__,  __LINE__, (format), __VA_ARGS__);\
        } while(0)

#define LOG_DEBUG_DATA(buf, len, format, ...) \
        do {\
            log_debug_hex(buf, len, __FILE__,  __LINE__, (format), __VA_ARGS__);\
        } while(0)

#define LOG_ERROR_DATA(buf, len, format, ...) \
        do {\
            log_error_hex(buf, len, __FILE__,  __LINE__, (format), __VA_ARGS__);\
        } while(0) 

#define LOG_INFO_DATA(buf, len, format, ...) \
        do {\
            log_info_hex(buf, len, __FILE__,  __LINE__, (format), __VA_ARGS__);\
        } while(0)

#define LOG_WARN_DATA(buf, len, format, ...) \
        do {\
            log_warn_hex(buf, len, __FILE__, __LINE__, (format), __VA_ARGS__);\
        } while(0)
    
/**
 * @brief record debug level log
 * @param[in] instance the log instance name in configure
 * @param[in] format the log format string
 */
extern void log_debug(const char* file, unsigned int line, const char* format, ...);

/**
 * @brief record info level log
 * @param[in] instance the log instance name in configure
 * @param[in] format the log format stirng
 */
extern void log_info(const char* file, unsigned int line, const char* format, ...);

/**
 * @brief record error level log
 * @param[in] instance the log instance name in configure
 * @param[in] format the log format stirng
 */
extern void log_error(const char* file, unsigned int line, const char* format, ...);

/**
 * @brief record warn level log
 * @param[in] instance the log instance name in configure
 * @param[in] format the log format stirng
 */

extern void log_warn(const char* file, unsigned int line, const char* format, ...);

/**
 * @brief record debug level log in hex style
 * @param[in] instance the log instance name in configure
 * @param[in] buf the data to log in hex style
 * @param[in] len the data length
 * @param[in] format the hex title format string
 */
extern void log_debug_hex(const char* buf, unsigned int len, const char* file, unsigned int line, const char* format, ...);

/**
 * @brief record info level log in hex style
 * @param[in] instance the log instance name in configure
 * @param[in] buf the data to log in hex style
 * @param[in] len the data length
 * @param[in] format the hex title format string
 */
extern void log_info_hex(const char* buf, unsigned int len, const char* file, unsigned int line, const char* format, ...);

/**
 * @brief record error level log in hex style
 * @param[in] instance the log instance name in configure
 * @param[in] buf the data to log in hex style
 * @param[in] len the data length
 * @param[in] format the hex title format string
 */
extern void log_error_hex(const char* buf, unsigned int len,const char* file,  unsigned int line, const char* format, ...);

/**
 * @brief record warn error level log in hex style
 * @param[in] instance the log instance name in configure
 * @param[in] buf the data to log in hex style
 * @param[in] len the data length
 * @param[in] format the hex title format string
 */
extern void log_warn_hex(const char* buf, unsigned int len, const char* file, unsigned int line, const char* format, ...);

#endif
