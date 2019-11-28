#pragma once
#include "../Graph/Graph.h"
#include "../Logic/Logic.h"

class Scene {
public:
	virtual void update() = 0;
	Scene(Graph* g, Logic* l);
	Logic* logical;
protected:
	Graph* graphical;

	
};
