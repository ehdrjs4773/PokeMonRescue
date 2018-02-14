#pragma once
#include "gameNode.h"
#include "tile.h"
#include <vector>

class aStar : public gameNode
{
private:
	vector<tile> _vTotalList;
	vector<tile>::iterator _viTotlaList;

	vector<tile> _vOpenList;
	vector<tile>::iterator _viOpenList;

	vector<tile> _vCloseList;
	vector<tile>::iterator _viCloseList;

	tile _startTile;
	tile _currentTile;
	tile _endTile;

	int _tileX;
	int _tileY;


public:
	aStar();
	~aStar();

	HRESULT init(tile* map, int numX, int numY, tile start, tile end);
	void release();

	vector<tile> addOpenList(tile current);
	vector<tile> pathFinder(tile current);


};

