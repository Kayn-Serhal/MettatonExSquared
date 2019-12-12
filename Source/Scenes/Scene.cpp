#pragma once
#include "../../Headers/Scenes/Scene.h"

Scene::Scene(Graph* g, Logic* l) {
	this->graphical = g;
	this->logical = l;
}

Scene::~Scene()
{
	this->logical->free();
	this->graphical->free();
	delete this->logical;
	delete this->graphical;
	this->logical = NULL;
	this->graphical = NULL;
}



