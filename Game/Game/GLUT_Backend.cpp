#include "GLUT_Backend.h"
#include "GameTypes.h"
#include <glut.h>

static Game::CCallbacks *Callbacks;

static void SpecialKeyboard(int Key, int x, int y)
{
	Callbacks->SpecialKeyboard(Key, x, y);
}

static void Keyboard(unsigned char Key, int x, int y)
{
	Callbacks->Keyboard(Key, x, y);
}

static void PassiveMouse(int x, int y)
{
	Callbacks->PassiveMouse(x, y);
}

static void Draw()
{
	Callbacks->Draw();
}

static void Idle()
{
	Callbacks->Idle();
}

static void InitCallbacks()
{
	glutDisplayFunc(Draw);
	glutIdleFunc(Idle);
	glutSpecialFunc(SpecialKeyboard);
	glutPassiveMotionFunc(PassiveMouse);
	glutKeyboardFunc(Keyboard);
}

void GLUTBackendInit(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
}

bool GLUTBackendCreateWindow(unsigned int Width, unsigned int Height, bool isFullScreen, const char* pTitle)
{
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(Width, Height);
	glutCreateWindow(pTitle);

	return true;
}

void GLUTBackendRun(Game::CCallbacks* pCallbacks)
{
	if (!pCallbacks)
		return;

	glClearColor(0, 0, 0, 0);
	gluOrtho2D(0, WindowWidth, WindowHeight, 0);
	
	Callbacks = pCallbacks;

	InitCallbacks();
	glutMainLoop();
}