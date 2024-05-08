#pragma once
#include "Vector3.h"
#include "TimeSystem.h"
#include "InputSystem.h"
#include "globalheader.h"

class Collider;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	void SetLocation(const Vector3& loc) { _location = loc; }
	void SetScale(const Vector3& scale) { _scale = scale; }
	void Setname(const std::string& name) { _name = name; }
	void SetEnable(bool state) { _Enable = state; }
	void CreateCollider();

	Vector3 GetLocation() const { return Vector3(_location); }
	Vector3 GetScale() const { return Vector3(_scale); }
	std::string GetName() const { return _name; }
	bool Enable() { return _Enable; }

	virtual void finalupdate() final;
	virtual void update() = 0;
	virtual void render() = 0;

	void ComponentRender();
	Collider* GetCollider() { return _collider; }

private:
	Vector3 _location;
	Vector3 _scale;
	std::string _name;
	bool _Enable = true;

	Collider* _collider;
};

/*
	게임오브젝트가 공통적으로 가지고 있는 특성 : 
	스프라이트 ID, 위치

*/