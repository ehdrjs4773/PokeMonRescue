#include "stdafx.h"
#include "playerPartner.h"

void playerPartner::frameUpdate()
{
	switch (_partner.state)
	{
	case PARTNER_IDLE:
		switch (_partner.direction)
		{
		case PARTNER_BOTTOM:
			_idleFrameX = _idleFrameY = 0;
			break;
		case PARTNER_LEFT_BOTTOM:
			_idleFrameX = 0;
			_idleFrameY = 1;
			break;
		case PARTNER_LEFT:
			_idleFrameX = 0;
			_idleFrameY = 2;
			break;
		case PARTNER_LEFT_TOP:
			_idleFrameX = 0;
			_idleFrameY = 3;
			break;
		case PARTNER_TOP:
			_idleFrameX = 0;
			_idleFrameY = 4;
			break;
		case PARTNER_RIGHT_TOP:
			_idleFrameX = 0;
			_idleFrameY = 5;
			break;
		case PARTNER_RIGHT:
			_idleFrameX = 0;
			_idleFrameY = 6;
			break;
		case PARTNER_RIGHT_BOTTOM:
			_idleFrameX = 0;
			_idleFrameY = 7;
			break;
		case PARTNER_DIRECTION_END:
			break;

		}
		break;
	case PARTNER_MOVE:
		switch (_partner.direction)
		{
		case PARTNER_BOTTOM:
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
		case PARTNER_LEFT_BOTTOM:
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
		case PARTNER_LEFT:
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
		case PARTNER_LEFT_TOP:
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
		case PARTNER_TOP:
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
		case PARTNER_RIGHT_TOP:
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
		case PARTNER_RIGHT:
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
		case PARTNER_RIGHT_BOTTOM:
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
		case PARTNER_DIRECTION_END:
			break;

		}
		break;
	case PARTNER_ATTACK:
		switch (_partner.direction)
		{
		case PARTNER_BOTTOM:
			_attackFrameY = 0;
			_attackCount++;
			if (_attackCount % ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_attackFrameX++;
				if (_attackFrameX > IMAGEMANAGER->findImage(tempNameAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_BOTTOM;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_attackCount = 0;
			}
			break;
		case PARTNER_LEFT_BOTTOM:
			_attackFrameY = 1;
			_attackCount++;
			if (_attackCount % ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_attackFrameX++;
				if (_attackFrameX > IMAGEMANAGER->findImage(tempNameAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_LEFT_BOTTOM;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_attackCount = 0;
			}
			break;
		case PARTNER_LEFT:
			_attackFrameY = 2;
			_attackCount++;
			if (_attackCount % ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_attackFrameX++;
				if (_attackFrameX > IMAGEMANAGER->findImage(tempNameAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_LEFT;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_attackCount = 0;
			}
			break;
		case PARTNER_LEFT_TOP:
			_attackFrameY = 3;
			_attackCount++;
			if (_attackCount % ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_attackFrameX++;
				if (_attackFrameX > IMAGEMANAGER->findImage(tempNameAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_LEFT_TOP;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_attackCount = 0;
			}
			break;
		case PARTNER_TOP:
			_attackFrameY = 4;
			_attackCount++;
			if (_attackCount % ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_attackFrameX++;
				if (_attackFrameX > IMAGEMANAGER->findImage(tempNameAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_TOP;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_attackCount = 0;
			}
			break;
		case PARTNER_RIGHT_TOP:
			_attackFrameY = 5;
			_attackCount++;
			if (_attackCount % ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_attackFrameX++;
				if (_attackFrameX > IMAGEMANAGER->findImage(tempNameAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_RIGHT_TOP;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_attackCount = 0;
			}
			break;
		case PARTNER_RIGHT:
			_attackFrameY = 6;
			_attackCount++;
			if (_attackCount % ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_attackFrameX++;
				if (_attackFrameX > IMAGEMANAGER->findImage(tempNameAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_RIGHT;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_attackCount = 0;
			}
			break;
		case PARTNER_RIGHT_BOTTOM:
			_attackFrameY = 7;
			_attackCount++;
			if (_attackCount % ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_attackFrameX++;
				if (_attackFrameX > IMAGEMANAGER->findImage(tempNameAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_RIGHT_BOTTOM;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_attackCount = 0;
			}
			break;
		case PARTNER_DIRECTION_END:
			break;

		}
		break;
	case PARTNER_SPECIAL_ATTACK_1:
		switch (_partner.direction)
		{
		case PARTNER_BOTTOM:
			_S_AttackFrameY = 0;
			_S_AttackCount++;
			if (_S_AttackCount % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX++;
				if (_S_AttackFrameX > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_BOTTOM;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_S_AttackCount = 0;
			}
			break;
		case PARTNER_LEFT_BOTTOM:
			_S_AttackFrameY = 1;
			_S_AttackCount++;
			if (_S_AttackCount % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX++;
				if (_S_AttackFrameX > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_LEFT_BOTTOM;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_S_AttackCount = 0;
			}
			break;
		case PARTNER_LEFT:
			_S_AttackFrameY = 2;
			_S_AttackCount++;
			if (_S_AttackCount % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX++;
				if (_S_AttackFrameX > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_LEFT;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_S_AttackCount = 0;
			}
			break;
		case PARTNER_LEFT_TOP:
			_S_AttackFrameY = 3;
			_S_AttackCount++;
			if (_S_AttackCount % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX++;
				if (_S_AttackFrameX > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_LEFT_TOP;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_S_AttackCount = 0;
			}
			break;
		case PARTNER_TOP:
			_S_AttackFrameY = 4;
			_S_AttackCount++;
			if (_S_AttackCount % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX++;
				if (_S_AttackFrameX > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_TOP;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_S_AttackCount = 0;
			}
			break;
		case PARTNER_RIGHT_TOP:
			_S_AttackFrameY = 5;
			_S_AttackCount++;
			if (_S_AttackCount % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX++;
				if (_S_AttackFrameX > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_RIGHT_TOP;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_S_AttackCount = 0;
			}
			break;
		case PARTNER_RIGHT:
			_S_AttackFrameY = 6;
			_S_AttackCount++;
			if (_S_AttackCount % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX++;
				if (_S_AttackFrameX > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_RIGHT;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_S_AttackCount = 0;
			}
			break;
		case PARTNER_RIGHT_BOTTOM:
			_S_AttackFrameY = 7;
			_S_AttackCount++;
			if (_S_AttackCount % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_S_AttackFrameX++;
				if (_S_AttackFrameX > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_RIGHT_BOTTOM;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_S_AttackCount = 0;
			}
			break;
		case PARTNER_DIRECTION_END:
			break;

		}
		break;
	case PARTNER_SPECIAL_ATTACK_2:
		break;
	case PARTNER_HURT:
		switch (_partner.direction)
		{
		case PARTNER_BOTTOM:
			_hurtFrameY = 0;
			_hurtCount++;
			if (_hurtCount % HURT_FRAME_UPDATE_SPEED == 0)
			{
				_hurtFrameX++;
				if (_hurtFrameX > IMAGEMANAGER->findImage(tempNameHurt.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_BOTTOM;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_hurtCount = 0;
			}
			break;
		case PARTNER_LEFT_BOTTOM:
			_hurtFrameY = 1;
			_hurtCount++;
			if (_hurtCount % HURT_FRAME_UPDATE_SPEED == 0)
			{
				_hurtFrameX++;
				if (_hurtFrameX > IMAGEMANAGER->findImage(tempNameHurt.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_LEFT_BOTTOM;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_hurtCount = 0;
			}
			break;
		case PARTNER_LEFT:
			_hurtFrameY = 2;
			_hurtCount++;
			if (_hurtCount % HURT_FRAME_UPDATE_SPEED == 0)
			{
				_hurtFrameX++;
				if (_hurtFrameX > IMAGEMANAGER->findImage(tempNameHurt.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_LEFT;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_hurtCount = 0;
			}
			break;
		case PARTNER_LEFT_TOP:
			_hurtFrameY = 3;
			_hurtCount++;
			if (_hurtCount % HURT_FRAME_UPDATE_SPEED == 0)
			{
				_hurtFrameX++;
				if (_hurtFrameX > IMAGEMANAGER->findImage(tempNameHurt.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_LEFT_TOP;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_hurtCount = 0;
			}
			break;
		case PARTNER_TOP:
			_hurtFrameY = 4;
			_hurtCount++;
			if (_hurtCount % HURT_FRAME_UPDATE_SPEED == 0)
			{
				_hurtFrameX++;
				if (_hurtFrameX > IMAGEMANAGER->findImage(tempNameHurt.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_TOP;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_hurtCount = 0;
			}
			break;
		case PARTNER_RIGHT_TOP:
			_hurtFrameY = 5;
			_hurtCount++;
			if (_hurtCount % HURT_FRAME_UPDATE_SPEED == 0)
			{
				_hurtFrameX++;
				if (_hurtFrameX > IMAGEMANAGER->findImage(tempNameHurt.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_RIGHT_TOP;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_hurtCount = 0;
			}
			break;
		case PARTNER_RIGHT:
			_hurtFrameY = 6;
			_hurtCount++;
			if (_hurtCount % HURT_FRAME_UPDATE_SPEED == 0)
			{
				_hurtFrameX++;
				if (_hurtFrameX > IMAGEMANAGER->findImage(tempNameHurt.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_RIGHT;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_hurtCount = 0;
			}
			break;
		case PARTNER_RIGHT_BOTTOM:
			_hurtFrameY = 7;
			_hurtCount++;
			if (_hurtCount % HURT_FRAME_UPDATE_SPEED == 0)
			{
				_hurtFrameX++;
				if (_hurtFrameX > IMAGEMANAGER->findImage(tempNameHurt.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_RIGHT_BOTTOM;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_hurtCount = 0;
			}
			break;
		case PARTNER_DIRECTION_END:
			break;
		}
		break;
	case PARTNER_DIE:
		switch (_partner.direction)
		{
		case PARTNER_BOTTOM:
			break;
		case PARTNER_LEFT_BOTTOM:
			break;
		case PARTNER_LEFT:
			break;
		case PARTNER_LEFT_TOP:
			break;
		case PARTNER_TOP:
			break;
		case PARTNER_RIGHT_TOP:
			break;
		case PARTNER_RIGHT:
			break;
		case PARTNER_RIGHT_BOTTOM:
			break;
		case PARTNER_DIRECTION_END:
			break;

		}
		break;
	case PARTNER_STATE_END:
		break;
	default:
		break;
	}
}