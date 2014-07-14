#include "CGame.h"

namespace Game
{
	CGame* CGame::_pGame;

	CGame::CGame()
	{

	}

	CGame::~CGame()
	{

	}

	CGame* CGame::GetInstance()
	{
		if (!_pGame)
			_pGame = new CGame();
		return _pGame;
	}

	void CGame::FreeInstance()
	{
		if (_pGame)
			delete _pGame;
		_pGame = nullptr;
	}

	void CGame::Run(int argc, char** argv, int Width, int Height, bool FuulScreen, const char* Title)
	{
		GLUTBackendInit(argc, argv);
		GLUTBackendCreateWindow(Width, Height, FuulScreen, Title);
		_pApp = CApp::GetApp();
		_pApp->Run();
		CApp::FreeApp();
	}
};