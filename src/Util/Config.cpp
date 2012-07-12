/**
 *
 *@file Config.cpp
 *
 *@brief
 *
 *@author ding gao tao
 *
 *@date   2010-09-07
 *
 */

#include <Config.h>

int Config::config_init(string sXmlFile)
{
    doc = xmlReadFile(sXmlFile.c_str(),"UTF-8",XML_PARSE_RECOVER); //�����ļ�
    
    //�������ĵ��Ƿ�ɹ���������ɹ���libxml��ָһ��ע��Ĵ���ֹͣ��
    //һ�����������ǲ��ʵ��ı��롣XML��׼�ĵ�������UTF-8��UTF-16�⻹�����������뱣�档
    //����ĵ���������libxml���Զ���Ϊ��ת����UTF-8���������XML������Ϣ������XML��׼��.
    
    if (NULL == doc)
    {
       //�ĵ��򿪴���
       return -1;
    }
    
    curNode = xmlDocGetRootElement(doc); //ȷ���ĵ���Ԫ��
    
    /*���ȷ�ϵ�ǰ�ĵ��а�������*/
    if (NULL == curNode)
    {
       //�յ�xml�ļ�
       xmlFreeDoc(doc);
       doc = NULL;
       
       return -1;
    }
    
    /*����������У�������Ҫȷ���ĵ�����ȷ�����͡���config���������ʾ����ʹ���ĵ��ĸ����͡�*/
    if (xmlStrcmp(curNode->name, BAD_CAST "config"))
    {
       //������Ԫ��ʧ��
       xmlFreeDoc(doc);
       doc = NULL;
       
       return -1;
    }
    
    return 0;
}

int Config::get_value(string sNodeName, string& sValue)
{ 
	  if(sNodeName.empty() || sNodeName.length() == 0)
	  {
	      return -1;
	  }
	  
	  sNodePath ="/" + string((const char*)(void*)curNode->name);
	  
	  int pos = sNodeName.rfind("/", sNodeName.length()) + 1;
	  
	  string sFindName = sNodeName.substr(pos);
	  
	  if(sFindName.empty() || sFindName.length() == 0)
	  {
	      return -1;
	  }
	  
	  sFindKey = sNodeName;
	  
	  iFindFlag = -1;
	  
	  return FindValue(doc, curNode, sFindName, sValue);
}

int Config::FindValue(xmlDocPtr doc, xmlNodePtr cur, string sNodeName, string& sValue)
{
	  if(iFindFlag == 0)
	  {
	      return 0;
	  }
	  
    xmlChar *key;
    
    cur = cur->xmlChildrenNode;
    
		while(cur != NULL)
		{			
				if((xmlStrcmp(cur->name, BAD_CAST "text")) && (xmlStrcmp(cur->name, (const xmlChar*)sNodeName.c_str())))
				{
					  if(sFindKey.find(sNodePath + "/" + string((const char*)(void*)cur->name)) != string::npos)
					  {
					      sNodePath +="/" + string((const char*)(void*)cur->name);
					  }
					  
						FindValue(doc, cur, sNodeName, sValue);
				}
				else if((!xmlStrcmp(cur->name, (const xmlChar*)sNodeName.c_str())))
				{
					  if(sFindKey.find(sNodePath + "/" + string((const char*)(void*)cur->name)) != string::npos)
					  {
					      sNodePath +="/" + string((const char*)(void*)cur->name);
					  }
						
						if(sFindKey == sNodePath)
						{
								key=xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
								
								sValue = string((const char*)(void*)key);
								xmlFree(key);
								
								iFindFlag = 0;
								
								return 0;
					  }
				}

				cur = cur->next;
		}
		
		return iFindFlag;
}

