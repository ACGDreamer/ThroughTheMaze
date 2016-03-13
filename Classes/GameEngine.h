#ifndef __GAMEENGINE_H__
#define __GAMEENGINE_H__

#include "base/GobleHead.h"
#include "DeviceConfigs.h"

static Size designResolutionSize = cocos2d::Size(DISPLAY_WIDTH, DISPLAY_HEIGHT);

enum gameMode { debug = 0, release };

class GameEg
{
public:
	static void  GameGlobalInit(string gameName);
	static void  GameGlobalDebug(gameMode mDebugStatus);
	static gameMode	 debugStatus;
	static std::string getWord(std::string key);
	static std::string  langData;
};


#endif // !__GAMEENGINE_H__