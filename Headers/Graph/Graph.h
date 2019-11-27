#pragma once
#include <SDL.h>
class Graph
{

public:
	Graph(SDL_Renderer* renderer);
	virtual void update() = 0;

protected : 
	SDL_Renderer* renderer;

private :

	virtual void load()= 0;
};