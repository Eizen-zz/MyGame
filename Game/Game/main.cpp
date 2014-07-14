#include "MainGame.h"

using namespace Game;

int main(int argc, char** argv)
{
	CGame* Game = CGame::GetInstance();
	Game->Run(argc, argv, WindowWidth, WindowHeight, false, "Game");
	return 0;
}