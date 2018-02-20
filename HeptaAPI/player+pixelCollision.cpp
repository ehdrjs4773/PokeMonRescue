#include "stdafx.h"
#include "player.h"

void player::pixelCollision()
{
	if (_player.state == PLAYER_MOVE)
	{
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
		}
	}

}