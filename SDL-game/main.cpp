#include "Game.h"

// remove when release
//#include "Windows.h"
#include <iostream>
// end of remove when release

// our Game object
Game* g_game = 0;

int main(int argc, char* argv[])
{
	// std::cout << "test";
	// remove when release
	//AllocConsole();
	//freopen("CON", "w", stdout);
	// end of remove when release

	g_game = new Game();

	g_game->init("Chapter 1", 100, 100, 640, 480, false);

	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}
	
	g_game->clean();

	return 0;
}