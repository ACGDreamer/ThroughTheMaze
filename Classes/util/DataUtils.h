#ifndef _DATA_UTILS_
#define _DATA_UTILS_
/****************************************************************
*	创建时间：2016/1/11 12:12
*	描述说明：和数据有关的工具类,单例
*	目前版本：1.0
*	版本内容:
1.0
①操作JSON
②操作XML
③随机函数
*****************************************************************/
#include "base/GobleHead.h"
#include "cocos-ext.h"
USING_NS_CC_EXT;
#include "json/rapidjson.h"
#include "json/document.h"
#include "tinyxml2/tinyxml2.h"

class DataUtils
{
public:
	DataUtils();
	~DataUtils();
	static	DataUtils * getInstance();

	/*
	*	获得一个本文文本内容的所有字符串
	*	fileName  文件名字
	*/
	string getStrFromFile(char* fileName);

	/*
	*   从JSON字符串读取一个key对应的string
	*	str  json字符串
	*	key	 value对应的key
	*/
	string getStrFromJson(string &str, string& key);

	/*
	*  获得一个本地XML文件的序列类
	*  file 文件名字
	*/
	tinyxml2::XMLDocument * getXml(string file);

	/*
	*	从一个XML中读取一个bool值的value
	*	file 为XML实例类
	*	pKey 为Key
	*/
	bool getBoolForXmlKey(tinyxml2::XMLDocument * file, const char* pKey);

	/*
	*	从一个XML中读取一个整型值的value
	*	file 为XML实例类
	*	pKey 为Key
	*/
	int getIntegerForXmlKey(tinyxml2::XMLDocument * file, const char* pKey);

	/*
	*	从一个XML中读取一个浮点值的value
	*	file 为XML实例类
	*	pKey 为Key
	*/
	float getFloatForXmlKey(tinyxml2::XMLDocument * file, const char* pKey);

	/*
	*	从一个XML中读取一个字符值得value
	*	file 为XML实例类
	*	pKey 为Key
	*/
	string getStringForXmlKey(tinyxml2::XMLDocument * file, const char* pKey);

	/*
	*	从一个元素中读取一个string
	*/
	const char* getContentFromElement(tinyxml2::XMLElement * file, const char* pKey);

	/*
	*	获得当前时间
	*/
	string getNowYearMonthDay();

	int random(int start = 0, int end = 10);
	float random(float start = 0.0f, float end = 1.0f);

private:
	static	DataUtils *  m_instance;

	string word;
	string changeWordStrToJson(string str);
	string replace_all_distinct(string& str, const string& old_value, const string& new_value);
	const char* getContent(tinyxml2::XMLDocument * file, const char* pKey);
};

#endif // !_DATA_UTILS_
