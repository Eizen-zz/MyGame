#ifndef _APP_H
#define _APP_H

#include "GLUT_Backend.h"

namespace Game
{
	class CApp : public CCallbacks
	{
		private:
			static CApp *_pApp;
			CApp();
			~CApp();
		public:
			void Run(void);
			static CApp* GetApp(void);
			static void  FreeApp(void);
			virtual void SpecialKeyboard(int Key, int x, int y);
			virtual void Keyboard(unsigned char Key, int x, int y);
			virtual void PassiveMouse(int x, int y);
			virtual void Draw(void);
			virtual void Idle(void);
	};
};

#endif