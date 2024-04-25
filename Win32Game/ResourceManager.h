#pragma once
#include "PathManager.h"
#include "Texture.h"
#include "globalheader.h"

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	static ResourceManager* GetInstance();
	static void DestroyInstance();

	void InitTexture();
	Texture& GetTexture(const std::wstring& key, const std::wstring& path);

private:
	static ResourceManager* instance;
	
};

