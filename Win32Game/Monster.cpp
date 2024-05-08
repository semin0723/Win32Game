#include "Monster.h"
#include "ResourceManager.h"
#include "RenderSystem.h"
#include "Collider.h"

Monster::Monster() : _MyTex(nullptr)
{
	_MyTex = ResourceManager::GetInstance()->GetTexture(L"Monster", L"CharactorTest.bmp");
	CreateCollider();
	GetCollider()->SetScale(Vector3(_MyTex->Width(), _MyTex->Height(), 0));
	GetCollider()->SetOffset(Vector3(_MyTex->Width() / 2, _MyTex->Height() / 2, 0));
}

Monster::~Monster()
{
}

void Monster::Update()
{
}

void Monster::Render()
{
	BitBlt(RenderSystem::GetInstance()->_backDC,
		GameObject::GetLocation()._x, GameObject::GetLocation()._y,
		_MyTex->Width(), _MyTex->Height(), _MyTex->GetDC(), 0, 0, SRCCOPY);

	ComponentRender();
}
