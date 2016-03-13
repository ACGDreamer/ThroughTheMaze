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

//������ͼ
TMXTiledMap* MapUtils::createMap(int level){
	string mapName = getMapName(level);
	TMXTiledMap* map = TMXTiledMap::create(mapName);
	return map;
}

//��ȡ��ͼ����
const char* MapUtils::getMapName(int level){
	return NULL;
}

//����ͼ�Թ�ǽ��ײ
bool checkWallCollisions(TMXTiledMap* map, Node* obj){
	return false;
}
//��ӵ��ߵ���ͼ
Vec2 getToolPosOnMap(TMXTiledMap* map){
	return Vec2(0, 0);
}