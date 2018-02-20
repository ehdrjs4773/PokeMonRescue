#include "stdafx.h"
#include "StageScene.h"
#include "player.h"
#include "enemyManager.h"



StageScene::StageScene()
{
}


StageScene::~StageScene()
{

}

HRESULT StageScene::init()
{
	_alphaMap = 0;
	DungoenNum = 0;
	UpId = true;
	DownId = false;
	_floor = 0;
	char tempfloor[256];
	sprintf(tempfloor, "%d-%d", DungoenNum, _floor);
	_nowStage = new Stage;
	_nowStage->init(tempfloor);

	_em = new enemyManager;

	_player->setStageMemAdressLink(_nowStage);

	_player->init("¸®ÀÚ¸ù");
	_player->setPosition(_nowStage->getPlayerStartUpid().x * 24 + 12, _nowStage->getPlayerStartUpid().y * 24 + 12);

	_em->setStageMemoryAdressLink(_nowStage);
	_em->setTileMemoryAdressLink(_nowStage->getTileAdress());
	_em->setPlayerMemoryAdressLink(_player);

	_em->init();

	CAMERAMANAGER->init(_nowStage->gettileCountX() * TILESIZEX, _nowStage->gettileCountY() * TILESIZEY, WINSIZEX, WINSIZEY, 0, 0, 1);

	return S_OK;
}

void StageScene::release()
{

}

void StageScene::update() 
{
	if (_alphaMap == 255)
	{
		_player->dungeonMove();
		if (_player->getPlayerTileIndexX() == _nowStage->getPlayerStartDownid().x &&
			_player->getPlayerTileIndexY() == _nowStage->getPlayerStartDownid().y)
		{
			if (DownId);
			else
			{
				_alphaMap = 0;
				UpId = true;
				DownId = true;
				++_floor;
				if (_floor > 2)
				{
					_floor = 0;
					++DungoenNum;
				}
				char tempfloor[256];
				sprintf(tempfloor, "%d-%d", DungoenNum, _floor);
				_nowStage->release();
				_nowStage->init(tempfloor);

				CAMERAMANAGER->init(_nowStage->gettileCountX() * TILESIZEX, _nowStage->gettileCountY() * TILESIZEY, WINSIZEX, WINSIZEY, 0, 0, 1);

				_player->setPosition(_nowStage->getPlayerStartUpid().x * 24 + 12, _nowStage->getPlayerStartUpid().y * 24 + 12);
			}
		}
		else
		{
			DownId = false;
		}
		if (_player->getPlayerTileIndexX() == _nowStage->getPlayerStartUpid().x &&
			_player->getPlayerTileIndexY() == _nowStage->getPlayerStartUpid().y)
		{
			if (UpId);
			else
			{
				if (_floor || DungoenNum)
				{
					_alphaMap = 0;
					UpId = true;
					DownId = true;
					--_floor;
					if (_floor < 0)
					{
						_floor = 2;
						--DungoenNum;
					}
					char tempfloor[256];
					sprintf(tempfloor, "%d-%d", DungoenNum, _floor);
					_nowStage->release();
					_nowStage->init(tempfloor);

					CAMERAMANAGER->init(_nowStage->gettileCountX() * TILESIZEX, _nowStage->gettileCountY() * TILESIZEY, WINSIZEX, WINSIZEY, 0, 0, 1);

					_player->setPosition(_nowStage->getPlayerStartDownid().x * 24 + 12, _nowStage->getPlayerStartDownid().y * 24 + 12);
				}
				else
				{
					
					SCENEMANAGER->init("npc");
					_player->setPosition(WINSIZEX - 30, WINSIZEY - 25);
					SCENEMANAGER->changeScene("npc");
				}
			}
		}
		else
		{
			UpId = false;
		}
	}
	else
	{
		_alphaMap += 5;
		if (_alphaMap > 255)_alphaMap = 255;
	}
	_player->update();
	_em->update();
	_nowStage->update(_player->getX(), _player->getY());
}

void StageScene::render() 
{
	_nowStage->render();
	_em->render();

	_player->render();
	IMAGEMANAGER->findImage("alphamap")->alphaRender(CAMERAMANAGER->getMemDC(), CAMERAMANAGER->getX(), CAMERAMANAGER->getY(), 255 - _alphaMap);
}