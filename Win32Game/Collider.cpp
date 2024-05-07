#include "Collider.h"
#include "RenderSystem.h"

UINT Collider::_NextID = 0;

Collider::Collider() : _owner(nullptr), _ID(_NextID++)
{
}

Collider::Collider(const Collider& origin) :
	_owner(nullptr),
	_Offset(origin._Offset),
	_Scale(origin._Scale),
	_ID(_NextID++)
{

}

Collider::~Collider()
{
}

void Collider::finalupdate()
{
	Vector3 objpos = _owner->GetLocation();
	_ColliderPos = objpos + _Offset;
}

void Collider::render()
{
	HPEN greenpen = RenderSystem::GetInstance()->GetPen(PEN_TYPE::GREEN);
	HPEN oldpen = (HPEN)SelectObject(RenderSystem::GetInstance()->_backDC, greenpen);

	HBRUSH hollowbrush = RenderSystem::GetInstance()->GetBrush(BRUSH_TYPE::HOLLOW);
	HBRUSH oldbrush = (HBRUSH)SelectObject(RenderSystem::GetInstance()->_backDC, hollowbrush);

	Rectangle(RenderSystem::GetInstance()->_backDC,
		(int)(_ColliderPos._x - _Scale._x / 2.f),
		(int)(_ColliderPos._y - _Scale._y / 2.f),
		(int)(_ColliderPos._x + _Scale._x / 2.f),
		(int)(_ColliderPos._y + _Scale._y / 2.f)
		);

	SelectObject(RenderSystem::GetInstance()->_backDC, oldpen);
	SelectObject(RenderSystem::GetInstance()->_backDC, oldbrush);
	
}

void Collider::OnCollisionEnter(Collider* collider)
{

}

void Collider::OnCollision(Collider* collider)
{

}

void Collider::OnCollisionExit(Collider* collider)
{

}
