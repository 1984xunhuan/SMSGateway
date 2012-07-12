/**
 *
 *@file ReceiveMessageDAO.h
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-07
 *
 */

#ifndef RECEIVEMESSAGEDAO_H_
#define RECEIVEMESSAGEDAO_H_

#include <ReceiveMessage.hpp>
#include <sstream>
#include <DAO.h>
#include <Log.h>

using namespace std;

class ReceiveMessageDAO
    : public ReceiveMessage
{
public:
	  /**
     * @brief desconstructor
     */
    ReceiveMessageDAO() : ReceiveMessage()
    {
    }
    
    /**
     * @brief desconstructor
     */
    virtual ~ReceiveMessageDAO()
    {
    }
    
    /**
     * @brief  set entity.\n
     * @param[in] ReceiveMessage entity.\n
     */
    void SetEntity(ReceiveMessage& obj);
    
    /**
     * @brief storage to database  .\n
     * @param[int] the point of dao.\n
     * @return   int .\n
     */
    int Save(DAO* pDAO);
};

#endif
