#pragma once
#include "globalheader.h"
#define IGNORE_UTILITY

class GameObject;

void CreateObject(GameObject* obj, LAYER_GROUP group);
void DeleteObject(GameObject* obj);
bool CheckRenderPosition(int& leftX, int& leftY, int& rightX, int& rightY);
int GetRandomNum(int dis);
int GetRandomNum(int from, int to);
Vector3 GetMousePos();
Vector3 GetWorldMousePos();
bool CheckMouseOnScreen();
bool CheckPositionOnUI();
bool CheckPositionOnUI(GameObject* obj);
bool CheckPositionOnWorld(GameObject* obj);