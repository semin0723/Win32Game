#include "SampleScene.h"
#include "SampleObject.h"

SampleScene::SampleScene()
{
}

SampleScene::~SampleScene()
{
}

void SampleScene::start()
{
	GameObject* sample = new SampleObject;
	sample->SetLocation(Vector3(100, 100, 0));
	AddObject(sample, LAYER_GROUP::DEFAULT);
}

void SampleScene::end()
{
	Scene::SceneEnd();
}
