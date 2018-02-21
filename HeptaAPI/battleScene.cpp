#include "stdafx.h"
#include "battleScene.h"
#include "player.h"
#include "enemyManager.h"

battleScene::battleScene()
{
}

battleScene::~battleScene()
{
}


HRESULT battleScene::init()
{
	_alphaMap = 0;			
	DungoenNum = 0;				//던전 넘버
	UpId = true;				//계단 보정용
	DownId = false;				//계단 보정용
	_floor = 0;					//몇층인가
	char tempfloor[256];
	sprintf(tempfloor, "%d-%d", DungoenNum, _floor);
	_nowStage = new Stage;
	_nowStage->init(tempfloor);

	_em = new enemyManager;

	_player->setStageMemAdressLink(_nowStage);

	_player->init("리자몽");
	_player->setPosition(_nowStage->getPlayerStartUpid().x * 24 + 12, _nowStage->getPlayerStartUpid().y * 24 + 12);

	_em->setStageMemoryAdressLink(_nowStage);
	_em->setTileMemoryAdressLink(_nowStage->getTileAdress());
	_em->setPlayerMemoryAdressLink(_player);

	_em->init();

	CAMERAMANAGER->init(_nowStage->gettileCountX() * TILESIZEX, _nowStage->gettileCountY() * TILESIZEY, WINSIZEX, WINSIZEY, 0, 0, 1);

	//--------------------------------

	_battleTrun = playerTurn; //항상 던전들어가서 처음은 플레이어 턴

	return S_OK;
}


void battleScene::release()
{

}


void battleScene::update()				//옵데이트!~~~
{

	if (_alphaMap == 255)			//알파로 255가된 화면이 나오면 움직일수있뜸!!
	{
		//플레이어턴일때 (이닛해놨으니 처음은 여기)
		if (_battleTrun == playerTurn)
		{
			//플레이어의 행동패턴의 종류는 (기본공격,스킬사용,플레이어가 한 타일을 이동,아이템을 사용) 
			//에너미랑 싸울때는 내가 공격하는 상대의 속성도 불러와야하는건가...?

			if (_player->getPlayerAction() == playerMove)
			{
				//움직여야 함
				_player->dungeonMove();

				_battleTrun = enemyTurn; //턴 넘겨줌
			}
			else if (_player->getPlayerAction() == playerAttack)
			{
				//공격하고 턴을 넘겨줌
				//_player->getAtkDamage()
				_battleTrun = enemyTurn; //턴 넘겨줌
			}
			else if (_player->getPlayerAction() == playerUseSkill)
			{
				//스킬쓰고 넘겨줌
				_battleTrun = enemyTurn; //턴 넘겨줌
			}
			else if (_player->getPlayerAction() == playerUseItem)
			{
				//아이템쓰고 넘겨줌
				_battleTrun = enemyTurn; //턴 넘겨줌
			}

		}
		//파트너턴일때		(아직 파트너가 없어 ㅜㅜ 인생은 솔플)
		//else if (_battleTrun == partnerTurn)
		//{
		//	//파트너의 행동패턴의 종류는 (플레이어를 따라서 이동,기본공격,스킬사용,주어진 아이템을 사용) 
		//	if (_partnerAction == partnerMove)
		//	{
		//
		//		_battleTrun = enemyTurn;
		//	}
		//	else if (_partnerAction == partnerAttack)
		//	{
		//
		//		_battleTrun = enemyTurn;
		//	}
		//	else if (_partnerAction == partnerUseSkill)
		//	{
		//
		//		_battleTrun = enemyTurn;
		//	}
		//
		//}
		//에너미턴일때
		else if (_battleTrun == enemyTurn)
		{
			//에너미의 행동패턴의 종류는 (플레이어에게 A*로 이동,기본공격,스킬을 사용)
			//에너미의 귀찮은점은 필드에 존재하는 에너미의 수를 찾아서 백터에 넣고 그 에너미들에게 움직일 순서를 정해주고
			//에너미들이 순서대로 전부 움직인 다음에야 플레이어에게 턴을 돌릴 수 있다

			//if (_enemyAction == enemyMove)
			//{
			//	
				_battleTrun = playerTurn;
			//}

		}	

		//============================================================================
		//밑에는 맵바꾸는거랑 몇층인지 바꾸는거데스~
		//============================================================================


		//플레이어가 계단에 도달했는가?
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


void battleScene::render()
{
	_nowStage->render();
	_em->render();

	_player->render();
	IMAGEMANAGER->findImage("alphamap")->alphaRender(CAMERAMANAGER->getMemDC(), CAMERAMANAGER->getX(), CAMERAMANAGER->getY(), 255 - _alphaMap);
}
