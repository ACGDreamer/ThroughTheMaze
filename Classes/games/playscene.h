#ifndef __PLAYSCENE_H__
#define __PLAYSCENE_H__

#include "base/GobleHead.h"

class PlayScene : public Layer
{
public:
	PlayScene();
	~PlayScene();

	bool init();

	void onEnter();
	void onExit();

	CREATE_FUNC(PlayScene);
private:

};


#endif // !__PLAYSCENE_H__
