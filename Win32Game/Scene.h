#pragma once
#include "Vector.hpp"
#include "globalheader.h"
#include "GameObject.h"
#include "Win32GameProject.h"
#include "PathManager.h"
#include "globalheader.h"
#include "GameObject.h"

class Scene {
public:
	int count_x = 30, count_y = 20;

	Scene();
	virtual ~Scene();

	void SetSceneName(std::string& name) { _SceneName = name; }
	std::string GetSceneName() const { return _SceneName; }

	virtual void start() = 0;
	virtual void end() = 0;

	void update();
	void render(HDC _bdc);

protected:
	void AddObject(GameObject* obj, LAYER_GROUP layer) { _GameObjects[(int)layer].push_back(obj); }

private:
	std::vector<GameObject*> _GameObjects[(int)LAYER_GROUP::END];
	std::string _SceneName;
};