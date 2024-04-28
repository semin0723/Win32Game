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
	_collider->_owner = this;
}

void GameObject::finalupdate()
{
	if (_collider != nullptr) {
		_collider->finalupdate();
	}
}

void GameObject::CompnentRender()
{
	if (_collider != nullptr) {
		_collider->render();
	}
}