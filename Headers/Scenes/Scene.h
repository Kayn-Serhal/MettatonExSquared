#pragma once
#include "../Graph/Graph.h"
#include "../Logic/Logic.h"

class Scene {
public:
	virtual void display();
	Scene(Graph* g, Logic* l);

protected:
	Graph* graphical;
	Logic* logical;
	
};
