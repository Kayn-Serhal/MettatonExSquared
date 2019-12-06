#pragma once
#include <string>
#include <SDL.h>


class MTT_Texture
{
public:
	MTT_Texture();
	~MTT_Texture();

	bool loadFromFile(std::string path, SDL_Renderer* renderer);
	bool loadFromFile(std::string path, SDL_Renderer* renderer, int r, int g, int b);
	void free();

	void render(int x, int y, SDL_Rect* clip, SDL_Renderer* renderer);

	int getWidth();
	int getHeight();


private:
	SDL_Texture* hardwareTexture;

	int width;
	int height;
};