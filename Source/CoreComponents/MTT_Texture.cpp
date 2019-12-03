#pragma once
#include "../../Headers/CoreComponents/MTT_Texture.h"
#include <SDL_image.h>


MTT_Texture::MTT_Texture()
{
	hardwareTexture = NULL;
	width = 0;
	height = 0;
}

MTT_Texture::~MTT_Texture()
{
	free();
}

bool MTT_Texture::loadFromFile(std::string path,SDL_Renderer* renderer)
{
	free();

	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			width = loadedSurface->w;
			height = loadedSurface->h;
		}
		SDL_FreeSurface(loadedSurface);
	}

	hardwareTexture = newTexture;
	return hardwareTexture != NULL;
}

bool MTT_Texture::loadFromFile(std::string path, SDL_Renderer* renderer, int r, int g, int b)
{
	free();

	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Transparency policy
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, r, g, b));

		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			width = loadedSurface->w;
			height = loadedSurface->h;
		}
		SDL_FreeSurface(loadedSurface);
	}

	hardwareTexture = newTexture;
	return hardwareTexture != NULL;
}

void MTT_Texture::free()
{
	if (hardwareTexture != NULL)
	{
		SDL_DestroyTexture(hardwareTexture);
		hardwareTexture = NULL;
		width = 0;
		height = 0;
	}
}


void MTT_Texture::render(int x, int y, SDL_Rect* clip, SDL_Renderer* renderer)
{
	SDL_Rect renderQuad = { x, y, width, height };

	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	
	SDL_RenderCopy(renderer, hardwareTexture, clip, &renderQuad);
}

int MTT_Texture::getWidth()
{
	return width;
}

int MTT_Texture::getHeight()
{
	return height;
}
