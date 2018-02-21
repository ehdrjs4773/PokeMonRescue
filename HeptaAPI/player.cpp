#include "stdafx.h"
#include "player.h"
#include "Stage.h"
#include "enemyManager.h"
#include "Npc.h"
#include "battleScene.h"

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

	//ó�� �ѹ��� �ʱ�ȭ �ؾ� �ϴ°͵�
	_isHurt = false;
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
	_player.currentHp = _playerStatus->getCurrentHP();

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

	//this->FrameUpdate();

	//for (_viPartner = _vPartner.begin(); _viPartner != _vPartner.end(); ++_viPartner)
	//{
	//	(*_viPartner)->update();
	//}

	EFFECTMANAGER->update();
}
void player::render()
{
	HDC hdc = CAMERAMANAGER->getMemDC();
	int x = CAMERAMANAGER->getX();
	int y = CAMERAMANAGER->getY();

	SetBkMode(hdc, TRANSPARENT);
	char str[128];
	sprintf_s(str, " �¾Ѵ� : %d ", _isHurt);
	TextOut(hdc, x + 100, y + 50, str, strlen(str));
	char str2[128];
	sprintf_s(str2, " _player.currentHp ���� �� : %d ", _player.currentHp);
	TextOut(hdc, x + 100, y + 75, str2, strlen(str2));
	char str3[128];
	sprintf_s(str3, " _playerStatus->getCurrentHP() ���� �� : %d ", _playerStatus->getCurrentHP());
	TextOut(hdc, x + 100, y + 100, str3, strlen(str3));

	//Rectangle(getMemDC(), _player.rc.left, _player.rc.top, _player.rc.right, _player.rc.bottom);
	draw();
	EFFECTMANAGER->render(hdc);
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

	//player+move.cpp�� ����
	playerTownMove();
	//������ ������Ʈ
	FrameUpdate();
	//������ ����
	correction();
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

	//if (_playerStatus->getCurrentHP() <= 0)
	//{
	//	_player.state = PLAYER_DIE;
	//}
	//if (_player.state == PLAYER_DIE) return;

	//���° Ÿ�Ͽ� �ִ��� �ε��� x,y
	_player.idx = _player.x / 24;
	_player.idy = _player.y / 24;

	//���° Ÿ�Ͽ� �ֳ�
	_player.tileIndex = _player.idx + (_player.idy * _stage->gettileCountX());

	//Ÿ�ϰ���
	tileCheak();

	//�ǰݻ���
	if (_player.currentHp != _playerStatus->getCurrentHP())
	{
		_isHurt = true;
		_player.state = PLAYER_HURT;

	}
	_player.currentHp = _playerStatus->getCurrentHP();
	

	//����� ���� 1
	if (KEYMANAGER->isOnceKeyDown('Q') && !_isAttack && !_onceMove && !_isHurt)
	{
		_isAttack = true;
		_player.state = PLAYER_SPECIAL_ATTACK_1;
	}

	//����� ���� 2
	if (KEYMANAGER->isOnceKeyDown('W') && !_isAttack && !_onceMove && !_isHurt)
	{
		_isAttack = true;
		_player.state = PLAYER_SPECIAL_ATTACK_2;
	}

	//����� ���� 2
	if (KEYMANAGER->isOnceKeyDown('E') && !_isAttack && !_onceMove && !_isHurt)
	{
		_isAttack = true;
		_player.state = PLAYER_SPECIAL_ATTACK_3;
	}

	//����Ű
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE) && !_isAttack && !_onceMove && !_isHurt)
	{
		_isAttack = true;
		_player.state = PLAYER_ATTACK;
	}
	//���ʾƷ�
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && KEYMANAGER->isStayKeyDown(VK_DOWN) && !(KEYMANAGER->isStayKeyDown(VK_RIGHT)) &&
		!(KEYMANAGER->isStayKeyDown(VK_UP)) && !_isAttack && !_onceMove && !_isHurt)
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
		!(KEYMANAGER->isStayKeyDown(VK_UP)) && !_isAttack && !_onceMove && !_isHurt)
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
		!(KEYMANAGER->isStayKeyDown(VK_DOWN)) && !_isAttack && !_onceMove && !_isHurt)
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
		!(KEYMANAGER->isStayKeyDown(VK_DOWN)) && !_isAttack && !_onceMove && !_isHurt)
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
		&& !(KEYMANAGER->isStayKeyDown(VK_LEFT)) && !_isAttack && !_onceMove && !_isHurt )
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
		&& !(KEYMANAGER->isStayKeyDown(VK_DOWN)) && !_isAttack && !_onceMove && !_isHurt)
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
		&& !(KEYMANAGER->isStayKeyDown(VK_DOWN)) && !_isAttack && !_onceMove && !_isHurt)
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
		&& !(KEYMANAGER->isStayKeyDown(VK_DOWN)) && !_isAttack && !_onceMove && !_isHurt)
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
				_player.state = PLAYER_IDLE;
				_battle->setTurn(enemyTurn);
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
				_player.state = PLAYER_IDLE;
				_battle->setTurn(enemyTurn);
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
				_player.state = PLAYER_IDLE;
				_battle->setTurn(enemyTurn);
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
				_player.state = PLAYER_IDLE;
				_battle->setTurn(enemyTurn);
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
				_player.state = PLAYER_IDLE;
				_battle->setTurn(enemyTurn);
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
				_player.state = PLAYER_IDLE;
				_battle->setTurn(enemyTurn);
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
				_player.state = PLAYER_IDLE;
				_battle->setTurn(enemyTurn);
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
				_player.state = PLAYER_IDLE;
				_battle->setTurn(enemyTurn);
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

	//������ ����
	FrameUpdate();

	CAMERAMANAGER->cameraMove(_player.x, _player.y);
	
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
