#ifndef _GAME_H_
#define _GAME_H_

#include "GameStateManager.h"

class Game
{
public:
	Game ();
	virtual ~Game ();
	virtual void run ();
protected:
	GameStateManager mGameStateManager;
};

#endif
