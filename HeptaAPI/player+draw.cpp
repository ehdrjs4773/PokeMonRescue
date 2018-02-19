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
					_bottomIdleFrameX, _bottomIdleFrameY);
			break;
			case PLAYER_LEFT_BOTTOM:
				IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_leftBottomIdleFrameX, _leftBottomIdleFrameY);
			break;
			case PLAYER_LEFT:
				IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_leftIdleFrameX, _leftIdleFrameY);
			break;
			case PLAYER_LEFT_TOP:
				IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_leftTopIdleFrameX, _leftTopIdleFrameY);
			break;
			case PLAYER_TOP:
				IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_topIdleFrameX, _topIdleFrameY);
			break;
			case PLAYER_RIGHT_TOP:
				IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_rightTopIdleFrameX, _rightTopIdleFrameY);
			break;
			case PLAYER_RIGHT:
				IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_rightIdleFrameX, _rightIdleFrameY);
			break;
			case PLAYER_RIGHT_BOTTOM:
				IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_rightBottomIdleFrameX, _rightBottomIdleFrameY);
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
					_bottomMoveFrameX, _bottomMoveFrameY);
			break;
			case PLAYER_LEFT_BOTTOM:
				IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_leftBottomMoveFrameX, _leftBottomMoveFrameY);
			break;
			case PLAYER_LEFT:
				IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_leftMoveFrameX, _leftMoveFrameY);
			break;
			case PLAYER_LEFT_TOP:
				IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_leftTopMoveFrameX, _leftTopMoveFrameY);
			break;
			case PLAYER_TOP:
				IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_topMoveFrameX, _topMoveFrameY);
			break;
			case PLAYER_RIGHT_TOP:
				IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_rightTopMoveFrameX, _rightTopMoveFrameY);
			break;
			case PLAYER_RIGHT:
				IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_rightMoveFrameX, _rightMoveFrameY);
			break;
			case PLAYER_RIGHT_BOTTOM:
				IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_rightBottomMoveFrameX, _rightBottomMoveFrameY);
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
					_bottomAttackFrameX, _bottomAttackFrameY);
			break;
			case PLAYER_LEFT_BOTTOM:
				IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_leftBottomAttackFrameX, _leftBottomAttackFrameY);
			break;
			case PLAYER_LEFT:
				IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_leftAttackFrameX, _leftAttackFrameY);
			break;
			case PLAYER_LEFT_TOP:
				IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_leftTopAttackFrameX, _leftTopAttackFrameY);
			break;
			case PLAYER_TOP:
				IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_topAttackFrameX, _topAttackFrameY);
			break;
			case PLAYER_RIGHT_TOP:
				IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_rightTopAttackFrameX, _rightTopAttackFrameY);
			break;
			case PLAYER_RIGHT:
				IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_rightAttackFrameX, _rightAttackFrameY);
			break;
			case PLAYER_RIGHT_BOTTOM:
				IMAGEMANAGER->findImage(tempNameAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_rightBottomAttackFrameX, _rightBottomAttackFrameY);
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
					_bottomSpecialAttackFrameX, _bottomSpecialAttackFrameY);
			break;
			case PLAYER_LEFT_BOTTOM:
				IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_leftBottomSpecialAttackFrameX, _leftBottomSpecialAttackFrameY);
			break;
			case PLAYER_LEFT:
				IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_leftSpecialAttackFrameX, _leftSpecialAttackFrameY);
			break;
			case PLAYER_LEFT_TOP:
				IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_leftTopSpecialAttackFrameX, _leftTopSpecialAttackFrameY);
			break;
			case PLAYER_TOP:
				IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_topSpecialAttackFrameX, _topSpecialAttackFrameY);
			break;
			case PLAYER_RIGHT_TOP:
				IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_rightTopSpecialAttackFrameX, _rightTopSpecialAttackFrameY);
			break;
			case PLAYER_RIGHT:
				IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_rightSpecialAttackFrameX, _rightSpecialAttackFrameY);
			break;
			case PLAYER_RIGHT_BOTTOM:
				IMAGEMANAGER->findImage(tempNameSpecialAttack.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_rightBottomSpecialAttackFrameX, _rightBottomSpecialAttackFrameY);
				break;
			break;
			case PLAYER_DIRECTION_END:
			break;

		}
		break;
	case PLAYER_SPECIAL_ATTACK_2:
		break;
	case PLAYER_HURT:
		switch (_player.direction)
		{
			case PLAYER_BOTTOM:
				IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_bottomHurtFrameX, _bottomHurtFrameY);
			break;
			case PLAYER_LEFT_BOTTOM:
				IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_leftBottomHurtFrameX, _leftBottomHurtFrameY);
			break;
			case PLAYER_LEFT:
				IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_leftHurtFrameX, _leftHurtFrameY);
			break;
			case PLAYER_LEFT_TOP:
				IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_leftTopHurtFrameX, _leftTopHurtFrameY);
			break;
			case PLAYER_TOP:
				IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_topHurtFrameX, _topHurtFrameY);
			break;
			case PLAYER_RIGHT_TOP:
				IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_rightTopHurtFrameX, _rightTopHurtFrameY);
			break;
			case PLAYER_RIGHT:
				IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_rightHurtFrameX, _rightHurtFrameY);
			break;
			case PLAYER_RIGHT_BOTTOM:
				IMAGEMANAGER->findImage(tempNameHurt.c_str())->frameRender(hdc, _player.imageRc.left, _player.imageRc.top,
					_rightBottomHurtFrameX, _rightBottomHurtFrameY);
			break;
			case PLAYER_DIRECTION_END:
			break;
		}
		break;
	case PLAYER_DIE:
		switch (_player.direction)
		{
			case PLAYER_BOTTOM:
			break;
			case PLAYER_LEFT_BOTTOM:
			break;
			case PLAYER_LEFT:
			break;
			case PLAYER_LEFT_TOP:
			break;
			case PLAYER_TOP:
			break;
			case PLAYER_RIGHT_TOP:
			break;
			case PLAYER_RIGHT:
			break;
			case PLAYER_RIGHT_BOTTOM:
			break;
			case PLAYER_DIRECTION_END:
			break;

		}
		break;
	case PLAYER_STATE_END:
		break;

	}
}