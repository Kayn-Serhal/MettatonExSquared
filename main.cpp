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
#include "Headers/InputHandler.h"






//MettatonSquared v0.0.1
//The goal? Try to make a prototype of a brand new fighting system for RPGs!
//For that, i will first try to remade the undertale combat system using SDL.
//Then, it will be Deltarune...
//And from that, i will try to implement mine.
//Mettaton EX will be the dummy enemy that i will use for this demo.
//I mean...
//You can't have too much Mettaton, and this is going to take a while...
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

void gamePlayLoop();

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

	return true;
}

bool initWindow()
{

	SDL_Window* futureGameWindow = SDL_CreateWindow("MettatonExSquared", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SWIDTH, SHEIGHT, SDL_WINDOW_SHOWN);
	if (futureGameWindow == NULL)
	{
		printf("Something went wrong when trying to build the window. %s", SDL_GetError());
		return false;
	}
	Graphics::graphicHandler.gameWindow = futureGameWindow;
	return true;
}

bool initRenderer()
{
	if (Graphics::graphicHandler.gameWindow == NULL)
	{
		printf("Well, currently there isn't any window created, so it might be difficult to set a renderer to it? Dumbass");
		return false;
	}
	SDL_Renderer* futureGameRenderer = SDL_CreateRenderer(Graphics::graphicHandler.gameWindow, -1, SDL_RENDERER_ACCELERATED);
	if (futureGameRenderer == NULL) {
		printf("Something went wrong when trying to initialize the renderer. %s", SDL_GetError());
		return false;
	}
	Graphics::graphicHandler.gameRenderer = futureGameRenderer;
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
	GameStateHandler::currentGamePlayState = GamePlayState::MOCKTITLE;
	GameLoader::loadScene(GamePlayState::MOCKTITLE);
	return true;
}

void gamePlayLoop()
{
	Graphics::graphicHandler.update();

}

void refreshScreen()
{
	SDL_RenderPresent(Graphics::graphicHandler.gameRenderer);
}

void close()
{
}

void processEvents(Uint32* lastTime)
{
	#define TICKSNEXTFRAME (1000/60)
	if (SDL_GetTicks() - *lastTime > TICKSNEXTFRAME) {
		const Uint8* k = SDL_GetKeyboardState(NULL);
		Inputs::inputHandler.handleEvent(k);
		*lastTime = SDL_GetTicks();
	}
}

int main(int argc, char* args[]) 
{
	init();
	initialLoad();
	bool quit = false;
	SDL_Event e;
	GamePlayState lastState = GamePlayState::LOADING; //We do that in order to force an update in the gameplayLoop

	Uint32 lastTime = 0;
	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT)
				quit = true;
		}
		processEvents(&lastTime);
		gamePlayLoop();
		refreshScreen();
	}
	close();
	return 0;
}