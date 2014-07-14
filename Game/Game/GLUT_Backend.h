#ifndef _GLUT_BACKEND_H
#define _GLUT_BACKEND_H

#include "CCallbacks.h"
#include <glut.h>

void GLUTBackendInit(int argc, char** argv);

bool GLUTBackendCreateWindow(unsigned int Width, unsigned int Height, bool isFullScreen, const char* pTitle);

void GLUTBackendRun(Game::CCallbacks* pCallbacks);

#endif