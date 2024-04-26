#include "TimeSystem.h"
#include "globalheader.h"

TimeManager* TimeManager::instance = nullptr;

TimeManager::TimeManager() : _curTime{ 0 }, _prevTime{ 0 }, _frequency{ 0 } , _deltaTime(0)
{
}

TimeManager::~TimeManager()
{
}

TimeManager* TimeManager::GetInstance() {
	if (instance == nullptr) {
		instance = new TimeManager();
	}
	return instance;
}

void TimeManager::DestroyInstance() {
	delete instance;
	instance = nullptr;
}

void TimeManager::InitTime()
{
	QueryPerformanceFrequency(&_frequency);
	QueryPerformanceCounter(&_curTime);
}

void TimeManager::UpdateTime()
{
	_prevTime = _curTime;
	QueryPerformanceCounter(&_curTime);

	_deltaTime = (float)(_curTime.QuadPart - _prevTime.QuadPart) / ((float)(_frequency.QuadPart) / 1000.0);
}

const float TimeManager::GetFrameRate()
{
	if (_deltaTime == 0) return 0;

	return ceil(((1000.0f / _deltaTime) * 1000) / 1000);
}

const float TimeManager::GetDeltaTime()
{
	return _deltaTime;
}
