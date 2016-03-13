#include "DataUtils.h"

DataUtils::DataUtils()
{
	word = "";
	timeval psv;
	gettimeofday(&psv, NULL);
	unsigned long int seed = psv.tv_sec * 1000 + psv.tv_usec / 1000;
	srand(seed);
}

DataUtils::~DataUtils()
{

}

DataUtils * DataUtils::getInstance()
{
	if (m_instance == nullptr)
		m_instance = new DataUtils();

	return m_instance;
}

string DataUtils::getStrFromFile(char * fileName)
{
	string filePath = FileUtils::getInstance()->fullPathForFilename(fileName);
	unsigned char *data = NULL;
	ssize_t len = 0;
	data = FileUtils::getInstance()->getFileData(filePath.c_str(), "r", &len);
	const char* p = static_cast<const char*>(static_cast<void *>(const_cast<unsigned char*>(data)));
	std::string str = p;
	if (data) delete[] data;
	return str;
}

string DataUtils::getStrFromJson(string & str, string & key)
{
	str = changeWordStrToJson(str);
	str = replace_all_distinct(str, "\r\n", "");
	word = "No Name";
	rapidjson::Document _doc;
	_doc.Parse<0>(str.c_str());
	if (_doc.HasParseError())
	{

	}
	if (_doc.IsObject()) {
		if (_doc.HasMember(key.c_str())) {
			const rapidjson::Value &word_key = _doc[key.c_str()];
			word = word_key.GetString();
		}
	}
	return word;
}



string DataUtils::changeWordStrToJson(string str)
{
	std::string::size_type pos = str.find("{", 0);
	str = str.replace(0, pos, "");
	pos = str.find("}", 0);
	std::string::size_type lastPos = pos;
	str = str.replace(lastPos + 1, str.length() - lastPos, "");
	return str;
}

string DataUtils::replace_all_distinct(string& str, const string& old_value, const string& new_value)
{
	for (std::string::size_type pos(0); pos != std::string::npos; pos += new_value.length())
	{
		if ((pos = str.find(old_value, pos)) != std::string::npos)
			str.replace(pos, old_value.length(), new_value);
		else
			break;
	}
	return   str;
}

tinyxml2::XMLDocument * DataUtils::getXml(string file)
{
	/*string file_path = FileUtils::getInstance()->fullPathForFilename(file);
	tinyxml2::XMLDocument * xmlDoc= new tinyxml2::XMLDocument();;
	xmlDoc->LoadFile(file_path.c_str());*/
	tinyxml2::XMLDocument* xmlDoc = new tinyxml2::XMLDocument();
	ssize_t bufferSize;
	auto pBuffer = FileUtils::sharedFileUtils()->getFileData(file, "rb", &bufferSize);
	int error = xmlDoc->Parse((const char*)pBuffer);
	pBuffer[(int)bufferSize - 1] = '\0';
	return xmlDoc;
}

bool DataUtils::getBoolForXmlKey(tinyxml2::XMLDocument * file, const char * pKey)
{
	bool ret = false;
	const char* content = getContent(file, pKey);
	ret = (!strcmp(content, "true"));
	return ret;
}

int DataUtils::getIntegerForXmlKey(tinyxml2::XMLDocument * file, const char * pKey)
{
	int ret = 0;
	const char* content = getContent(file, pKey);
	ret = atoi(content);
	return ret;
}

float DataUtils::getFloatForXmlKey(tinyxml2::XMLDocument * file, const char * pKey)
{
	float ret = 0.0f;
	const char* content = getContent(file, pKey);
	ret = utils::atof(content);
	return ret;
}

string DataUtils::getStringForXmlKey(tinyxml2::XMLDocument * file, const char * pKey)
{
	string ret = "";
	const char* content = getContent(file, pKey);
	//ret = StringUtils::format(content);
	ret = content;
	return ret;
}

const char * DataUtils::getContentFromElement(tinyxml2::XMLElement * file, const char * pKey)
{
	tinyxml2::XMLElement* curNode = nullptr;
	curNode = file;
	while (nullptr != curNode)
	{
		const char* nodeName = curNode->Value();
		if (!strcmp(nodeName, pKey))
		{
			break;
		}

		curNode = curNode->NextSiblingElement();
	}
	if (curNode != nullptr)
	{
		const char* content = curNode->GetText();
		return content;
	}
	return nullptr;
}

const char * DataUtils::getContent(tinyxml2::XMLDocument * file, const char * pKey)
{
	tinyxml2::XMLElement* curNode = nullptr;
	curNode = file->FirstChildElement();
	while (nullptr != curNode)
	{
		const char* nodeName = curNode->Value();
		if (!strcmp(nodeName, pKey))
		{
			break;
		}

		curNode = curNode->NextSiblingElement();
	}
	if (curNode != nullptr)
	{
		const char* content = curNode->GetText();
		return content;
	}
	return nullptr;
}

string DataUtils::getNowYearMonthDay()
{
	struct tm *tm;
	time_t timep;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	time(&timep);
#else
	struct timeval tv;
	gettimeofday(&tv, NULL);
	timep = tv.tv_sec;
#endif
	tm = localtime(&timep);
	int year = tm->tm_year + 1900;//年
	int month = tm->tm_mon + 1;//月
	int day = tm->tm_mday;//日
	return  StringUtils::format("%i%i%i", year, month, day);
}

int DataUtils::random(int start, int end)
{
	if (end < start) {
		std::swap(start, end);
	}
	return CCRANDOM_0_1() * (end - start) + start;
}

float DataUtils::random(float start, float end)
{
	if (end < start) {
		std::swap(start, end);
	}
	return CCRANDOM_0_1() * (end - start) + start;
}

DataUtils* DataUtils::m_instance = nullptr;