#include "OpenGameArch.h"
#include "GameStateManager.h"
#include "GameStateGamePlay.h"
#include <OgreRoot.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreConfigFile.h>

Game::Game ()
{
	mGameStateManager = new GameStateManager();
	// setup root
	Ogre::String pluginFileName = "cfg/plugin.cfg";
	Ogre::String ConfigFileName = "cfg/ogre.cfg";
	Ogre::String LogFileName = "log/ogre.log";
	mRoot = new Ogre::Root(pluginFileName, ConfigFileName, LogFileName);

	// setup resource
	Ogre::String resourceConfigFile = "cfg/resource.cfg";
	Ogre::ConfigFile resourceConfig;
	resourceConfig.load(resourceConfigFile);

	Ogre::ConfigFile::SectionIterator secIter = resourceConfig.getSectionIterator();
	Ogre::String secName, typeName, archName;
	while (secIter.hasMoreElements())
	{
		secName = secIter.peekNextKey();
		Ogre::ConfigFile::SettingsMultiMap *settings = secIter.getNext();
		Ogre::ConfigFile::SettingsMultiMap::iterator i;
		for (i = settings->begin(); i != settings->end(); ++i)
		{
			typeName = i->first;
			archName = i->second;
			Ogre::ResourceGroupManager::getSingleton().addResourceLocation(archName, typeName, secName);
		}
	}

	// setup rendering config
	if (!mRoot->restoreConfig())
	{
		if (!mRoot->showConfigDialog())
		{
			exit (1);
		}
	}

	// initialise rendering window
	mWindow = mRoot->initialise(true, "test window");

}

Game::~Game ()
{
}

void Game::run ()
{
	GameStateGamePlay* gsGamePlay = new GameStateGamePlay(this);
	mGameStateManager->change(gsGamePlay);
}

#ifdef _cplusplus
extern "C" 
{
#endif
	int main (int argc, char **argv)
	{
		Game* game = new Game();

		game->run();
		return 0;
	}
#ifdef _cplusplus
}
#endif
