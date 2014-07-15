#ifndef _CALLBACKS_H
#define _CALLBACKS_H

namespace Game
{
	class CCallbacks
	{
		public:
			virtual void SpecialKeyboard(int Key, int x, int y) = 0;
			virtual void Keyboard(unsigned char Key, int x, int y) = 0;
			virtual void PassiveMouse(int x, int y) = 0;
			virtual void Draw(void) = 0;
			virtual void Idle(void) = 0;
			virtual void Mouse(int button, int state, int x, int y) = 0;
	};

};

#endif /* CALLBACKS_H */