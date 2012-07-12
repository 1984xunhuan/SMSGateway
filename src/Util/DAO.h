/**
 *
 *@file DAO.h
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-06
 *
 */
 
#ifndef DAO_H_
#define DAO_H_

#include <iostream>
#include <occi.h>

using namespace oracle::occi;
using namespace std;

class DAO
{
public:
    DAO(bool commit = false, string user = "", string passwd = "", string db = "")
        : autocommit(commit)
    {
        //env  = Environment::createEnvironment (Environment::THREADED_MUTEXED);
        //env  = Environment::createEnvironment (Environment::DEFAULT);
        env  = Environment::createEnvironment ("ZHS16GBK","UTF8");
        conn = env->createConnection (user, passwd, db);
    }

    ~DAO()
    {
        env->terminateConnection (conn);
        Environment::terminateEnvironment (env);
    }
    
    ResultSet* Query(string sSql) throw (SQLException);
    
    int Update(string sSql) throw (SQLException);
    
    void Commit() throw (SQLException);

    void Rollback() throw (SQLException);
    
    void CloseResultSet(ResultSet *rs) throw (SQLException);
    	
    void Close() throw (SQLException);
private:
    Environment *env;
    Connection  *conn;
    Statement   *stmt;   
    bool        autocommit;
};

#endif
