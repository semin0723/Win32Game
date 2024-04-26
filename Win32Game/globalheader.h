#pragma once

#include "framework.h"
#include <SDKDDKVer.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "Resource.h"

#include <vector>
#include <map>
#include <string>
#include <cmath>

enum class LAYER_GROUP {
	DEFAULT,
	
	UI,
	END = 32,
};

enum class SCENE_LAYER {
	MAIN,
	PLAY,

	END,
};