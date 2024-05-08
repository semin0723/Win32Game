#include "SampleObject.h"
#include "ResourceManager.h"
#include "InputSystem.h"
#include "RenderSystem.h"
#include "TimeSystem.h"
#include "Collider.h"

SampleObject::SampleObject() : _myTex(nullptr)
{
	_myTex = ResourceManager::GetInstance()->GetTexture(L"Charactor", L"CharactorTest.bmp");
	GameObject::CreateCollider();
	GetCollider()->SetScale(Vector3(_myTex->Width(), _myTex->Height(), 0));
	GetCollider()->SetOffset(Vector3(_myTex->Width() / 2, _myTex->Height() / 2, 0));
}

SampleObject::~SampleObject()
{
}

void SampleObject::update()
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
	
	SetLocation(GetLocation() + dir * MoveSpeed * TimeManager::GetInstance()->GetDeltaTime());
}

void SampleObject::render()
{
	BitBlt(RenderSystem::GetInstance()->_backDC,
		GameObject::GetLocation()._x, GameObject::GetLocation()._y,
		_myTex->Width(), _myTex->Height(), _myTex->GetDC(), 0, 0, SRCCOPY);
	ComponentRender();
}
