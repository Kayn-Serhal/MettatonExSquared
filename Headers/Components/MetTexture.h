#pragma once
#include <string>
#include <SDL.h>


class MetTexture
{
public:
	MetTexture();

	~MetTexture();

	bool loadFromFile(std::string path, SDL_Renderer* renderer);

	void free();


	void render(int x, int y, SDL_Rect* clip, SDL_Renderer* renderer);

	int getWidth();
	int getHeight();

private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;
};