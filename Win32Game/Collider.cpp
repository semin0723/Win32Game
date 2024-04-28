#include "Collider.h"
#include "RenderSystem.h"

Collider::Collider() : _owner(nullptr)
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
