#include "ResourceManager.h"
#include "PathManager.h"

ResourceManager* ResourceManager::instance = nullptr;

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
}

ResourceManager* ResourceManager::GetInstance()
{
    if (instance == nullptr) {
        instance = new ResourceManager;
    }
    return instance;
}

void ResourceManager::DestroyInstance()
{
    delete instance;
    instance = nullptr;
}

void ResourceManager::InitTexture()
{

}

Texture& ResourceManager::GetTexture(const std::wstring& key, const std::wstring& path)
{
    // TODO: 여기에 경로와 key를 들고 와서 key에 해당하는 텍스쳐가 존재하면 그결 반환하고, 아니면 파일로드해서 저장하고 반환한다.
}