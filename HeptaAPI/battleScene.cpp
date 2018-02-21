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
	DungoenNum = 0;				//���� �ѹ�
	UpId = true;				//��� ������
	DownId = false;				//��� ������
	_floor = 0;					//�����ΰ�
	char tempfloor[256];
	sprintf(tempfloor, "%d-%d", DungoenNum, _floor);
	_nowStage = new Stage;
	_nowStage->init(tempfloor);

	_em = new enemyManager;

	_player->setStageMemAdressLink(_nowStage);
	_player->setEmMemAdressLink(_em);

	_player->init("���ڸ�");
	_player->setPosition(_nowStage->getPlayerStartUpid().x * 24 + 12, _nowStage->getPlayerStartUpid().y * 24 + 12);

	_em->setStageMemoryAdressLink(_nowStage);
	_em->setTileMemoryAdressLink(_nowStage->getTileAdress());
	_em->setPlayerMemoryAdressLink(_player);

	_em->init();

	CAMERAMANAGER->init(_nowStage->gettileCountX() * TILESIZEX, _nowStage->gettileCountY() * TILESIZEY, WINSIZEX, WINSIZEY, 0, 0, 1);

	//--------------------------------

	_battleTrun = playerTurn; //�׻� �������� ó���� �÷��̾� ��

	_player->setBattleSceneMemory(this);

	return S_OK;
}


void battleScene::release()
{

}


void battleScene::update()				//�ɵ���Ʈ!~~~
{

	if (_alphaMap == 255)//���ķ� 255���� ȭ���� ������ �����ϼ��ֶ�!!
	{

		StageUpDown();

		//�÷��̾����϶� (�̴��س����� ó���� ����)
		if (_battleTrun == playerTurn)
		{
			//�÷��̾��� �ൿ������ ������ (�⺻����,��ų���,�÷��̾ �� Ÿ���� �̵�,�������� ���) 
			//���ʹ̶� �οﶧ�� ���� �����ϴ� ����� �Ӽ��� �ҷ��;��ϴ°ǰ�...?

			// �� �� ���� ���⼭ �÷��̾ �����̰� ���� ��Ÿ�� �������������� _playerAction �� playerMove�� �ٲ�ϴ� 
			_player->dungeonMove();		

			if (_player->getPlayerAction() == playerMove)  //_playerAction�� playerMove�� �ٲ�� �Ϸο�����?
			{
				// �׷� ���� �������ٴ� �Ŵ� ���� �������� ������ �Ѱ��ݴϴ�
				_player->setPlayerAction(playerEnd);
				_battleTrun = enemyTurn; //�� �Ѱ���

			}
			else if (_player->getPlayerAction() == playerAttack)
			{
				//�����ϰ� ���� �Ѱ���
				//if(_player->getIsAttack())
				_battleTrun = enemyTurn; //�� �Ѱ���
			}
			else if (_player->getPlayerAction() == playerUseSkill)
			{
				//��ų���� �Ѱ���
				_battleTrun = enemyTurn; //�� �Ѱ���
			}
			else if (_player->getPlayerAction() == playerUseItem)
			{
				//�����۾��� �Ѱ���
				_battleTrun = enemyTurn; //�� �Ѱ���
			}
		}
		//��Ʈ�����϶�		(���� ��Ʈ�ʰ� ���� �̤� �λ��� ����)
		//else if (_battleTrun == partnerTurn)
		//{
		//	//��Ʈ���� �ൿ������ ������ (�÷��̾ ���� �̵�,�⺻����,��ų���,�־��� �������� ���) 
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
		//���ʹ����϶�
		else if (_battleTrun == enemyTurn)
		{
			_em->enemyTrunManager();

			if (_em->getEnemyAction() == enemyMove)
			{
				_em->setEnemyAction(enemyEnd);
				_battleTrun = playerTurn;
			}
		
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
	_nowStage->getminimap()->alphaRender(CAMERAMANAGER->getMemDC(), CAMERAMANAGER->getX(), CAMERAMANAGER->getY(), 200);
	IMAGEMANAGER->findImage("alphamap")->alphaRender(CAMERAMANAGER->getMemDC(), CAMERAMANAGER->getX(), CAMERAMANAGER->getY(), 255 - _alphaMap);
}

void battleScene::StageUpDown()
{
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