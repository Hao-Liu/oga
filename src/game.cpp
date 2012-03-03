#include "game.h"
#include "GameStateManager.h"
#include "GameStateGamePlay.h"

Game::Game ()
{
}

Game::~Game ()
{
}

void Game::run ()
{
	GameStateGamePlay* gsGamePlay = new GameStateGamePlay();
	mGameStateManager.change(gsGamePlay);
}

#ifdef _cplusplus
extern "C" 
{
#endif
	int main (int argc, char **argv)
	{
		Game game;

		game.run();
		return 0;
	}
#ifdef _cplusplus
}
#endif
