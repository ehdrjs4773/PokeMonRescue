#include "enemyManager.h"
#include "tile.h"
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

	_chicorita = new chicorita;
	_chicorita->init(_chicoName, _tile[TILEX-3+2*TILEX].getCenterX() 
		, _tile[3 + 3 * TILEX].getCenterY());

	_vEnemyPokemon.push_back(_chicorita);

	_dandegi = new dandegi;
	_dandegi->init(_dandegiName, _tile[TILEX - 3 + TILEX * 12].getCenterX()
		, _tile[TILEX - 3 + TILEX * 12 ].getCenterY());
	_vEnemyPokemon.push_back(_dandegi);


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
	enemyMoveManager();

}
void enemyManager::render()	
{

		_chicorita->render();
		_dandegi->render();
	
}


void enemyManager::enemyMoveManager()
{
	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		for (int i = 0; i < _vEnemyPokemon.size(); i++)
		{
			for (int j = 0; j < _vEnemyPokemon.size(); j++)
			{
			int currentTileX = (int)_vEnemyPokemon[i]->getX() / 24;
			int currentTileY = (int)_vEnemyPokemon[i]->getY() / 24;

				switch (_vEnemyPokemon[i]->getDirection())
				{
			case DOWN:
				if (_tile[currentTileX + TILEX *(currentTileY + 1)].gettileKind() == LAND)
				{
					_vEnemyPokemon[i]->enemyMoveSign();
				}
				break;
			case UP:
				if (_tile[currentTileX + TILEX *(currentTileY - 1)].gettileKind() == LAND)
				{
					_vEnemyPokemon[i]->enemyMoveSign();
				}
				break;
			case RIGHT:
				if (_tile[currentTileX + 1 + TILEX *currentTileY].gettileKind() == LAND)
				{
					_vEnemyPokemon[i]->enemyMoveSign();
				}
				break;
			case LEFT:
				if (_tile[currentTileX - 1 + TILEX *currentTileY].gettileKind() == LAND)
				{
					_vEnemyPokemon[i]->enemyMoveSign();
				}
				break;

			case RIGHTUP:
				if (_tile[currentTileX + 1 + TILEX *currentTileY].gettileKind() == LAND
					&& _tile[currentTileX + TILEX *(currentTileY - 1)].gettileKind() == LAND
					&& _tile[currentTileX + 1 + TILEX *(currentTileY - 1)].gettileKind() == LAND)
				{
					_vEnemyPokemon[i]->enemyMoveSign();
				}
				break;
			case LEFTUP:
				if (_tile[currentTileX - 1 + TILEX *currentTileY].gettileKind() == LAND
					&& _tile[currentTileX + TILEX *(currentTileY - 1)].gettileKind() == LAND
					&& _tile[currentTileX - 1 + TILEX *(currentTileY - 1)].gettileKind() == LAND)
				{
					_vEnemyPokemon[i]->enemyMoveSign();
				}
				break;

			case RIGHTDOWN:
				if (_tile[currentTileX + 1 + TILEX *currentTileY].gettileKind() == LAND
					&& _tile[currentTileX + TILEX *(currentTileY + 1)].gettileKind() == LAND
					&& _tile[currentTileX + 1 + TILEX *(currentTileY + 1)].gettileKind() == LAND)
				{
					_vEnemyPokemon[i]->enemyMoveSign();
				}
				break;
			case LEFTDOWN:
				if (_tile[currentTileX - 1 + TILEX *currentTileY].gettileKind() == LAND
					&& _tile[currentTileX + TILEX *(currentTileY + 1)].gettileKind() == LAND
					&& _tile[currentTileX - 1 + TILEX *(currentTileY + 1)].gettileKind() == LAND)
				{
					_vEnemyPokemon[i]->enemyMoveSign();
				}
				break;
				}
			}
		}
	}
}
