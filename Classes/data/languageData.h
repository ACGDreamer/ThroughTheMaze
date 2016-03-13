#ifndef __LANGUAGEDATA_H__
#define __LANGUAGEDATA_H__

#include "cocos2d.h"

USING_NS_CC;

class LanguageData
{
public:
	LanguageData();
	~LanguageData();

	static LanguageData* getInstance();
	static void destoryInstance();

	const char* getValue(const std::string key);
private:
	bool init(const char* file);

private:

	std::string languageJson;

	static LanguageData *s_languageData;
};

#endif //__LANGUAGEDATA_H__