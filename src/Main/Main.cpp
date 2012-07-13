/**
 *
 *@file Main.cpp
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-01
 *
 */

#include<unistd.h>
#include<signal.h>
#include<SMSSrv.h>

int g_exit_flag = 0;

void OnExit(int n)
{
    g_exit_flag = 1;
}

void OnException(int n)
{
    g_exit_flag = 1;
}

int main(int argc, char** argv)
{
	  signal(SIGINT, OnExit);
	  
	  signal(SIGSEGV, OnException);
	
    SMSSrv mSmsSrv;
    
    mSmsSrv.Init();
    
    mSmsSrv.Login();
    
    while(!g_exit_flag)
    {
        mSmsSrv.Run();
        
        usleep(100);
    }
    
    mSmsSrv.Logout();
}
