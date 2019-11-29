#pragma once
#include "../../Headers/Components/MetTexture.h"
#include <SDL_image.h>


MetTexture::MetTexture()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

MetTexture::~MetTexture()
{
	free();
}

bool MetTexture::loadFromFile(std::string path,SDL_Renderer* renderer)
{
	free();

	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

bool MetTexture::loadFromFile(std::string path, SDL_Renderer* renderer, int r, int g, int b)
{
	free();

	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, r, g, b));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

void MetTexture::free()
{
	//Free texture if it exists
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}


void MetTexture::render(int x, int y, SDL_Rect* clip, SDL_Renderer* renderer)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	
	SDL_RenderCopy(renderer, mTexture, clip, &renderQuad);
}

int MetTexture::getWidth()
{
	return mWidth;
}

int MetTexture::getHeight()
{
	return mHeight;
}

void MetTexture::setBlendMode(SDL_BlendMode blending)
{
	SDL_SetTextureAlphaMod(mTexture, blending);
}

SDL_Texture* MetTexture::getSDLTexture()
{
	return mTexture;
}
