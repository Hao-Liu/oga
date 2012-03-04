#include <Ogre.h>
#include <OgreRenderWindow.h>
#include <OgreConfigFile.h>
#include "GameStateGamePlay.h"
#include "SinbadCharacterController.h"

GameStateGamePlay::GameStateGamePlay (Game* game)
{
	Ogre::String mapConfigFile = "cfg/ogretestmap.cfg";
	Ogre::ConfigFile cf;
	cf.load (mapConfigFile);
	Ogre::String mArchive = cf.getSetting("Archive");
	Ogre::String mMap     = cf.getSetting("Map");
	Ogre::ResourceGroupManager::getSingleton().addResourceLocation(mArchive, "Zip",
			Ogre::ResourceGroupManager::getSingleton().getWorldResourceGroupName(), true);

	mRoot = game->getRoot();

	mWindow = game->getWindow();
	// create the scene manager
	mSceneManager = mRoot->createSceneManager("BspSceneManager");

	// create the camera
	mCamera = mSceneManager->createCamera("SceneCamera"); 
	// create a viewport covering the entire window
	mViewport = mWindow->addViewport(mCamera);
	mViewport->setBackgroundColour(Ogre::ColourValue(0,0,0));
	mCamera->setAspectRatio(Ogre::Real(mViewport->getActualWidth()) / Ogre::Real(mViewport->getActualHeight()));

	// load resources
	//Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
	//TODO: may have some bugs here
	mRGM = &(Ogre::ResourceGroupManager::getSingleton());
	mRGM->linkWorldGeometryToResourceGroup (mRGM->getWorldResourceGroupName(), mMap, mSceneManager);
	mRGM->initialiseResourceGroup (mRGM->getWorldResourceGroupName());
	mRGM->loadResourceGroup (mRGM->getWorldResourceGroupName(), false);
}

bool GameStateGamePlay::mouseMoved(const OIS::MouseEvent& event)
{
	//m_cameraMan->injectMouseMove(event);
	mSinbad->injectMouseMove(event);
	return true;
}

bool GameStateGamePlay::mousePressed(const OIS::MouseEvent& event, OIS::MouseButtonID id)
{
	//m_cameraMan->injectMouseDown(event, id);
	mSinbad->injectMouseDown(event, id);
	return true;
}

bool GameStateGamePlay::mouseReleased(const OIS::MouseEvent& event, OIS::MouseButtonID id)
{
	//m_cameraMan->injectMouseUp(event, id);
	//mSinbad->injectMouseUp(event, id);
	return true;
}

bool GameStateGamePlay::keyPressed(const OIS::KeyEvent& event)
{
	if (event.key == OIS::KC_ESCAPE)
	{
		exit();
	}
	//m_cameraMan->injectKeyDown(event);
	mSinbad->injectKeyDown(event);
	return true;
}

bool GameStateGamePlay::keyReleased(const OIS::KeyEvent& event)
{
	//m_cameraMan->injectKeyUp(event);
	mSinbad->injectKeyUp(event);
	return true;
}

bool GameStateGamePlay::frameRenderingQueued(const Ogre::FrameEvent& event)
{
	m_mouse->capture();
	m_keyboard->capture();
	//m_cameraMan->frameRenderingQueued(event);
	mSinbad->addTime(event.timeSinceLastFrame);
	/*
	Ogre::RaySceneQuery * rayQuery = m_sceneManager->createRayQuery(Ogre::Ray(m_camera->getPosition(), Ogre::Vector3::NEGATIVE_UNIT_Z));
	rayQuery->setWorldFragmentType(Ogre::SceneQuery::WFT_PLANE_BOUNDED_REGION);

	Ogre::RaySceneQueryResult& queryResult = rayQuery->execute();

	Ogre::RaySceneQueryResult::iterator i = queryResult.begin();

	if (i!=queryResult.end())
	{
		if (i->distance < 80)
			m_camera->setPosition(m_camera->getPosition() + Ogre::Vector3(0, 0, 80 - i->distance));
		else
			m_camera->setPosition(m_camera->getPosition() - Ogre::Vector3(0, 0, 0));
		std::cout << "Detected: " + Ogre::StringConverter::toString(i->distance) << "\n";
	}
*/
	return true;
}

void GameStateGamePlay::enter ()
{
	// create scene
	// create a ogre head entity
	Ogre::Entity* ogreHead = mSceneManager->createEntity("Head", "ogrehead.mesh");
//	ogreHead->setMaterialName("Examples/CelShading");
	Ogre::SceneNode* headNode = mSceneManager->getRootSceneNode()->createChildSceneNode("HeadNode");
	headNode->attachObject(ogreHead);
	headNode->setPosition(Ogre::Vector3(0, -100, 100));

	mSinbad = new SinbadCharacterController(mCamera);

	// setup lights
	mSceneManager->setAmbientLight(Ogre::ColourValue(0.0, 0.0, 0.0));
	Ogre::Light* light = mSceneManager->createLight("MainLight");
	light->setPosition(80,80,40);

	// initialise OIS
	size_t mWindowHandle = 0;
	mWindow->getCustomAttribute("WINDOW", &mWindowHandle);
	std::ostringstream mWindowHandleString; 
	mWindowHandleString << mWindowHandle;
	OIS::ParamList paramList;
	paramList.insert(std::make_pair(std::string("WINDOW"), mWindowHandleString.str()));
	OIS::InputManager* inputManager = OIS::InputManager::createInputSystem(paramList);

	// setup mouse listener
	m_mouse = static_cast<OIS::Mouse*>(inputManager->createInputObject(OIS::OISMouse, true));
	m_mouse->setEventCallback(this);

	// adjust mouse clipping area
	unsigned int width, height, depth;
	int left, top;
	mWindow->getMetrics(width, height, depth, left, top);
	const OIS::MouseState &mouseState = m_mouse->getMouseState();
	mouseState.width = width;
	mouseState.height = height;

	// setup keyboard listener
	m_keyboard = static_cast<OIS::Keyboard*>(inputManager->createInputObject(OIS::OISKeyboard, true));
	m_keyboard->setEventCallback(this);

	mRoot->addFrameListener(this);
	mRoot->startRendering();
}
void GameStateGamePlay::exit ()
{
}
void GameStateGamePlay::pause ()
{
}
void GameStateGamePlay::resume ()
{
}
