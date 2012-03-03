#ifndef _STATE_GAMEPLAY_H_
#define _STATE_GAMEPLAY_H_

#include "GameState.h"

class GameStateGamePlay : public GameState
{
	void enter ();
	void exit ();
	void pause ();
	void resume ();
};
#endif
