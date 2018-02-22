#include "stdafx.h"
#include "player.h"
#include "Stage.h"
#include "enemyManager.h"
#include "Npc.h"

// =======================
// ## 프레임 업뎃 하는곳 ##
// =======================
void player::FrameUpdate()
{
	switch (_player.state)
	{
	case PLAYER_IDLE:
		switch (_player.direction)
		{
		case PLAYER_BOTTOM:
			_idleFrameY = 0;
			_idleCount++;
			if (_idleCount % MOVE_FRAME_UPDATE_SPEED == 0)
			{
				_idleFrameX++;
				if (_idleFrameX > IMAGEMANAGER->findImage(tempNameIdle.c_str())->getMaxFrameX())
					_idleFrameX = 0;
				_idleCount = 0;
			}

			break;
		case PLAYER_LEFT_BOTTOM:
			_idleFrameY = 1;
			_idleCount++;
			if (_idleCount % MOVE_FRAME_UPDATE_SPEED == 0)
			{
				_idleFrameX++;
				if (_idleFrameX > IMAGEMANAGER->findImage(tempNameIdle.c_str())->getMaxFrameX())
					_idleFrameX = 0;
				_idleCount = 0;
			}
			break;
		case PLAYER_LEFT:
			_idleFrameY = 2;
			_idleCount++;
			if (_idleCount % MOVE_FRAME_UPDATE_SPEED == 0)
			{
				_idleFrameX++;
				if (_idleFrameX > IMAGEMANAGER->findImage(tempNameIdle.c_str())->getMaxFrameX())
					_idleFrameX = 0;
				_idleCount = 0;
			}
			break;
		case PLAYER_LEFT_TOP:
			_idleFrameY = 3;
			_idleCount++;
			if (_idleCount % MOVE_FRAME_UPDATE_SPEED == 0)
			{
				_idleFrameX++;
				if (_idleFrameX > IMAGEMANAGER->findImage(tempNameIdle.c_str())->getMaxFrameX())
					_idleFrameX = 0;
				_idleCount = 0;
			}
			break;
		case PLAYER_TOP:
			_idleFrameY = 4;
			_idleCount++;
			if (_idleCount % MOVE_FRAME_UPDATE_SPEED == 0)
			{
				_idleFrameX++;
				if (_idleFrameX > IMAGEMANAGER->findImage(tempNameIdle.c_str())->getMaxFrameX())
					_idleFrameX = 0;
				_idleCount = 0;
			}
			break;
		case PLAYER_RIGHT_TOP:
			_idleFrameY = 5;
			_idleCount++;
			if (_idleCount % MOVE_FRAME_UPDATE_SPEED == 0)
			{
				_idleFrameX++;
				if (_idleFrameX > IMAGEMANAGER->findImage(tempNameIdle.c_str())->getMaxFrameX())
					_idleFrameX = 0;
				_idleCount = 0;
			}
			break;
		case PLAYER_RIGHT:
			_idleFrameY = 6;
			_idleCount++;
			if (_idleCount % MOVE_FRAME_UPDATE_SPEED == 0)
			{
				_idleFrameX++;
				if (_idleFrameX > IMAGEMANAGER->findImage(tempNameIdle.c_str())->getMaxFrameX())
					_idleFrameX = 0;
				_idleCount = 0;
			}
			break;
		case PLAYER_RIGHT_BOTTOM:
			_idleFrameY = 7;
			_idleCount++;
			if (_idleCount % MOVE_FRAME_UPDATE_SPEED == 0)
			{
				_idleFrameX++;
				if (_idleFrameX > IMAGEMANAGER->findImage(tempNameIdle.c_str())->getMaxFrameX())
					_idleFrameX = 0;
				_idleCount = 0;
			}
			break;
		case PLAYER_DIRECTION_END:
			break;

		}
		break;
	case PLAYER_MOVE:
		switch (_player.direction)
		{
		case PLAYER_BOTTOM:
			_moveFrameY = 0;
			_moveCount++;
			if (_moveCount % MOVE_FRAME_UPDATE_SPEED == 0)
			{
				_moveFrameX++;
				if (_moveFrameX > IMAGEMANAGER->findImage(tempNameMove.c_str())->getMaxFrameX())
					_moveFrameX = 0;
				_moveCount = 0;
			}

			break;
		case PLAYER_LEFT_BOTTOM:
			_moveFrameY = 1;
			_moveCount++;
			if (_moveCount % MOVE_FRAME_UPDATE_SPEED == 0)
			{
				_moveFrameX++;
				if (_moveFrameX > IMAGEMANAGER->findImage(tempNameMove.c_str())->getMaxFrameX())
					_moveFrameX = 0;
				_moveCount = 0;
			}
			break;
		case PLAYER_LEFT:
			_moveFrameY = 2;
			_moveCount++;
			if (_moveCount % MOVE_FRAME_UPDATE_SPEED == 0)
			{
				_moveFrameX++;
				if (_moveFrameX > IMAGEMANAGER->findImage(tempNameMove.c_str())->getMaxFrameX())
					_moveFrameX = 0;
				_moveCount = 0;
			}
			break;
		case PLAYER_LEFT_TOP:
			_moveFrameY = 3;
			_moveCount++;
			if (_moveCount % MOVE_FRAME_UPDATE_SPEED == 0)
			{
				_moveFrameX++;
				if (_moveFrameX > IMAGEMANAGER->findImage(tempNameMove.c_str())->getMaxFrameX())
					_moveFrameX = 0;
				_moveCount = 0;
			}
			break;
		case PLAYER_TOP:
			_moveFrameY = 4;
			_moveCount++;
			if (_moveCount % MOVE_FRAME_UPDATE_SPEED == 0)
			{
				_moveFrameX++;
				if (_moveFrameX > IMAGEMANAGER->findImage(tempNameMove.c_str())->getMaxFrameX())
					_moveFrameX = 0;
				_moveCount = 0;
			}
			break;
		case PLAYER_RIGHT_TOP:
			_moveFrameY = 5;
			_moveCount++;
			if (_moveCount % MOVE_FRAME_UPDATE_SPEED == 0)
			{
				_moveFrameX++;
				if (_moveFrameX > IMAGEMANAGER->findImage(tempNameMove.c_str())->getMaxFrameX())
					_moveFrameX = 0;
				_moveCount = 0;
			}
			break;
		case PLAYER_RIGHT:
			_moveFrameY = 6;
			_moveCount++;
			if (_moveCount % MOVE_FRAME_UPDATE_SPEED == 0)
			{
				_moveFrameX++;
				if (_moveFrameX > IMAGEMANAGER->findImage(tempNameMove.c_str())->getMaxFrameX())
					_moveFrameX = 0;
				_moveCount = 0;
			}
			break;
		case PLAYER_RIGHT_BOTTOM:
			_moveFrameY = 7;
			_moveCount++;
			if (_moveCount % MOVE_FRAME_UPDATE_SPEED == 0)
			{
				_moveFrameX++;
				if (_moveFrameX > IMAGEMANAGER->findImage(tempNameMove.c_str())->getMaxFrameX())
					_moveFrameX = 0;
				_moveCount = 0;
			}
			break;
		case PLAYER_DIRECTION_END:
			break;

		}
		break;
	case PLAYER_ATTACK:
		switch (_player.direction)
		{
		case PLAYER_BOTTOM:
			_attackFrameY = 0;
			_attackCount++;
			if (_attackCount % ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_attackFrameX++;
				if (_attackFrameX > IMAGEMANAGER->findImage(tempNameAttack.c_str())->getMaxFrameX())
				{
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex + _stage->gettileCountX()]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getAtk());
								break;
							}

						}
					}
					valueInit();
					_player.direction = PLAYER_BOTTOM;
					_player.state = PLAYER_IDLE;
					_playerAction = playerAttack;
				}
				_attackCount = 0;
			}
			break;
		case PLAYER_LEFT_BOTTOM:
			_attackFrameY = 1;
			_attackCount++;
			if (_attackCount % ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_attackFrameX++;
				if (_attackFrameX > IMAGEMANAGER->findImage(tempNameAttack.c_str())->getMaxFrameX())
				{
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex - 1]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex + _stage->gettileCountX()]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getAtk());
								break;
							}
						}
					}
					valueInit();
					_player.direction = PLAYER_LEFT_BOTTOM;
					_player.state = PLAYER_IDLE;
					_playerAction = playerAttack;
				}
				_attackCount = 0;
			}
			break;
		case PLAYER_LEFT:
			_attackFrameY = 2;
			_attackCount++;
			if (_attackCount % ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_attackFrameX++;
				if (_attackFrameX > IMAGEMANAGER->findImage(tempNameAttack.c_str())->getMaxFrameX())
				{
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex - 1]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getAtk());
								break;
							}
						}
					}
					valueInit();
					_player.direction = PLAYER_LEFT;
					_player.state = PLAYER_IDLE;
					_playerAction = playerAttack;
				}
				_attackCount = 0;
			}
			break;
		case PLAYER_LEFT_TOP:
			_attackFrameY = 3;
			_attackCount++;
			if (_attackCount % ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_attackFrameX++;
				if (_attackFrameX > IMAGEMANAGER->findImage(tempNameAttack.c_str())->getMaxFrameX())
				{
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex - 1]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex - 1 - _stage->gettileCountX()]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getAtk());
								break;
							}
						}
					}
					valueInit();
					_player.direction = PLAYER_LEFT_TOP;
					_player.state = PLAYER_IDLE;
					_playerAction = playerAttack;
				}
				_attackCount = 0;
			}
			break;
		case PLAYER_TOP:
			_attackFrameY = 4;
			_attackCount++;
			if (_attackCount % ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_attackFrameX++;
				if (_attackFrameX > IMAGEMANAGER->findImage(tempNameAttack.c_str())->getMaxFrameX())
				{
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex - _stage->gettileCountX()]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getAtk());
								break;
							}
						}
					}
					valueInit();
					_player.direction = PLAYER_TOP;
					_player.state = PLAYER_IDLE;
					_playerAction = playerAttack;
				}
				_attackCount = 0;
			}
			break;
		case PLAYER_RIGHT_TOP:
			_attackFrameY = 5;
			_attackCount++;
			if (_attackCount % ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_attackFrameX++;
				if (_attackFrameX > IMAGEMANAGER->findImage(tempNameAttack.c_str())->getMaxFrameX())
				{
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex + 1]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex + 1 - _stage->gettileCountX()]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getAtk());
								break;
							}
						}
					}
					valueInit();
					_player.direction = PLAYER_RIGHT_TOP;
					_player.state = PLAYER_IDLE;
					_playerAction = playerAttack;
				}
				_attackCount = 0;
			}
			break;
		case PLAYER_RIGHT:
			_attackFrameY = 6;
			_attackCount++;
			if (_attackCount % ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_attackFrameX++;
				if (_attackFrameX > IMAGEMANAGER->findImage(tempNameAttack.c_str())->getMaxFrameX())
				{
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex + 1]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getAtk());
								break;
							}
						}
					}

					valueInit();
					_player.direction = PLAYER_RIGHT;
					_player.state = PLAYER_IDLE;
					_playerAction = playerAttack;
				}
				_attackCount = 0;
			}
			break;
		case PLAYER_RIGHT_BOTTOM:
			_attackFrameY = 7;
			_attackCount++;
			if (_attackCount % ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_attackFrameX++;
				if (_attackFrameX > IMAGEMANAGER->findImage(tempNameAttack.c_str())->getMaxFrameX())
				{
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex + 1]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex + 1 + _stage->gettileCountX()]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getAtk());
								break;
							}
						}
					}
					valueInit();
					_player.direction = PLAYER_RIGHT_BOTTOM;
					_player.state = PLAYER_IDLE;
					_playerAction = playerAttack;
				}
				_attackCount = 0;
			}
			break;
		case PLAYER_DIRECTION_END:
			break;
		}
		break;
	case PLAYER_SPECIAL_ATTACK_1:
		switch (_player.direction)
		{
		case PLAYER_BOTTOM:
			_S_AttackFrameY = 0;
			_S_AttackCount++;
			if (_S_AttackCount % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX++;
				if (_S_AttackFrameX > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					EFFECTMANAGER->play(_playerStatus->getVSkill()[0]->getName(), _stage->getTileAdress()[_player.tileIndex]->getCenterX()
						, _stage->getTileAdress()[_player.tileIndex + _stage->gettileCountX()]->getCenterY());
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex + _stage->gettileCountX()]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getSpecialATK());
								break;
							}

						}
					}
					valueInit();
					_player.direction = PLAYER_BOTTOM;
					_player.state = PLAYER_IDLE;
					_playerAction = playerUseSkill;
				}
				_S_AttackCount = 0;
			}
			break;
		case PLAYER_LEFT_BOTTOM:
			_S_AttackFrameY = 1;
			_S_AttackCount++;
			if (_S_AttackCount % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX++;
				if (_S_AttackFrameX > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					EFFECTMANAGER->play(_playerStatus->getVSkill()[0]->getName(), _stage->getTileAdress()[_player.tileIndex - 1]->getCenterX()
						, _stage->getTileAdress()[_player.tileIndex + _stage->gettileCountX()]->getCenterY());
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex - 1]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex + _stage->gettileCountX()]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getSpecialATK());
								break;
							}
						}
					}
					valueInit();
					_player.direction = PLAYER_LEFT_BOTTOM;
					_player.state = PLAYER_IDLE;
					_playerAction = playerUseSkill;
				}
				_S_AttackCount = 0;
			}
			break;
		case PLAYER_LEFT:
			_S_AttackFrameY = 2;
			_S_AttackCount++;
			if (_S_AttackCount % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX++;
				if (_S_AttackFrameX > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					EFFECTMANAGER->play(_playerStatus->getVSkill()[0]->getName(), _stage->getTileAdress()[_player.tileIndex - 1]->getCenterX()
						, _stage->getTileAdress()[_player.tileIndex]->getCenterY());
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex - 1]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getSpecialATK());
								break;
							}
						}
					}
					valueInit();
					_player.direction = PLAYER_LEFT;
					_player.state = PLAYER_IDLE;
					_playerAction = playerUseSkill;
				}
				_S_AttackCount = 0;
			}
			break;
		case PLAYER_LEFT_TOP:
			_S_AttackFrameY = 3;
			_S_AttackCount++;
			if (_S_AttackCount % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX++;
				if (_S_AttackFrameX > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					EFFECTMANAGER->play(_playerStatus->getVSkill()[0]->getName(), _stage->getTileAdress()[_player.tileIndex - 1]->getCenterX()
						, _stage->getTileAdress()[_player.tileIndex - 1 - _stage->gettileCountX()]->getCenterY());
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex - 1]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex - 1 - _stage->gettileCountX()]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getSpecialATK());
								break;
							}
						}
					}
					valueInit();
					_player.direction = PLAYER_LEFT_TOP;
					_player.state = PLAYER_IDLE;
					_playerAction = playerUseSkill;
				}
				_S_AttackCount = 0;
			}
			break;
		case PLAYER_TOP:
			_S_AttackFrameY = 4;
			_S_AttackCount++;
			if (_S_AttackCount % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX++;
				if (_S_AttackFrameX > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					EFFECTMANAGER->play(_playerStatus->getVSkill()[0]->getName(), _stage->getTileAdress()[_player.tileIndex]->getCenterX()
						, _stage->getTileAdress()[_player.tileIndex - _stage->gettileCountX()]->getCenterY());
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex - _stage->gettileCountX()]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getSpecialATK());
								break;
							}
						}
					}
					valueInit();
					_player.direction = PLAYER_TOP;
					_player.state = PLAYER_IDLE;
					_playerAction = playerUseSkill;
				}
				_S_AttackCount = 0;
			}
			break;
		case PLAYER_RIGHT_TOP:
			_S_AttackFrameY = 5;
			_S_AttackCount++;
			if (_S_AttackCount % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX++;
				if (_S_AttackFrameX > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					EFFECTMANAGER->play(_playerStatus->getVSkill()[0]->getName(), _stage->getTileAdress()[_player.tileIndex + 1]->getCenterX()
						, _stage->getTileAdress()[_player.tileIndex + 1 - _stage->gettileCountX()]->getCenterY());
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex + 1]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex + 1 - _stage->gettileCountX()]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getSpecialATK());
								break;
							}
						}
					}
					valueInit();
					_player.direction = PLAYER_RIGHT_TOP;
					_player.state = PLAYER_IDLE;
					_playerAction = playerUseSkill;
				}
				_S_AttackCount = 0;
			}
			break;
		case PLAYER_RIGHT:
			_S_AttackFrameY = 6;
			_S_AttackCount++;
			if (_S_AttackCount % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX++;
				if (_S_AttackFrameX > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					EFFECTMANAGER->play(_playerStatus->getVSkill()[0]->getName(), _stage->getTileAdress()[_player.tileIndex + 1]->getCenterX()
						, _stage->getTileAdress()[_player.tileIndex]->getCenterY());
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex + 1]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getSpecialATK());
								break;
							}
						}
					}
					valueInit();
					_player.direction = PLAYER_RIGHT;
					_player.state = PLAYER_IDLE;
					_playerAction = playerUseSkill;
				}
				_S_AttackCount = 0;
			}
			break;
		case PLAYER_RIGHT_BOTTOM:
			_S_AttackFrameY = 7;
			_S_AttackCount++;
			if (_S_AttackCount % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX++;
				if (_S_AttackFrameX > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					EFFECTMANAGER->play(_playerStatus->getVSkill()[0]->getName(), _stage->getTileAdress()[_player.tileIndex + 1]->getCenterX()
						, _stage->getTileAdress()[_player.tileIndex + 1 + _stage->gettileCountX()]->getCenterY());
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex + 1]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex + 1 + _stage->gettileCountX()]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getSpecialATK());
								break;
							}
						}
					}
					valueInit();
					_player.direction = PLAYER_RIGHT_BOTTOM;
					_player.state = PLAYER_IDLE;
					_playerAction = playerUseSkill;
				}
				_S_AttackCount = 0;
			}
			break;
		case PLAYER_DIRECTION_END:
			break;

		}
		break;
	case PLAYER_SPECIAL_ATTACK_2:
		switch (_player.direction)
		{
		case PLAYER_BOTTOM:
			_S_AttackFrameY_2 = 0;
			_S_AttackCount_2++;
			if (_S_AttackCount_2 % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX_2++;
				if (_S_AttackFrameX_2 > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					EFFECTMANAGER->play(_playerStatus->getVSkill()[1]->getName(), _stage->getTileAdress()[_player.tileIndex]->getCenterX()
						, _stage->getTileAdress()[_player.tileIndex + _stage->gettileCountX()]->getCenterY());
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex + _stage->gettileCountX()]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getSpecialATK());
								break;
							}

						}
					}
					valueInit();
					_player.direction = PLAYER_BOTTOM;
					_player.state = PLAYER_IDLE;
					_playerAction = playerUseSkill;
				}
				_S_AttackCount_2 = 0;
			}
			break;
		case PLAYER_LEFT_BOTTOM:
			_S_AttackFrameY_2 = 1;
			_S_AttackCount_2++;
			if (_S_AttackCount_2 % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX_2++;
				if (_S_AttackFrameX_2 > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					EFFECTMANAGER->play(_playerStatus->getVSkill()[1]->getName(), _stage->getTileAdress()[_player.tileIndex - 1]->getCenterX()
						, _stage->getTileAdress()[_player.tileIndex + _stage->gettileCountX()]->getCenterY());
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex - 1]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex + _stage->gettileCountX()]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getSpecialATK());
								break;
							}
						}
					}
					valueInit();
					_player.direction = PLAYER_LEFT_BOTTOM;
					_player.state = PLAYER_IDLE;
					_playerAction = playerUseSkill;
				}
				_S_AttackCount_2 = 0;
			}
			break;
		case PLAYER_LEFT:
			_S_AttackFrameY_2 = 2;
			_S_AttackCount_2++;
			if (_S_AttackCount_2 % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX_2++;
				if (_S_AttackFrameX_2 > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					EFFECTMANAGER->play(_playerStatus->getVSkill()[1]->getName(), _stage->getTileAdress()[_player.tileIndex - 1]->getCenterX()
						, _stage->getTileAdress()[_player.tileIndex]->getCenterY());
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex - 1]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getSpecialATK());
								break;
							}
						}
					}
					valueInit();
					_player.direction = PLAYER_LEFT;
					_player.state = PLAYER_IDLE;
					_playerAction = playerUseSkill;
				}
				_S_AttackCount_2 = 0;
			}
			break;
		case PLAYER_LEFT_TOP:
			_S_AttackFrameY_2 = 3;
			_S_AttackCount_2++;
			if (_S_AttackCount_2 % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX_2++;
				if (_S_AttackFrameX_2 > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					EFFECTMANAGER->play(_playerStatus->getVSkill()[1]->getName(), _stage->getTileAdress()[_player.tileIndex - 1]->getCenterX()
						, _stage->getTileAdress()[_player.tileIndex - 1 - _stage->gettileCountX()]->getCenterY());
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex - 1]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex - 1 - _stage->gettileCountX()]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getSpecialATK());
								break;
							}
						}
					}
					valueInit();
					_player.direction = PLAYER_LEFT_TOP;
					_player.state = PLAYER_IDLE;
					_playerAction = playerUseSkill;
				}
				_S_AttackCount_2 = 0;
			}
			break;
		case PLAYER_TOP:
			_S_AttackFrameY_2 = 4;
			_S_AttackCount_2++;
			if (_S_AttackCount_2 % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX_2++;
				if (_S_AttackFrameX_2 > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					EFFECTMANAGER->play(_playerStatus->getVSkill()[1]->getName(), _stage->getTileAdress()[_player.tileIndex]->getCenterX()
						, _stage->getTileAdress()[_player.tileIndex - _stage->gettileCountX()]->getCenterY());
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex - _stage->gettileCountX()]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getSpecialATK());
								break;
							}
						}
					}
					valueInit();
					_player.direction = PLAYER_TOP;
					_player.state = PLAYER_IDLE;
					_playerAction = playerUseSkill;
				}
				_S_AttackCount_2 = 0;
			}
			break;
		case PLAYER_RIGHT_TOP:
			_S_AttackFrameY_2 = 5;
			_S_AttackCount_2++;
			if (_S_AttackCount_2 % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX_2++;
				if (_S_AttackFrameX_2 > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					EFFECTMANAGER->play(_playerStatus->getVSkill()[1]->getName(), _stage->getTileAdress()[_player.tileIndex + 1]->getCenterX()
						, _stage->getTileAdress()[_player.tileIndex + 1 - _stage->gettileCountX()]->getCenterY());
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex + 1]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex + 1 - _stage->gettileCountX()]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getSpecialATK());
								break;
							}
						}
					}
					valueInit();
					_player.direction = PLAYER_RIGHT_TOP;
					_player.state = PLAYER_IDLE;
					_playerAction = playerUseSkill;
				}
				_S_AttackCount_2 = 0;
			}
			break;
		case PLAYER_RIGHT:
			_S_AttackFrameY_2 = 6;
			_S_AttackCount_2++;
			if (_S_AttackCount_2 % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX_2++;
				if (_S_AttackFrameX_2 > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					EFFECTMANAGER->play(_playerStatus->getVSkill()[1]->getName(), _stage->getTileAdress()[_player.tileIndex + 1]->getCenterX()
						, _stage->getTileAdress()[_player.tileIndex]->getCenterY());
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex + 1]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getSpecialATK());
								break;
							}
						}
					}
					valueInit();
					_player.direction = PLAYER_RIGHT;
					_player.state = PLAYER_IDLE;
					_playerAction = playerUseSkill;
				}
				_S_AttackCount_2 = 0;
			}
			break;
		case PLAYER_RIGHT_BOTTOM:
			_S_AttackFrameY_2 = 7;
			_S_AttackCount_2++;
			if (_S_AttackCount_2 % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX_2++;
				if (_S_AttackFrameX_2 > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					EFFECTMANAGER->play(_playerStatus->getVSkill()[1]->getName(), _stage->getTileAdress()[_player.tileIndex + 1]->getCenterX()
						, _stage->getTileAdress()[_player.tileIndex + 1 + _stage->gettileCountX()]->getCenterY());
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex + 1]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex + 1 + _stage->gettileCountX()]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getSpecialATK());
								break;
							}
						}
					}
					valueInit();
					_player.direction = PLAYER_RIGHT_BOTTOM;
					_player.state = PLAYER_IDLE;
					_playerAction = playerUseSkill;
				}
				_S_AttackCount_2 = 0;
			}
			break;
		case PLAYER_DIRECTION_END:
			break;

		}
		break;
	case PLAYER_SPECIAL_ATTACK_3:
		switch (_player.direction)
		{
		case PLAYER_BOTTOM:
			_S_AttackFrameY_3 = 0;
			_S_AttackCount_3++;
			if (_S_AttackCount_3 % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX_3++;
				if (_S_AttackFrameX_3 > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					EFFECTMANAGER->play(_playerStatus->getVSkill()[2]->getName(), _stage->getTileAdress()[_player.tileIndex]->getCenterX()
						, _stage->getTileAdress()[_player.tileIndex + _stage->gettileCountX()]->getCenterY());
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex + _stage->gettileCountX()]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getSpecialATK());
								break;
							}

						}
					}
					valueInit();
					_player.direction = PLAYER_BOTTOM;
					_player.state = PLAYER_IDLE;
					_playerAction = playerUseSkill;
				}
				_S_AttackCount_3 = 0;
			}
			break;
		case PLAYER_LEFT_BOTTOM:
			_S_AttackFrameY_3 = 1;
			_S_AttackCount_3++;
			if (_S_AttackCount_3 % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX_3++;
				if (_S_AttackFrameX_3 > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					EFFECTMANAGER->play(_playerStatus->getVSkill()[2]->getName(), _stage->getTileAdress()[_player.tileIndex - 1]->getCenterX()
						, _stage->getTileAdress()[_player.tileIndex + _stage->gettileCountX()]->getCenterY());
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex - 1]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex + _stage->gettileCountX()]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getSpecialATK());
								break;
							}
						}
					}
					valueInit();
					_player.direction = PLAYER_LEFT_BOTTOM;
					_player.state = PLAYER_IDLE;
					_playerAction = playerUseSkill;
				}
				_S_AttackCount_3 = 0;
			}
			break;
		case PLAYER_LEFT:
			_S_AttackFrameY_3 = 2;
			_S_AttackCount_3++;
			if (_S_AttackCount_3 % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX_3++;
				if (_S_AttackFrameX_3 > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					EFFECTMANAGER->play(_playerStatus->getVSkill()[2]->getName(), _stage->getTileAdress()[_player.tileIndex - 1]->getCenterX()
						, _stage->getTileAdress()[_player.tileIndex]->getCenterY());
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex - 1]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getSpecialATK());
								break;
							}
						}
					}
					valueInit();
					_player.direction = PLAYER_LEFT;
					_player.state = PLAYER_IDLE;
					_playerAction = playerUseSkill;
				}
				_S_AttackCount_3 = 0;
			}
			break;
		case PLAYER_LEFT_TOP:
			_S_AttackFrameY_3 = 3;
			_S_AttackCount_3++;
			if (_S_AttackCount_3 % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX_3++;
				if (_S_AttackFrameX_3 > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					EFFECTMANAGER->play(_playerStatus->getVSkill()[2]->getName(), _stage->getTileAdress()[_player.tileIndex - 1]->getCenterX()
						, _stage->getTileAdress()[_player.tileIndex - 1 - _stage->gettileCountX()]->getCenterY());
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex - 1]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex - 1 - _stage->gettileCountX()]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getSpecialATK());
								break;
							}
						}
					}
					valueInit();
					_player.direction = PLAYER_LEFT_TOP;
					_player.state = PLAYER_IDLE;
					_playerAction = playerUseSkill;
				}
				_S_AttackCount_3 = 0;
			}
			break;
		case PLAYER_TOP:
			_S_AttackFrameY_3 = 4;
			_S_AttackCount_3++;
			if (_S_AttackCount_3 % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX_3++;
				if (_S_AttackFrameX_3 > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					EFFECTMANAGER->play(_playerStatus->getVSkill()[2]->getName(), _stage->getTileAdress()[_player.tileIndex]->getCenterX()
						, _stage->getTileAdress()[_player.tileIndex - _stage->gettileCountX()]->getCenterY());
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex - _stage->gettileCountX()]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getSpecialATK());
								break;
							}
						}
					}
					valueInit();
					_player.direction = PLAYER_TOP;
					_player.state = PLAYER_IDLE;
					_playerAction = playerUseSkill;
				}
				_S_AttackCount_2 = 0;
			}
			break;
		case PLAYER_RIGHT_TOP:
			_S_AttackFrameY_3 = 5;
			_S_AttackCount_3++;
			if (_S_AttackCount_3 % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX_3++;
				if (_S_AttackFrameX_3 > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					EFFECTMANAGER->play(_playerStatus->getVSkill()[2]->getName(), _stage->getTileAdress()[_player.tileIndex + 1]->getCenterX()
						, _stage->getTileAdress()[_player.tileIndex + 1 - _stage->gettileCountX()]->getCenterY());
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex + 1]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex + 1 - _stage->gettileCountX()]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getSpecialATK());
								break;
							}
						}
					}
					valueInit();
					_player.direction = PLAYER_RIGHT_TOP;
					_player.state = PLAYER_IDLE;
					_playerAction = playerUseSkill;
				}
				_S_AttackCount_3 = 0;
			}
			break;
		case PLAYER_RIGHT:
			_S_AttackFrameY_3 = 6;
			_S_AttackCount_3++;
			if (_S_AttackCount_3 % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX_3++;
				if (_S_AttackFrameX_3 > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					EFFECTMANAGER->play(_playerStatus->getVSkill()[2]->getName(), _stage->getTileAdress()[_player.tileIndex + 1]->getCenterX()
						, _stage->getTileAdress()[_player.tileIndex]->getCenterY());
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex + 1]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getSpecialATK());
								break;
							}
						}
					}
					valueInit();
					_player.direction = PLAYER_RIGHT;
					_player.state = PLAYER_IDLE;
					_playerAction = playerUseSkill;
				}
				_S_AttackCount_3 = 0;
			}
			break;
		case PLAYER_RIGHT_BOTTOM:
			_S_AttackFrameY_3 = 7;
			_S_AttackCount_3++;
			if (_S_AttackCount_3 % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX_3++;
				if (_S_AttackFrameX_3 > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					EFFECTMANAGER->play(_playerStatus->getVSkill()[2]->getName(), _stage->getTileAdress()[_player.tileIndex + 1]->getCenterX()
						, _stage->getTileAdress()[_player.tileIndex + 1 + _stage->gettileCountX()]->getCenterY());
					//공격
					for (int i = 0; i < _em->getVEnemyPokemon().size(); ++i)
					{
						if (_stage->getTileAdress()[_player.tileIndex + 1]->getIndexX() ==
							_em->getVEnemyPokemon()[i]->getTileX() &&
							_stage->getTileAdress()[_player.tileIndex + 1 + _stage->gettileCountX()]->getIndexY() ==
							_em->getVEnemyPokemon()[i]->getTileY())
						{
							if (_isAttack)
							{
								_em->getVEnemyPokemon()[i]->damageToHP(_playerStatus->getSpecialATK());
								break;
							}
						}
					}
					valueInit();
					_player.direction = PLAYER_RIGHT_BOTTOM;
					_player.state = PLAYER_IDLE;
					_playerAction = playerUseSkill;
				}
				_S_AttackCount_3 = 0;
			}
			break;
		case PLAYER_DIRECTION_END:
			break;

		}
		break;
	case PLAYER_SPECIAL_ATTACK_4:
		break;
	case PLAYER_HURT:
		switch (_player.direction)
		{
		case PLAYER_BOTTOM:
			_hurtFrameY = 0;
			_hurtCount++;
			if (_hurtCount % HURT_FRAME_UPDATE_SPEED == 0)
			{
				_hurtFrameX++;
				if (_hurtFrameX > IMAGEMANAGER->findImage(tempNameHurt.c_str())->getMaxFrameX())
				{
					valueInit();
					_isHurt = false;
					_player.direction = PLAYER_BOTTOM;
					_player.state = PLAYER_IDLE;

				}
				_hurtCount = 0;
			}
			break;
		case PLAYER_LEFT_BOTTOM:
			_hurtFrameY = 1;
			_hurtCount++;
			if (_hurtCount % HURT_FRAME_UPDATE_SPEED == 0)
			{
				_hurtFrameX++;
				if (_hurtFrameX > IMAGEMANAGER->findImage(tempNameHurt.c_str())->getMaxFrameX())
				{
					valueInit();
					_isHurt = false;
					_player.direction = PLAYER_LEFT_BOTTOM;
					_player.state = PLAYER_IDLE;

				}
				_hurtCount = 0;
			}
			break;
		case PLAYER_LEFT:
			_hurtFrameY = 2;
			_hurtCount++;
			if (_hurtCount % HURT_FRAME_UPDATE_SPEED == 0)
			{
				_hurtFrameX++;
				if (_hurtFrameX > IMAGEMANAGER->findImage(tempNameHurt.c_str())->getMaxFrameX())
				{
					valueInit();
					_isHurt = false;
					_player.direction = PLAYER_LEFT;
					_player.state = PLAYER_IDLE;

				}
				_hurtCount = 0;
			}
			break;
		case PLAYER_LEFT_TOP:
			_hurtFrameY = 3;
			_hurtCount++;
			if (_hurtCount % HURT_FRAME_UPDATE_SPEED == 0)
			{
				_hurtFrameX++;
				if (_hurtFrameX > IMAGEMANAGER->findImage(tempNameHurt.c_str())->getMaxFrameX())
				{
					valueInit();
					_isHurt = false;
					_player.direction = PLAYER_LEFT_TOP;
					_player.state = PLAYER_IDLE;

				}
				_hurtCount = 0;
			}
			break;
		case PLAYER_TOP:
			_hurtFrameY = 4;
			_hurtCount++;
			if (_hurtCount % HURT_FRAME_UPDATE_SPEED == 0)
			{
				_hurtFrameX++;
				if (_hurtFrameX > IMAGEMANAGER->findImage(tempNameHurt.c_str())->getMaxFrameX())
				{
					valueInit();
					_isHurt = false;
					_player.direction = PLAYER_TOP;
					_player.state = PLAYER_IDLE;

				}
				_hurtCount = 0;
			}
			break;
		case PLAYER_RIGHT_TOP:
			_hurtFrameY = 5;
			_hurtCount++;
			if (_hurtCount % HURT_FRAME_UPDATE_SPEED == 0)
			{
				_hurtFrameX++;
				if (_hurtFrameX > IMAGEMANAGER->findImage(tempNameHurt.c_str())->getMaxFrameX())
				{
					valueInit();
					_isHurt = false;
					_player.direction = PLAYER_RIGHT_TOP;
					_player.state = PLAYER_IDLE;

				}
				_hurtCount = 0;
			}
			break;
		case PLAYER_RIGHT:
			_hurtFrameY = 6;
			_hurtCount++;
			if (_hurtCount % HURT_FRAME_UPDATE_SPEED == 0)
			{
				_hurtFrameX++;
				if (_hurtFrameX > IMAGEMANAGER->findImage(tempNameHurt.c_str())->getMaxFrameX())
				{
					valueInit();
					_isHurt = false;
					_player.direction = PLAYER_RIGHT;
					_player.state = PLAYER_IDLE;

				}
				_hurtCount = 0;
			}
			break;
		case PLAYER_RIGHT_BOTTOM:
			_hurtFrameY = 7;
			_hurtCount++;
			if (_hurtCount % HURT_FRAME_UPDATE_SPEED == 0)
			{
				_hurtFrameX++;
				if (_hurtFrameX > IMAGEMANAGER->findImage(tempNameHurt.c_str())->getMaxFrameX())
				{
					valueInit();
					_isHurt = false;
					_player.direction = PLAYER_RIGHT_BOTTOM;
					_player.state = PLAYER_IDLE;

				}
				_hurtCount = 0;
			}
			break;
		case PLAYER_DIRECTION_END:
			break;
		}
		break;
	case PLAYER_DIE:
		_dieCount++;
		if (_dieCount % 50 == 0)
		{
			_dieFrameX++;
			if (_dieFrameX > IMAGEMANAGER->findImage(tempNameDie.c_str())->getMaxFrameX())
			{
				_playerStatus->setCurrentHP(_playerStatus->getMaxHP() / 4);
				_player.state = PLAYER_IDLE;
				_player.direction = PLAYER_BOTTOM;
				_isDie = false;
				SCENEMANAGER->changeScene("npc");
				SCENEMANAGER->init("npc");
			}
			_dieCount = 0;
			
		}
		break;
	case PLAYER_STATE_END:
		break;
	default:
		break;
	}
}