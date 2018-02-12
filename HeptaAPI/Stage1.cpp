#include "stdafx.h"
#include "Stage1.h"

Stage1::Stage1()
{
}


Stage1::~Stage1()
{

}

HRESULT Stage1::init()
{
	this->load();
	IMAGEMANAGER->addFrameImage("tarrain0-0", ".//bmps//map//tarrain0//0.bmp", 384, 384, 16, 16, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tarrain0-1", ".//bmps//map//tarrain0//1.bmp", 384, 384, 16, 16, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tarrain0-2", ".//bmps//map//tarrain0//2.bmp", 384, 384, 16, 16, false, true, RGB(255, 0, 255));

	_playerIndexPt = PointMake(76 % 20, 76 / 20);

	return S_OK;
}

void Stage1::release()
{

}

void Stage1::update() 
{

}

void Stage1::render() 
{
	char str[256];
	for (int i = 0; i < _tileCountX * _tileCountY; ++i)
	{
		sprintf(str, "tarrain%d-%d", (int)_terrain, _tiles[i].gettileKind());
		IMAGEMANAGER->findImage(str)->frameRender(getMemDC(),
			_tiles[i].getIndexX() * TILESIZEX, _tiles[i].getIndexY() * TILESIZEY,
			_tiles[i].getTarrainFrameX(), _tiles[i].getTarrainFrameY());
	}
}



void Stage1::load()
{
	char str[256];
	sprintf(str, ".//map//num1map.map");
	HANDLE file;
	DWORD read;

	file = CreateFile(str, GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, &_terrain, sizeof(_terrain), &read, NULL);
	ReadFile(file, &_tileCountX, sizeof(_tileCountX), &read, NULL);
	ReadFile(file, &_tileCountY, sizeof(_tileCountY), &read, NULL);

	_tiles = new tile[_tileCountX * _tileCountY];

	memset(_tiles, NULL, sizeof(tile) * _tileCountX * _tileCountY);

	ReadFile(file, _tiles, sizeof(tile) * _tileCountX * _tileCountY, &read, NULL);
	

	CloseHandle(file);
}