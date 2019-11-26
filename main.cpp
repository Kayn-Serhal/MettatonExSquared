#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <stdio.h>
#include <SDL_mixer.h>
#include <sstream>
#include "Headers\GraphicHandler.h"
#include "Headers\GameStateHandler.h"
#include "Headers\GameLoader.h"



using namespace std;

const int SWIDTH = 640;
const int SHEIGHT = 480;

const int SCREEN_FPS = 60;


/*Startup procedure*/
bool init();
bool initWindow();
bool initRenderer();
bool initAddOns();


bool initialLoad();

void gamePlayLoop(SDL_Event event, GamePlayState state);

void refreshScreen();

void close();


bool init()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		printf("An error occured when trying to load SDL. %s", SDL_GetError());
		return false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {

		}
		else
		{
			initWindow();
			initRenderer();
			initAddOns();
		}
	}
}

bool initWindow()
{

	SDL_Window* futureGameWindow = SDL_CreateWindow("MettatonExSquared", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SWIDTH, SHEIGHT, SDL_WINDOW_SHOWN);
	if (futureGameWindow == NULL)
	{
		printf("Something went wrong when trying to build the window. %s", SDL_GetError());
		return false;
	}
	GraphicHandler::gameWindow = futureGameWindow;
	return true;
}

bool initRenderer()
{
	if (GraphicHandler::gameWindow == NULL)
	{
		printf("Well, currently there isn't any window created, so it might be difficult to set a renderer to it? Dumbass");
		return false;
	}
	SDL_Renderer* futureGameRenderer = SDL_CreateRenderer(GraphicHandler::gameWindow, -1, SDL_RENDERER_ACCELERATED);
	if (futureGameRenderer == NULL) {
		printf("Something went wrong when trying to initialize the renderer. %s", SDL_GetError());
		return false;
	}
	GraphicHandler::gameRenderer=futureGameRenderer;
	return true;

}

bool initAddOns()
{
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("the addon SDL_Image can't load properly. Error %s", IMG_GetError());
		return false;
	}
	if (TTF_Init() == -1)
	{
		printf("Well, the addon managing the fonts is acting up. Error %s", TTF_GetError());
		return false;
	}
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("The sound addon is not gonna let you use it, i'm afraid. Error %s", Mix_GetError());
		return false;
	}
	return true;
}

bool initialLoad()
{
	GameStateHandler::currentGamePlayState = GamePlayState::LOADING;
	//LoadSomeShit
	GameStateHandler::currentGamePlayState = GamePlayState::MOCKTITLE;
	return true;
}

void gamePlayLoop(SDL_Event e,GamePlayState state)
{
	GameLoader::loadScene(state);

}

void refreshScreen()
{
	SDL_RenderPresent(GraphicHandler::gameRenderer);

}

void close()
{
}

int main(int argc, char* args[]) 
{
	init();
	initialLoad();
	bool quit = false;
	SDL_Event e;
	GamePlayState lastState = GamePlayState::LOADING; //We do that in order to force an update in the gameplayLoop

	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT)
				quit = true;
			gamePlayLoop(e, lastState);
		}
		refreshScreen();

	}
	close();
	return 0;
}