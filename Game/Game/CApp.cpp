#include "CApp.h"
#include <cmath>

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
		//----------------------------------------------------
		glColor3f(1, 1, 1);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(400, 400);
		glColor3f(0, 0.4, 0);
		for (float i = 0; i < 2 * 3.14; i+= 3.14 / 36)
			glVertex2f(400 + 50 * sin(i), 400 + 50 * cos(i));
		glEnd();
		//----------------------------------------------------
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

	void CApp::Mouse(int button, int state, int x, int y)
	{

	}
};