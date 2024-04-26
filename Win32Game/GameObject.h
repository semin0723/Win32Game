#pragma once
#include "Vector3.h"
#include "Win32GameProject.h"
#include "TimeSystem.h"
#include "InputSystem.h"
#include "globalheader.h"

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();
	void SetLocation(const Vector3& loc) { _location = loc; }
	void SetScale(const Vector3& scale) { _scale = scale; }
	void Setname(const std::string& name) { _name = name; }
	void SetEnable(bool state) { _Enable = state; }
	

	Vector3 GetLocation() const { return Vector3(_location); }
	Vector3 GetScale() const { return Vector3(_scale); }
	std::string GetName() const { return _name; }
	bool Enable() { return _Enable; }

	virtual void update() = 0;
	virtual void render(HDC _bdc) = 0;

private:
	Vector3 _location;
	Vector3 _scale;
	std::string _name;
	bool _Enable = true;
};

/*
	���ӿ�����Ʈ�� ���������� ������ �ִ� Ư�� : 
	��������Ʈ ID, ��ġ

*/