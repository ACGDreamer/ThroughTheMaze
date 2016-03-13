#ifndef __GAMEDATA_H__
#define __GAMEDATA_H__

#include "cocos2d.h"

#define ISDEBUG false

class GameData
{
public:
	static GameData* getInstance();
	static void destoryInstance();
	cocos2d::Layer * dlgContainer;
protected:
	virtual bool init();
private:
	static GameData* m_instance;
};

#endif //__GAMEDATA_H__