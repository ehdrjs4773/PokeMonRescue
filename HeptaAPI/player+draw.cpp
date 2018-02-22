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
		IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
			_idleFrameX, _idleFrameY);
		break;
	case PLAYER_MOVE:
		IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
			_moveFrameX, _moveFrameY);
		break;
	case PLAYER_ATTACK:
		IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
			_attackFrameX, _attackFrameY);
		break;
	case PLAYER_SPECIAL_ATTACK_1:
		IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
			_S_AttackFrameX, _S_AttackFrameY);
		break;
	case PLAYER_SPECIAL_ATTACK_2:
		IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
			_S_AttackFrameX_2, _S_AttackFrameY_2);
		break;
	case PLAYER_SPECIAL_ATTACK_3:
		IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
			_S_AttackFrameX_3, _S_AttackFrameY_3);
		break;
	case PLAYER_SPECIAL_ATTACK_4:
		IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
			_S_AttackFrameX_4, _S_AttackFrameY_4);
		break;
	case PLAYER_HURT:
		IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
			_hurtFrameX, _hurtFrameY);
		break;
	case PLAYER_DIE:
		IMAGEMANAGER->findImage(tempNameDie.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
			_dieFrameX, 0);		
		break;
	case PLAYER_STATE_END:
		break;

	}
}