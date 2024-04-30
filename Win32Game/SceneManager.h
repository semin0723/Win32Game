#pragma once
#include "globalheader.h"

class Scene;

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	static SceneManager* GetInstance();
	static void DestroyInstance();
	void InitScene();
	void update();
	void render();
	void LoadScene(int idx);
	const Scene* GetCurScene() const { return _curScene; }

private:
	static SceneManager* instance;
	Scene* _Scenes[(int)SCENE_LAYER::END];
	Scene* _curScene;
};

