#ifndef __Game__
#define __Game__

#include "SDL.h"
#include "TextureManager.h"
#include "Player.h"

class Game
{
public:

	Game() {}
	~Game() {}

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void render();
	void update();
	void handleEvents();
	void clean();

	// a function to access the private running variable
	bool running() { return m_bRunning; }

	GameObject m_go;
	Player m_player;

private:
	bool m_bRunning;

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	int m_currentFrame;
};

#endif /* defined(__Game__) */