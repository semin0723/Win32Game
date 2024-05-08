#pragma once
#include "globalheader.h"

class WinApp
{
public:

	WinApp() = default;
	~WinApp() = default;

	void Initialize(HInstance hInstance);

	void Run();

	void Finalize();

	HInstance GetInstance() const { return m_hInstance; }

	HWND GetWindow() const { return m_hWnd; }

	const int GetWidth() const { return width; }
	const int GetHeight() const { return height; }

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:

	HInstance m_hInstance = { 0 };  // HInstance is a handle to an Instance of a module.
	HWND m_hWnd = { 0 };			// HWND is a handle to a window.

	int width = 1024;
	int height = 768;
};

namespace global
{
	const WinApp& GetWinApp();
}