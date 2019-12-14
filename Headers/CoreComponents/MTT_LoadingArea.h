#pragma once
#include <SDL.h>
#include <string>

class MTT_LoadingArea
{

public: 
	SDL_Rect loadingAreaCoordinates;
	std::string zoneOfDestination;
	std::string subZoneOfDestination;

	int destinationX; //The x value of the player in the new area
	int destinationY; //The y value of the new area
};