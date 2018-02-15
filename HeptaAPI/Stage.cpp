#include "stdafx.h"
#include "Stage.h"

Stage::Stage()
{
}


Stage::~Stage()
{

}

HRESULT Stage::init(string name)
{
	_name = name;
	this->load(_name);
	_playerIndexPt = PointMake(76 % 20, 76 / 20);

	return S_OK;
}

void Stage::release()
{

}

void Stage::update() 
{
	
}

void Stage::render(RECT nowrc, int x, int y) 
{
	char str[256];
	for (int i = 0; i < _tileCountX * _tileCountY; ++i)
	{
		sprintf(str, "tarrain%d-%d", (int)_terrain, _tiles[i]->gettileKind());
		IMAGEMANAGER->findImage(str)->frameRender(getMemDC(),
			_tiles[i]->getIndexX() * TILESIZEX, _tiles[i]->getIndexY() * TILESIZEY,
			_tiles[i]->getTarrainFrameX(), _tiles[i]->getTarrainFrameY());
	}

}



void Stage::load(string name)
{
	char str[256];
	sprintf(str, ".//map//%s.map", _name.c_str());
	HANDLE file;
	DWORD read;

	file = CreateFile(str, GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, &_terrain, sizeof(_terrain), &read, NULL);
	ReadFile(file, &_tileCountX, sizeof(_tileCountX), &read, NULL);
	ReadFile(file, &_tileCountY, sizeof(_tileCountY), &read, NULL);

	for (int i = 0; i < _tileCountX * _tileCountY; ++i)
	{
		tile* temp;
		temp = new tile;
		_tiles.push_back(temp);
		ReadFile(file, &(*_tiles[i]), sizeof(tile), &read, NULL);
	}

	CloseHandle(file);
}