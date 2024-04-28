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
    //TODO: ���⼭ �浹 ��Ʈ������ �����ؾ��մϴ�. ������ : ��  //  ū �� : ��

}

void CollisionManager::Reset()
{
    //TODO: ���⼭ �浹 ��Ʈ������ �����ؾ��մϴ�.
}
