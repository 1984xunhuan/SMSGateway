/**
 *
 *@file TerminateService.cpp
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-01
 *
 */

#include <TerminateService.h>

/**
 * @brief init message header.
 * @param[in] void
 * @return int
 */
int TerminateService::InitMessageHeader()
{
    LOG_DEBUG("%s","Init message header!");
    
    total_length = 12;
    command_id   = CMPP_TERMINATE;
    
    return 0;
}
