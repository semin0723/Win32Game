#include "CollisionManager.h"
#include "SceneManager.h"
#include "Scene.h"
#include "GameObject.h"
#include "globalheader.h"


CollisionManager* CollisionManager::instance = nullptr;

CollisionManager::CollisionManager() : _CollisionMatrix{}
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
    //모든 레이어 행을 돌면서 충돌중인지 체크 해야 합니다.
    //CollisionMatrix를 돌면서 & 면 CollisionGroupUpdate() 호출
    for (int row = 0; row < (int)LAYER_GROUP::END; row++) {
        for (int col = row; col < (int)LAYER_GROUP::END; col++) {
            if (_CollisionMatrix[row] & (1 << col)) {
                CollisionGroupUpdate((LAYER_GROUP)row, (LAYER_GROUP)col);
            }
        }
    }

}

void CollisionManager::CheckGroup(LAYER_GROUP a, LAYER_GROUP b)
{
    //여기서 충돌 매트릭스를 설정해야합니다. 작은값 : 행  //  큰 값 : 열
    _CollisionMatrix[(int)min(a, b)] ^= (1 << (int)max(a, b));
}

void CollisionManager::CollisionGroupUpdate(LAYER_GROUP a, LAYER_GROUP b)
{
    //현재 씬에서 해당하는 그룹의 오브젝트들을 전부 가져와서 여기서 업데이트 해줍니다.
    //vector<GameObject*> 타입의 값을 받아와야 합니다.
    const Scene* curScene = SceneManager::GetInstance()->GetCurScene();

    const std::vector<GameObject*>& groupA = curScene->GetGroupObject(a);
    const std::vector<GameObject*>& groupB = curScene->GetGroupObject(b);

    //TODO: 충돌체가 있는 오브젝트만 충돌을 검사해야 합니다.
    //TODO: 동일한 충돌체가 서로 충돌을 감지하는 일이 없게 해야합니다.
    for (int i = 0; i < groupA.size(); i++) {
        if (groupA[i]->GetCollider() == nullptr) continue;
        for (int j = 0; j < groupB.size(); i++) {
            if (groupB[i]->GetCollider() == nullptr || groupA[i] == groupB[j]) {
                continue;
            }

            //TODO: 이전 프레임의 충돌 정보를 가지고 와서 충돌 상태를 판단합니다.
            if (OnCollisionEnter(groupA[i]->GetCollider(), groupB[j]->GetCollider())) {

            }
            else {

            }

        }
    }
}

bool CollisionManager::OnCollisionEnter(Collider* a, Collider* b)
{
    //TODO: 여기서 Collider끼리 충돌을 체크 해야 합니다.
    return false;
}
