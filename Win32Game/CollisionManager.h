#pragma once
#include "globalheader.h"
#include "Collider.h"

class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();

	static CollisionManager* GetInstance();
	static void DestroyInstance();

	void Init();
	void update();
	void CheckGroup(LAYER_GROUP a, LAYER_GROUP b);
	void Reset() { memset(_CollisionMatrix, 0, sizeof(_CollisionMatrix)); }

private:
	static CollisionManager* instance;

	UINT _CollisionMatrix[(int)LAYER_GROUP::END];


	void CollisionGroupUpdate(LAYER_GROUP a, LAYER_GROUP b);

	bool OnCollisionEnter(Collider* a, Collider* b);
};

