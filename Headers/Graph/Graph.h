#pragma once
#include <SDL.h>
#include "Camera.h"
class Graph
{

public:
	Graph(SDL_Renderer* renderer);
	virtual void update() = 0;

protected : 
	SDL_Renderer* renderer;
	virtual void load() = 0;
	Camera camera;



};