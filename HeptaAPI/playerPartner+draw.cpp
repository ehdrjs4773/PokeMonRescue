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
				_idleFrameX, _idleFrameY);
			break;
		case PARTNER_LEFT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_idleFrameX, _idleFrameY);
			break;
		case PARTNER_LEFT:
			IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_idleFrameX, _idleFrameY);
			break;
		case PARTNER_LEFT_TOP:
			IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_idleFrameX, _idleFrameY);
			break;
		case PARTNER_TOP:
			IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_idleFrameX, _idleFrameY);
			break;
		case PARTNER_RIGHT_TOP:
			IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_idleFrameX, _idleFrameY);
			break;
		case PARTNER_RIGHT:
			IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_idleFrameX, _idleFrameY);
			break;
		case PARTNER_RIGHT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_idleFrameX, _idleFrameY);
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
				_moveFrameX, _moveFrameY);
			break;
		case PARTNER_LEFT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_moveFrameX, _moveFrameY);
			break;
		case PARTNER_LEFT:
			IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_moveFrameX, _moveFrameY);
			break;
		case PARTNER_LEFT_TOP:
			IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_moveFrameX, _moveFrameY);
			break;
		case PARTNER_TOP:
			IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_moveFrameX, _moveFrameY);
			break;
		case PARTNER_RIGHT_TOP:
			IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_moveFrameX, _moveFrameY);
			break;
		case PARTNER_RIGHT:
			IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_moveFrameX, _moveFrameY);
			break;
		case PARTNER_RIGHT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_moveFrameX, _moveFrameY);
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
				_attackFrameX, _attackFrameY);
			break;
		case PARTNER_LEFT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_attackFrameX, _attackFrameY);
			break;
		case PARTNER_LEFT:
			IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_attackFrameX, _attackFrameY);
			break;
		case PARTNER_LEFT_TOP:
			IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_attackFrameX, _attackFrameY);
			break;
		case PARTNER_TOP:
			IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_attackFrameX, _attackFrameY);
			break;
		case PARTNER_RIGHT_TOP:
			IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_attackFrameX, _attackFrameY);
			break;
		case PARTNER_RIGHT:
			IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_attackFrameX, _attackFrameY);
			break;
		case PARTNER_RIGHT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_attackFrameX, _attackFrameY);
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
				_S_AttackFrameX, _S_AttackFrameY);
			break;
		case PARTNER_LEFT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_S_AttackFrameX, _S_AttackFrameY);
			break;
		case PARTNER_LEFT:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_S_AttackFrameX, _S_AttackFrameY);
			break;
		case PARTNER_LEFT_TOP:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_S_AttackFrameX, _S_AttackFrameY);
			break;
		case PARTNER_TOP:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_S_AttackFrameX, _S_AttackFrameY);
			break;
		case PARTNER_RIGHT_TOP:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_S_AttackFrameX, _S_AttackFrameY);
			break;
		case PARTNER_RIGHT:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_S_AttackFrameX, _S_AttackFrameY);
			break;
		case PARTNER_RIGHT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_S_AttackFrameX, _S_AttackFrameY);
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
				_hurtFrameX, _hurtFrameY);
			break;
		case PARTNER_LEFT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_hurtFrameX, _hurtFrameY);
			break;
		case PARTNER_LEFT:
			IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_hurtFrameX, _hurtFrameY);
			break;
		case PARTNER_LEFT_TOP:
			IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_hurtFrameX, _hurtFrameY);
			break;
		case PARTNER_TOP:
			IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_hurtFrameX, _hurtFrameY);
			break;
		case PARTNER_RIGHT_TOP:
			IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_hurtFrameX, _hurtFrameY);
			break;
		case PARTNER_RIGHT:
			IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_hurtFrameX, _hurtFrameY);
			break;
		case PARTNER_RIGHT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _partner.imageRc.left, _partner.imageRc.top,
				_hurtFrameX, _hurtFrameY);
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