#include "../../Headers/CoreComponents/MTT_JsonFactory.h"
#include "../../rapidjson/document.h"
#include "../../rapidjson/istreamwrapper.h"
#include  <fstream>

using namespace rapidjson;

std::vector<MTT_GraphicalObject*> MTT_JsonFactory::listOfAssetsFromJsonFile(std::string relativePathToJsonFile)
{
	return std::vector<MTT_GraphicalObject*>();
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
