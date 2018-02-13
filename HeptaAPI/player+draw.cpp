#include "stdafx.h"
#include "player.h"

// =======================
// ## 이미지 그려주는 곳 ## 
// =======================
void player::draw()
{
	switch (_player.state)
	{
	case PLAYER_IDLE:
		switch (_player.direction)
		{
			case PLAYER_BOTTOM:
				IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(getMemDC(), _player.rc.left, _player.rc.top,
					_bottomIdleFrameX, _bottomIdleFrameY);
			break;
			case PLAYER_LEFT_BOTTOM:
				IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(getMemDC(), _player.rc.left, _player.rc.top,
					_leftBottomIdleFrameX, _leftBottomIdleFrameY);
			break;
			case PLAYER_LEFT:
				IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(getMemDC(), _player.rc.left, _player.rc.top,
					_leftIdleFrameX, _leftIdleFrameY);
			break;
			case PLAYER_LEFT_TOP:
				IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(getMemDC(), _player.rc.left, _player.rc.top,
					_leftTopIdleFrameX, _leftTopIdleFrameY);
			break;
			case PLAYER_TOP:
				IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(getMemDC(), _player.rc.left, _player.rc.top,
					_topIdleFrameX, _topIdleFrameY);
			break;
			case PLAYER_RIGHT_TOP:
				IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(getMemDC(), _player.rc.left, _player.rc.top,
					_rightTopIdleFrameX, _rightTopIdleFrameY);
			break;
			case PLAYER_RIGHT:
				IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(getMemDC(), _player.rc.left, _player.rc.top,
					_rightIdleFrameX, _rightIdleFrameY);
			break;
			case PLAYER_RIGHT_BOTTOM:
				IMAGEMANAGER->findImage(tempNameIdle.c_str())->frameRender(getMemDC(), _player.rc.left, _player.rc.top,
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
				IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(getMemDC(), _player.rc.left, _player.rc.top,
					_bottomMoveFrameX, _bottomMoveFrameY);
			break;
			case PLAYER_LEFT_BOTTOM:
				IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(getMemDC(), _player.rc.left, _player.rc.top,
					_leftBottomMoveFrameX, _leftBottomMoveFrameY);
			break;
			case PLAYER_LEFT:
				IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(getMemDC(), _player.rc.left, _player.rc.top,
					_leftMoveFrameX, _leftMoveFrameY);
			break;
			case PLAYER_LEFT_TOP:
				IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(getMemDC(), _player.rc.left, _player.rc.top,
					_leftTopMoveFrameX, _leftTopMoveFrameY);
			break;
			case PLAYER_TOP:
				IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(getMemDC(), _player.rc.left, _player.rc.top,
					_topMoveFrameX, _topMoveFrameY);
			break;
			case PLAYER_RIGHT_TOP:
				IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(getMemDC(), _player.rc.left, _player.rc.top,
					_rightTopMoveFrameX, _rightTopMoveFrameY);
			break;
			case PLAYER_RIGHT:
				IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(getMemDC(), _player.rc.left, _player.rc.top,
					_rightMoveFrameX, _rightMoveFrameY);
			break;
			case PLAYER_RIGHT_BOTTOM:
				IMAGEMANAGER->findImage(tempNameMove.c_str())->frameRender(getMemDC(), _player.rc.left, _player.rc.top,
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
	case PLAYER_SPECIAL_ATTACK_1:
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
	case PLAYER_SPECIAL_ATTACK_2:
		break;
	case PLAYER_HURT:
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