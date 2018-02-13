#include "stdafx.h"
#include "player.h"

// ====================
// ## 플레이어 움직임 ##
// ====================
void player::playerMove()
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
				_player.y += PLAYER_SPEED;
			break;
			case PLAYER_LEFT_BOTTOM:
				_player.x -= PLAYER_SPEED;
				_player.y += PLAYER_SPEED;
			break;
			case PLAYER_LEFT:
				_player.x -= PLAYER_SPEED;
			break;
			case PLAYER_LEFT_TOP:
				_player.x -= PLAYER_SPEED;
				_player.y -= PLAYER_SPEED;
			break;
			case PLAYER_TOP:
				_player.y -= PLAYER_SPEED;
			break;
			case PLAYER_RIGHT_TOP:
				_player.x += PLAYER_SPEED;
				_player.y -= PLAYER_SPEED;
			break;
			case PLAYER_RIGHT:
				_player.x += PLAYER_SPEED;
			break;
			case PLAYER_RIGHT_BOTTOM:
				_player.x += PLAYER_SPEED;
				_player.y += PLAYER_SPEED;
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