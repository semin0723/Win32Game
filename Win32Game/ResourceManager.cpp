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
    // TODO: ���⿡ ��ο� key�� ��� �ͼ� key�� �ش��ϴ� �ؽ��İ� �����ϸ� �װ� ��ȯ�ϰ�, �ƴϸ� ���Ϸε��ؼ� �����ϰ� ��ȯ�Ѵ�.
}