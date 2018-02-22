#include "enemyManager.h"
#include "Stage.h"
#include "player.h"

#define TILEX WINSIZEX / TILESIZEX
#define TILEY WINSIZEY / TILESIZEY



enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{

}


HRESULT enemyManager::init()
{
	imageInit();


	
		enemyBirth(ENEMY_CHICORITA,
			_stage->getrespontile()[0]->getIndexX(),
			_stage->getrespontile()[0]->getIndexY(), 1);
		enemyBirth(ENEMY_DANDEGI, _stage->getrespontile()[1]->getIndexX(),
			_stage->getrespontile()[1]->getIndexY(), 1);
		enemyBirth(ENEMY_POLYGON, _stage->getrespontile()[3]->getIndexX(),
			_stage->getrespontile()[3]->getIndexY() + 1, 1);
		enemyBirth(ENEMY_PURIN, _stage->getrespontile()[4]->getIndexX(),
			_stage->getrespontile()[4]->getIndexY(), 1);
		enemyBirth(ENEMY_RUKARIO, _stage->getrespontile()[5]->getIndexX(),
			_stage->getrespontile()[5]->getIndexY(), 1);
		enemyBirth(ENEMY_GRAENA, _stage->getrespontile()[6]->getIndexX(),
			_stage->getrespontile()[6]->getIndexY(), 1);
		enemyBirth(ENEMY_MANKEY, _stage->getrespontile()[7]->getIndexX(),
			_stage->getrespontile()[7]->getIndexY(), 1);
		enemyBirth(ENEMY_TANGURI, _stage->getrespontile()[8]->getIndexX(),
			_stage->getrespontile()[8]->getIndexY(), 1);


	_selectSkill = 0;
	_enemyTurn = false;

	return S_OK;
}
void enemyManager::release()
{

}
void enemyManager::update()	
{

	_mapNum = *_pMapNum;
	_floorNum = *_pFloorNum;

	if (_mapNum == 0 && _floorNum == 0)
	{
		for (int i = 0; i < _vEnemyPokemon.size(); i++)
		{
			_vEnemyPokemon[i]->update();
		}
		_tileCheckX = _pl->getPlayerTileIndexX();
		_tileCheckY = _pl->getPlayerTileIndexY();
		enemyDead();
	}
	else if(_mapNum == 0 && _floorNum == 1)
	{
		_vEnemyPokemon.clear();
	}
	else if (_mapNum ==3)
	{ 
		if(_vEnemyPokemon.size()==0)
		enemyBirth(ENEMY_DANDEGI, _pl->getPlayerTileIndexX() ,_pl->getPlayerTileIndexY()-5, 1);

		for (int i = 0; i < _vEnemyPokemon.size(); i++)
		{
			_vEnemyPokemon[i]->update();
			_tileCheckX = _pl->getPlayerTileIndexX();
			_tileCheckY = _pl->getPlayerTileIndexY();
			enemyDead();
		}
	}

			
}
void enemyManager::render()	
{

	for (int i = 0; i < _vEnemyPokemon.size(); i++)
	{
			_vEnemyPokemon[i]->render();
	}

}


void enemyManager::enemyMoveManager(int arrNum)
{

			int currentTileX = (int)_vEnemyPokemon[arrNum]->getX() / 24;
			int currentTileY = (int)_vEnemyPokemon[arrNum]->getY() / 24;

				switch (_vEnemyPokemon[arrNum]->getDirection())
				{
				case DOWN:
					if (currentTileX == _tileCheckX && currentTileY + 1 == _tileCheckY) break;

					if (_tile[currentTileX + _stage->gettileCountX() *(currentTileY + 1)]->gettileKind() == LAND)
					{
						_vEnemyPokemon[arrNum]->enemyMoveSign();
					}
					break;
				case UP:
					if (currentTileX == _tileCheckX && currentTileY - 1 == _tileCheckY) break;

					if (_tile[currentTileX + _stage->gettileCountX() *(currentTileY - 1)]->gettileKind() == LAND)
					{
						_vEnemyPokemon[arrNum]->enemyMoveSign();
					}
					break;
				case RIGHT:
					if (currentTileX + 1 == _tileCheckX && currentTileY == _tileCheckY) break;

					if (_tile[currentTileX + 1 + _stage->gettileCountX() *currentTileY]->gettileKind() == LAND)
					{
						_vEnemyPokemon[arrNum]->enemyMoveSign();
					}
					break;
				case LEFT:
					if (currentTileX - 1 == _tileCheckX && currentTileY == _tileCheckY) break;
					if (_tile[currentTileX - 1 + _stage->gettileCountX() *currentTileY]->gettileKind() == LAND)
					{
						_vEnemyPokemon[arrNum]->enemyMoveSign();
					}
					break;

				case RIGHTUP:
					if (currentTileX + 1 == _tileCheckX && currentTileY - 1 == _tileCheckY) break;

					if (_tile[currentTileX + 1 + _stage->gettileCountX() *currentTileY]->gettileKind() == LAND
						&& _tile[currentTileX + _stage->gettileCountX() *(currentTileY - 1)]->gettileKind() == LAND
						&& _tile[currentTileX + 1 + _stage->gettileCountX() *(currentTileY - 1)]->gettileKind() == LAND)
					{
						_vEnemyPokemon[arrNum]->enemyMoveSign();
					}
					break;
				case LEFTUP:
					if (currentTileX - 1 == _tileCheckX && currentTileY - 1 == _tileCheckY) break;
					if (_tile[currentTileX - 1 + _stage->gettileCountX() *currentTileY]->gettileKind() == LAND
						&& _tile[currentTileX + _stage->gettileCountX() *(currentTileY - 1)]->gettileKind() == LAND
						&& _tile[currentTileX - 1 + _stage->gettileCountX() *(currentTileY - 1)]->gettileKind() == LAND)
					{
						_vEnemyPokemon[arrNum]->enemyMoveSign();
					}
					break;

				case RIGHTDOWN:
					if (currentTileX + 1 == _tileCheckX && currentTileY + 1 == _tileCheckY) break;
					if (_tile[currentTileX + 1 + _stage->gettileCountX() *currentTileY]->gettileKind() == LAND
						&& _tile[currentTileX + _stage->gettileCountX() *(currentTileY + 1)]->gettileKind() == LAND
						&& _tile[currentTileX + 1 + _stage->gettileCountX() *(currentTileY + 1)]->gettileKind() == LAND)
					{
						_vEnemyPokemon[arrNum]->enemyMoveSign();
					}
					break;
				case LEFTDOWN:
					if (currentTileX - 1 == _tileCheckX && currentTileY + 1 == _tileCheckY) break;
					if (_tile[currentTileX - 1 + _stage->gettileCountX() *currentTileY]->gettileKind() == LAND
						&& _tile[currentTileX + _stage->gettileCountX() *(currentTileY + 1)]->gettileKind() == LAND
						&& _tile[currentTileX - 1 + _stage->gettileCountX() *(currentTileY + 1)]->gettileKind() == LAND)
					{
						_vEnemyPokemon[arrNum]->enemyMoveSign();
					}
					break;
				}

}



void enemyManager::enemyAtkManager(int arrNum)
{
	if(_vEnemyPokemon[arrNum]->getState() != STATE_ATTACK 
		&&_vEnemyPokemon[arrNum]->getState() != STATE_SKILL)
	_selectSkill = RND->getInt(2);

	if (_vEnemyPokemon[arrNum]->getPokemoName() != "단데기")
	{
		_selectSkill = 0;
	}

	switch (_selectSkill)
	{
	case 0:
		if (_vEnemyPokemon[arrNum]->getState() != STATE_ATTACK)
		{
			int plHP = _pl->getCurrentHP();
			int emAtk = _vEnemyPokemon[arrNum]->getAtk();
			plHP -= emAtk;
			_pl->getStatus()->setCurrentHP(plHP);
			SOUNDMANAGER->play("공격", 1, false);
		}
		_vEnemyPokemon[arrNum]->enemyAttackMotion();
		break;

	case 1:
		if (_vEnemyPokemon[arrNum]->getState() != STATE_SKILL)
		{
			int plHP = _pl->getCurrentHP();
			int emAtk = _vEnemyPokemon[arrNum]->getSpecialATK();
			plHP -= emAtk;
			_pl->getStatus()->setCurrentHP(plHP);

			SOUNDMANAGER->play("레쿠쟈", 1, false);
		}
		_vEnemyPokemon[arrNum]->enemyskillSign();


		break;
	}
}
void enemyManager::enemyTrunManager()
{
	
	//if (KEYMANAGER->isOnceKeyDown('D'))
	//{
	//	//시작부분     
	//	
	//	_enemyTurn = true;
	//}
	//
	//if (!_enemyTurn)
	//{
	//	return;
	//}


		for (int i = 0; i < _vEnemyPokemon.size(); i++)
		{
			if (i == 0)
			{
				if(!_vEnemyPokemon[i]->getCheakTrun())
				_vEnemyPokemon[i]->setMyturn(true);
				_vEnemyPokemon[i]->setCheakturn(true);
			}
			else
			{
				if (!_vEnemyPokemon[i]->getCheakTrun() &&
					!_vEnemyPokemon[i]->getMyturn()	   &&
					_vEnemyPokemon[i-1]->getCheakTrun() &&
					!_vEnemyPokemon[i-1]->getMyturn() )
				{
					_vEnemyPokemon[i]->setMyturn(true);
					_vEnemyPokemon[i]->setCheakturn(true);
				}
			}
			
			bool isturnOver = false;
			for (int j = 0; j < _vEnemyPokemon.size(); j++)
			{
				if (_vEnemyPokemon[j]->getMyturn() || !_vEnemyPokemon[j]->getCheakTrun())
				{
					isturnOver = true;
				}
			}
			if (!isturnOver)
			{
				for (int j = 0; j < _vEnemyPokemon.size(); j++)
				{
					_vEnemyPokemon[j]->setMyturn(false);
					_vEnemyPokemon[j]->setCheakturn(false);
				}
				_enemyTurn = false;
				//여기가 완전히 턴이 끝나는부분
				_enemyAction = enemyMove;
			}

			if (!_vEnemyPokemon[i]->getMyturn())
			{	
					continue;	
			}




	

			bool canAtk = false;
			if (_vEnemyPokemon[i]->getState() == STATE_MOVE)
			{
				return;
			}
			int currentTileX = (int)_vEnemyPokemon[i]->getX() / 24;
			int currentTileY = (int)_vEnemyPokemon[i]->getY() / 24;

			for (int j = -1; j < 2; j++)
			{
				for (int k = -1; k < 2; k++)
				{
					if (currentTileX + j == _tileCheckX
						&& currentTileY + k == _tileCheckY)
					{
						canAtk = true;
					}
				}
			}
			if (canAtk)
			{
				enemyAtkManager(i);
				continue;
			}
			else if (!canAtk)
			{
				//if (getDistance(_pl->getX(), _pl->getY(), _vEnemyPokemon[i]->getX(), _vEnemyPokemon[i]->getY()) >= 240)
				//{
				//	_vEnemyPokemon[i]->setMyturn(false);
				//}
				_vEnemyPokemon[i]->enemyASTARStart();

				enemyMoveManager(i);
				continue;
			}

			_vEnemyPokemon[i]->setMyturn(false);
		}
	
}













void enemyManager::enemyBirth(ENEMY enemys, int tileX, int tileY, int level)
{
	switch (enemys)
	{
	case ENEMY_CHICORITA:
		_chicorita = new enemy;
		_chicorita->setPlayerMemoryAdressLink(_pl);
		_chicorita->setStageMemoryAdressLink(_stage);
		_chicorita->init(_chicoName, _tile[tileX]->getCenterX()
			, _tile[_stage->gettileCountX() * tileY]->getCenterY(), 5);
		_vEnemyPokemon.push_back(_chicorita);
		break;
	case ENEMY_DANDEGI:
		_dandegi = new enemy;
		_dandegi->setStageMemoryAdressLink(_stage);
		_dandegi->setPlayerMemoryAdressLink(_pl);
		_dandegi->init(_dandegiName, _tile[tileX]->getCenterX()
			, _tile[_stage->gettileCountX() * tileY]->getCenterY(), 9);
		_vEnemyPokemon.push_back(_dandegi);
		break;
	case ENEMY_POLYGON:
		_polygon = new enemy;
		_polygon->setStageMemoryAdressLink(_stage);
		_polygon->setPlayerMemoryAdressLink(_pl);

		_polygon->init(_polygonName, _tile[tileX]->getCenterX()
			, _tile[_stage->gettileCountX() * tileY]->getCenterY(), level);
		_vEnemyPokemon.push_back(_polygon);
		break;
	case ENEMY_PURIN:
		_purin = new enemy;
		_purin->setStageMemoryAdressLink(_stage);
		_purin->setPlayerMemoryAdressLink(_pl);

		_purin->init(_purinName, _tile[tileX]->getCenterX()
			, _tile[_stage->gettileCountX() * tileY]->getCenterY(), level);
		_vEnemyPokemon.push_back(_purin);
		break;
	case ENEMY_GRAENA:
		_graena = new enemy;
		_graena->setStageMemoryAdressLink(_stage);
		_graena->setPlayerMemoryAdressLink(_pl);

		_graena->init(_graenaName, _tile[tileX]->getCenterX()
			, _tile[_stage->gettileCountX() * tileY]->getCenterY(), level);
		_vEnemyPokemon.push_back(_graena);
		break;
	case ENEMY_RUKARIO:
		_rukario = new enemy;
		_rukario->setStageMemoryAdressLink(_stage);
		_rukario->setPlayerMemoryAdressLink(_pl);

		_rukario->init(_rukarioName, _tile[tileX]->getCenterX()
			, _tile[_stage->gettileCountX() * tileY]->getCenterY(), level);
		_vEnemyPokemon.push_back(_rukario);
		break;
	case ENEMY_MANKEY:
		_mankey = new enemy;
		_mankey->setStageMemoryAdressLink(_stage);
		_mankey->setPlayerMemoryAdressLink(_pl);

		_mankey->init(_mankeyName, _tile[tileX]->getCenterX()
			, _tile[_stage->gettileCountX() * tileY]->getCenterY(), level);
		_vEnemyPokemon.push_back(_mankey);
		break;
	case ENEMY_TANGURI:
		_tanguri = new enemy;
		_tanguri->setStageMemoryAdressLink(_stage);
		_tanguri->setPlayerMemoryAdressLink(_pl);

		_tanguri->init(_tanguriName, _tile[tileX]->getCenterX()
			, _tile[_stage->gettileCountX() * tileY]->getCenterY(), level);
		_vEnemyPokemon.push_back(_tanguri);
		break;
	case ENEMY_ELECTIVIRE:
		_electivire = new enemy;
		_electivire->setStageMemoryAdressLink(_stage);
		_electivire->setPlayerMemoryAdressLink(_pl);

		_electivire->init(_electivireName, _tile[tileX]->getCenterX()
			, _tile[_stage->gettileCountX() * tileY]->getCenterY(), level);
		_vEnemyPokemon.push_back(_electivire);
		break;
	}
}



void enemyManager::enemyDead()
{
	for (int i = 0; i < _vEnemyPokemon.size(); i++)
	{
		//언사인드 인트라 체력이 0밑으로가면 오버플로우로 제일 윗부분으로 가서 그냥 이렇게 해놨음 ㅎ
		if (_vEnemyPokemon[i]->getCurrentHP() >= 60000 || _vEnemyPokemon[i]->getCurrentHP() <= 0)
		{
			if (_vEnemyPokemon[i]->getName() == "푸린")
			{
				if (SOUNDMANAGER->isPlaySound("푸린의노래"))
					SOUNDMANAGER->stop("푸린의노래");

			}
			_vEnemyPokemon.erase(_vEnemyPokemon.begin() + i);
		}
	}
}



