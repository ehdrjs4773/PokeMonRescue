#include "stdafx.h"
#include "player.h"
#include "Stage.h"
#include "enemyManager.h"

// ===============
// ## 타일 검출 ##
// ===============
void player::tileCheak()
{
	//아래
	if (_stage->getTileAdress()[_player.tileIndex + _stage->gettileCountX()]->gettileKind() == LAND)
		_isBottomMove = true;
	else _isBottomMove = false;
	for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
	{
		if (_stage->getTileAdress()[_player.tileIndex]->getIndexX() ==
			_em->getVEnemyPokemon()[i]->getTileX() &&
			_stage->getTileAdress()[_player.tileIndex + _stage->gettileCountX()]->getIndexY() ==
			_em->getVEnemyPokemon()[i]->getTileY())
		{
			_isBottomMove = false;
			break;
		}	
	}
	
	//왼쪽아래
	if (_stage->getTileAdress()[_player.tileIndex - 1]->gettileKind() == LAND &&
		(_stage->getTileAdress()[_player.tileIndex - 1 + _stage->gettileCountX()]->gettileKind() == LAND) &&
		(_stage->getTileAdress()[_player.tileIndex + _stage->gettileCountX()]->gettileKind() == LAND))
		_isLeftBottomMove = true;
	else _isLeftBottomMove = false;
	for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
	{
		if (_stage->getTileAdress()[_player.tileIndex - 1]->getIndexX() ==
			_em->getVEnemyPokemon()[i]->getTileX() &&
			_stage->getTileAdress()[_player.tileIndex + _stage->gettileCountX()]->getIndexY() ==
			_em->getVEnemyPokemon()[i]->getTileY())
		{
			_isLeftBottomMove = false;
			break;
		}
	}

	//왼쪽
	if (_stage->getTileAdress()[_player.tileIndex - 1]->gettileKind() == LAND)
		_isLeftMove = true;
	else _isLeftMove = false;
	for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
	{
		if (_stage->getTileAdress()[_player.tileIndex - 1]->getIndexX() ==
			_em->getVEnemyPokemon()[i]->getTileX() &&
			_stage->getTileAdress()[_player.tileIndex]->getIndexY() ==
			_em->getVEnemyPokemon()[i]->getTileY())
		{
			_isLeftMove = false;
			break;
		}
	}

	//왼쪽위
	if (_stage->getTileAdress()[_player.tileIndex - 1]->gettileKind() == LAND &&
		(_stage->getTileAdress()[_player.tileIndex - 1 - _stage->gettileCountX()]->gettileKind() == LAND) &&
		(_stage->getTileAdress()[_player.tileIndex - _stage->gettileCountX()]->gettileKind() == LAND))
		_isLeftTopMove = true;
	else _isLeftTopMove = false;
	for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
	{
		if (_stage->getTileAdress()[_player.tileIndex - 1]->getIndexX() ==
			_em->getVEnemyPokemon()[i]->getTileX() &&
			_stage->getTileAdress()[_player.tileIndex - 1 - _stage->gettileCountX()]->getIndexY() ==
			_em->getVEnemyPokemon()[i]->getTileY())
		{
			_isLeftTopMove = false;
			break;
		}
	}

	//위
	if (_stage->getTileAdress()[_player.tileIndex - _stage->gettileCountX()]->gettileKind() == LAND)
		_isTopMove = true;
	else _isTopMove = false;
	for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
	{
		if (_stage->getTileAdress()[_player.tileIndex]->getIndexX() ==
			_em->getVEnemyPokemon()[i]->getTileX() &&
			_stage->getTileAdress()[_player.tileIndex - _stage->gettileCountX()]->getIndexY() ==
			_em->getVEnemyPokemon()[i]->getTileY())
		{
			_isTopMove = false;
			break;
		}
	}

	//오른쪽위
	if (_stage->getTileAdress()[_player.tileIndex + 1]->gettileKind() == LAND &&
		(_stage->getTileAdress()[_player.tileIndex + 1 - _stage->gettileCountX()]->gettileKind() == LAND) &&
		(_stage->getTileAdress()[_player.tileIndex - _stage->gettileCountX()]->gettileKind() == LAND))
		_isRightTopMove = true;
	else _isRightTopMove = false;
	for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
	{
		if (_stage->getTileAdress()[_player.tileIndex + 1]->getIndexX() ==
			_em->getVEnemyPokemon()[i]->getTileX() &&
			_stage->getTileAdress()[_player.tileIndex + 1 - _stage->gettileCountX()]->getIndexY() ==
			_em->getVEnemyPokemon()[i]->getTileY())
		{
			_isRightTopMove = false;
			break;
		}
	}

	//오른쪽
	if (_stage->getTileAdress()[_player.tileIndex + 1]->gettileKind() == LAND)
		_isRightMove = true;
	else _isRightMove = false;
	for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
	{
		if (_stage->getTileAdress()[_player.tileIndex + 1]->getIndexX() ==
			_em->getVEnemyPokemon()[i]->getTileX() &&
			_stage->getTileAdress()[_player.tileIndex]->getIndexY() ==
			_em->getVEnemyPokemon()[i]->getTileY())
		{
			_isRightMove = false;
			break;
		}
	}

	//오른쪽아래
	if (_stage->getTileAdress()[_player.tileIndex + 1]->gettileKind() == LAND &&
		(_stage->getTileAdress()[_player.tileIndex + 1 + _stage->gettileCountX()]->gettileKind() == LAND) &&
		(_stage->getTileAdress()[_player.tileIndex + _stage->gettileCountX()]->gettileKind() == LAND))
		_isRightBottomMove = true;
	else _isRightBottomMove = false;
	for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
	{
		if (_stage->getTileAdress()[_player.tileIndex + 1]->getIndexX() ==
			_em->getVEnemyPokemon()[i]->getTileX() &&
			_stage->getTileAdress()[_player.tileIndex + 1 + _stage->gettileCountX()]->getIndexY() ==
			_em->getVEnemyPokemon()[i]->getTileY())
		{
			_isRightBottomMove = false;
			break;
		}
	}

}

