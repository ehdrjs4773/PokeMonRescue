#include "stdafx.h"
#include "player.h"

// =======================
// ## 보정작업 해주는 곳 ##
// =======================
void player::correction()
{
	switch (_player.state)
	{
	case PLAYER_IDLE:
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
	case PLAYER_MOVE:
		switch (_player.direction)
		{
		case PLAYER_BOTTOM:	
			if (KEYMANAGER->isStayKeyDown(VK_UP))
			{
				_player.direction = PLAYER_BOTTOM;
				_player.state = PLAYER_IDLE;
				return;
			}
			if (KEYMANAGER->isStayKeyDown(VK_LEFT))
			{
				_player.direction = PLAYER_LEFT_BOTTOM;
				_player.state = PLAYER_MOVE;
				return;
			}
			if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
			{
				_player.direction = PLAYER_RIGHT_BOTTOM;
				_player.state = PLAYER_MOVE;
				return;
			}
			break;
		case PLAYER_LEFT_BOTTOM:
			if (KEYMANAGER->isStayKeyDown(VK_RIGHT) || KEYMANAGER->isStayKeyDown(VK_UP))
			{
				_player.direction = PLAYER_LEFT_BOTTOM;
				_player.state = PLAYER_IDLE;
				return;
			}
			break;
		case PLAYER_LEFT:
			if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
			{
				_player.direction = PLAYER_LEFT;
				_player.state = PLAYER_IDLE;
				return;
			}
			if (KEYMANAGER->isStayKeyDown(VK_DOWN))
			{
				_player.direction = PLAYER_LEFT_BOTTOM;
				_player.state = PLAYER_MOVE;
				return;
			}
			if (KEYMANAGER->isStayKeyDown(VK_UP))
			{
				_player.direction = PLAYER_LEFT_TOP;
				_player.state = PLAYER_MOVE;
				return;
			}
			break;
		case PLAYER_LEFT_TOP:
			if (KEYMANAGER->isStayKeyDown(VK_RIGHT) || KEYMANAGER->isStayKeyDown(VK_DOWN))
			{
				_player.direction = PLAYER_LEFT_TOP;
				_player.state = PLAYER_IDLE;
				return;
			}
			break;
		case PLAYER_TOP:	
			if (KEYMANAGER->isStayKeyDown(VK_DOWN))
			{
				_player.direction = PLAYER_TOP;
				_player.state = PLAYER_IDLE;
				return;
			}
			if (KEYMANAGER->isStayKeyDown(VK_LEFT))
			{
				_player.direction = PLAYER_LEFT_TOP;
				_player.state = PLAYER_MOVE;
				return;
			}
			if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
			{
				_player.direction = PLAYER_RIGHT_TOP;
				_player.state = PLAYER_MOVE;
				return;
			}
			break;
		case PLAYER_RIGHT_TOP:
			if (KEYMANAGER->isStayKeyDown(VK_LEFT) || KEYMANAGER->isStayKeyDown(VK_DOWN))
			{
				_player.direction = PLAYER_RIGHT_TOP;
				_player.state = PLAYER_IDLE;
				return;
			}
			break;
		case PLAYER_RIGHT:	
			if (KEYMANAGER->isStayKeyDown(VK_LEFT))
			{
				_player.direction = PLAYER_RIGHT;
				_player.state = PLAYER_IDLE;
				return;
			}
			if (KEYMANAGER->isStayKeyDown(VK_DOWN))
			{
				_player.direction = PLAYER_RIGHT_BOTTOM;
				_player.state = PLAYER_MOVE;
				return;
			}
			if (KEYMANAGER->isStayKeyDown(VK_UP))
			{
				_player.direction = PLAYER_RIGHT_TOP;
				_player.state = PLAYER_MOVE;
				return;
			}
			break;
		case PLAYER_RIGHT_BOTTOM:
			if (KEYMANAGER->isStayKeyDown(VK_LEFT) || KEYMANAGER->isStayKeyDown(VK_UP))
			{
				_player.direction = PLAYER_RIGHT_BOTTOM;
				_player.state = PLAYER_IDLE;
				return;
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
	}
}