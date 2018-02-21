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
	//���� �� ����
	_player.direction = PLAYER_BOTTOM;
	_player.state = PLAYER_IDLE;

	//���� �ʱ�ȭ ( player+valueInit.cpp�� ���� )
	valueInit();

	_isWallCrash = false;
	_player.townSpeed = 3.0f;

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
	//�������� ������
	//townMove();

	//�������� ������
	//dungeonMove();

	CAMERAMANAGER->cameraMove(_player.x, _player.y);

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
	char str[128];
	sprintf_s(str, " �浹 �Ұ� ���� �� : %d ", _town->getHouse());
	TextOut(hdc, x + 200, y + 50, str, strlen(str));
	//char str2[128];
	//sprintf_s(str2, " ( _player.y ) ���� �� : %f ", _player.y);
	//TextOut(hdc, x + 200, y + 75, str2, strlen(str2));
	//char str3[128];
	//sprintf_s(str3, " ( _player.startX ) ���� �� : %f ", _player.startX);
	//TextOut(hdc, x + 200, y + 100, str3, strlen(str3));
	//char str4[128];
	//sprintf_s(str4, " ( _player.startY ) ���� �� : %f ", _player.startY);
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
	//sprintf_s(str7, " _player.idx �� : %d ", _player.idx);
	//TextOut(hdc, x + 200, y + 200, str7, strlen(str7));
	//char str8[128];
	//sprintf_s(str8, " _player.idy �� : %d ", _player.idy);
	//TextOut(hdc, x + 200, y + 225, str8, strlen(str8));


	//Rectangle(getMemDC(), _player.rc.left, _player.rc.top, _player.rc.right, _player.rc.bottom);
	//for (_viPartner = _vPartner.begin(); _viPartner != _vPartner.end(); ++_viPartner)
	//{
	//	(*_viPartner)->render();
	//}
	draw();
}

// ================================================================================================
// ================================ ## �������� ������ ## ==========================================
// ================================================================================================
void player::townMove()
{
	//����Ű
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

	//���ʾƷ�
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && KEYMANAGER->isStayKeyDown(VK_DOWN) && !(KEYMANAGER->isStayKeyDown(VK_RIGHT)) &&
		!(KEYMANAGER->isStayKeyDown(VK_UP)) && !_isAttack)
	{
		_player.angle = 225 * DEG2RAD;
		_player.direction = PLAYER_LEFT_BOTTOM;
		_player.state = PLAYER_MOVE;
	}
	//�����ʾƷ�
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && KEYMANAGER->isStayKeyDown(VK_DOWN) && !(KEYMANAGER->isStayKeyDown(VK_LEFT)) &&
		!(KEYMANAGER->isStayKeyDown(VK_UP)) && !_isAttack)
	{
		_player.angle = 315 * DEG2RAD;
		_player.direction = PLAYER_RIGHT_BOTTOM;
		_player.state = PLAYER_MOVE;
	}
	//������
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && KEYMANAGER->isStayKeyDown(VK_UP) && !(KEYMANAGER->isStayKeyDown(VK_RIGHT)) &&
		!(KEYMANAGER->isStayKeyDown(VK_DOWN)) && !_isAttack)
	{
		_player.angle = 135 * DEG2RAD;
		_player.direction = PLAYER_LEFT_TOP;
		_player.state = PLAYER_MOVE;
	}
	//��������
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && KEYMANAGER->isStayKeyDown(VK_UP) && !(KEYMANAGER->isStayKeyDown(VK_LEFT)) &&
		!(KEYMANAGER->isStayKeyDown(VK_DOWN)) && !_isAttack)
	{
		_player.angle = 45 * DEG2RAD;
		_player.direction = PLAYER_RIGHT_TOP;
		_player.state = PLAYER_MOVE;
	}
	//�Ʒ�
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && !(KEYMANAGER->isStayKeyDown(VK_RIGHT)) && !(KEYMANAGER->isStayKeyDown(VK_UP))
		&& !(KEYMANAGER->isStayKeyDown(VK_LEFT)) && !_isAttack)
	{
		_player.angle = 270 * DEG2RAD;
		_player.direction = PLAYER_BOTTOM;
		_player.state = PLAYER_MOVE;
	}
	//��
	if (KEYMANAGER->isStayKeyDown(VK_UP) && !(KEYMANAGER->isStayKeyDown(VK_RIGHT)) && !(KEYMANAGER->isStayKeyDown(VK_LEFT))
		&& !(KEYMANAGER->isStayKeyDown(VK_DOWN)) && !_isAttack)
	{
		_player.angle = 90 * DEG2RAD;
		_player.direction = PLAYER_TOP;
		_player.state = PLAYER_MOVE;
	}
	//����
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && !(KEYMANAGER->isStayKeyDown(VK_RIGHT)) && !(KEYMANAGER->isStayKeyDown(VK_UP))
		&& !(KEYMANAGER->isStayKeyDown(VK_DOWN)) && !_isAttack)
	{
		_player.angle = 180 * DEG2RAD;
		_player.direction = PLAYER_LEFT;
		_player.state = PLAYER_MOVE;
	}
	//������
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && !(KEYMANAGER->isStayKeyDown(VK_LEFT)) && !(KEYMANAGER->isStayKeyDown(VK_UP))
		&& !(KEYMANAGER->isStayKeyDown(VK_DOWN)) && !_isAttack)
	{
		_player.angle = 0 * DEG2RAD;
		_player.direction = PLAYER_RIGHT;
		_player.state = PLAYER_MOVE;
	}

	//�ȼ��浹
	pixelCollision();

	//���� �ε������� �ӵ�����
	if (!_isWallCrash)
	{
		_player.townSpeed = 3.0f;
	}
	else
	{
		_player.townSpeed = 0.0f;
	}

	//������Ű ������
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
	//��Ű ���� ��
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
	//�Ʒ�Ű ������
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
	//����Ű ���� ��
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
	
	//������ ������Ʈ
	FrameUpdate();
	//������ ����
	correction();
	//player+move.cpp�� ����
	playerTownMove();
	//������Ʈ
	_player.rc = RectMakeCenter(_player.x, _player.y, 24, 24);
	//�̹��� �ѷ��ִ� rc
	_player.imageRc = RectMakeCenter(_player.x, _player.y, IMAGEMANAGER->findImage(tempNameIdle.c_str())->getFrameWidth(),
		IMAGEMANAGER->findImage(tempNameIdle.c_str())->getFrameHeight());

	

}

// ============================================================================================
// ================================== ## �������� ������ ## ====================================
// ============================================================================================
void player::dungeonMove()
{
	//���° Ÿ�Ͽ� �ִ��� �ε��� x,y
	_player.idx = _player.x / 24;
	_player.idy = _player.y / 24;

	//���° Ÿ�Ͽ� �ֳ�
	_player.tileIndex = _player.idx + (_player.idy * _stage->gettileCountX());

	//Ÿ�ϰ���
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

	//����Ű
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
	//���ʾƷ�
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
	//�����ʾƷ�
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
	//������
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
	//��������
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
	//�Ʒ�
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
	//��
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
	//����
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
	//������
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
	
	//������ ����
	FrameUpdate();
	//������ ���� ( �������� �ʿ� ������ )
	//correction();
	//player+move.cpp�� ����
	playerDgMove();

	//�̰ɷ� ��Ÿ�Ͼ� �̵��ϴ°�ó�� ���̰� �Ұ���
	switch (_player.state)
	{
	case PLAYER_MOVE:
		switch (_player.direction)
		{
		case PLAYER_BOTTOM:
			if (TILESIZEX <= getDistance(_player.startX, _player.startY, _player.x, _player.y))
			{
				_onceMove = false;
				//����			
				if (_player.x != _stage->getTileAdress()[_player.tileIndex]->getCenterX())
					_player.x = _stage->getTileAdress()[_player.tileIndex]->getCenterX();
				if (_player.y != _stage->getTileAdress()[_player.tileIndex]->getCenterY())
					_player.y = _stage->getTileAdress()[_player.tileIndex]->getCenterY();
				_player.direction = PLAYER_BOTTOM;
				_player.state = PLAYER_IDLE;
				_playerAction = playerMove;			//�ӽ�
				//������ �Ծ��� ��
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
				//����
				if (_player.x != _stage->getTileAdress()[_player.tileIndex]->getCenterX())
					_player.x = _stage->getTileAdress()[_player.tileIndex]->getCenterX();
				if (_player.y != _stage->getTileAdress()[_player.tileIndex]->getCenterY())
					_player.y = _stage->getTileAdress()[_player.tileIndex]->getCenterY();
				_player.direction = PLAYER_LEFT_BOTTOM;
				_player.state = PLAYER_IDLE;
				//������ �Ծ��� ��
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
				//����
				if (_player.x != _stage->getTileAdress()[_player.tileIndex]->getCenterX())
					_player.x = _stage->getTileAdress()[_player.tileIndex]->getCenterX();
				if (_player.y != _stage->getTileAdress()[_player.tileIndex]->getCenterY())
					_player.y = _stage->getTileAdress()[_player.tileIndex]->getCenterY();
				_player.direction = PLAYER_LEFT;
				_player.state = PLAYER_IDLE;
				//������ �Ծ��� ��
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
				//����
				if (_player.x != _stage->getTileAdress()[_player.tileIndex]->getCenterX())
					_player.x = _stage->getTileAdress()[_player.tileIndex]->getCenterX();
				if (_player.y != _stage->getTileAdress()[_player.tileIndex]->getCenterY())
					_player.y = _stage->getTileAdress()[_player.tileIndex]->getCenterY();
				_player.direction = PLAYER_LEFT_TOP;
				_player.state = PLAYER_IDLE;
				//������ �Ծ��� ��
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
				//����
				if (_player.x != _stage->getTileAdress()[_player.tileIndex]->getCenterX())
					_player.x = _stage->getTileAdress()[_player.tileIndex]->getCenterX();
				if (_player.y != _stage->getTileAdress()[_player.tileIndex]->getCenterY())
					_player.y = _stage->getTileAdress()[_player.tileIndex]->getCenterY();
				_player.direction = PLAYER_TOP;
				_player.state = PLAYER_IDLE;
				//������ �Ծ��� ��
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
				//����
				if (_player.x != _stage->getTileAdress()[_player.tileIndex]->getCenterX())
					_player.x = _stage->getTileAdress()[_player.tileIndex]->getCenterX();
				if (_player.y != _stage->getTileAdress()[_player.tileIndex]->getCenterY())
					_player.y = _stage->getTileAdress()[_player.tileIndex]->getCenterY();
				_player.direction = PLAYER_RIGHT_TOP;
				_player.state = PLAYER_IDLE;
				//������ �Ծ��� ��
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
				//����
				if (_player.x != _stage->getTileAdress()[_player.tileIndex]->getCenterX())
					_player.x = _stage->getTileAdress()[_player.tileIndex]->getCenterX();
				if (_player.y != _stage->getTileAdress()[_player.tileIndex]->getCenterY())
					_player.y = _stage->getTileAdress()[_player.tileIndex]->getCenterY();
				_player.direction = PLAYER_RIGHT;
				_player.state = PLAYER_IDLE;
				//������ �Ծ��� ��
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
				//����
				if (_player.x != _stage->getTileAdress()[_player.tileIndex]->getCenterX())
					_player.x = _stage->getTileAdress()[_player.tileIndex]->getCenterX();
				if (_player.y != _stage->getTileAdress()[_player.tileIndex]->getCenterY())
					_player.y = _stage->getTileAdress()[_player.tileIndex]->getCenterY();
				_player.direction = PLAYER_RIGHT_BOTTOM;
				_player.state = PLAYER_IDLE;
				//������ �Ծ��� ��
				if ((int)_stage->getTileAdress()[_player.tileIndex]->getObject() < 6)
				{
					_stage->getTileAdress()[_player.tileIndex]->setObject(OBJECT_NONE);
				}
			}
			break;
		}
		break;
	}
	
	//������Ʈ
	_player.rc = RectMakeCenter(_player.x, _player.y, 24, 24);

	//�̹��� �ѷ��ִ� rc
	_player.imageRc = RectMakeCenter(_player.x, _player.y, 72, 72);
	
}

void player::addPartner(pokemon* p)
{
	if (_vPartner.size() >= 3)
		return;

	playerPartner* temp;
	temp->init(p->getName());

	_vPartner.push_back(temp);
}

void player::setPosition(float startX, float startY)
{
	//��ǥ
	_player.x = startX /** 24 + 12*/;
	_player.y = startY /** 24 + 12*/;

	//���° Ÿ�� x, y�� �ֳ�
	_player.idx = _player.x / 24;
	_player.idy = _player.y / 24;

	//���° Ÿ�Ͽ� �ֳ�
	_player.tileIndex = _player.idx + (_player.idy * _stage->gettileCountX());

	//���� ���� ��Ʈ
	_player.rc = RectMakeCenter(_player.x, _player.y, 24, 24);

	//�̹��� �׷��ִ� ��Ʈ
	_player.imageRc = RectMakeCenter(_player.x, _player.y, IMAGEMANAGER->findImage(tempNameIdle.c_str())->getFrameWidth(),
		IMAGEMANAGER->findImage(tempNameIdle.c_str())->getFrameHeight());

	
}