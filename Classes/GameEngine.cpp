#include "GameEngine.h"

void GameEg::GameGlobalInit(string gameName)
{
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if (!glview) {
		glview = GLViewImpl::createWithRect(gameName, Rect(0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT), 1);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
		glview->setFrameSize(DISPLAY_WIDTH, DISPLAY_HEIGHT);
		glview->setFrameZoomFactor(0.72f);
#endif

		director->setOpenGLView(glview);
		//调试信息
		director->setDisplayStats(true);
		//帧率
		director->setAnimationInterval(1.0 / 60);

	}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	glview->setDesignResolutionSize(DISPLAY_WIDTH, DISPLAY_HEIGHT, ResolutionPolicy::SHOW_ALL);
#else
	glview->setDesignResolutionSize(DISPLAY_WIDTH, DISPLAY_HEIGHT, ResolutionPolicy::SHOW_ALL);
#endif

	//首次进入游戏初始化基本数据
	if (UserDefault::getInstance()->getIntegerForKey("starttime", 0))
	{
		UserDefault::getInstance()->setBoolForKey("bgMusic", true);
		UserDefault::getInstance()->setBoolForKey("soundMusic", true);
	}

	//启动次数+1，用启动次数来判断是否是新手，1为第一次进入
	int starttime = UserDefault::getInstance()->getIntegerForKey("starttime", 0);
	starttime++;
	UserDefault::getInstance()->setIntegerForKey("starttime", starttime);

}

void GameEg::GameGlobalDebug(gameMode mDebugStatus)
{
	GameEg::debugStatus = mDebugStatus;
	auto director = Director::getInstance();
	director->setDisplayStats(mDebugStatus == debug ? true : false);
}

string GameEg::getWord(string key)
{
	/*Json::Value lang;
	JsonUtils::initJsonWithString(GameEg::langData, lang);
	auto str = JsonUtils::getString(lang, key.c_str());
	return str;*/
	return NULL;
}

gameMode GameEg::debugStatus = gameMode::debug;
string GameEg::langData = "";