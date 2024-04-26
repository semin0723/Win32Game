#include "ResourceManager.h"
#include "PathManager.h"

ResourceManager* ResourceManager::instance = nullptr;

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
    for (auto i = _Textures.begin(); i != _Textures.end(); i++) {
        delete i->second;
    }
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

Texture* ResourceManager::GetTexture(const std::wstring& key, const std::wstring& path)
{
    //���⿡ ��ο� key�� ��� �ͼ� key�� �ش��ϴ� �ؽ��İ� �����ϸ� �װ� ��ȯ�ϰ�, �ƴϸ� ���Ϸε��ؼ� �����ϰ� ��ȯ�Ѵ�.
    if (_Textures.find(key) != _Textures.end()) {
        return _Textures[key];
    }

    std::wstring filepath = PathManager::GetInstance()->GetContentPath();
    filepath += path;
    
    Texture* newTexture = new Texture;
    newTexture->Load(filepath);
    newTexture->SetKey(key);
    newTexture->SetPath(filepath);
    
    _Textures.insert({ key, newTexture });

    return newTexture;
}