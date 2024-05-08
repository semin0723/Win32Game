#pragma once
#include "globalheader.h"

struct Event {
	EVENT_TYPE Event;
	DWORD lParam;
	DWORD wParam;
};

class EventManager
{
public:
	EventManager();
	~EventManager();

	static EventManager* GetInstance();
	static void DestroyInstance();

	void Update();

private:
	static EventManager* Instance;

	std::vector<Event> _Events;
};

