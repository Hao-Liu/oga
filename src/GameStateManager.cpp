#include "GameStateManager.h"
#include "GameState.h"
#include <stdio.h>
#include <assert.h>

GameStateManager::GameStateManager ()
{
	mCurrentGameState = NULL;
}

GameStateManager::~GameStateManager ()
{
}

void GameStateManager::change (GameState* gs)
{
	assert(gs != NULL);
	if (mCurrentGameState)
	{
		mCurrentGameState->exit();
	}
	else
	{
	}
	gs->enter();
	mCurrentGameState = gs;
}

void GameStateManager::push ()
{
}

void GameStateManager::pop ()
{
}
