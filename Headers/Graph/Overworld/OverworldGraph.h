#pragma once
#include "../Graph.h"
#include "../../CoreComponents/MTT_Texture.h"
#include "../../GameComponents/Player/Player.h"
#include "../../GameComponents/Cat.h"
#include "../../CoreComponents/MTT_LoadingArea.h"
#include "../../../rapidjson/document.h"
#include  <fstream>
#include "../../../rapidjson/istreamwrapper.h"
#include <string>
#include "../../CoreComponents/MTT_JsonFactory.h"

using namespace rapidjson;

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

	OverworldGraph(std::string area, std::string subArea, SDL_Renderer* r) : Graph(r) {

		this->subArea = subArea;
		this->area = area;

		this->pathAssets = LEVEL_FOLDER_ROOT + this->area + "\\" + this->subArea + "\\";

		this ->loadingAreas = MTT_JsonFactory::listOfLoadingAreasFromJsonFile(this->pathAssets +LOADINGAREAS_FILE);
		

		this->load();

	}


	//Should be equal to the biggest size of background image
	int LEVELWIDTH = 1000; 
	int LEVELHEIGHT = 1000;

	void update();

	void load();

	void free();
	

	Player* player = 0;


	std::vector<MTT_LoadingArea> loadingAreas;
	std::vector<MTT_GraphicalObject*> areaAssets;


private:

	void checkIfPlayerIsTryingToGoOutOfBoundsBecauseHeIsProllyADumbass();
	void checkIfCameraIsTryingToGoOutOfBounds();
	std::string area;
	std::string subArea;
	std::string pathAssets;

	MTT_Texture backGroundTexture;
};