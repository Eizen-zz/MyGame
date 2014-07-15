#include "CRacket.h"

Game::CRacket::CRacket()
{
	_bActive = true;
	_bPause = false;
	_bRacketBoomBonus = false;
	_bRacketLongBonus = false;
	_bLeftState = false;
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
	w = _w;
	h = _h;
}

void Game::CRacket::SetBoomBomus(bool State)
{
	_bRacketBoomBonus = State;
}

void Game::CRacket::SetLongBonus(bool State)
{
	_bRacketLongBonus = State;
}

void Game::CRacket::SetPause(bool State)
{
	_bPause = State;
}

void Game::CRacket::SetState(bool State)
{
	_bActive = State;
}

void Game::CRacket::SetLeftState(bool State)
{
	_bLeftState = State;
}

void Game::CRacket::Draw(void)
{
	if (_bRacketLongBonus)
	{
		// Call to function the length of the racket
	}

	if (_bRacketBoomBonus)
	{
		// Call to function
	}

	glBegin(GL_POLYGON);
	glColor3f(255, 255, 255);
	glVertex2f(x, y);
	glColor3f(255, 255, 255);
	glVertex2f(x + w, y);
	glColor3f(r, g, b);
	glVertex2f(x + w, y + h);
	glColor3f(r, g, b);
	glVertex2f(x, y + h);
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
	return w;
}

bool Game::CRacket::GetState(void)
{
	return _bActive;
}