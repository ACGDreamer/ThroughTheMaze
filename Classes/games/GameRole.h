#ifndef __GAMEROLE_H__
#define __GAMEROLE_H__

#include "base/GobleHead.h"

class GameRole : public Node
{
public:
	GameRole();
	~GameRole();

private:
	Sprite* m_currentRole;
};


#endif // !__GAMEROLE_H__
