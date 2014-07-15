#ifndef _BULLET_H
#define _BULLET_H

#include "GameTypes.h"
#include <cmath>
#include <glut.h>

namespace Game
{
	struct TBullet
	{
	private:
		float x, y, r, dy;
		bool _bState;
		uint cr, cg, cb;
	public:
		TBullet() {}
		~TBullet() {}
		TBullet(float _x, float _y, float _r, float _dy, uint _cr, uint _cg, uint _cb)
		{
			dy = _dy;
			x = _x;
			y = _y;
			r = _r;

			cr = _cr;
			cg = _cg;
			cb = _cb;
		}
		void Draw(void)
		{
			glBegin(GL_TRIANGLE_FAN);
			glColor3f(1, 1, 1);
			glVertex2f(x, y);
			glColor3ub(cr, cg, cb);
			for (float i = 0; i < 2 * 3.14; i += 3.14 / 36)
				glVertex2f(x + r * sin(i), y + r * cos(i));
			glEnd();
		}
		void SetState(bool State) { _bState = State; }
		void SetColor(uint _r, uint _g, uint _b)
		{
			cr = _r;
			cg = _g;
			cb = _b;
		}
		bool GetState(void) { return _bState; }
		void Move(void)
		{
			y -= dy;

			if (y - r < 0)
				_bState = false;
		}
	};
};

#endif