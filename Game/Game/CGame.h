#ifndef _GAME_H
#define _GAME_H

#include "CApp.h"

namespace Game
{
	class CGame
	{
		private:
			static CGame *_pGame;
			CApp* _pApp;
			CGame();
			~CGame();
		public:
			void Run(int argc, char** argv, int Width, int Height, bool FuulScreen, const char* Title);
			static CGame* GetInstance(void);
			static void FreeInstance(void);
	};
};

#endif