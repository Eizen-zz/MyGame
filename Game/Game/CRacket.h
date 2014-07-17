#ifndef _RACKET_H
#define _RACKET_H

#include "GameTypes.h"

namespace Game
{
	class CRacket
	{
	private:
		float x, y, _fWidth, _fHeight;
		uint r, g, b;
		bool _bActive, _bPause;
	public:
		CRacket();
		~CRacket();
		void SetSize(float _w, float _h);
		void SetCoord(float _x, float _y);
		void Draw(void);
		void SetState(bool State);
		void SetColor(uint _r, uint _g, uint _b);
		void SetPause(bool State);
		bool GetState(void);
		unsigned int GetWidth(void);
	};
}

#endif