/**
 *
 *@file Config.h
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-07
 *
 */
 
#ifndef CONFIG_H_
#define CONFIG_H_

#include <iostream>
#include <libxml/parser.h>

using namespace std;
	
class Config
{
public:
    Config()
    {
    }
    
    virtual ~Config()
    {
    	   if(doc != NULL)
    	   {
             xmlFreeDoc(doc);
         }
    }
    
    int config_init(string sXmlFile);
    
    int get_value(string sNodeName, string& sValue);
    
private:
	  int FindValue(xmlDocPtr doc, xmlNodePtr cur, string sNodeName, string& sValue);
    
private:
    xmlDocPtr doc;           //��������ĵ�ָ��
    xmlNodePtr curNode;      //������ָ��(����Ҫ��Ϊ���ڸ��������ƶ�)
    string sNodePath;
    string sFindKey;
    int    iFindFlag;
};

#endif
