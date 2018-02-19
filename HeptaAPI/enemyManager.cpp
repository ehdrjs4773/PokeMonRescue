#include "enemyManager.h"
#include "Stage.h"

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
	enemyBirth(ENEMY_CHICORITA, 5, 5, 99);
	enemyBirth(ENEMY_DANDEGI, 6, 5, 99);
	enemyBirth(ENEMY_POLYGON, 7, 5, 99);
	enemyBirth(ENEMY_PURIN, 8, 5, 99);
	enemyBirth(ENEMY_PURIN, 9, 5, 99);
	enemyBirth(ENEMY_GRAENA, 10, 5, 99);
	enemyBirth(ENEMY_MANKEY, 11, 5, 99);
	enemyBirth(ENEMY_TANGURI, 12, 5, 99);
	


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

	for (int i = 0; i < _vEnemyPokemon.size(); i++)
	{
		_vEnemyPokemon[i]->render();
	}
	
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
				if (_tile[currentTileX + _stage->gettileCountX() *(currentTileY + 1)]->gettileKind() == LAND)
				{
					_vEnemyPokemon[i]->enemyMoveSign();
				}
				break;
			case UP:
				if (_tile[currentTileX + _stage->gettileCountX() *(currentTileY - 1)]->gettileKind() == LAND)
				{
					_vEnemyPokemon[i]->enemyMoveSign();
				}
				break;
			case RIGHT:
				if (_tile[currentTileX + 1 + _stage->gettileCountX() *currentTileY]->gettileKind() == LAND)
				{
					_vEnemyPokemon[i]->enemyMoveSign();
				}
				break;
			case LEFT:
				if (_tile[currentTileX - 1 + _stage->gettileCountX() *currentTileY]->gettileKind() == LAND)
				{
					_vEnemyPokemon[i]->enemyMoveSign();
				}
				break;

			case RIGHTUP:
				if (_tile[currentTileX + 1 + _stage->gettileCountX() *currentTileY]->gettileKind() == LAND
					&& _tile[currentTileX + _stage->gettileCountX() *(currentTileY - 1)]->gettileKind() == LAND
					&& _tile[currentTileX + 1 + _stage->gettileCountX() *(currentTileY - 1)]->gettileKind() == LAND)
				{
					_vEnemyPokemon[i]->enemyMoveSign();
				}
				break;
			case LEFTUP:
				if (_tile[currentTileX - 1 + _stage->gettileCountX() *currentTileY]->gettileKind() == LAND
					&& _tile[currentTileX + _stage->gettileCountX() *(currentTileY - 1)]->gettileKind() == LAND
					&& _tile[currentTileX - 1 + _stage->gettileCountX() *(currentTileY - 1)]->gettileKind() == LAND)
				{
					_vEnemyPokemon[i]->enemyMoveSign();
				}
				break;

			case RIGHTDOWN:
				if (_tile[currentTileX + 1 + _stage->gettileCountX() *currentTileY]->gettileKind() == LAND
					&& _tile[currentTileX + _stage->gettileCountX() *(currentTileY + 1)]->gettileKind() == LAND
					&& _tile[currentTileX + 1 + _stage->gettileCountX() *(currentTileY + 1)]->gettileKind() == LAND)
				{
					_vEnemyPokemon[i]->enemyMoveSign();
				}
				break;
			case LEFTDOWN:
				if (_tile[currentTileX - 1 + _stage->gettileCountX() *currentTileY]->gettileKind() == LAND
					&& _tile[currentTileX + _stage->gettileCountX() *(currentTileY + 1)]->gettileKind() == LAND
					&& _tile[currentTileX - 1 + _stage->gettileCountX() *(currentTileY + 1)]->gettileKind() == LAND)
				{
					_vEnemyPokemon[i]->enemyMoveSign();
				}
				break;
				}
			}
		}
	}
}


void enemyManager::enemyBirth(ENEMY enemy, int tileX, int tileY, int level)
{
	switch (enemy)
	{
	case ENEMY_CHICORITA:
		_chicorita = new chicorita;
		_chicorita->init(_chicoName, _tile[tileX]->getCenterX()
			, _tile[_stage->gettileCountX() * tileY]->getCenterY(), 5, ELEMENT_WATER);
		_vEnemyPokemon.push_back(_chicorita);
		break;
	case ENEMY_DANDEGI:
		_dandegi = new dandegi;
		_dandegi->init(_dandegiName, _tile[tileX]->getCenterX()
			, _tile[_stage->gettileCountX() * tileY]->getCenterY(), 9, ELEMENT_WATER);
		_vEnemyPokemon.push_back(_dandegi);
		break;
	case ENEMY_POLYGON:
		_polygon = new polygon;
		_polygon->init(_polygonName, _tile[tileX]->getCenterX()
			, _tile[_stage->gettileCountX() * tileY]->getCenterY(), level, ELEMENT_WATER);
		_vEnemyPokemon.push_back(_polygon);
		break;
	case ENEMY_PURIN:
		_purin = new purin;
		_purin->init(_purinName, _tile[tileX]->getCenterX()
			, _tile[_stage->gettileCountX() * tileY]->getCenterY(), level, ELEMENT_WATER);
		_vEnemyPokemon.push_back(_purin);
		break;
	case ENEMY_GRAENA:
		_graena = new graena;
		_graena->init(_graenaName, _tile[tileX]->getCenterX()
			, _tile[_stage->gettileCountX() * tileY]->getCenterY(), level, ELEMENT_WATER);
		_vEnemyPokemon.push_back(_graena);
		break;
	case ENEMY_RUKARIO:
		_rukario = new rukario;
		_rukario->init(_graenaName, _tile[tileX]->getCenterX()
			, _tile[_stage->gettileCountX() * tileY]->getCenterY(), level, ELEMENT_WATER);
		_vEnemyPokemon.push_back(_rukario);
		break;
	case ENEMY_MANKEY:
		_mankey = new mankey;
		_mankey->init(_mankeyName, _tile[tileX]->getCenterX()
			, _tile[_stage->gettileCountX() * tileY]->getCenterY(), level, ELEMENT_WATER);
		_vEnemyPokemon.push_back(_mankey);
		break;
	case ENEMY_TANGURI:
		_tanguri = new tanguri;
		_tanguri->init(_tanguriName, _tile[tileX]->getCenterX()
			, _tile[_stage->gettileCountX() * tileY]->getCenterY(), level, ELEMENT_WATER);
		_vEnemyPokemon.push_back(_tanguri);
		break;
	case ENEMY_ELECTIVIRE:
		_electivire = new electivire;
		_electivire->init(_electivireName, _tile[tileX]->getCenterX()
			, _tile[_stage->gettileCountX() * tileY]->getCenterY(), level, ELEMENT_WATER);
		_vEnemyPokemon.push_back(_electivire);
		break;
	}
}