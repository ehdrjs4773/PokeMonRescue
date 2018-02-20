#include "stdafx.h"
#include "playerPartner.h"

void playerPartner::draw()
{
	HDC hdc = CAMERAMANAGER->getMemDC();

	switch (_partner.state)
	{
	case PARTNER_IDLE:
		switch (_partner.direction)
		{
		case PARTNER_BOTTOM:
			IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_bottomIdleFrameX, _bottomIdleFrameY);
			break;
		case PARTNER_LEFT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_leftBottomIdleFrameX, _leftBottomIdleFrameY);
			break;
		case PARTNER_LEFT:
			IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_leftIdleFrameX, _leftIdleFrameY);
			break;
		case PARTNER_LEFT_TOP:
			IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_leftTopIdleFrameX, _leftTopIdleFrameY);
			break;
		case PARTNER_TOP:
			IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_topIdleFrameX, _topIdleFrameY);
			break;
		case PARTNER_RIGHT_TOP:
			IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_rightTopIdleFrameX, _rightTopIdleFrameY);
			break;
		case PARTNER_RIGHT:
			IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_rightIdleFrameX, _rightIdleFrameY);
			break;
		case PARTNER_RIGHT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_rightBottomIdleFrameX, _rightBottomIdleFrameY);
			break;
		case PARTNER_DIRECTION_END:
			break;

		}
		break;
	case PARTNER_MOVE:
		switch (_partner.direction)
		{
		case PARTNER_BOTTOM:
			IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_bottomMoveFrameX, _bottomMoveFrameY);
			break;
		case PARTNER_LEFT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_leftBottomMoveFrameX, _leftBottomMoveFrameY);
			break;
		case PARTNER_LEFT:
			IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_leftMoveFrameX, _leftMoveFrameY);
			break;
		case PARTNER_LEFT_TOP:
			IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_leftTopMoveFrameX, _leftTopMoveFrameY);
			break;
		case PARTNER_TOP:
			IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_topMoveFrameX, _topMoveFrameY);
			break;
		case PARTNER_RIGHT_TOP:
			IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_rightTopMoveFrameX, _rightTopMoveFrameY);
			break;
		case PARTNER_RIGHT:
			IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_rightMoveFrameX, _rightMoveFrameY);
			break;
		case PARTNER_RIGHT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_rightBottomMoveFrameX, _rightBottomMoveFrameY);
			break;
		case PARTNER_DIRECTION_END:
			break;

		}
		break;
	case PARTNER_ATTACK:
		switch (_partner.direction)
		{
		case PARTNER_BOTTOM:
			IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_bottomMoveFrameX, _bottomMoveFrameY);
			break;
		case PARTNER_LEFT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_leftBottomMoveFrameX, _leftBottomMoveFrameY);
			break;
		case PARTNER_LEFT:
			IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_leftMoveFrameX, _leftMoveFrameY);
			break;
		case PARTNER_LEFT_TOP:
			IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_leftTopMoveFrameX, _leftTopMoveFrameY);
			break;
		case PARTNER_TOP:
			IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_topMoveFrameX, _topMoveFrameY);
			break;
		case PARTNER_RIGHT_TOP:
			IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_rightTopMoveFrameX, _rightTopMoveFrameY);
			break;
		case PARTNER_RIGHT:
			IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_rightMoveFrameX, _rightMoveFrameY);
			break;
		case PARTNER_RIGHT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_rightBottomMoveFrameX, _rightBottomMoveFrameY);
			break;
		case PARTNER_DIRECTION_END:
			break;

		}
		break;
	case PARTNER_SPECIAL_ATTACK_1:
		switch (_partner.direction)
		{
		case PARTNER_BOTTOM:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_bottomSpecialAttackFrameX, _bottomSpecialAttackFrameY);
			break;
		case PARTNER_LEFT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_leftBottomSpecialAttackFrameX, _leftBottomSpecialAttackFrameY);
			break;
		case PARTNER_LEFT:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_leftSpecialAttackFrameX, _leftSpecialAttackFrameY);
			break;
		case PARTNER_LEFT_TOP:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_leftTopSpecialAttackFrameX, _leftTopSpecialAttackFrameY);
			break;
		case PARTNER_TOP:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_topSpecialAttackFrameX, _topSpecialAttackFrameY);
			break;
		case PARTNER_RIGHT_TOP:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_rightTopSpecialAttackFrameX, _rightTopSpecialAttackFrameY);
			break;
		case PARTNER_RIGHT:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_rightSpecialAttackFrameX, _rightSpecialAttackFrameY);
			break;
		case PARTNER_RIGHT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_rightBottomSpecialAttackFrameX, _rightBottomSpecialAttackFrameY);
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
			IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_bottomHurtFrameX, _bottomHurtFrameY);
			break;
		case PARTNER_LEFT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_leftBottomHurtFrameX, _leftBottomHurtFrameY);
			break;
		case PARTNER_LEFT:
			IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_leftHurtFrameX, _leftHurtFrameY);
			break;
		case PARTNER_LEFT_TOP:
			IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_leftTopHurtFrameX, _leftTopHurtFrameY);
			break;
		case PARTNER_TOP:
			IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_topHurtFrameX, _topHurtFrameY);
			break;
		case PARTNER_RIGHT_TOP:
			IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_rightTopHurtFrameX, _rightTopHurtFrameY);
			break;
		case PARTNER_RIGHT:
			IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_rightHurtFrameX, _rightHurtFrameY);
			break;
		case PARTNER_RIGHT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_rightBottomHurtFrameX, _rightBottomHurtFrameY);
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