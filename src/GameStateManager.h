#ifndef _GAME_STATE_MANAGER_H_
#define _GAME_STATE_MANAGER_H_
#include "GameState.h"
class GameStateManager
{
	GameState* mCurrentGameState;
public:
	GameStateManager();
	virtual ~GameStateManager();
	void change(GameState* gs);
	void push();
	void pop();
};

#endif
