#include"UiManage.h"
#include "data/GameData.h"
#include "HelloWorldScene.h"


UiManager::UiManager()
{
	m_currentScene = NONE;
	m_preScene = NONE;
	m_willScene = NONE;
	logLayer = nullptr;
}

UiManager::~UiManager()
{

}

UiManager * UiManager::getInstance()
{
	if (m_instance == nullptr)
		m_instance = new UiManager();
	return m_instance;
}


//切换场景
void UiManager::showScene(sceneEnum sceneId)
{
	//判断场景
	if (m_currentScene == sceneId&&m_willScene == NONE) return;
	if (m_currentScene != NONE)
	{
		m_preScene = m_currentScene;
	}
	m_currentScene = sceneId;
	//合格，往下执行
	auto scene = Scene::create();
	Layer * layer = nullptr;
	switch (sceneId)
	{
	case UiManager::NONE:
		break;
	case UiManager::HELLOWORLD:
		layer = HelloWorld::create();
		break;
	default:
		break;
	}

	////进入自加载资源
	//if (layer->isAutoLoad == true && layer->resoureQue.size() > 0 && sceneId != UiManager::ROADINGSCENE&&m_willScene == NONE)
	//{
	//	GameData::getInstance()->loadQue = layer->resoureQue;
	//	layer = LoadingLayer::create();
	//	m_willScene = sceneId;
	//}
	//else if (m_willScene != NONE)
	//{
	//	m_willScene = NONE;
	//}
	//else
	//{

	//}

	scene->addChild(layer);
	GameData::getInstance()->dlgContainer = Layer::create();
	scene->addChild(GameData::getInstance()->dlgContainer);

	if (m_preScene != NONE)
	{
		//auto changeMode = TransitionFade::create(0.2f, scene, Color3B(0, 0, 0));
		Director::getInstance()->replaceScene(scene);
	}
	else
	{
		Director::getInstance()->runWithScene(scene);
	}
}

//添加dialog
void UiManager::showDlg(dlgEnum dlgId)
{
	switch (dlgId)
	{
	case UiManager::SETDLG:
		//GameData::getInstance()->dlgContainer->addChild(SetDlg::create());
		break;
	default:
		break;
	}
}

bool UiManager::hasDlg()
{
	if (GameData::getInstance()->dlgContainer->getChildren().size() > 0)
	{
		return true;
	}
	return false;
}

void UiManager::addLog(string logtxt)
{
	if (!ISDEBUG) return;
	if (logLayer == nullptr)
	{
		logLayer = Layer::create();
		Director::getInstance()->setNotificationNode(logLayer);
		logLayer->retain();
	}

	auto label = Label::createWithSystemFont("0", "Arial", 20);
	label->setTextColor(Color4B(255, 0, 0, 255));
	label->setWidth(540);
	label->setAnchorPoint(Vec2(0, 0));
	logLayer->addChild(label);
	label->setString(logtxt.c_str());
	label->setPosition(Vec2(20, 940 - 20 * logoLabel.size()));
	logoLabel.pushBack(label);
	if (logoLabel.size() > 45)
	{
		Label *  tempLabel = logoLabel.at(0);
		logoLabel.eraseObject(tempLabel);
		tempLabel->removeFromParent();
		for (int i = 0; i < logoLabel.size(); i++)
		{
			logoLabel.at(i)->setPosition(Vec2(20, 940 - 20 * i));
		}
	}
}


UiManager* UiManager::m_instance = nullptr;