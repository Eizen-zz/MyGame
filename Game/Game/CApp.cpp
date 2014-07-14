#include "CApp.h"

namespace Game
{
	CApp* CApp::_pApp;

	CApp::CApp()
	{

	}

	CApp::~CApp()
	{

	}

	CApp* CApp::GetApp(void)
	{
		if (!_pApp)
			_pApp = new CApp();
		return _pApp;
	}

	void CApp::FreeApp(void)
	{
		if (_pApp)
			delete _pApp;
		_pApp = nullptr;
	}

	void CApp::Draw(void)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glRectf(0, 0, 100, 100);
		glutSwapBuffers();
	}

	void CApp::Run(void)
	{
		GLUTBackendRun(this);
	}

	void CApp::Idle(void)
	{
		Draw();
	}

	void CApp::SpecialKeyboard(int Key, int x, int y)
	{

	}

	void CApp::Keyboard(unsigned char Key, int x, int y)
	{

	}

	void CApp::PassiveMouse(int x, int y)
	{

	}
};