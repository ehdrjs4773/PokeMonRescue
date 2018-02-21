#include "stdafx.h"
#include "player.h"
#include "Stage.h"
#include "enemyManager.h"
#include "Npc.h"

player::player()
{
}


player::~player()
{
}

HRESULT player::init()
{


	return S_OK;
}

HRESULT player::init(string charName)
{
	//방향 및 상태
	_player.direction = PLAYER_BOTTOM;
	_player.state = PLAYER_IDLE;

	//변수 초기화 ( player+valueInit.cpp에 있음 )
	valueInit();

	_isWallCrash = false;
	_player.townSpeed = 3.0f;
	_player.money = 1000;

	tempNameIdle = charName + "_idle";
	tempNameMove = charName + "_move";
	tempNameAttack = charName + "_attack";
	tempNameSpecialAttack = charName + "_specialAttack";
	tempNameHurt = charName + "_hurt";

	_playerStatus = new pokemon;
	_playerStatus->pokemonStatus(charName, 1);

	return S_OK;
}
void player::release()
{

}
void player::update()
{
	//마을에서 움직임
	//townMove();

	//던전에서 움직임
	//dungeonMove();

	//this->FrameUpdate();

	//for (_viPartner = _vPartner.begin(); _viPartner != _vPartner.end(); ++_viPartner)
	//{
	//	(*_viPartner)->update();
	//}
}
void player::render()
{
	HDC hdc = CAMERAMANAGER->getMemDC();
	int x = CAMERAMANAGER->getX();
	int y = CAMERAMANAGER->getY();

	//SetBkMode(hdc, TRANSPARENT);
	//char str[128];
	//sprintf_s(str, " 바텀무브 불값 : %d ", _isBottomMove);
	//TextOut(hdc, x + 200, y + 50, str, strlen(str));
	//char str2[128];
	//sprintf_s(str2, " ( _player.y ) 현재 값 : %f ", _player.y);
	//TextOut(hdc, x + 200, y + 75, str2, strlen(str2));
	//char str3[128];
	//sprintf_s(str3, " ( _player.startX ) 현재 값 : %f ", _player.startX);
	//TextOut(hdc, x + 200, y + 100, str3, strlen(str3));
	//char str4[128];
	//sprintf_s(str4, " ( _player.startY ) 현재 값 : %f ", _player.startY);
	//TextOut(hdc, x + 200, y + 125, str4, strlen(str4));
	//
	//char str5[128];
	//sprintf_s(str5, " _player.x / 24 : %f ", _player.x / 24);
	//TextOut(hdc, x + 200, y + 150, str5, strlen(str5));
	//char str6[128];
	//sprintf_s(str6, " _player.y / 24 : %f ", _player.y / 24);
	//TextOut(hdc, x + 200, y + 175, str6, strlen(str6));
	//
	//char str7[128];
	//sprintf_s(str7, " _player.idx 값 : %d ", _player.idx);
	//TextOut(hdc, x + 200, y + 200, str7, strlen(str7));
	//char str8[128];
	//sprintf_s(str8, " _player.idy 값 : %d ", _player.idy);
	//TextOut(hdc, x + 200, y + 225, str8, strlen(str8));


	//Rectangle(getMemDC(), _player.rc.left, _player.rc.top, _player.rc.right, _player.rc.bottom);
	//for (_viPartner = _vPartner.begin(); _viPartner != _vPartner.end(); ++_viPartner)
	//{
	//	(*_viPartner)->render();
	//}
	draw();
}

// ================================================================================================
// ================================ ## 마을에서 움직임 ## ==========================================
// ================================================================================================
void player::townMove()
{
	//공격키
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_isAttack = true;

		switch (_player.direction)
		{
		case PLAYER_BOTTOM:
			_player.direction = PLAYER_BOTTOM;
			_player.state = PLAYER_ATTACK;
			break;
		case PLAYER_LEFT_BOTTOM:
			_player.direction = PLAYER_LEFT_BOTTOM;
			_player.state = PLAYER_ATTACK;
			break;
		case PLAYER_LEFT:
			_player.direction = PLAYER_LEFT;
			_player.state = PLAYER_ATTACK;
			break;
		case PLAYER_LEFT_TOP:
			_player.direction = PLAYER_LEFT_TOP;
			_player.state = PLAYER_ATTACK;
			break;
		case PLAYER_TOP:
			_player.direction = PLAYER_TOP;
			_player.state = PLAYER_ATTACK;
			break;
		case PLAYER_RIGHT_TOP:
			_player.direction = PLAYER_RIGHT_TOP;
			_player.state = PLAYER_ATTACK;
			break;
		case PLAYER_RIGHT:
			_player.direction = PLAYER_RIGHT;
			_player.state = PLAYER_ATTACK;
			break;
		case PLAYER_RIGHT_BOTTOM:
			_player.direction = PLAYER_RIGHT_BOTTOM;
			_player.state = PLAYER_ATTACK;
			break;
		}
	}

	//왼쪽아래
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && KEYMANAGER->isStayKeyDown(VK_DOWN) && !(KEYMANAGER->isStayKeyDown(VK_RIGHT)) &&
		!(KEYMANAGER->isStayKeyDown(VK_UP)) && !_isAttack)
	{
		_player.angle = 225 * DEG2RAD;
		_player.direction = PLAYER_LEFT_BOTTOM;
		_player.state = PLAYER_MOVE;
	}
	//오른쪽아래
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && KEYMANAGER->isStayKeyDown(VK_DOWN) && !(KEYMANAGER->isStayKeyDown(VK_LEFT)) &&
		!(KEYMANAGER->isStayKeyDown(VK_UP)) && !_isAttack)
	{
		_player.angle = 315 * DEG2RAD;
		_player.direction = PLAYER_RIGHT_BOTTOM;
		_player.state = PLAYER_MOVE;
	}
	//왼쪽위
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && KEYMANAGER->isStayKeyDown(VK_UP) && !(KEYMANAGER->isStayKeyDown(VK_RIGHT)) &&
		!(KEYMANAGER->isStayKeyDown(VK_DOWN)) && !_isAttack)
	{
		_player.angle = 135 * DEG2RAD;
		_player.direction = PLAYER_LEFT_TOP;
		_player.state = PLAYER_MOVE;
	}
	//오른쪽위
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && KEYMANAGER->isStayKeyDown(VK_UP) && !(KEYMANAGER->isStayKeyDown(VK_LEFT)) &&
		!(KEYMANAGER->isStayKeyDown(VK_DOWN)) && !_isAttack)
	{
		_player.angle = 45 * DEG2RAD;
		_player.direction = PLAYER_RIGHT_TOP;
		_player.state = PLAYER_MOVE;
	}
	//아래
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && !(KEYMANAGER->isStayKeyDown(VK_RIGHT)) && !(KEYMANAGER->isStayKeyDown(VK_UP))
		&& !(KEYMANAGER->isStayKeyDown(VK_LEFT)) && !_isAttack)
	{
		_player.angle = 270 * DEG2RAD;
		_player.direction = PLAYER_BOTTOM;
		_player.state = PLAYER_MOVE;
	}
	//위
	if (KEYMANAGER->isStayKeyDown(VK_UP) && !(KEYMANAGER->isStayKeyDown(VK_RIGHT)) && !(KEYMANAGER->isStayKeyDown(VK_LEFT))
		&& !(KEYMANAGER->isStayKeyDown(VK_DOWN)) && !_isAttack)
	{
		_player.angle = 90 * DEG2RAD;
		_player.direction = PLAYER_TOP;
		_player.state = PLAYER_MOVE;
	}
	//왼쪽
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && !(KEYMANAGER->isStayKeyDown(VK_RIGHT)) && !(KEYMANAGER->isStayKeyDown(VK_UP))
		&& !(KEYMANAGER->isStayKeyDown(VK_DOWN)) && !_isAttack)
	{
		_player.angle = 180 * DEG2RAD;
		_player.direction = PLAYER_LEFT;
		_player.state = PLAYER_MOVE;
	}
	//오른쪽
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && !(KEYMANAGER->isStayKeyDown(VK_LEFT)) && !(KEYMANAGER->isStayKeyDown(VK_UP))
		&& !(KEYMANAGER->isStayKeyDown(VK_DOWN)) && !_isAttack)
	{
		_player.angle = 0 * DEG2RAD;
		_player.direction = PLAYER_RIGHT;
		_player.state = PLAYER_MOVE;
	}

	//픽셀충돌
	pixelCollision();

	//벽에 부딪혔을때 속도조절
	if (!_isWallCrash)
	{
		_player.townSpeed = 3.0f;
	}
	else
	{
		_player.townSpeed = 0.0f;
	}

	//오른쪽키 땟을때
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT) && (_player.direction == PLAYER_RIGHT_TOP || _player.direction == PLAYER_RIGHT ||
		_player.direction == PLAYER_RIGHT_BOTTOM) && !_isAttack)
	{
		valueInit();

		if (KEYMANAGER->isOnceKeyUp(VK_UP))
		{
			_player.direction = PLAYER_RIGHT_TOP;
			_player.state = PLAYER_IDLE;
		}
		else if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
		{
			_player.direction = PLAYER_RIGHT_BOTTOM;
			_player.state = PLAYER_IDLE;
		}
		else
		{
			_player.direction = PLAYER_RIGHT;
			_player.state = PLAYER_IDLE;
		}
	}
	//윗키 땟을 때
	if (KEYMANAGER->isOnceKeyUp(VK_UP) && (_player.direction == PLAYER_LEFT_TOP || _player.direction == PLAYER_TOP ||
		_player.direction == PLAYER_RIGHT_TOP) && !_isAttack)
	{
		valueInit();

		if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
		{
			_player.direction = PLAYER_LEFT_TOP;
			_player.state = PLAYER_IDLE;
		}
		else if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
		{
			_player.direction = PLAYER_RIGHT_TOP;
			_player.state = PLAYER_IDLE;
		}
		else
		{
			_player.direction = PLAYER_TOP;
			_player.state = PLAYER_IDLE;
		}
	}
	//아랫키 땟을때
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN) && (_player.direction == PLAYER_LEFT_BOTTOM || _player.direction == PLAYER_BOTTOM ||
		_player.direction == PLAYER_RIGHT_BOTTOM) && !_isAttack)
	{
		valueInit();

		if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
		{
			_player.direction = PLAYER_LEFT_BOTTOM;
			_player.state = PLAYER_IDLE;
		}
		else if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
		{
			_player.direction = PLAYER_RIGHT_BOTTOM;
			_player.state = PLAYER_IDLE;
		}
		else
		{
			_player.direction = PLAYER_BOTTOM;
			_player.state = PLAYER_IDLE;
		}
	}
	//왼쪽키 땟을 때
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT) && (_player.direction == PLAYER_LEFT_TOP || _player.direction == PLAYER_LEFT ||
		_player.direction == PLAYER_LEFT_BOTTOM) && !_isAttack)
	{
		valueInit();

		if (KEYMANAGER->isOnceKeyUp(VK_UP))
		{
			_player.direction = PLAYER_LEFT_TOP;
			_player.state = PLAYER_IDLE;
		}
		else if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
		{
			_player.direction = PLAYER_LEFT_BOTTOM;
			_player.state = PLAYER_IDLE;
		}
		else
		{
			_player.direction = PLAYER_LEFT;
			_player.state = PLAYER_IDLE;
		}
	}

	//player+move.cpp에 있음
	playerTownMove();
	//프레임 업데이트
	FrameUpdate();
	//프레임 보정
	correction();
	//실제렉트
	_player.rc = RectMakeCenter(_player.x, _player.y, 24, 24);
	//이미지 뿌려주는 rc
	_player.imageRc = RectMakeCenter(_player.x, _player.y, IMAGEMANAGER->findImage(tempNameIdle.c_str())->getFrameWidth(),
		IMAGEMANAGER->findImage(tempNameIdle.c_str())->getFrameHeight());

	

}

// ============================================================================================
// ================================== ## 던전에서 움직임 ## ====================================
// ============================================================================================
void player::dungeonMove()
{
	//몇번째 타일에 있는지 인덱스 x,y
	_player.idx = _player.x / 24;
	_player.idy = _player.y / 24;

	//몇번째 타일에 있냐
	_player.tileIndex = _player.idx + (_player.idy * _stage->gettileCountX());

	//타일검출
	tileCheak();

	if (KEYMANAGER->isOnceKeyDown(VK_F1) && !_onceMove)
	{
		_isAttack = true;
		_player.state = PLAYER_SPECIAL_ATTACK_1;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F2) && !_onceMove)
	{
		_isAttack = true;
		_player.state = PLAYER_HURT;
	}

	//공격키
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE) && !_onceMove)
	{
		_isAttack = true;

		switch (_player.direction)
		{
		case PLAYER_BOTTOM:
			_player.direction = PLAYER_BOTTOM;
			_player.state = PLAYER_ATTACK;
			break;
		case PLAYER_LEFT_BOTTOM:
			_player.direction = PLAYER_LEFT_BOTTOM;
			_player.state = PLAYER_ATTACK;
			break;
		case PLAYER_LEFT:
			_player.direction = PLAYER_LEFT;
			_player.state = PLAYER_ATTACK;
			break;
		case PLAYER_LEFT_TOP:
			_player.direction = PLAYER_LEFT_TOP;
			_player.state = PLAYER_ATTACK;
			break;
		case PLAYER_TOP:
			_player.direction = PLAYER_TOP;
			_player.state = PLAYER_ATTACK;
			break;
		case PLAYER_RIGHT_TOP:
			_player.direction = PLAYER_RIGHT_TOP;
			_player.state = PLAYER_ATTACK;
			break;
		case PLAYER_RIGHT:
			_player.direction = PLAYER_RIGHT;
			_player.state = PLAYER_ATTACK;
			break;
		case PLAYER_RIGHT_BOTTOM:
			_player.direction = PLAYER_RIGHT_BOTTOM;
			_player.state = PLAYER_ATTACK;
			break;
		}
	}
	//왼쪽아래
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && KEYMANAGER->isStayKeyDown(VK_DOWN) && !(KEYMANAGER->isStayKeyDown(VK_RIGHT)) &&
		!(KEYMANAGER->isStayKeyDown(VK_UP)) && !_isAttack && !_onceMove)
	{
		_player.direction = PLAYER_LEFT_BOTTOM;

		if (_isLeftBottomMove)
		{
			_onceMove = true;
			_player.startX = _player.x;
			_player.startY = _player.y;

			_player.state = PLAYER_MOVE;
		}
	}
	//오른쪽아래
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && KEYMANAGER->isStayKeyDown(VK_DOWN) && !(KEYMANAGER->isStayKeyDown(VK_LEFT)) &&
		!(KEYMANAGER->isStayKeyDown(VK_UP)) && !_isAttack && !_onceMove)
	{
		_player.direction = PLAYER_RIGHT_BOTTOM;

		if (_isRightBottomMove)
		{
			_onceMove = true;
			_player.startX = _player.x;
			_player.startY = _player.y;

			_player.state = PLAYER_MOVE;
		}
	}
	//왼쪽위
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && KEYMANAGER->isStayKeyDown(VK_UP) && !(KEYMANAGER->isStayKeyDown(VK_RIGHT)) &&
		!(KEYMANAGER->isStayKeyDown(VK_DOWN)) && !_isAttack && !_onceMove)
	{
		_player.direction = PLAYER_LEFT_TOP;

		if (_isLeftTopMove)
		{
			_onceMove = true;
			_player.startX = _player.x;
			_player.startY = _player.y;

			_player.state = PLAYER_MOVE;
		}
	}
	//오른쪽위
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && KEYMANAGER->isStayKeyDown(VK_UP) && !(KEYMANAGER->isStayKeyDown(VK_LEFT)) &&
		!(KEYMANAGER->isStayKeyDown(VK_DOWN)) && !_isAttack && !_onceMove)
	{
		_player.direction = PLAYER_RIGHT_TOP;

		if (_isRightTopMove)
		{
			_onceMove = true;
			_player.startX = _player.x;
			_player.startY = _player.y;

			_player.state = PLAYER_MOVE;
		}
	}
	//아래
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && !(KEYMANAGER->isStayKeyDown(VK_RIGHT)) && !(KEYMANAGER->isStayKeyDown(VK_UP))
		&& !(KEYMANAGER->isStayKeyDown(VK_LEFT)) && !_isAttack && !_onceMove)
	{
		_player.direction = PLAYER_BOTTOM;

		if (_isBottomMove)
		{
			_onceMove = true;
			_player.startX = _player.x;
			_player.startY = _player.y;

			_player.state = PLAYER_MOVE;
		}
	}
	//위
	if (KEYMANAGER->isStayKeyDown(VK_UP) && !(KEYMANAGER->isStayKeyDown(VK_RIGHT)) && !(KEYMANAGER->isStayKeyDown(VK_LEFT))
		&& !(KEYMANAGER->isStayKeyDown(VK_DOWN)) && !_isAttack && !_onceMove)
	{
		_player.direction = PLAYER_TOP;

		if (_isTopMove)
		{
			_onceMove = true;
			_player.startX = _player.x;
			_player.startY = _player.y;

			_player.state = PLAYER_MOVE;
		}
	}
	//왼쪽
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && !(KEYMANAGER->isStayKeyDown(VK_RIGHT)) && !(KEYMANAGER->isStayKeyDown(VK_UP))
		&& !(KEYMANAGER->isStayKeyDown(VK_DOWN)) && !_isAttack && !_onceMove)
	{
		_player.direction = PLAYER_LEFT;

		if (_isLeftMove)
		{
			_onceMove = true;
			_player.startX = _player.x;
			_player.startY = _player.y;

			_player.state = PLAYER_MOVE;
		}
	}
	//오른쪽
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && !(KEYMANAGER->isStayKeyDown(VK_LEFT)) && !(KEYMANAGER->isStayKeyDown(VK_UP))
		&& !(KEYMANAGER->isStayKeyDown(VK_DOWN)) && !_isAttack && !_onceMove)
	{
		_player.direction = PLAYER_RIGHT;

		if (_isRightMove)
		{
			_onceMove = true;
			_player.startX = _player.x;
			_player.startY = _player.y;

			_player.state = PLAYER_MOVE;
		}
	}
	//프레임 보정 ( 던전에선 필요 없을듯 )
	//correction();
	//player+move.cpp에 있음
	playerDgMove();

	//이걸로 한타일씩 이동하는것처럼 보이게 할거임
	switch (_player.state)
	{
	case PLAYER_MOVE:
		switch (_player.direction)
		{
		case PLAYER_BOTTOM:
			if (TILESIZEX <= getDistance(_player.startX, _player.startY, _player.x, _player.y))
			{
				_onceMove = false;
				
				//보정			
				if (_player.x != _stage->getTileAdress()[_player.tileIndex]->getCenterX())
					_player.x = _stage->getTileAdress()[_player.tileIndex]->getCenterX();
				if (_player.y != _stage->getTileAdress()[_player.tileIndex]->getCenterY())
					_player.y = _stage->getTileAdress()[_player.tileIndex]->getCenterY();
				_player.state = PLAYER_IDLE;
				_playerAction = playerMove;			//임시
				//아이템 먹었을 때
				if ((int)_stage->getTileAdress()[_player.tileIndex]->getObject() < 6)
				{
					_stage->getTileAdress()[_player.tileIndex]->setObject(OBJECT_NONE);
				}
			}
			break;
		case PLAYER_LEFT_BOTTOM:
			if (sqrtf(TILESIZEX * TILESIZEX + TILESIZEY * TILESIZEY)
				<= getDistance(_player.startX, _player.startY, _player.x, _player.y))
			{
				_onceMove = false;

				//보정
				if (_player.x != _stage->getTileAdress()[_player.tileIndex]->getCenterX())
					_player.x = _stage->getTileAdress()[_player.tileIndex]->getCenterX();
				if (_player.y != _stage->getTileAdress()[_player.tileIndex]->getCenterY())
					_player.y = _stage->getTileAdress()[_player.tileIndex]->getCenterY();
				_player.state = PLAYER_IDLE;
				//아이템 먹었을 때
				if ((int)_stage->getTileAdress()[_player.tileIndex]->getObject() < 6)
				{
					_stage->getTileAdress()[_player.tileIndex]->setObject(OBJECT_NONE);
				}
			}
			break;
		case PLAYER_LEFT:
			if (TILESIZEX <= getDistance(_player.startX, _player.startY, _player.x, _player.y))
			{
				_onceMove = false;

				//보정
				if (_player.x != _stage->getTileAdress()[_player.tileIndex]->getCenterX())
					_player.x = _stage->getTileAdress()[_player.tileIndex]->getCenterX();
				if (_player.y != _stage->getTileAdress()[_player.tileIndex]->getCenterY())
					_player.y = _stage->getTileAdress()[_player.tileIndex]->getCenterY();
				_player.state = PLAYER_IDLE;
				//아이템 먹었을 때
				if ((int)_stage->getTileAdress()[_player.tileIndex]->getObject() < 6)
				{
					_stage->getTileAdress()[_player.tileIndex]->setObject(OBJECT_NONE);
				}
			}
			break;
		case PLAYER_LEFT_TOP:
			if (sqrtf(TILESIZEX * TILESIZEX + TILESIZEY * TILESIZEY)
				<= getDistance(_player.startX, _player.startY, _player.x, _player.y))
			{
				_onceMove = false;

				//보정
				if (_player.x != _stage->getTileAdress()[_player.tileIndex]->getCenterX())
					_player.x = _stage->getTileAdress()[_player.tileIndex]->getCenterX();
				if (_player.y != _stage->getTileAdress()[_player.tileIndex]->getCenterY())
					_player.y = _stage->getTileAdress()[_player.tileIndex]->getCenterY();
				_player.state = PLAYER_IDLE;
				//아이템 먹었을 때
				if ((int)_stage->getTileAdress()[_player.tileIndex]->getObject() < 6)
				{
					_stage->getTileAdress()[_player.tileIndex]->setObject(OBJECT_NONE);
				}
			}
			break;
		case PLAYER_TOP:
			if (TILESIZEX <= getDistance(_player.startX, _player.startY, _player.x, _player.y))
			{
				_onceMove = false;

				//보정
				if (_player.x != _stage->getTileAdress()[_player.tileIndex]->getCenterX())
					_player.x = _stage->getTileAdress()[_player.tileIndex]->getCenterX();
				if (_player.y != _stage->getTileAdress()[_player.tileIndex]->getCenterY())
					_player.y = _stage->getTileAdress()[_player.tileIndex]->getCenterY();
				_player.state = PLAYER_IDLE;
				//아이템 먹었을 때
				if ((int)_stage->getTileAdress()[_player.tileIndex]->getObject() < 6)
				{
					_stage->getTileAdress()[_player.tileIndex]->setObject(OBJECT_NONE);
				}
			}
			break;
		case PLAYER_RIGHT_TOP:
			if (sqrtf(TILESIZEX * TILESIZEX + TILESIZEY * TILESIZEY)
				<= getDistance(_player.startX, _player.startY, _player.x, _player.y))
			{
				_onceMove = false;

				//보정
				if (_player.x != _stage->getTileAdress()[_player.tileIndex]->getCenterX())
					_player.x = _stage->getTileAdress()[_player.tileIndex]->getCenterX();
				if (_player.y != _stage->getTileAdress()[_player.tileIndex]->getCenterY())
					_player.y = _stage->getTileAdress()[_player.tileIndex]->getCenterY();
				_player.state = PLAYER_IDLE;
				//아이템 먹었을 때
				if ((int)_stage->getTileAdress()[_player.tileIndex]->getObject() < 6)
				{
					_stage->getTileAdress()[_player.tileIndex]->setObject(OBJECT_NONE);
				}
			}
			break;
		case PLAYER_RIGHT:
			if (TILESIZEX <= getDistance(_player.startX, _player.startY, _player.x, _player.y))
			{
				_onceMove = false;

				//보정
				if (_player.x != _stage->getTileAdress()[_player.tileIndex]->getCenterX())
					_player.x = _stage->getTileAdress()[_player.tileIndex]->getCenterX();
				if (_player.y != _stage->getTileAdress()[_player.tileIndex]->getCenterY())
					_player.y = _stage->getTileAdress()[_player.tileIndex]->getCenterY();
				_player.state = PLAYER_IDLE;
				//아이템 먹었을 때
				if ((int)_stage->getTileAdress()[_player.tileIndex]->getObject() < 6)
				{
					_stage->getTileAdress()[_player.tileIndex]->setObject(OBJECT_NONE);
				}
			}
			break;
		case PLAYER_RIGHT_BOTTOM:
			if (sqrtf(TILESIZEX * TILESIZEX + TILESIZEY * TILESIZEY)
				<= getDistance(_player.startX, _player.startY, _player.x, _player.y))
			{
				_onceMove = false;

				//보정
				if (_player.x != _stage->getTileAdress()[_player.tileIndex]->getCenterX())
					_player.x = _stage->getTileAdress()[_player.tileIndex]->getCenterX();
				if (_player.y != _stage->getTileAdress()[_player.tileIndex]->getCenterY())
					_player.y = _stage->getTileAdress()[_player.tileIndex]->getCenterY();
				_player.state = PLAYER_IDLE;
				//아이템 먹었을 때
				if ((int)_stage->getTileAdress()[_player.tileIndex]->getObject() < 6)
				{
					_stage->getTileAdress()[_player.tileIndex]->setObject(OBJECT_NONE);
				}
			}
			break;
		}
		break;
	}

	//프레임 업뎃
	FrameUpdate();

	CAMERAMANAGER->cameraMove(_player.x, _player.y);
	
	//실제렉트
	_player.rc = RectMakeCenter(_player.x, _player.y, 24, 24);

	//이미지 뿌려주는 rc
	_player.imageRc = RectMakeCenter(_player.x, _player.y, 72, 72);
	
}

void player::addPartner(pokemon* p)
{
	if (_vPartner.size() >= 3)
		return;

	playerPartner* temp;
	temp->init(p->getName());
	_playerStatus = new pokemon;
	_playerStatus->pokemonStatus(p->getName(), 1);

	_vPartner.push_back(temp);
}

void player::setPosition(float startX, float startY)
{
	//좌표
	_player.x = startX /** 24 + 12*/;
	_player.y = startY /** 24 + 12*/;

	//몇번째 타일 x, y에 있나
	_player.idx = _player.x / 24;
	_player.idy = _player.y / 24;

	//몇번째 타일에 있냐
	_player.tileIndex = _player.idx + (_player.idy * _stage->gettileCountX());

	//실제 사용될 렉트
	_player.rc = RectMakeCenter(_player.x, _player.y, 24, 24);

	//이미지 그려주는 렉트
	_player.imageRc = RectMakeCenter(_player.x, _player.y, IMAGEMANAGER->findImage(tempNameIdle.c_str())->getFrameWidth(),
		IMAGEMANAGER->findImage(tempNameIdle.c_str())->getFrameHeight());
}

void player::enemyAttack()
{

}