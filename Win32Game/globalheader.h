#pragma once
#include <vector>
#include <map>
#include <string>

enum class LAYER_GROUP {
	BG,
	TITLE,
	BUTTON,
	
	UI,
	END = 32,
};

enum class SCENE_LAYER {
	MAIN,
	PLAY,

	END,
};