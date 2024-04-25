#include "Texture.h"

Texture::Texture() : _DC(0), _Bitmap(0), _BitInfo{}
{
}

Texture::~Texture()
{
	DeleteDC(_DC);
	DeleteObject(_Bitmap);
}

void Texture::Load()
{
	//TODO: 여기에 이미지를 로드해 갖고오는 코드를 만들어야 합니다.
}
