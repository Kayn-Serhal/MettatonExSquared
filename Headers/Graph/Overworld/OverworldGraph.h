#pragma once
#include "../Graph.h"
#include "../../CoreComponents/MTT_Texture.h"
#include "../../GameComponents/Player/Player.h"
#include "../../GameComponents/Cat.h"
#include "../../CoreComponents/MTT_LoadingArea.h"
#include "../../../rapidjson/rapidjson.h"
#include "../../../rapidjson/document.h"
#include "../../../rapidjson/stringbuffer.h"
#include "../../../rapidjson/prettywriter.h"
#include <string>



class OverworldGraph : public Graph
{
public:

	const std::string LEVEL_FOLDER_ROOT = "OW_area\\";
	const std::string LOADINGAREAS_FILE = "loadingAreas.json";
	const std::string ASSETS_DEFINITION_FILE = "areaAssets.json";
	const std::string BACKGROUND_FILE = "bg.png"; 
	

	OverworldGraph(SDL_Renderer* r) : Graph(r) {
		this->load();
	}

	OverworldGraph(std::string area, int id, SDL_Renderer* r) : Graph(r) {

		this->id = id;
		this->area = area;
		//Go on folder
		//Retrieve data and put it in the class
		//for now loadingAreas will suffice

	}


	//Should be equal to the biggest size of background image
	int LEVELWIDTH = 1000; 
	int LEVELHEIGHT = 1000;

	void update();

	void load();

	void free();
	

	Player* player = 0;
	Cat* aRandomCat = 0;


	std::vector<MTT_LoadingArea> loadingAreas;


private:

	void checkIfPlayerIsTryingToGoOutOfBoundsBecauseHeIsProllyADumbass();
	void checkIfCameraIsTryingToGoOutOfBounds();
	std::string area;
	int id=1;

	MTT_Texture backGroundTexture;


};