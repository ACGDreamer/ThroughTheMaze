#include "MapUtils.h"

MapUtils* MapUtils::m_Instance = NULL;

MapUtils* MapUtils::getInstance(){
	if (!m_Instance)
	{
		m_Instance = new MapUtils();
	}
	return m_Instance;
}

void MapUtils::destroyInstance(){
	
	CC_SAFE_DELETE(m_Instance);

}

//创建地图
TMXTiledMap* MapUtils::createMap(int level){
	string mapName = getMapName(level);
	TMXTiledMap* map = TMXTiledMap::create(mapName);
	return map;
}

//获取地图名称
const char* MapUtils::getMapName(int level){
	return NULL;
}

//检测地图迷宫墙碰撞
bool checkWallCollisions(TMXTiledMap* map, Node* obj){
	return false;
}
//添加道具到地图
Vec2 getToolPosOnMap(TMXTiledMap* map){
	return Vec2(0, 0);
}