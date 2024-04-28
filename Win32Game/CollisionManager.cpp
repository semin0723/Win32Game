#include "CollisionManager.h"

CollisionManager* CollisionManager::instance = nullptr;

CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{
}

CollisionManager* CollisionManager::GetInstance()
{
    if (instance == nullptr) {
        instance = new CollisionManager;
    }
    return instance;
}

void CollisionManager::DestroyInstance()
{
    delete instance;
    instance = nullptr;
}

void CollisionManager::Init()
{
}

void CollisionManager::update()
{
}

void CollisionManager::CheckGroup(LAYER_GROUP a, LAYER_GROUP b)
{
    //TODO: 여기서 충돌 매트릭스를 설정해야합니다. 작은값 : 행  //  큰 값 : 열

}

void CollisionManager::Reset()
{
    //TODO: 여기서 충돌 매트릭스를 해제해야합니다.
}
