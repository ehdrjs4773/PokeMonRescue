#include "enemy.h"
#include "Stage.h"



enemy::enemy()
{
}


enemy::~enemy()
{

}


HRESULT enemy::init()
{
	
	return S_OK;
}

HRESULT enemy::init(tagImageName PokemonName, float x, float y,  int level)
{

	//����ü�� ����ξ��� ���ϸ��� �̸��� �޾ƿ��� �������ͽ� �ʱ�ȭ
	pokemonStatus(PokemonName.pokemonName, level);

	//4�� �̹��� �ʱ�ȭ
	_pokemon.idleImageName = PokemonName.idleImage;
	_pokemon.idleImage = IMAGEMANAGER->findImage(PokemonName.idleImage);

	_pokemon.moveImageName = PokemonName.moveImage;
	_pokemon.moveImage = IMAGEMANAGER->findImage(PokemonName.moveImage);

	_pokemon.atkImageName= PokemonName.attackImage;
	_pokemon.atkImage = IMAGEMANAGER->findImage(PokemonName.attackImage);

	_pokemon.hurtImageName = PokemonName.hurtImage;
	_pokemon.hurtImage = IMAGEMANAGER->findImage(PokemonName.hurtImage);

	//��ǥ �ʱ�ȭ �� �̰� ���߿� �������������� �޾ƿ��� �Ǵϱ�
	_pokemon.x = x;
	_pokemon.y = y;


	_pokemon.rc = RectMakeCenter(_pokemon.x, _pokemon.y, 20, 20);
	//Rectangle(getMemDC(), _pokemon.x - 5, _pokemon.y - 5, _pokemon.x + 5, _pokemon.y + 5);

	
	_pokemon.speed = 2;
	//�𷺼��� �⺻������ �Ʒ��� �ٶ���
	_pokemon.direction = UP;

	//�⺻����
	_pokemon.state = STATE_IDLE;

	//�����ӹ�ȣ�� ī��Ʈ�� �ʱ�ȭ
	_idleIndex = 0;
	_moveIndex = 0;
	_atkIndex = 0;
	_hurtIndex = 0;
	
	_idleReverse = false;
	_moveReverse = false;
	_hurtReverse = false;
	_atkReverse = false;
	_isMove = false;
	_distance = 0;

	_count = 0;
	
	return S_OK;
}
void enemy::release()
{

}
void enemy::update() 
{

	//bool isOpen = false;
	//tile start;
	//tile end;
	//
	//for (int i = 0; i < _stage->gettileCountX()* _stage->gettileCountY(); ++i)
	//{
	//	RECT temp = RectMakeCenter(_stage->getTileAdress()[i]->getCenterX(),
	//		_stage->getTileAdress()[i]->getCenterY(), TILESIZEX, TILESIZEY);
	//	if (PtInRect(&temp, PointMake(_pokemon.x, _pokemon.y)))
	//	{
	//		start = *_stage->getTileAdress()[i];
	//		break;
	//	}
	//}
	//
	//for (int i = 0; i < _stage->gettileCountX()* _stage->gettileCountY(); ++i)
	//{
	//	RECT temp = RectMakeCenter(_stage->getTileAdress()[i]->getCenterX(),
	//		_stage->getTileAdress()[i]->getCenterY(), TILESIZEX, TILESIZEY);
	//	if (PtInRect(&temp, PointMake(_ptMouse.x, _ptMouse.y)))
	//	{
	//		if (!_stage->getTileAdress()[i]->getIsOpen()) continue;
	//		else if (_stage->getTileAdress()[i]->getIsOpen())
	//		{
	//			isOpen = true;
	//			end = *_stage->getTileAdress()[i];
	//		}
	//		break;
	//	}
	//}
	//
	//if (!isOpen)
	//{
	//	return;
	//}
	//_ast->init(_stage->getTileAdress(), _stage->gettileCountX(), _stage->gettileCountY(), start, end);
	//_vCloseList = _ast->pathFinder(start);




	//���� ���¸� �޾Ƽ� �Ѵ�.
	setState();
	//���� �������� ����ġ�� �����Ѵ� ������ ���� �������ƴ� Ű�Է��̱⿡
	
	_pokemon.rc = RectMakeCenter(_pokemon.x, _pokemon.y, 20, 20);

	if (KEYMANAGER->isOnceKeyDown('S'))
	{
		_isMove = true;
	}
	if (_isMove)
	{
		enemyTileMove();
	}
	if(_pokemon.state == STATE_IDLE)
		enemyAngleSetting();
}

void enemy::render() 
{
	switch (_pokemon.state)
	{

		//�⺻����
	case STATE_IDLE:
		_pokemon.idleImage->frameRender(CAMERAMANAGER->getMemDC(), _pokemon.x - _pokemon.idleImage->getFrameHeight() / 2,
			_pokemon.y - _pokemon.idleImage->getFrameWidth() / 2,_idleIndex, _pokemon.direction);
		break;

		//�̵�����
	case STATE_MOVE:
		_pokemon.moveImage->frameRender(CAMERAMANAGER->getMemDC(), _pokemon.x - _pokemon.moveImage->getFrameHeight() / 2,
			_pokemon.y - _pokemon.moveImage->getFrameWidth() / 2, _moveIndex, _pokemon.direction);
		break;
		
		//��˰ݷ���
	case STATE_ATTACK:
		_pokemon.atkImage->frameRender(CAMERAMANAGER->getMemDC(), _pokemon.x - _pokemon.atkImage->getFrameHeight() / 2,
			_pokemon.y - _pokemon.atkImage->getFrameWidth() / 2, _atkIndex, _pokemon.direction);
		break;

		//Ÿ�ݷ���
	case STATE_HURT:
		_pokemon.hurtImage->frameRender(CAMERAMANAGER->getMemDC(), _pokemon.x - _pokemon.hurtImage->getFrameHeight() / 2,
			_pokemon.y - _pokemon.hurtImage->getFrameWidth() / 2,_hurtIndex, _pokemon.direction);
		break;
	}

	//Rectangle(getMemDC(), _pokemon.x - 5, _pokemon.y - 5, _pokemon.x + 5, _pokemon.y + 5);

} 


//�ֵ��� ������ �������� ����ϴ� �Լ�
void enemy::setState()
{
	_count++;

	if (_count % 20 == 0)
	{
		//�������� ���� Ʈ��� �Ųٷ� ����� �ϰ�
		//�������� ���� ������ �⺻���� �������� ����Ѵ�.
		//�⺻ �̵� ���� �����ϴ°� ����� 
		switch (_pokemon.state)
		{
		case STATE_IDLE:
			if (0 != _pokemon.idleImage->getMaxFrameX())
			{
				if (_idleReverse) { _idleIndex--; }
				if (!_idleReverse) { _idleIndex++; }
			}
			_moveIndex=0;
			_atkIndex=0;
			_hurtIndex=0; 
			break;

		case STATE_MOVE:
			if (0 != _pokemon.moveImage->getMaxFrameX())
			{
				if (_moveReverse) { _moveIndex--; }
				if (!_moveReverse) { _moveIndex++; }
			}
			_idleIndex = 0;
			_atkIndex = 0;
			_hurtIndex = 0;
			break;

		case STATE_ATTACK:
			if (0 != _pokemon.atkImage->getMaxFrameX())
			{
				_atkIndex++;
			}
			_idleIndex = 0;
			_moveIndex = 0;
			_hurtIndex = 0;
			break;
		case STATE_HURT:
			if (0 != _pokemon.hurtImage->getMaxFrameX())
			{
				if (_hurtReverse) { _hurtIndex--; }
				if (!_hurtReverse) { _hurtIndex++; }
			}
			_idleIndex = 0;
			_moveIndex = 0;
			_atkIndex = 0;
			break;
		}
		
		_count = 0;
	}

	//���� �������� ������ �ٴ޾����� Ʈ��� �ٲ㼭 �Ųܷ� ������
	//���� �������� �ʹݿ� �ٴ޾����� ������ �ٲ㼭 ���������� ������
	//�׷��� �����Ӹƽ��� 0�̸� �������� �ʰ� �׳� ������ �д�.
	

	//�⺻����
		if (_idleIndex >= _pokemon.idleImage->getMaxFrameX()) { _idleReverse = true; }
		else if (_idleIndex <= 0) { _idleReverse = false; }

	//�̵�����
		if (_moveIndex >= _pokemon.moveImage->getMaxFrameX()) { _moveReverse = true; }
		else if (_moveIndex <= 0) { _moveReverse = false; }

	//���ݰ���
		if (_atkIndex >= _pokemon.atkImage->getMaxFrameX())
		{
			_atkIndex = 0;
			_pokemon.state = STATE_IDLE;
		}


	//Ÿ�ݰ���
		if (_hurtIndex >= _pokemon.hurtImage->getMaxFrameX()) { _hurtReverse = true; }
		else if (_hurtIndex <= 0) { _hurtReverse = false; }

}


void enemy::enemyAngleSetting()
{
	//if (_vCloseList.size() <= 0)
	//	return;

	//RECT temp = RectMakeCenter(_vCloseList[_vCloseList.size() - 1].getCenterX(), _vCloseList[_vCloseList.size() - 1].getCenterY(), TILESIZEX, TILESIZEY);
	float target = getAngle(_pokemon.x, _pokemon.y, _ptMouse.x, _ptMouse.y);
	//float target = getAngle(_pokemon.x, _pokemon.y, _vCloseList[_vCloseList.size() - 1].getCenterX(), _vCloseList[_vCloseList.size() - 1].getCenterY());

	
	if(target <= PI8 && target >=0 || target >= PI8*15 && target <= PI8 * 16)
	{
		_pokemon.direction = RIGHT;
	}
	if (PI8 < target && PI8*3 > target)
	{
		_pokemon.direction = RIGHTUP;
	}
	if (PI8 * 3 <= target && PI8 * 5 >= target)
	{
		_pokemon.direction = UP;
	}
	if (PI8 * 5 < target && PI8 * 7 > target)
	{
		_pokemon.direction = LEFTUP;
	}
	if (PI8 * 7 <= target && PI8 * 9 >= target)
	{
		_pokemon.direction = LEFT;
	}
	if (PI8 * 9< target && PI8 * 11 > target)
	{
		_pokemon.direction = LEFTDOWN;
	}
	if (PI8 * 11 <= target && PI8 * 13 >= target)
	{
		_pokemon.direction = DOWN;
	}
	if (PI8 * 13 < target && PI8 * 15 > target)
	{
		_pokemon.direction = RIGHTDOWN;
	}
}





void enemy::enemyTileMove()
{
	_pokemon.idx = _pokemon.x / 24;
	_pokemon.idy = _pokemon.y / 24;
	_pokemon.tileIndex = _pokemon.idx + _pokemon.idy;
	if (_distance < 24)
	{
		_tempSpeed = _pokemon.speed;

		if (_distance + _pokemon.speed <= 24)
		{
			_distance += _pokemon.speed;
		}
		else if (_distance + _pokemon.speed > 24)
		{
			_pokemon.speed = 24 - _distance;
			_distance += _pokemon.speed;
		}
	}
	if (_distance > 24)
	{
		_distance = 0;
		_isMove = false;
		_pokemon.speed = _tempSpeed;
		return;
	}
	if (_distance == 24)
	{
		_distance = 0;
		_isMove = false;
		
	}

	switch (_pokemon.direction)
	{
	case UP:
		_pokemon.y -= _pokemon.speed;
		break;
	case LEFTUP:
		_pokemon.y -= _pokemon.speed;
		_pokemon.x -= _pokemon.speed;
		break;
	case LEFT:
		_pokemon.x -= _pokemon.speed;
		break;
	case LEFTDOWN:
		_pokemon.y += _pokemon.speed;
		_pokemon.x -= _pokemon.speed;
		break;
	case DOWN:
		_pokemon.y += _pokemon.speed;
		break;
	case RIGHTDOWN:
		_pokemon.x += _pokemon.speed;
		_pokemon.y += _pokemon.speed;
		break;
	case RIGHT:
		_pokemon.x += _pokemon.speed;
		break;
	case RIGHTUP:
		_pokemon.y -= _pokemon.speed;
		_pokemon.x += _pokemon.speed;
		break;
	}
	
	if (_isMove)
	{
		_pokemon.state = STATE_MOVE;
	}
	else if (!_isMove)
	{
		_pokemon.state= STATE_IDLE;
	}
	_pokemon.speed = _tempSpeed;
}

void enemy::enemyAttackMotion()
{
	_pokemon.state = STATE_ATTACK;
}
void enemy::enemyHurtMotion()
{
	_pokemon.state = STATE_HURT;
}
void enemy::enemyMoveSign()
{
	_isMove = true;
}
