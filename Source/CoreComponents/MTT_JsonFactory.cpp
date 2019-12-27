#include "../../Headers/CoreComponents/MTT_JsonFactory.h"
#include "../../rapidjson/document.h"
#include "../../rapidjson/istreamwrapper.h"
#include  <fstream>
#include "../../Headers/GameComponents/Cat.h"
#include <map>
#include <string>

using namespace rapidjson;


//That's going to be a bit rocky
//But oh boy it runs
template<typename T> MTT_GraphicalObject* createInstance() { return new T; }


std::vector<MTT_GraphicalObject*> MTT_JsonFactory::listOfAssetsFromJsonFile(std::string relativePathToJsonFile)
{

	std::ifstream ifs(relativePathToJsonFile);

	IStreamWrapper isw(ifs);
	Document d;
	d.ParseStream(isw);

	std::vector<MTT_GraphicalObject*> superMarioBrothersSuperShow; //it's the superMarioBrothersSuperShow! It contains all the assets.

	const Value& v = d["areaAssets"];
	for (SizeType i = 0; i < v.Size(); i++)
	{
		MTT_GraphicalObject* porgus = MTT_JsonFactory::objectFromString(v[i]["NameAsset"].GetString()); //just the object we are trying to fill rn.
																										//I was probably stoned when i did this so porgus seemed like a cool
																										//variable name.
		porgus->x = (v[i]["x"].GetInt());
		porgus->y = (v[i]["y"].GetInt());
		porgus->hitbox.x = porgus->x;
		porgus->hitbox.y = porgus->y;

		//I'll fucking do it again!
		const Value& interactiveTexts = v[i]["dialogues"];
		;
		for (SizeType ITSize = 0; ITSize < interactiveTexts.Size(); ITSize++)
		{
			porgus->textualInteractions.push_back(interactiveTexts[ITSize].GetString());
		}

		superMarioBrothersSuperShow.push_back(porgus);
	}

	return superMarioBrothersSuperShow;


	
}

std::vector<MTT_LoadingArea> MTT_JsonFactory::listOfLoadingAreasFromJsonFile(std::string relativePathToJsonFile)
{

	std::ifstream ifs(relativePathToJsonFile);

	IStreamWrapper isw(ifs);
	Document d;
	d.ParseStream(isw);

	std::vector<MTT_LoadingArea> areas;

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
		areas.push_back(area);
	}

	return areas;

}



MTT_GraphicalObject* MTT_JsonFactory::objectFromString(std::string nameObject)
{
	typedef std::map<std::string, MTT_GraphicalObject * (*)()> map_type;
	map_type map;
	map["Cat"] = &createInstance<Cat>;
	//Add more stuff here. We're just testing right now
	//This thing could be initialized statically but you know i'm lazy
	//Best performance will result of such choice tho

	return map[nameObject]();
}