#pragma once
#include "Vector3.h"
#include "GameObject.h"

class GameObjcet;

class Collider
{
public:
	Collider();
	~Collider();

	void finalupdate();

	void SetOffset(const Vector3& pos) { _Offset = pos; }
	void SetPos(const Vector3& pos) { _ColliderPos = pos; }
	void SetScale(const Vector3& scale) { _Scale = scale; }

	Vector3 GetOffset() const { return _Offset; }
	Vector3 GetPos() const { return _ColliderPos; }
	Vector3 GetScale() const { return _Scale; }

	void render();

private:
	GameObject* _owner;
	Vector3 _Offset;
	Vector3 _ColliderPos;
	Vector3 _Scale;

	friend class GameObject;
};

