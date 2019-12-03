#pragma once
#include "../../Headers/Components/MTT_Texture.h"
#include <SDL_image.h>


MTT_Texture::MTT_Texture()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

MTT_Texture::~MTT_Texture()
{
	free();
}

bool MTT_Texture::loadFromFile(std::string path,SDL_Renderer* renderer)
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

bool MTT_Texture::loadFromFile(std::string path, SDL_Renderer* renderer, int r, int g, int b)
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

void MTT_Texture::free()
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


void MTT_Texture::render(int x, int y, SDL_Rect* clip, SDL_Renderer* renderer)
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

int MTT_Texture::getWidth()
{
	return mWidth;
}

int MTT_Texture::getHeight()
{
	return mHeight;
}

void MTT_Texture::setBlendMode(SDL_BlendMode blending)
{
	SDL_SetTextureAlphaMod(mTexture, blending);
}

SDL_Texture* MTT_Texture::getSDLTexture()
{
	return mTexture;
}
