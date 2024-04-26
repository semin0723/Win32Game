#pragma once

class GameObjcet;

class Collider
{
public:
	void fixedupdate();

	friend class GameObject;
private:
	GameObject* _owner;

	Vector3 _Offset;
};

