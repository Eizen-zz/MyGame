#include "CTexture.h"
#include "GameTypes.h"

Game::CTexture::CTexture()
{
	_bAllowDraw = false;
}

Game::CTexture::~CTexture()
{
	if (_pTexture)
		delete _pTexture;
	_pTexture = nullptr;
}

void Game::CTexture::LoadTexture(const char* FileName)
{
	_pTexture = auxDIBImageLoadA(FileName);
	glGenTextures(1, &texture[0]);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, _pTexture->sizeX, _pTexture->sizeY,
							 0, GL_RGB, GL_UNSIGNED_BYTE, _pTexture->data);

	_bAllowDraw = true;
}

void Game::CTexture::Draw(float min_x, float max_x, float min_y, float max_y)
{
	if (_bAllowDraw)
	{
		_fTextureMin_x = min_x;
		_fTextureMax_x = max_x;
		_fTextureMin_y = min_y;
		_fTextureMax_y = max_y;

		glColor3f(1, 1, 1);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glBegin(GL_QUADS);
			glTexCoord2f(0, 0); glVertex2f(min_x, min_y);
			glTexCoord2f(0, 1); glVertex2f(min_x, max_y);
			glTexCoord2f(1, 1); glVertex2f(max_x, max_y);
			glTexCoord2f(1, 0); glVertex2f(max_x, min_y);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glColor3f(1, 1, 1);
	}
}

void Game::CTexture::AllowLoading(bool State)
{
	_bAllowDraw = State;
}

bool Game::CTexture::isMouseOnTexture(float x, float y)
{
	return (((x > _fTextureMin_x) && (x < _fTextureMax_x)) &&
		   ((y < _fTextureMin_y) && (y > _fTextureMax_y)));
}

float Game::CTexture::GetWidth(void)
{
	return _pTexture->sizeX;
}

float Game::CTexture::GetHeight(void)
{
	return _pTexture->sizeY;
}

bool Game::CTexture::GetState(void)
{
	return _bAllowDraw;
}