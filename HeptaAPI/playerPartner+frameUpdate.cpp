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
			_bottomIdleFrameX = _bottomIdleFrameY = 0;
			break;
		case PARTNER_LEFT_BOTTOM:
			_leftBottomIdleFrameX = 0;
			_leftBottomIdleFrameY = 1;
			break;
		case PARTNER_LEFT:
			_leftIdleFrameX = 0;
			_leftIdleFrameY = 2;
			break;
		case PARTNER_LEFT_TOP:
			_leftTopIdleFrameX = 0;
			_leftTopIdleFrameY = 3;
			break;
		case PARTNER_TOP:
			_topIdleFrameX = 0;
			_topIdleFrameY = 4;
			break;
		case PARTNER_RIGHT_TOP:
			_rightTopIdleFrameX = 0;
			_rightTopIdleFrameY = 5;
			break;
		case PARTNER_RIGHT:
			_rightIdleFrameX = 0;
			_rightIdleFrameY = 6;
			break;
		case PARTNER_RIGHT_BOTTOM:
			_rightBottomIdleFrameX = 0;
			_rightBottomIdleFrameY = 7;
			break;
		case PARTNER_DIRECTION_END:
			break;

		}
		break;
	case PARTNER_MOVE:
		switch (_partner.direction)
		{
		case PARTNER_BOTTOM:
			_bottomMoveFrameY = 0;
			_bottomMoveCount++;
			if (_bottomMoveCount % MOVE_FRAME_UPDATE_SPEED == 0)
			{
				_bottomMoveFrameX++;
				if (_bottomMoveFrameX > IMAGEMANAGER->findImage(tempNameMove.c_str())->getMaxFrameX())
					_bottomMoveFrameX = 0;
				_bottomMoveCount = 0;
			}

			break;
		case PARTNER_LEFT_BOTTOM:
			_leftBottomMoveFrameY = 1;
			_leftBottomMoveCount++;
			if (_leftBottomMoveCount % MOVE_FRAME_UPDATE_SPEED == 0)
			{
				_leftBottomMoveFrameX++;
				if (_leftBottomMoveFrameX > IMAGEMANAGER->findImage(tempNameMove.c_str())->getMaxFrameX())
					_leftBottomMoveFrameX = 0;
				_leftBottomMoveCount = 0;
			}
			break;
		case PARTNER_LEFT:
			_leftMoveFrameY = 2;
			_leftMoveCount++;
			if (_leftMoveCount % MOVE_FRAME_UPDATE_SPEED == 0)
			{
				_leftMoveFrameX++;
				if (_leftMoveFrameX > IMAGEMANAGER->findImage(tempNameMove.c_str())->getMaxFrameX())
					_leftMoveFrameX = 0;
				_leftMoveCount = 0;
			}
			break;
		case PARTNER_LEFT_TOP:
			_leftTopMoveFrameY = 3;
			_leftTopMoveCount++;
			if (_leftTopMoveCount % MOVE_FRAME_UPDATE_SPEED == 0)
			{
				_leftTopMoveFrameX++;
				if (_leftTopMoveFrameX > IMAGEMANAGER->findImage(tempNameMove.c_str())->getMaxFrameX())
					_leftTopMoveFrameX = 0;
				_leftTopMoveCount = 0;
			}
			break;
		case PARTNER_TOP:
			_topMoveFrameY = 4;
			_topMoveCount++;
			if (_topMoveCount % MOVE_FRAME_UPDATE_SPEED == 0)
			{
				_topMoveFrameX++;
				if (_topMoveFrameX > IMAGEMANAGER->findImage(tempNameMove.c_str())->getMaxFrameX())
					_topMoveFrameX = 0;
				_topMoveCount = 0;
			}
			break;
		case PARTNER_RIGHT_TOP:
			_rightTopMoveFrameY = 5;
			_rightTopMoveCount++;
			if (_rightTopMoveCount % MOVE_FRAME_UPDATE_SPEED == 0)
			{
				_rightTopMoveFrameX++;
				if (_rightTopMoveFrameX > IMAGEMANAGER->findImage(tempNameMove.c_str())->getMaxFrameX())
					_rightTopMoveFrameX = 0;
				_rightTopMoveCount = 0;
			}
			break;
		case PARTNER_RIGHT:
			_rightMoveFrameY = 6;
			_rightMoveCount++;
			if (_rightMoveCount % MOVE_FRAME_UPDATE_SPEED == 0)
			{
				_rightMoveFrameX++;
				if (_rightMoveFrameX > IMAGEMANAGER->findImage(tempNameMove.c_str())->getMaxFrameX())
					_rightMoveFrameX = 0;
				_rightMoveCount = 0;
			}
			break;
		case PARTNER_RIGHT_BOTTOM:
			_rightBottomMoveFrameY = 7;
			_rightBottomMoveCount++;
			if (_rightBottomMoveCount % MOVE_FRAME_UPDATE_SPEED == 0)
			{
				_rightBottomMoveFrameX++;
				if (_rightBottomMoveFrameX > IMAGEMANAGER->findImage(tempNameMove.c_str())->getMaxFrameX())
					_rightBottomMoveFrameX = 0;
				_rightBottomMoveCount = 0;
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
			_bottomAttackFrameY = 0;
			_bottomAttackCount++;
			if (_bottomAttackCount % ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_bottomAttackFrameX++;
				if (_bottomAttackFrameX > IMAGEMANAGER->findImage(tempNameAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_BOTTOM;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_bottomAttackCount = 0;
			}
			break;
		case PARTNER_LEFT_BOTTOM:
			_leftBottomAttackFrameY = 1;
			_leftBottomAttackCount++;
			if (_leftBottomAttackCount % ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_leftBottomAttackFrameX++;
				if (_leftBottomAttackFrameX > IMAGEMANAGER->findImage(tempNameAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_LEFT_BOTTOM;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_leftBottomAttackCount = 0;
			}
			break;
		case PARTNER_LEFT:
			_leftAttackFrameY = 2;
			_leftAttackCount++;
			if (_leftAttackCount % ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_leftAttackFrameX++;
				if (_leftAttackFrameX > IMAGEMANAGER->findImage(tempNameAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_LEFT;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_leftAttackCount = 0;
			}
			break;
		case PARTNER_LEFT_TOP:
			_leftTopAttackFrameY = 3;
			_leftTopAttackCount++;
			if (_leftTopAttackCount % ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_leftTopAttackFrameX++;
				if (_leftTopAttackFrameX > IMAGEMANAGER->findImage(tempNameAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_LEFT_TOP;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_leftTopAttackCount = 0;
			}
			break;
		case PARTNER_TOP:
			_topAttackFrameY = 4;
			_topAttackCount++;
			if (_topAttackCount % ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_topAttackFrameX++;
				if (_topAttackFrameX > IMAGEMANAGER->findImage(tempNameAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_TOP;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_topAttackCount = 0;
			}
			break;
		case PARTNER_RIGHT_TOP:
			_rightTopAttackFrameY = 5;
			_rightTopAttackCount++;
			if (_rightTopAttackCount % ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_rightTopAttackFrameX++;
				if (_rightTopAttackFrameX > IMAGEMANAGER->findImage(tempNameAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_RIGHT_TOP;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_rightTopAttackCount = 0;
			}
			break;
		case PARTNER_RIGHT:
			_rightAttackFrameY = 6;
			_rightAttackCount++;
			if (_rightAttackCount % ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_rightAttackFrameX++;
				if (_rightAttackFrameX > IMAGEMANAGER->findImage(tempNameAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_RIGHT;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_rightAttackCount = 0;
			}
			break;
		case PARTNER_RIGHT_BOTTOM:
			_rightBottomAttackFrameY = 7;
			_rightBottomAttackCount++;
			if (_rightBottomAttackCount % ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_rightBottomAttackFrameX++;
				if (_rightBottomAttackFrameX > IMAGEMANAGER->findImage(tempNameAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_RIGHT_BOTTOM;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_rightBottomAttackCount = 0;
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
			_bottomSpecialAttackFrameY = 0;
			_bottomSpecialAttackCount++;
			if (_bottomSpecialAttackCount % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_bottomSpecialAttackFrameX++;
				if (_bottomSpecialAttackFrameX > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_BOTTOM;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_bottomSpecialAttackCount = 0;
			}
			break;
		case PARTNER_LEFT_BOTTOM:
			_leftBottomSpecialAttackFrameY = 1;
			_leftBottomSpecialAttackCount++;
			if (_leftBottomSpecialAttackCount % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_leftBottomSpecialAttackFrameX++;
				if (_leftBottomSpecialAttackFrameX > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_LEFT_BOTTOM;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_leftBottomSpecialAttackCount = 0;
			}
			break;
		case PARTNER_LEFT:
			_leftSpecialAttackFrameY = 2;
			_leftSpecialAttackCount++;
			if (_leftSpecialAttackCount % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_leftSpecialAttackFrameX++;
				if (_leftSpecialAttackFrameX > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_LEFT;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_leftSpecialAttackCount = 0;
			}
			break;
		case PARTNER_LEFT_TOP:
			_leftTopSpecialAttackFrameY = 3;
			_leftTopSpecialAttackCount++;
			if (_leftTopSpecialAttackCount % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_leftTopSpecialAttackFrameX++;
				if (_leftTopSpecialAttackFrameX > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_LEFT_TOP;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_leftTopSpecialAttackCount = 0;
			}
			break;
		case PARTNER_TOP:
			_topSpecialAttackFrameY = 4;
			_topSpecialAttackCount++;
			if (_topSpecialAttackCount % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_topSpecialAttackFrameX++;
				if (_topSpecialAttackFrameX > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_TOP;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_topSpecialAttackCount = 0;
			}
			break;
		case PARTNER_RIGHT_TOP:
			_rightTopSpecialAttackFrameY = 5;
			_rightTopSpecialAttackCount++;
			if (_rightTopSpecialAttackCount % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_rightTopSpecialAttackFrameX++;
				if (_rightTopSpecialAttackFrameX > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_RIGHT_TOP;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_rightTopSpecialAttackCount = 0;
			}
			break;
		case PARTNER_RIGHT:
			_rightSpecialAttackFrameY = 6;
			_rightSpecialAttackCount++;
			if (_rightSpecialAttackCount % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_rightSpecialAttackFrameX++;
				if (_rightSpecialAttackFrameX > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_RIGHT;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_rightSpecialAttackCount = 0;
			}
			break;
		case PARTNER_RIGHT_BOTTOM:
			_rightBottomSpecialAttackFrameY = 7;
			_rightBottomSpecialAttackCount++;
			if (_rightBottomSpecialAttackCount % S_ATTACK_FRAME_UPDATE_SPEED == 0)
			{
				_rightBottomSpecialAttackFrameX++;
				if (_rightBottomSpecialAttackFrameX > IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_RIGHT_BOTTOM;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_rightBottomSpecialAttackCount = 0;
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
			_bottomHurtFrameY = 0;
			_bottomHurtCount++;
			if (_bottomHurtCount % HURT_FRAME_UPDATE_SPEED == 0)
			{
				_bottomHurtFrameX++;
				if (_bottomHurtFrameX > IMAGEMANAGER->findImage(tempNameHurt.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_BOTTOM;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_bottomHurtCount = 0;
			}
			break;
		case PARTNER_LEFT_BOTTOM:
			_leftBottomHurtFrameY = 1;
			_leftBottomHurtCount++;
			if (_leftBottomHurtCount % HURT_FRAME_UPDATE_SPEED == 0)
			{
				_leftBottomHurtFrameX++;
				if (_leftBottomHurtFrameX > IMAGEMANAGER->findImage(tempNameHurt.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_LEFT_BOTTOM;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_leftBottomHurtCount = 0;
			}
			break;
		case PARTNER_LEFT:
			_leftHurtFrameY = 2;
			_leftHurtCount++;
			if (_leftHurtCount % HURT_FRAME_UPDATE_SPEED == 0)
			{
				_leftHurtFrameX++;
				if (_leftHurtFrameX > IMAGEMANAGER->findImage(tempNameHurt.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_LEFT;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_leftHurtCount = 0;
			}
			break;
		case PARTNER_LEFT_TOP:
			_leftTopHurtFrameY = 3;
			_leftTopHurtCount++;
			if (_leftTopHurtCount % HURT_FRAME_UPDATE_SPEED == 0)
			{
				_leftTopHurtFrameX++;
				if (_leftTopHurtFrameX > IMAGEMANAGER->findImage(tempNameHurt.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_LEFT_TOP;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_leftTopHurtCount = 0;
			}
			break;
		case PARTNER_TOP:
			_topHurtFrameY = 4;
			_topHurtCount++;
			if (_topHurtCount % HURT_FRAME_UPDATE_SPEED == 0)
			{
				_topHurtFrameX++;
				if (_topHurtFrameX > IMAGEMANAGER->findImage(tempNameHurt.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_TOP;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_topHurtCount = 0;
			}
			break;
		case PARTNER_RIGHT_TOP:
			_rightTopHurtFrameY = 5;
			_rightTopHurtCount++;
			if (_rightTopHurtCount % HURT_FRAME_UPDATE_SPEED == 0)
			{
				_rightTopHurtFrameX++;
				if (_rightTopHurtFrameX > IMAGEMANAGER->findImage(tempNameHurt.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_RIGHT_TOP;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_rightTopHurtCount = 0;
			}
			break;
		case PARTNER_RIGHT:
			_rightHurtFrameY = 6;
			_rightHurtCount++;
			if (_rightHurtCount % HURT_FRAME_UPDATE_SPEED == 0)
			{
				_rightHurtFrameX++;
				if (_rightHurtFrameX > IMAGEMANAGER->findImage(tempNameHurt.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_RIGHT;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_rightHurtCount = 0;
			}
			break;
		case PARTNER_RIGHT_BOTTOM:
			_rightBottomHurtFrameY = 7;
			_rightBottomHurtCount++;
			if (_rightBottomHurtCount % HURT_FRAME_UPDATE_SPEED == 0)
			{
				_rightBottomHurtFrameX++;
				if (_rightBottomHurtFrameX > IMAGEMANAGER->findImage(tempNameHurt.c_str())->getMaxFrameX())
				{
					_partner.direction = PARTNER_RIGHT_BOTTOM;
					_partner.state = PARTNER_IDLE;
					valueInit();
				}
				_rightBottomHurtCount = 0;
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