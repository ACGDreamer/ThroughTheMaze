#include "playscene.h"

PlayScene::PlayScene()
{
}

PlayScene::~PlayScene()
{
}

//初始化
bool PlayScene::init(){
	if (!Layer::init()){
		return false;
	}
	return true;
}

void PlayScene::onEnter(){
	Layer::onEnter();
}

void PlayScene::onExit(){
	Layer::onExit();
}