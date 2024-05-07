#include "Scene.h"

Scene::Scene() {
	_SceneName = "";
}
Scene::~Scene() {
	for (int i = 0; i < (int)LAYER_GROUP::END; i++) {
		for (int j = 0; j < _GameObjects[i].size(); j++) {
			if (_GameObjects[i][j] != nullptr) {
				delete _GameObjects[i][j];
			}
		}
	}
}

void Scene::update() {
	for (int i = 0; i < (int)LAYER_GROUP::END; i++) {
		for (int j = 0; j < _GameObjects[i].size(); j++) {
			if(_GameObjects[i][j]->Enable() == true) _GameObjects[i][j]->update();
		}
	}
}

void Scene::finalupdate()
{
	for (int i = 0; i < (int)LAYER_GROUP::END; i++) {
		for (int j = 0; j < _GameObjects[i].size(); j++) {
			if (_GameObjects[i][j]->Enable() == true) _GameObjects[i][j]->finalupdate();
		}
	}
}

void Scene::render() {
	for (int i = 0; i < (int)LAYER_GROUP::END; i++) {
		for (int j = 0; j < _GameObjects[i].size(); j++) {
			if (_GameObjects[i][j]->Enable() == true) _GameObjects[i][j]->render();
		}
	}
}

void Scene::SceneEnd()
{
	for (int i = 0; i < (int)LAYER_GROUP::END; i++) {
		for (int j = 0; j < _GameObjects[i].size(); j++) {
			if (_GameObjects[i][j] != nullptr) {
				delete _GameObjects[i][j];
			}
		}
	}
}
