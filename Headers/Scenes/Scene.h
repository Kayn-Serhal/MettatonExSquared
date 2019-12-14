#pragma once
#include "../Graph/Graph.h"
#include "../Logic/Logic.h"

class Scene {
public:
	Scene(Graph* g, Logic* l);
	Logic* logical;
	virtual void free() = 0;
	~Scene();
protected:
	Graph* graphical;

	
};
