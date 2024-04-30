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
    //��� ���̾� ���� ���鼭 �浹������ üũ �ؾ� �մϴ�.
    //CollisionMatrix�� ���鼭 & �� CollisionGroupUpdate() ȣ��
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
    //���⼭ �浹 ��Ʈ������ �����ؾ��մϴ�. ������ : ��  //  ū �� : ��
    _CollisionMatrix[(int)min(a, b)] ^= (1 << (int)max(a, b));
}

void CollisionManager::CollisionGroupUpdate(LAYER_GROUP a, LAYER_GROUP b)
{
    //���� ������ �ش��ϴ� �׷��� ������Ʈ���� ���� �����ͼ� ���⼭ ������Ʈ ���ݴϴ�.
    //vector<GameObject*> Ÿ���� ���� �޾ƿ;� �մϴ�.
    const Scene* curScene = SceneManager::GetInstance()->GetCurScene();

    const std::vector<GameObject*>& groupA = curScene->GetGroupObject(a);
    const std::vector<GameObject*>& groupB = curScene->GetGroupObject(b);

    //TODO: �浹ü�� �ִ� ������Ʈ�� �浹�� �˻��ؾ� �մϴ�.
    //TODO: ������ �浹ü�� ���� �浹�� �����ϴ� ���� ���� �ؾ��մϴ�.
    for (int i = 0; i < groupA.size(); i++) {
        if (groupA[i]->GetCollider() == nullptr) continue;
        for (int j = 0; j < groupB.size(); i++) {
            if (groupB[i]->GetCollider() == nullptr || groupA[i] == groupB[j]) {
                continue;
            }

            //TODO: ���� �������� �浹 ������ ������ �ͼ� �浹 ���¸� �Ǵ��մϴ�.
            if (OnCollisionEnter(groupA[i]->GetCollider(), groupB[j]->GetCollider())) {

            }
            else {

            }

        }
    }
}

bool CollisionManager::OnCollisionEnter(Collider* a, Collider* b)
{
    //TODO: ���⼭ Collider���� �浹�� üũ �ؾ� �մϴ�.
    return false;
}
