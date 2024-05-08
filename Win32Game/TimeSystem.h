#pragma once
#include <Windows.h>

class TimeManager
{
public:
	TimeManager();
	~TimeManager();

	static TimeManager* GetInstance();
	static void DestroyInstance();

	void InitTime();
	void UpdateTime();
	const float GetFrameRate();
	const float GetDeltaTime();

private:
	LARGE_INTEGER _curTime;
	LARGE_INTEGER _prevTime;
	LARGE_INTEGER _frequency;

	float _deltaTime;

	static TimeManager* Instance;
};