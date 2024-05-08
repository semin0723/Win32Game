#include "EventManager.h"

EventManager* EventManager::Instance = nullptr;

EventManager::EventManager()
{
}

EventManager::~EventManager()
{
}

EventManager* EventManager::GetInstance()
{
	if (Instance == nullptr) {
		Instance = new EventManager;
	}
	return Instance;
}

void EventManager::DestroyInstance()
{
	delete Instance;
	Instance = nullptr;
}

void EventManager::Update()
{

}
