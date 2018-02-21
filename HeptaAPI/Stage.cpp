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
	_minimap = new image;
	_minimap->init(".\\bmps\\map\\usingalpha.bmp", WINSIZEX, WINSIZEY, true, true, RGB(0, 0, 0));

	return S_OK;
}

void Stage::release()
{
	_minimap->release();
}

void Stage::update(int playerx, int playery) 
{
	_renderrc = RectMake(CAMERAMANAGER->getX(), CAMERAMANAGER->getY(), WINSIZEX, WINSIZEY);
	char str[256];
	int tempid = (_renderrc.left / 24) + (_renderrc.top / 24) * _tileCountX;
	for (int i = 0; i < 21 * 16; ++i)
	{
		if (tempid + i % 21 + i / 21 * _tileCountX >= _tiles.size()) continue;
		if (_renderrc.left / 24 > _tileCountX - 20)continue;
		if (_renderrc.top / 24 > _tileCountY - 15)continue;
		RECT temp;
		RECT temptilerc = RectMake(_tiles[tempid + i % 21 + i / 21 * _tileCountX]->getIndexX() * 24,
			_tiles[tempid + i % 21 + i / 21 * _tileCountX]->getIndexY() * 24, 24, 24);
		if (!IntersectRect(&temp, &_renderrc, &temptilerc))
		{
			continue;
		}
		if (_tiles[tempid + i % 21 + i / 21 * _tileCountX]->getIsGo())
		{
			IMAGEMANAGER->findImage("minimap")->frameRender(_minimap->getMemDC(),
				_tiles[tempid + i % 21 + i / 21 * _tileCountX]->getIndexX() * 4,
				_tiles[tempid + i % 21 + i / 21 * _tileCountX]->getIndexY() * 4,
				_tiles[tempid + i % 21 + i / 21 * _tileCountX]->getTarrainFrameX(),
				_tiles[tempid + i % 21 + i / 21 * _tileCountX]->getTarrainFrameY());
		}
	}
}

void Stage::render() 
{
	char str[256];
	int tempid = (_renderrc.left / 24) + (_renderrc.top / 24) * _tileCountX;
	for (int i = 0; i < 21 * 16; ++i)
	{
		if (tempid + i % 21 + i / 21 * _tileCountX >= _tiles.size()) continue;
		if (_renderrc.left / 24 > _tileCountX - 20)continue;
		if (_renderrc.top / 24 > _tileCountY - 15)continue;
		RECT temp;
		RECT temptilerc = RectMake(_tiles[tempid + i % 21 + i / 21 * _tileCountX]->getIndexX() * 24, 
			_tiles[tempid + i % 21 + i / 21 * _tileCountX]->getIndexY() * 24, 24, 24);
		if (!IntersectRect(&temp, &_renderrc, &temptilerc))
		{
			continue;
		}
		sprintf(str, "tarrain%d-%d", (int)_terrain, _tiles[tempid + i % 21 + i / 21 * _tileCountX]->gettileKind());
		IMAGEMANAGER->findImage(str)->frameRender(CAMERAMANAGER->getMemDC(),
			_tiles[tempid + i % 21 + i / 21 * _tileCountX]->getIndexX() * TILESIZEX, 
			_tiles[tempid + i % 21 + i / 21 * _tileCountX]->getIndexY() * TILESIZEY,
			_tiles[tempid + i % 21 + i / 21 * _tileCountX]->getTarrainFrameX(), 
			_tiles[tempid + i % 21 + i / 21 * _tileCountX]->getTarrainFrameY());
		IMAGEMANAGER->findImage("objectlist")->frameRender(CAMERAMANAGER->getMemDC(),
			0 + _tiles[tempid + i % 21 + i / 21 * _tileCountX]->getIndexX() * TILESIZEX,
			0 + _tiles[tempid + i % 21 + i / 21 * _tileCountX]->getIndexY() * TILESIZEY,
			(int)_tiles[tempid + i % 21 + i / 21 * _tileCountX]->getObject(), 0);
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
	ReadFile(file, &_playerStartUpid, sizeof(_playerStartUpid), &read, NULL);
	ReadFile(file, &_playerStartDownid, sizeof(_playerStartDownid), &read, NULL);

	for (int i = 0; i < _tileCountX * _tileCountY; ++i)
	{
		tile* temp;
		temp = new tile;
		_tiles.push_back(temp);
		ReadFile(file, &(*_tiles[i]), sizeof(tile), &read, NULL);
		if (temp->getObject() == OBJECT_RESPAWN)
		{
			_respontiles.push_back(temp);
		}
		if (_tiles[i]->getIsGo())_tiles[i]->setIsOpen(true);
	}

	CloseHandle(file);
}