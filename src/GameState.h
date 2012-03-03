#ifndef _GAME_STATE_H_
#define _GAME_STATE_H_
class GameState
{
//	mSceneManager;
public:
	virtual void enter ()  = 0;
	virtual void exit ()   = 0;
	virtual void pause ()  = 0;
	virtual void resume () = 0;
};
#endif
