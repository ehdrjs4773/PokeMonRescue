#include "stdafx.h"
#include "player.h"

// ====================
// ## �÷��̾� ������ ##
// ====================
void player::playerTownMove()
{
	switch (_player.state)
	{
	case PLAYER_MOVE:
		switch (_player.direction)
		{
			case PLAYER_BOTTOM:
				if (KEYMANAGER->isStayKeyDown(SPEED_UP_KEY))
				{
					_player.y += PLAYER_TOWN_SPEED * 2;
				}
				else
				_player.y += PLAYER_TOWN_SPEED;
			break;
			case PLAYER_LEFT_BOTTOM:
				if (KEYMANAGER->isStayKeyDown(SPEED_UP_KEY))
				{
					_player.x -= PLAYER_TOWN_SPEED * 2;
					_player.y += PLAYER_TOWN_SPEED * 2;
				}
				else
				{
					_player.x -= PLAYER_TOWN_SPEED;
					_player.y += PLAYER_TOWN_SPEED;
				}		
			break;
			case PLAYER_LEFT:
				if (KEYMANAGER->isStayKeyDown(SPEED_UP_KEY))
				{
					_player.x -= PLAYER_TOWN_SPEED * 2;
				}
				else
				_player.x -= PLAYER_TOWN_SPEED;
			break;
			case PLAYER_LEFT_TOP:
				if (KEYMANAGER->isStayKeyDown(SPEED_UP_KEY))
				{
					_player.x -= PLAYER_TOWN_SPEED * 2;
					_player.y -= PLAYER_TOWN_SPEED * 2;
				}
				else
				{
					_player.x -= PLAYER_TOWN_SPEED;
					_player.y -= PLAYER_TOWN_SPEED;
				}
			break;
			case PLAYER_TOP:
				if (KEYMANAGER->isStayKeyDown(SPEED_UP_KEY))
				{
					_player.y -= PLAYER_TOWN_SPEED * 2;
				}
				else
				_player.y -= PLAYER_TOWN_SPEED;
			break;
			case PLAYER_RIGHT_TOP:
				if (KEYMANAGER->isStayKeyDown(SPEED_UP_KEY))
				{
					_player.x += PLAYER_TOWN_SPEED * 2;
					_player.y -= PLAYER_TOWN_SPEED * 2;
				}
				else
				{
					_player.x += PLAYER_TOWN_SPEED;
					_player.y -= PLAYER_TOWN_SPEED;
				}
			break;
			case PLAYER_RIGHT:
				if (KEYMANAGER->isStayKeyDown(SPEED_UP_KEY))
				{
					_player.x += PLAYER_TOWN_SPEED * 2;
				}
				else
				_player.x += PLAYER_TOWN_SPEED;
			break;
			case PLAYER_RIGHT_BOTTOM:
				if (KEYMANAGER->isStayKeyDown(SPEED_UP_KEY))
				{
					_player.x += PLAYER_TOWN_SPEED * 2;
					_player.y += PLAYER_TOWN_SPEED * 2;
				}
				else
				{
					_player.x += PLAYER_TOWN_SPEED;
					_player.y += PLAYER_TOWN_SPEED;
				}

			break;
			case PLAYER_DIRECTION_END:
			break;
		}
		break;
	}
}

void player::playerDgMove()
{
	switch (_player.state)
	{
	case PLAYER_MOVE:
		switch (_player.direction)
		{
		case PLAYER_BOTTOM:
			if (KEYMANAGER->isStayKeyDown(SPEED_UP_KEY))
			{
				_player.y += PLAYER_DUNGEON_SPEED * 4;
			}
			else
			_player.y += PLAYER_DUNGEON_SPEED;
				
			break;
		case PLAYER_LEFT_BOTTOM:
			if (KEYMANAGER->isStayKeyDown(SPEED_UP_KEY))
			{
				_player.x -= PLAYER_DUNGEON_SPEED * 4;
				_player.y += PLAYER_DUNGEON_SPEED * 4;
			}
			else
			{
				_player.x -= PLAYER_DUNGEON_SPEED;
				_player.y += PLAYER_DUNGEON_SPEED;
			}
			break;
		case PLAYER_LEFT:
			if (KEYMANAGER->isStayKeyDown(SPEED_UP_KEY))
			{
				_player.x -= PLAYER_DUNGEON_SPEED * 4;
			}
			else
				_player.x -= PLAYER_DUNGEON_SPEED;
			break;
		case PLAYER_LEFT_TOP:
			if (KEYMANAGER->isStayKeyDown(SPEED_UP_KEY))
			{
				_player.x -= PLAYER_DUNGEON_SPEED * 4;
				_player.y -= PLAYER_DUNGEON_SPEED * 4;
			}
			else
			{
				_player.x -= PLAYER_DUNGEON_SPEED;
				_player.y -= PLAYER_DUNGEON_SPEED;
			}
			break;
		case PLAYER_TOP:
			if (KEYMANAGER->isStayKeyDown(SPEED_UP_KEY))
			{
				_player.y -= PLAYER_DUNGEON_SPEED * 4;
			}
			else
				_player.y -= PLAYER_DUNGEON_SPEED;
			break;
		case PLAYER_RIGHT_TOP:
			if (KEYMANAGER->isStayKeyDown(SPEED_UP_KEY))
			{
				_player.x += PLAYER_DUNGEON_SPEED * 4;
				_player.y -= PLAYER_DUNGEON_SPEED * 4;
			}
			else
			{
				_player.x += PLAYER_DUNGEON_SPEED;
				_player.y -= PLAYER_DUNGEON_SPEED;
			}
			break;
		case PLAYER_RIGHT:
			if (KEYMANAGER->isStayKeyDown(SPEED_UP_KEY))
			{
				_player.x += PLAYER_DUNGEON_SPEED * 4;
			}
			else
				_player.x += PLAYER_DUNGEON_SPEED;
			break;
		case PLAYER_RIGHT_BOTTOM:
			if (KEYMANAGER->isStayKeyDown(SPEED_UP_KEY))
			{
				_player.x += PLAYER_DUNGEON_SPEED * 4;
				_player.y += PLAYER_DUNGEON_SPEED * 4;
			}
			else
			{
				_player.x += PLAYER_DUNGEON_SPEED;
				_player.y += PLAYER_DUNGEON_SPEED;
			}

			break;
		case PLAYER_DIRECTION_END:
			break;
		}
		break;
	}
}