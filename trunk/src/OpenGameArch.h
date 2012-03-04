#ifndef _OPEN_GAME_ARCH_H_
#define _OPEN_GAME_ARCH_H_

#include "GameStateManager.h"
#include <OgreRoot.h>

class Game
{
public:
	Game ();
	virtual ~Game ();
	virtual void run ();
	Ogre::Root* getRoot () { return mRoot; }
	Ogre::RenderWindow* getWindow () { return mWindow; }

protected:
	GameStateManager* mGameStateManager;
	Ogre::Root* mRoot;
	Ogre::RenderWindow* mWindow;
};

#endif
