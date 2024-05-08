#include "SampleObject.h"
#include "ResourceManager.h"
#include "InputSystem.h"
#include "RenderSystem.h"
#include "TimeSystem.h"
#include "Collider.h"

SampleObject::SampleObject() : _MyTex(nullptr)
{
	_MyTex = ResourceManager::GetInstance()->GetTexture(L"Charactor", L"CharactorTest.bmp");
	GameObject::CreateCollider();
	GetCollider()->SetScale(Vector3(_MyTex->Width(), _MyTex->Height(), 0));
	GetCollider()->SetOffset(Vector3(_MyTex->Width() / 2, _MyTex->Height() / 2, 0));
}

SampleObject::~SampleObject()
{
}

void SampleObject::Update()
{
	Vector3 dir(0, 0, 0);
	if (InputSystem::GetInstance()->isKey(VK_UP)) {
		dir += Vector3(0, -1, 0);
	}
	if (InputSystem::GetInstance()->isKey(VK_DOWN)) {
		dir += Vector3(0, 1, 0);
	}
	if (InputSystem::GetInstance()->isKey(VK_LEFT)) {
		dir += Vector3(-1, 0, 0);
	}
	if (InputSystem::GetInstance()->isKey(VK_RIGHT)) {
		dir += Vector3(1, 0, 0);
	}
	
	SetLocation(GetLocation() + dir * _MoveSpeed * TimeManager::GetInstance()->GetDeltaTime());
}

void SampleObject::Render()
{
	BitBlt(RenderSystem::GetInstance()->_backDC,
		GameObject::GetLocation()._x, GameObject::GetLocation()._y,
		_MyTex->Width(), _MyTex->Height(), _MyTex->GetDC(), 0, 0, SRCCOPY);
	ComponentRender();
}
