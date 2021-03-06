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

		std::ifstream ifs(this->pathAssets + LOADINGAREAS_FILE);
		IStreamWrapper isw(ifs);
		Document d;
		d.ParseStream(isw);
		
		const Value& v = d["loadingAreas"];
		for (SizeType i = 0; i < v.Size(); i++)
		{
			MTT_LoadingArea area;
			area.loadingAreaCoordinates.h = v[i]["loadingAreaCoordinates"]["h"].GetInt();
			area.loadingAreaCoordinates.w = v[i]["loadingAreaCoordinates"]["w"].GetInt();
			area.loadingAreaCoordinates.x = v[i]["loadingAreaCoordinates"]["x"].GetInt();
			area.loadingAreaCoordinates.y = v[i]["loadingAreaCoordinates"]["y"].GetInt();

			area.zoneOfDestination = v[i]["zoneOfDestination"].GetString();
			area.subZoneOfDestination = v[i]["subZoneOfDestination"].GetString();
			area.destinationX = v[i]["destinationX"].GetInt();
			area.destinationY = v[i]["destinationY"].GetInt();
			this->loadingAreas.push_back(area);
		}
		

		this->load();

		
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
	std::string subArea;
	std::string pathAssets;

	MTT_Texture backGroundTexture;


};