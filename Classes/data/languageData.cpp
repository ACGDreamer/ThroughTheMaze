#include "languageData.h"
#include "util/DataUtils.h"

LanguageData * LanguageData::s_languageData = NULL;

LanguageData::LanguageData(){
}

LanguageData::~LanguageData()
{
	//CC_SAFE_DELETE(rapidJson);
}

LanguageData* LanguageData::getInstance()
{
	if (!s_languageData)
	{
		s_languageData = new LanguageData();
		if (!s_languageData->init("language.json"))
		{
			CC_SAFE_DELETE(s_languageData);
		}
	}

	return s_languageData;
}

void LanguageData::destoryInstance(){
	CC_SAFE_DELETE(s_languageData);
}

bool LanguageData::init(const char* file){
	DataUtils::getInstance()->getStrFromFile(file);

	return true;
}