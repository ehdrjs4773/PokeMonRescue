#include "stdafx.h"
#include "player.h"

// =======================
// ## 이미지 그려주는 곳 ## 
// =======================
void player::draw()
{
	HDC hdc = CAMERAMANAGER->getMemDC();
	switch (_player.state)
	{
	case PLAYER_IDLE:
		switch (_player.direction)
		{
		case PLAYER_BOTTOM:
			IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_idleFrameX, _idleFrameY);
			break;
		case PLAYER_LEFT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_idleFrameX, _idleFrameY);
			break;
		case PLAYER_LEFT:
			IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_idleFrameX, _idleFrameY);
			break;
		case PLAYER_LEFT_TOP:
			IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_idleFrameX, _idleFrameY);
			break;
		case PLAYER_TOP:
			IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_idleFrameX, _idleFrameY);
			break;
		case PLAYER_RIGHT_TOP:
			IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_idleFrameX, _idleFrameY);
			break;
		case PLAYER_RIGHT:
			IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_idleFrameX, _idleFrameY);
			break;
		case PLAYER_RIGHT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_idleFrameX, _idleFrameY);
			break;
		case PLAYER_DIRECTION_END:
			break;

		}
		break;
	case PLAYER_MOVE:
		switch (_player.direction)
		{
		case PLAYER_BOTTOM:
			IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_moveFrameX, _moveFrameY);
			break;
		case PLAYER_LEFT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_moveFrameX, _moveFrameY);
			break;
		case PLAYER_LEFT:
			IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_moveFrameX, _moveFrameY);
			break;
		case PLAYER_LEFT_TOP:
			IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_moveFrameX, _moveFrameY);
			break;
		case PLAYER_TOP:
			IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_moveFrameX, _moveFrameY);
			break;
		case PLAYER_RIGHT_TOP:
			IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_moveFrameX, _moveFrameY);
			break;
		case PLAYER_RIGHT:
			IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_moveFrameX, _moveFrameY);
			break;
		case PLAYER_RIGHT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_moveFrameX, _moveFrameY);
			break;
		case PLAYER_DIRECTION_END:
			break;

		}
		break;
	case PLAYER_ATTACK:
		switch (_player.direction)
		{
		case PLAYER_BOTTOM:
			IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_attackFrameX, _attackFrameY);
			break;
		case PLAYER_LEFT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_attackFrameX, _attackFrameY);
			break;
		case PLAYER_LEFT:
			IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_attackFrameX, _attackFrameY);
			break;
		case PLAYER_LEFT_TOP:
			IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_attackFrameX, _attackFrameY);
			break;
		case PLAYER_TOP:
			IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_attackFrameX, _attackFrameY);
			break;
		case PLAYER_RIGHT_TOP:
			IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_attackFrameX, _attackFrameY);
			break;
		case PLAYER_RIGHT:
			IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_attackFrameX, _attackFrameY);
			break;
		case PLAYER_RIGHT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_attackFrameX, _attackFrameY);
			break;
		case PLAYER_DIRECTION_END:
			break;

		}
		break;
	case PLAYER_SPECIAL_ATTACK_1:
		switch (_player.direction)
		{
		case PLAYER_BOTTOM:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX, _S_AttackFrameY);
			break;
		case PLAYER_LEFT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX, _S_AttackFrameY);
			break;
		case PLAYER_LEFT:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX, _S_AttackFrameY);
			break;
		case PLAYER_LEFT_TOP:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX, _S_AttackFrameY);
			break;
		case PLAYER_TOP:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX, _S_AttackFrameY);
			break;
		case PLAYER_RIGHT_TOP:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX, _S_AttackFrameY);
			break;
		case PLAYER_RIGHT:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX, _S_AttackFrameY);
			break;
		case PLAYER_RIGHT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX, _S_AttackFrameY);
			break;
			break;
		case PLAYER_DIRECTION_END:
			break;

		}
		break;
	case PLAYER_SPECIAL_ATTACK_2:
		switch (_player.direction)
		{
		case PLAYER_BOTTOM:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX_2, _S_AttackFrameY_2);
			break;
		case PLAYER_LEFT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX_2, _S_AttackFrameY_2);
			break;
		case PLAYER_LEFT:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX_2, _S_AttackFrameY_2);
			break;
		case PLAYER_LEFT_TOP:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX_2, _S_AttackFrameY_2);
			break;
		case PLAYER_TOP:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX_2, _S_AttackFrameY_2);
			break;
		case PLAYER_RIGHT_TOP:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX_2, _S_AttackFrameY_2);
			break;
		case PLAYER_RIGHT:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX_2, _S_AttackFrameY_2);
			break;
		case PLAYER_RIGHT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX_2, _S_AttackFrameY_2);
			break;
			break;
		case PLAYER_DIRECTION_END:
			break;

		}
		break;
	case PLAYER_SPECIAL_ATTACK_3:
		switch (_player.direction)
		{
		case PLAYER_BOTTOM:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX_3, _S_AttackFrameY_3);
			break;
		case PLAYER_LEFT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX_3, _S_AttackFrameY_3);
			break;
		case PLAYER_LEFT:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX_3, _S_AttackFrameY_3);
			break;
		case PLAYER_LEFT_TOP:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX_3, _S_AttackFrameY_3);
			break;
		case PLAYER_TOP:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX_3, _S_AttackFrameY_3);
			break;
		case PLAYER_RIGHT_TOP:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX_3, _S_AttackFrameY_3);
			break;
		case PLAYER_RIGHT:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX_3, _S_AttackFrameY_3);
			break;
		case PLAYER_RIGHT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX_3, _S_AttackFrameY_3);
			break;
			break;
		case PLAYER_DIRECTION_END:
			break;

		}
		break;
	case PLAYER_SPECIAL_ATTACK_4:
		switch (_player.direction)
		{
		case PLAYER_BOTTOM:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX_4, _S_AttackFrameY_4);
			break;
		case PLAYER_LEFT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX_4, _S_AttackFrameY_4);
			break;
		case PLAYER_LEFT:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX_4, _S_AttackFrameY_4);
			break;
		case PLAYER_LEFT_TOP:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX_4, _S_AttackFrameY_4);
			break;
		case PLAYER_TOP:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX_4, _S_AttackFrameY_4);
			break;
		case PLAYER_RIGHT_TOP:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX_4, _S_AttackFrameY_4);
			break;
		case PLAYER_RIGHT:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX_4, _S_AttackFrameY_4);
			break;
		case PLAYER_RIGHT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_S_AttackFrameX_4, _S_AttackFrameY_4);
			break;
			break;
		case PLAYER_DIRECTION_END:
			break;

		}
		break;
	case PLAYER_HURT:
		switch (_player.direction)
		{
		case PLAYER_BOTTOM:
			IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_hurtFrameX, _hurtFrameY);
			break;
		case PLAYER_LEFT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_hurtFrameX, _hurtFrameY);
			break;
		case PLAYER_LEFT:
			IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_hurtFrameX, _hurtFrameY);
			break;
		case PLAYER_LEFT_TOP:
			IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_hurtFrameX, _hurtFrameY);
			break;
		case PLAYER_TOP:
			IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_hurtFrameX, _hurtFrameY);
			break;
		case PLAYER_RIGHT_TOP:
			IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_hurtFrameX, _hurtFrameY);
			break;
		case PLAYER_RIGHT:
			IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_hurtFrameX, _hurtFrameY);
			break;
		case PLAYER_RIGHT_BOTTOM:
			IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
				_hurtFrameX, _hurtFrameY);
			break;
		case PLAYER_DIRECTION_END:
			break;
		}
		break;
	case PLAYER_DIE:
		IMAGEMANAGER->findImage(tempNameDie.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
			_dieFrameX, 0);		
		break;
	case PLAYER_STATE_END:
		break;

	}
}