#include "GameObject.h"
#include "Collider.h"

GameObject::GameObject() : _location(0, 0, 0), _scale(0, 0, 0), _name(""), _collider(nullptr)
{
}
GameObject::~GameObject() 
{
	if (_collider != nullptr) {
		delete _collider;
	}
}

void GameObject::CreateCollider()
{
	_collider = new Collider;
	_collider->_Owner = this;
}

void GameObject::FinalUpdate()
{
	if (_collider != nullptr) {
		_collider->FinalUpdate();
	}
}

void GameObject::ComponentRender()
{
	if (_collider != nullptr) {
		_collider->Render();
	}
}