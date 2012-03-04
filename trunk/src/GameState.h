#ifndef _GAME_STATE_H_
#define _GAME_STATE_H_
#include <OgreSceneManager.h>
#include <OgreCamera.h>
#include <OgreViewport.h>
//#include "OpenGameArch.h"
class GameState
{
protected:
	Ogre::Root* mRoot;
	Ogre::SceneManager* mSceneManager;
	Ogre::Camera* mCamera;
	Ogre::RenderWindow* mWindow;
	Ogre::Viewport* mViewport;
	Ogre::ResourceGroupManager* mRGM;
public:
	virtual void enter ()  = 0;
	virtual void exit ()   = 0;
	virtual void pause ()  = 0;
	virtual void resume () = 0;
};
#endif
