#include "stdafx.h"
#include "aStar.h"


aStar::aStar()
{
}


aStar::~aStar()
{

}

HRESULT aStar::init(vector<tile*> map, int numX, int numY, tile start, tile end)
{
	this->release();

	for (int i = 0; i < numX*numY; ++i)
	{
		_vTotalList.push_back(*map[i]);
	}

	_startTile = _currentTile = start;

	_endTile = end;
	_tileX = numX;
	_tileY = numY;

	return S_OK;
}

void aStar::release()
{
	_vTotalList.clear();
	_vOpenList.clear();
	_vCloseList.clear();
}

vector<tile> aStar::addOpenList(tile current)
{
	int startX = current.getIndexX() - 1;
	int startY = current.getIndexY() - 1;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			//예외처리
			if (startX + j < 0 || startY + i < 0) continue;
			if (startX + j >= _tileX - 1 || startY + i >= _tileY - 1) continue;

			//대각선 예외처리
			if (j == 0 && i == 0)
			{
				tile temp = _vTotalList[startX + (startY + 1)* _tileX];
				tile temp2 = _vTotalList[startX + 1+ (startY)*_tileX];
				if (!temp.getIsOpen()) continue;
				if (!temp2.getIsOpen()) continue;
			}
			if (j == 2 && i == 0)
			{
				tile temp = _vTotalList[startX + (startY + 1)* _tileX];
				tile temp2 = _vTotalList[startX + 1 + (startY)* _tileX];
				if (!temp.getIsOpen()) continue;
				if (!temp2.getIsOpen()) continue;
			}
			if (j == 2 && i == 2)
			{
				tile temp = _vTotalList[startX + 2 + (startY + 1)*_tileX];
				tile temp2 = _vTotalList[startX + 1 + (startY + 2)*_tileX];
				if (!temp.getIsOpen()) continue;
				if (!temp2.getIsOpen()) continue;
			}
			if (j == 0 && i == 2)
			{
				tile temp = _vTotalList[startX + 1 + (startY + 2)];
				tile temp2 = _vTotalList[startX + (startY + 1)*_tileX];
				if (!temp.getIsOpen()) continue;
				if (!temp2.getIsOpen()) continue;
			}

			tile node = _vTotalList[(startY*_tileX) + startX + j + (i*_tileX)];

			if (!node.getIsOpen()) continue;
			if (node.getIndexX() == _startTile.getIndexX() &&
				node.getIndexY() == _startTile.getIndexY()) continue;

			//현재타일 갱신
			tile* tempNode = new tile;
			(*tempNode) = current;
			node.setParentNode(tempNode);

			//주변 타일 검출
			bool addObj = true;

			for (_viOpenList = _vOpenList.begin(); _viOpenList != _vOpenList.end(); ++_viOpenList)
			{
				//이미 있음
				if ((*_viOpenList).getIndexX() == node.getIndexX() &&
					(*_viOpenList).getIndexY() == node.getIndexY())
				{
					addObj = false;
					break;
				}
			}
			if (!addObj) continue;

			_vOpenList.push_back(node);
		}
	}

	return _vOpenList;
}

vector<tile> aStar::pathFinder(tile current)
{
	//start == end 예외처리
	if (_startTile.getIndexX() == _endTile.getIndexX() &&
		_startTile.getIndexY() == _endTile.getIndexY()) return _vCloseList;

	int addOpenListNum = addOpenList(current).size();
	float tempTotalCost = INT_MAX;
	tile tempTile;

	for (int i = 0; i < addOpenListNum; ++i)
	{
		//H값 연산
		_vOpenList[i].setCostToGoal(abs(_endTile.getIndexX() - _vOpenList[i].getIndexY())+
			abs(_endTile.getIndexY() - _vOpenList[i].getIndexY())*10);


		//G값 연산
		POINT center1 = PointMake(_vOpenList[i].getParentNode()->getCenterX(), _vOpenList[i].getParentNode()->getCenterY());
		POINT center2 = PointMake(_vOpenList[i].getCenterX(), _vOpenList[i].getCenterY());

		_vOpenList[i].setCostFromStart((getDistance(center1.x, center1.y, center2.x, center2.y) > TILESIZEX) ? 14 : 10);


		//F값 연산
		_vOpenList[i].setTotalCost(_vOpenList[i].getCostToGoal() + _vOpenList[i].getCostFromStart());


		//F값 비교
		if (tempTotalCost > _vOpenList[i].getTotalCost())
		{
			tempTotalCost = _vOpenList[i].getTotalCost();
			tempTile = _vOpenList[i];
		}
		
		bool addObj = true;
		for (_viOpenList = _vOpenList.begin(); _viOpenList != _vOpenList.end(); ++_viOpenList)
		{
			if ((*_viOpenList).getIndexX() == tempTile.getIndexX() &&
				(*_viOpenList).getIndexY() == tempTile.getIndexY())
			{
				addObj = false;
				break;
			}
		}

		tempTile.setIsOpen(false);
		_vOpenList[i].setIsOpen(false);
		for (int i = 0; i < _vTotalList.size(); ++i)
		{
			if (_vTotalList[i].getIndexX() == tempTile.getIndexX() &&
				_vTotalList[i].getIndexY() == tempTile.getIndexY())
			{
				_vTotalList[i].setIsOpen(false);
				break;
			}
		}

		if (!addObj) continue;
		_vOpenList.push_back(tempTile);
	}

	//
	if (tempTile.getIndexX() == _endTile.getIndexX() &&
		tempTile.getIndexY() == _endTile.getIndexY())
	{
		_vCloseList.push_back(tempTile);
		while (!(tempTile.getIndexX() == _startTile.getIndexX() &&
			tempTile.getIndexY() == _startTile.getIndexY()))
		{
			_vCloseList.push_back((*tempTile.getParentNode()));
			tempTile = (*tempTile.getParentNode());
		}
		_vCloseList.erase(_vCloseList.end() - 1);
		return _vCloseList;
	}

	for (_viOpenList = _vOpenList.begin(); _viOpenList != _vOpenList.end(); ++_viOpenList)
	{
		//최단경로 오픈 리스트에서 삭제
		if ((*_viOpenList).getIndexX() == tempTile.getIndexX() &&
			(*_viOpenList).getIndexY() == tempTile.getIndexY())
		{
			_viOpenList = _vOpenList.erase(_viOpenList);
			break;
		}
			
	}

	_currentTile = tempTile;
	

	return pathFinder(_currentTile);// 재귀
}

