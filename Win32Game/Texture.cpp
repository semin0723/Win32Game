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
	//TODO: ���⿡ �̹����� �ε��� ������� �ڵ带 ������ �մϴ�.
}
