#pragma once
#include "GameObject.h"
#include "Texture.h"

class SampleObject :
    public GameObject
{
public:
    SampleObject();
    ~SampleObject();

    void update();
    void render();

private:
    Texture* _myTex;

    float MoveSpeed = 0.5f;
};

