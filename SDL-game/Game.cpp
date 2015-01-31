#include "Game.h"
#include <SDL_image.h>

// remove when release
#include <iostream>
// end of remove when release


typedef TextureManager TheTextureManager;

bool Game::init(const char* title, int xpos, int ypos, int width,
	int height, bool fullscreen)
{
	// attempt to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		int flags = 0;

		if (fullscreen)
		{
			flags = SDL_WINDOW_FULLSCREEN;
		}
		std::cout << "SDL init success\n";
		// init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (m_pWindow != 0) // window init success
		{
			std::cout << "window creation success\n";
			//m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_SOFTWARE);
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0) //renderer init success
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer,
					0, 0, 0, 255);
			}
			else
			{
				std::cout << "renderer init fail\n";
				return false; // renderer init fail
			}
		}
		else
		{
			std::cout << "window init fail\n";
			return false; // window init fail
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false; // SDL init fail
	}
	std::cout << "init success\n";
	m_bRunning = true; // everything inited successfully,
	// start the main loop

	// to load
	if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
	{
		return false;
	}

	// to draw
	TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82, m_pRenderer);

	//SDL_TextureManager.load("assets/animate-alpha.png", "animate", m_pRenderer);
	SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);

	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color

	TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82, m_pRenderer);
	TheTextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);
	//SDL_TextureManager.draw("animate", 0, 0, 128, 82, m_pRenderer);
	//SDL_TextureManager.drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);

	SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Game::handleEvents()
{

}