#include "GameData.h"


GameData* GameData::m_instance = NULL;

GameData* GameData::getInstance(){
	if (!m_instance)
	{
		m_instance = new GameData();
		m_instance->init();
	}
	return m_instance;
}

void GameData::destoryInstance(){
	if (m_instance)
	{
		delete m_instance;
	}
}

bool GameData::init(){
	//添加游戏数据初始化相关
	dlgContainer = NULL;
	return true;
}