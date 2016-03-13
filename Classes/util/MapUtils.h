#ifndef __MAPUTILS_H__
#define __MAPUTILS_H__

#include "base/GobleHead.h"

class MapUtils
{
public:
	static MapUtils* getInstance();
	static void destroyInstance();
	//创建地图
	TMXTiledMap* createMap(int level);
	//检测地图迷宫墙碰撞
	bool checkWallCollisions(TMXTiledMap* map, Node* obj);
	//添加道具到地图
	Vec2 getToolPosOnMap(TMXTiledMap* map);
protected:
private:
	//根据关卡获取地图名
	const char* getMapName(int level);

	static MapUtils* m_Instance;
};

#endif // !__MAPUTILS_H__
