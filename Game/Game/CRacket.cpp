#include "CRacket.h"
#include <glut.h>

Game::CRacket::CRacket()
{
	_bActive = true;
	_bPause = false;
}

Game::CRacket::~CRacket()
{

}

void Game::CRacket::SetCoord(float _x, float _y)
{
	if (!_bPause)
	{
		x = _x;
		y = _y;
	}
}

void Game::CRacket::SetSize(float _w, float _h)
{
	_fWidth = _w;
	_fHeight = _h;
}

void Game::CRacket::SetPause(bool State)
{
	_bPause = State;
}

void Game::CRacket::SetState(bool State)
{
	_bActive = State;
}

void Game::CRacket::Draw(void)
{
	glBegin(GL_POLYGON);
	glColor3f(255, 255, 255);
	glVertex2f(x, y);
	glColor3f(255, 255, 255);
	glVertex2f(x + _fWidth, y);
	glColor3f(r, g, b);
	glVertex2f(x + _fWidth, y + _fHeight);
	glColor3f(r, g, b);
	glVertex2f(x, y + _fHeight);
	glEnd();
}

void Game::CRacket::SetColor(uint _r, uint _g, uint _b)
{
	r = _r;
	g = _g;
	b = _b;
}

unsigned int Game::CRacket::GetWidth(void)
{
	return _fWidth;
}

bool Game::CRacket::GetState(void)
{
	return _bActive;
}