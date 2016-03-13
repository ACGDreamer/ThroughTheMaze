#ifndef _UIMANAGER_H_
#define _UIMANAGER_H_
/****************************************************************
*
*	创建时间：2016/1/11 14:04
*	描述说明：UI管理类,包括场景管理,对话框管理,单例
*	目前版本：1.0
*	版本内容:
1.0
①统一管理对话框和场景
*****************************************************************/
#include "base/GobleHead.h"



class UiManager
{
public:
	UiManager();
	~UiManager();
	static	UiManager * getInstance();

	//场景
	enum sceneEnum	{ NONE, HELLOWORLD };
	//对话框
	enum dlgEnum	{ SETDLG};
	//显示场景
	void showScene(sceneEnum sceneId);
	//显示对话框
	void showDlg(dlgEnum dlgId);
	//是否有弹框
	bool hasDlg();
	//
	sceneEnum					m_willScene;
	sceneEnum getCurrentScene(){ return m_currentScene; };
	//
	Layer * logLayer;
	void addLog(string logtxt);
	Vector<Label *> logoLabel;
private:
	static UiManager	*		m_instance;
	sceneEnum					m_currentScene;
	sceneEnum					m_preScene;
};


#endif // !_UIMANAGER_H_

