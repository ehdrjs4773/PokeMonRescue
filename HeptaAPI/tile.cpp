#include "stdafx.h"
#include "tile.h"


tile::tile()
{
}


tile::~tile()
{

}

HRESULT tile::init(int idx, int idy)
{
	_mapNum = 0;
	_whatTile = 0;
	_tileKind = WALL;

	_idx = idx;
	_idy = idy;
	_centerx = _idx * TILESIZEX + TILESIZEX / 2;
	_centery = _idy * TILESIZEY + TILESIZEY / 2;
	_terrainFrameX = 0;
	_terrainFrameY = 0;

	_object = OBJECT_NONE;
	_objFrameX = 0;
	_objFrameY = 0;

	_totalcost = 0;
	_costFromStart = 0;
	_costToGoal = 0;
	_isOpen = false;
	_isgo = false;
	_parentNode = NULL;

	return S_OK;
}

void tile::release()
{

}

void tile::update()	
{

}

void tile::render()	
{

}
