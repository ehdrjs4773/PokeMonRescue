#include "stdafx.h"
#include "player.h"
#include "Npc.h"

// =======================
// ## 픽셀충돌 ( 마을 ) ## 
// =======================
void player::pixelCollision()
{
	RECT rcCollision;

	rcCollision = _player.rc;

	rcCollision.right -= 4;
	rcCollision.left += 4;
	rcCollision.top += 4;
	rcCollision.bottom -= 4;

	_isWallCrash = false;
	
	if (_player.state == PLAYER_MOVE)
	{
		//X축
		switch (_player.direction)
		{
		case PLAYER_LEFT: case PLAYER_LEFT_BOTTOM: case PLAYER_LEFT_TOP:
			for (int i = rcCollision.top; i <= rcCollision.bottom; ++i)
			{
				for (int j = _player.rc.left + 5; j > _player.rc.left - 5; --j)
				{
					if (!_town->getHouse())
					{
						COLORREF color = GetPixel(IMAGEMANAGER->findImage("townMagenta")->getMemDC(), j, i);

						if (GetRValue(color) == 255 &&
							GetGValue(color) == 0 &&
							GetBValue(color) == 0)
						{
							_isWallCrash = true;
							_player.state = PLAYER_IDLE;
							_player.x = j + (_player.rc.right - _player.rc.left) / 2;
							break;
						}
					}
					if (_town->getHouse())
					{
						COLORREF color = GetPixel(IMAGEMANAGER->findImage("saveTownMagenta")->getMemDC(), j, i);

						if (GetRValue(color) == 255 &&
							GetGValue(color) == 0 &&
							GetBValue(color) == 0)
						{
							_isWallCrash = true;
							_player.state = PLAYER_IDLE;
							_player.x = j + (_player.rc.right - _player.rc.left) / 2;
							break;
						}
					}
					
				}
			}
			break;
		case PLAYER_RIGHT: case PLAYER_RIGHT_BOTTOM: case PLAYER_RIGHT_TOP:
			for (int i = rcCollision.top; i <= rcCollision.bottom; ++i)
			{
				for (int j = _player.rc.right - 5; j < _player.rc.right + 5; ++j)
				{
					if (!_town->getHouse())
					{
						COLORREF color = GetPixel(IMAGEMANAGER->findImage("townMagenta")->getMemDC(), j, i);

						if (GetRValue(color) == 255 &&
							GetGValue(color) == 0 &&
							GetBValue(color) == 0)
						{
							_isWallCrash = true;
							_player.state = PLAYER_IDLE;
							_player.x = j - (_player.rc.right - _player.rc.left) / 2;
							break;
						}
					}
					if (_town->getHouse())
					{
						COLORREF color = GetPixel(IMAGEMANAGER->findImage("saveTownMagenta")->getMemDC(), j, i);

						if (GetRValue(color) == 255 &&
							GetGValue(color) == 0 &&
							GetBValue(color) == 0)
						{
							_isWallCrash = true;
							_player.state = PLAYER_IDLE;
							_player.x = j - (_player.rc.right - _player.rc.left) / 2;
							break;
						}
					}
				}
			}
			break;
		}
		//Y축
		switch (_player.direction)
		{
		case PLAYER_BOTTOM: case PLAYER_LEFT_BOTTOM: case PLAYER_RIGHT_BOTTOM:
			for (int i = rcCollision.left; i <= rcCollision.right; ++i)
			{
				for (int j = _player.rc.bottom - 5; j < _player.rc.bottom + 5; ++j)
				{
					if (!_town->getHouse())
					{
						COLORREF color = GetPixel(IMAGEMANAGER->findImage("townMagenta")->getMemDC(), i, j);

						if (GetRValue(color) == 255 &&
							GetGValue(color) == 0 &&
							GetBValue(color) == 0)
						{
							_isWallCrash = true;
							_player.state = PLAYER_IDLE;
							_player.y = j - (_player.rc.right - _player.rc.left) / 2;
							break;
						}
					}
					if (_town->getHouse())
					{
						COLORREF color = GetPixel(IMAGEMANAGER->findImage("saveTownMagenta")->getMemDC(), i, j);

						if (GetRValue(color) == 255 &&
							GetGValue(color) == 0 &&
							GetBValue(color) == 0)
						{
							_isWallCrash = true;
							_player.state = PLAYER_IDLE;
							_player.y = j - (_player.rc.right - _player.rc.left) / 2;
							break;
						}
					}
				}
			}
			break;		
		case PLAYER_TOP: case PLAYER_LEFT_TOP: case PLAYER_RIGHT_TOP:
			for (int i = rcCollision.left; i <= rcCollision.right; ++i)
			{
				for (int j = _player.rc.top + 5; j > _player.rc.top - 5; --j)
				{
					if (!_town->getHouse())
					{
						COLORREF color = GetPixel(IMAGEMANAGER->findImage("townMagenta")->getMemDC(), i, j);

						if (GetRValue(color) == 255 &&
							GetGValue(color) == 0 &&
							GetBValue(color) == 0)
						{
							_isWallCrash = true;
							_player.state = PLAYER_IDLE;
							_player.y = j + (_player.rc.right - _player.rc.left) / 2;
							break;
						}
					}
					if (_town->getHouse())
					{
						COLORREF color = GetPixel(IMAGEMANAGER->findImage("saveTownMagenta")->getMemDC(), i, j);

						if (GetRValue(color) == 255 &&
							GetGValue(color) == 0 &&
							GetBValue(color) == 0)
						{
							_isWallCrash = true;
							_player.state = PLAYER_IDLE;
							_player.y = j + (_player.rc.right - _player.rc.left) / 2;
							break;
						}
					}
				}
			}
			break;
		}
		return;
	}

}