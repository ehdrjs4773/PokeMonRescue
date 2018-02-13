#include "stdafx.h"
#include "player.h"

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
				_bottomIdleFrameX = _bottomIdleFrameY = 0;
			break;
			case PLAYER_LEFT_BOTTOM:
				_leftBottomIdleFrameX = 0;
				_leftBottomIdleFrameY = 1;
			break;
			case PLAYER_LEFT:
				_leftIdleFrameX = 0;
				_leftIdleFrameY = 2;
			break;
			case PLAYER_LEFT_TOP:
				_leftTopIdleFrameX = 0;
				_leftTopIdleFrameY = 3;
			break;
			case PLAYER_TOP:
				_topIdleFrameX = 0;
				_topIdleFrameY = 4;
			break;
			case PLAYER_RIGHT_TOP:
				_rightTopIdleFrameX = 0;
				_rightTopIdleFrameY = 5;
			break;
			case PLAYER_RIGHT:
				_rightIdleFrameX = 0;
				_rightIdleFrameY = 6;
			break;
			case PLAYER_RIGHT_BOTTOM:
				_rightBottomIdleFrameX = 0;
				_rightBottomIdleFrameY = 7;
			break;
			case PLAYER_DIRECTION_END:
			break;

		}
		break;
	case PLAYER_MOVE:
		switch (_player.direction)
		{
			case PLAYER_BOTTOM:
				_bottomMoveFrameY = 0;
				_bottomMoveCount++;
				if (_bottomMoveCount % 10 == 0)
				{
					_bottomMoveFrameX++;
					if (_bottomMoveFrameX > IMAGEMANAGER->findImage(tempNameMove.c_str())->getMaxFrameX())
					_bottomMoveFrameX = 0;
					_bottomMoveCount = 0;
				}
			break;
			case PLAYER_LEFT_BOTTOM:
				_leftBottomMoveFrameY = 1;
				_leftBottomMoveCount++;
				if (_leftBottomMoveCount % 10 == 0)
				{
					_leftBottomMoveFrameX++;
					if (_leftBottomMoveFrameX > IMAGEMANAGER->findImage(tempNameMove.c_str())->getMaxFrameX())
					_leftBottomMoveFrameX = 0;
					_leftBottomMoveCount = 0;
				}
			break;
			case PLAYER_LEFT:
				_leftMoveFrameY = 2;
				_leftMoveCount++;
				if (_leftMoveCount % 10 == 0)
				{
					_leftMoveFrameX++;
					if (_leftMoveFrameX > IMAGEMANAGER->findImage(tempNameMove.c_str())->getMaxFrameX())
					_leftMoveFrameX = 0;
					_leftMoveCount = 0;
				}
			break;
			case PLAYER_LEFT_TOP:
				_leftTopMoveFrameY = 3;
				_leftTopMoveCount++;
				if (_leftTopMoveCount % 10 == 0)
				{
					_leftTopMoveFrameX++;
					if (_leftTopMoveFrameX > IMAGEMANAGER->findImage(tempNameMove.c_str())->getMaxFrameX())
					_leftTopMoveFrameX = 0;
					_leftTopMoveCount = 0;
				}
			break;
			case PLAYER_TOP:
				_topMoveFrameY = 4;
				_topMoveCount++;
				if (_topMoveCount % 10 == 0)
				{
					_topMoveFrameX++;
					if (_topMoveFrameX > IMAGEMANAGER->findImage(tempNameMove.c_str())->getMaxFrameX())
					_topMoveFrameX = 0;
					_topMoveCount = 0;
				}
			break;
			case PLAYER_RIGHT_TOP:
				_rightTopMoveFrameY = 5;
				_rightTopMoveCount++;
				if (_rightTopMoveCount % 10 == 0)
				{
					_rightTopMoveFrameX++;
					if (_rightTopMoveFrameX > IMAGEMANAGER->findImage(tempNameMove.c_str())->getMaxFrameX())
					_rightTopMoveFrameX = 0;
					_rightTopMoveCount = 0;
				}
			break;
			case PLAYER_RIGHT:
				_rightMoveFrameY = 6;
				_rightMoveCount++;
				if (_rightMoveCount % 10 == 0)
				{
					_rightMoveFrameX++;
					if (_rightMoveFrameX > IMAGEMANAGER->findImage(tempNameMove.c_str())->getMaxFrameX())
					_rightMoveFrameX = 0;
					_rightMoveCount = 0;
				}
			break;
			case PLAYER_RIGHT_BOTTOM:
				_rightBottomMoveFrameY = 7;
				_rightBottomMoveCount++;
				if (_rightBottomMoveCount % 10 == 0)
				{
					_rightBottomMoveFrameX++;
					if (_rightBottomMoveFrameX > IMAGEMANAGER->findImage(tempNameMove.c_str())->getMaxFrameX())
					_rightBottomMoveFrameX = 0;
					_rightBottomMoveCount = 0;
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
	default:
		break;
	}
}