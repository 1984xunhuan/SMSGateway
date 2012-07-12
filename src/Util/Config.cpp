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
    doc = xmlReadFile(sXmlFile.c_str(),"UTF-8",XML_PARSE_RECOVER); //解析文件
    
    //检查解析文档是否成功，如果不成功，libxml将指一个注册的错误并停止。
    //一个常见错误是不适当的编码。XML标准文档除了用UTF-8或UTF-16外还可用其它编码保存。
    //如果文档是这样，libxml将自动地为你转换到UTF-8。更多关于XML编码信息包含在XML标准中.
    
    if (NULL == doc)
    {
       //文档打开错误
       return -1;
    }
    
    curNode = xmlDocGetRootElement(doc); //确定文档根元素
    
    /*检查确认当前文档中包含内容*/
    if (NULL == curNode)
    {
       //空得xml文件
       xmlFreeDoc(doc);
       doc = NULL;
       
       return -1;
    }
    
    /*在这个例子中，我们需要确认文档是正确的类型。“config”是在这个示例中使用文档的根类型。*/
    if (xmlStrcmp(curNode->name, BAD_CAST "config"))
    {
       //分析根元素失败
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

