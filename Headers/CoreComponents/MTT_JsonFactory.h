#pragma once
#include "MTT_GraphicalObject.h"
#include "MTT_LoadingArea.h"
#include <vector>


class MTT_JsonFactory
{

public:
	static std::vector<MTT_GraphicalObject*> listOfAssetsFromJsonFile(std::string relativePathToJsonFile);
	static std::vector<MTT_LoadingArea> listOfLoadingAreasFromJsonFile(std::string relativePathToJsonFile);

private:
	static MTT_GraphicalObject* objectFromString(std::string nameObject);

};