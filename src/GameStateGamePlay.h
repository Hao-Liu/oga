#ifndef _STATE_GAMEPLAY_H_
#define _STATE_GAMEPLAY_H_

#include <Ogre.h>
#include <OIS.h>
#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreLogManager.h>
#include <OgreRoot.h>
#include <OgreViewport.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreConfigFile.h>

#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISMouse.h>
#include <OISKeyboard.h>

#include "OpenGameArch.h"
#include "GameState.h"
#include "SinbadCharacterController.h"

class GameStateGamePlay : public GameState, public OIS::MouseListener, public OIS::KeyListener, public Ogre::FrameListener, public Ogre::WindowEventListener
{
protected:
	Ogre::String mArchive;
	Ogre::String mMap;
	OIS::Mouse* m_mouse;
	OIS::Keyboard* m_keyboard;
	SinbadCharacterController* mSinbad;
	virtual bool mouseMoved(const OIS::MouseEvent& arg);
	virtual bool mousePressed(const OIS::MouseEvent& arg, OIS::MouseButtonID id);
	virtual bool mouseReleased(const OIS::MouseEvent& arg, OIS::MouseButtonID id);
	virtual bool keyPressed(const OIS::KeyEvent& arg);
	virtual bool keyReleased(const OIS::KeyEvent& arg);
	virtual bool frameRenderingQueued(const Ogre::FrameEvent& arg);
public:
	GameStateGamePlay(Game* game);
	void enter ();
	void exit ();
	void pause ();
	void resume ();
};
#endif
