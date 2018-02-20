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
	enemyBirth(ENEMY_CHICORITA, 2, 2, 99);
	//enemyBirth(ENEMY_DANDEGI, 2, 3, 99);
	//enemyBirth(ENEMY_POLYGON, 2, 4, 99);
	//enemyBirth(ENEMY_PURIN, 3, 2, 99);
	//enemyBirth(ENEMY_RUKARIO, 3, 4, 99);
	//enemyBirth(ENEMY_GRAENA, 4, 2, 99);
	//enemyBirth(ENEMY_MANKEY, 4, 3, 99);
	//enemyBirth(ENEMY_TANGURI, 4, 4, 99);
	

	
	
	return S_OK;
}
void enemyManager::release()
{

}
void enemyManager::update()	
{
	for (int i = 0; i < _vEnemyPokemon.size(); i++)
	{
		_vEnemyPokemon[i]->update();
	}
	_tileCheckX = _pl->getPlayerTileIndexX();
	_tileCheckY = _pl->getPlayerTileIndexY();
	
	enemyTrunManager();


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
				if (currentTileX + 1 == _tileCheckX  && currentTileY == _tileCheckY) break;
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
				{
				if (_tile[currentTileX - 1 + _stage->gettileCountX() *currentTileY]->gettileKind() == LAND
					&& _tile[currentTileX + _stage->gettileCountX() *(currentTileY - 1)]->gettileKind() == LAND
					&& _tile[currentTileX - 1 + _stage->gettileCountX() *(currentTileY - 1)]->gettileKind() == LAND)
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
					_vEnemyPokemon[arrNum]->enemyMoveSign();
				break;
				}

}


void enemyManager::enemyBirth(ENEMY enemy, int tileX, int tileY, int level)
{
	switch (enemy)
	{
	case ENEMY_CHICORITA:
		_chicorita = new chicorita;
		_chicorita->setStageMemoryAdressLink(_stage);
		_chicorita->init(_chicoName, _tile[tileX]->getCenterX()
			, _tile[_stage->gettileCountX() * tileY]->getCenterY(), 5);
		_vEnemyPokemon.push_back(_chicorita);
		break;
	case ENEMY_DANDEGI:
		_dandegi = new dandegi;
		_dandegi->setStageMemoryAdressLink(_stage);
		_dandegi->init(_dandegiName, _tile[tileX]->getCenterX()
			, _tile[_stage->gettileCountX() * tileY]->getCenterY(), 9);
		_vEnemyPokemon.push_back(_dandegi);
		break;
	case ENEMY_POLYGON:
		_polygon = new polygon;
		_polygon->setStageMemoryAdressLink(_stage);

		_polygon->init(_polygonName, _tile[tileX]->getCenterX()
			, _tile[_stage->gettileCountX() * tileY]->getCenterY(), level);
		_vEnemyPokemon.push_back(_polygon);
		break;
	case ENEMY_PURIN:
		_purin = new purin;
		_purin->setStageMemoryAdressLink(_stage);

		_purin->init(_purinName, _tile[tileX]->getCenterX()
			, _tile[_stage->gettileCountX() * tileY]->getCenterY(), level);
		_vEnemyPokemon.push_back(_purin);
		break;
	case ENEMY_GRAENA:
		_graena = new graena;
		_graena->setStageMemoryAdressLink(_stage);

		_graena->init(_graenaName, _tile[tileX]->getCenterX()
			, _tile[_stage->gettileCountX() * tileY]->getCenterY(), level);
		_vEnemyPokemon.push_back(_graena);
		break;
	case ENEMY_RUKARIO:
		_rukario = new rukario;
		_rukario->setStageMemoryAdressLink(_stage);

		_rukario->init(_rukarioName, _tile[tileX]->getCenterX()
		, _tile[_stage->gettileCountX() * tileY]->getCenterY(), level);
		_vEnemyPokemon.push_back(_rukario);
		break;
	case ENEMY_MANKEY:
		_mankey = new mankey;
		_mankey->setStageMemoryAdressLink(_stage);

		_mankey->init(_mankeyName, _tile[tileX]->getCenterX()
			, _tile[_stage->gettileCountX() * tileY]->getCenterY(), level);
		_vEnemyPokemon.push_back(_mankey);
		break;
	case ENEMY_TANGURI:
		_tanguri = new tanguri;
		_tanguri->setStageMemoryAdressLink(_stage);

		_tanguri->init(_tanguriName, _tile[tileX]->getCenterX()
			, _tile[_stage->gettileCountX() * tileY]->getCenterY(), level);
		_vEnemyPokemon.push_back(_tanguri);
		break;
	case ENEMY_ELECTIVIRE:
		_electivire = new electivire;
		_electivire->setStageMemoryAdressLink(_stage);

		_electivire->init(_electivireName, _tile[tileX]->getCenterX()
			, _tile[_stage->gettileCountX() * tileY]->getCenterY(), level);
		_vEnemyPokemon.push_back(_electivire);
		break;
	}
}

void enemyManager::enemyAtkManager(int arrNum)
{
	_vEnemyPokemon[arrNum]->enemyAttackMotion();
	_vEnemyPokemon[arrNum]->getPokemonStatus();
}
void enemyManager::enemyTrunManager()
{
	
	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		for (int i = 0; i < _vEnemyPokemon.size(); i++)
		{
			bool canAtk = false;

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
				enemyMoveManager(i);
				continue;
			}
		}
	}

}