/**
 *
 *@file DAO.cpp
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-06
 *
 */
 
#include <DAO.h>

ResultSet* DAO::Query(string sSql) throw (SQLException)
{
    stmt = conn->createStatement (sSql);
    stmt->setAutoCommit(autocommit);
    ResultSet* rs = stmt->executeQuery();
    
    return rs;
}

int DAO::Update(string sSql) throw (SQLException)
{
    stmt = conn->createStatement (sSql);
    stmt->setAutoCommit(autocommit);
    
    return stmt->executeUpdate ();
}

void DAO::Commit() throw (SQLException)
{
    conn->commit();
}

void DAO::Rollback() throw (SQLException)
{
    conn->rollback();
}

void DAO::CloseResultSet(ResultSet *rs) throw (SQLException)
{
    stmt->closeResultSet (rs);
}

void DAO::Close() throw (SQLException)
{
    conn->terminateStatement (stmt);
}

