#include "enemy.h"



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

HRESULT enemy::init(tagImageName PokemonName, float x, float y)
{


	//4대 이미지 초기화
	_pokemon.idleImageName = PokemonName.idleImage;
	_pokemon.idleImage = IMAGEMANAGER->findImage(PokemonName.idleImage);

	_pokemon.moveImageName = PokemonName.moveImage;
	_pokemon.moveImage = IMAGEMANAGER->findImage(PokemonName.moveImage);

	_pokemon.atkImageName= PokemonName.attackImage;
	_pokemon.atkImage = IMAGEMANAGER->findImage(PokemonName.attackImage);

	_pokemon.hurtImageName = PokemonName.hurtImage;
	_pokemon.hurtImage = IMAGEMANAGER->findImage(PokemonName.hurtImage);

	//좌표 초기화 뭐 이건 나중에 리스폰지역으로 받아오면 되니까
	_pokemon.x = x;
	_pokemon.y = y;
	
	//디렉션은 기본적으로 아래를 바라보자
	_pokemon.direction = UP;

	//기본상태
	_pokemon.state = STATE_IDLE;

	//프레임번호와 카운트의 초기화
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

	//현재 상태를 받아서 한다.
	setState();
	//적의 움직임을 스위치로 관리한다 하지만 아직 각도가아닌 키입력이기에
	
	if (KEYMANAGER->isOnceKeyDown('S'))
	{
		_isMove = true;
	}
	if (_isMove)
		enemyTileMove();
	else if(!_isMove)
		enemyAngleSetting();

}

void enemy::render() 
{

	switch (_pokemon.state)
	{

		//기본렌더
	case STATE_IDLE:
		_pokemon.idleImage->frameRender(getMemDC(), _pokemon.x - _pokemon.idleImage->getFrameHeight() / 2,
			_pokemon.y - _pokemon.idleImage->getFrameWidth() / 2);
		break;

		//이동렌더
	case STATE_MOVE:
		_pokemon.moveImage->frameRender(getMemDC(), _pokemon.x - _pokemon.moveImage->getFrameHeight() / 2,
			_pokemon.y - _pokemon.moveImage->getFrameWidth() / 2);
		break;
		
		//고옹격렌더
	case STATE_ATTACK:
		_pokemon.atkImage->frameRender(getMemDC(), _pokemon.x - _pokemon.atkImage->getFrameHeight() / 2,
			_pokemon.y - _pokemon.atkImage->getFrameWidth() / 2);
		break;

		//타격렌더
	case STATE_HURT:
		_pokemon.hurtImage->frameRender(getMemDC(), _pokemon.x - _pokemon.hurtImage->getFrameHeight() / 2,
			_pokemon.y - _pokemon.hurtImage->getFrameWidth() / 2);
		break;
	}

	Rectangle(getMemDC(), _pokemon.x - 5, _pokemon.y - 5, _pokemon.x + 5, _pokemon.y + 5);

} 


//애들의 상태의 프레임을 계산하는 함수
void enemy::setState()
{
	_count++;

	if (_count % 20 == 0)
	{
		//리버스가 만약 트루면 거꾸로 재생을 하고
		//리버스가 만약 폴스면 기본으로 프레임을 재생한다.
		//기본 이동 공격 아파하는것 등등은 
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

	//각자 프레임의 정점에 다달았을때 트루로 바꿔서 거꿀로 돌린다
	//각자 프레임의 초반에 다달았을때 폴스로 바꿔서 정상적으로 돌린다
	//그러나 프레임맥스가 0이면 실행하지 않고 그냥 가만히 둔다.
	

	//기본관련
		if (_idleIndex >= _pokemon.idleImage->getMaxFrameX()) { _idleReverse = true; }
		else if (_idleIndex <= 0) { _idleReverse = false; }

	//이동관련
		if (_moveIndex >= _pokemon.moveImage->getMaxFrameX()) { _moveReverse = true; }
		else if (_moveIndex <= 0) { _moveReverse = false; }

	//공격관련
		if (_atkIndex >= _pokemon.atkImage->getMaxFrameX())
		{
			_atkIndex = 0;
			_pokemon.state = STATE_IDLE;
		}


	//타격관련
		if (_hurtIndex >= _pokemon.hurtImage->getMaxFrameX()) { _hurtReverse = true; }
		else if (_hurtIndex <= 0) { _hurtReverse = false; }

	_pokemon.idleImage->setFrameX(_idleIndex);
	_pokemon.moveImage->setFrameX(_moveIndex);
	_pokemon.atkImage->setFrameX(_atkIndex);
	_pokemon.hurtImage->setFrameX(_hurtIndex);

}


void enemy::enemyAngleSetting()
{
	float target = getAngle(_pokemon.x, _pokemon.y, _ptMouse.x, _ptMouse.y);
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
	_pokemon.idleImage->setFrameY(_pokemon.direction);
	_pokemon.moveImage->setFrameY(_pokemon.direction);
	_pokemon.atkImage->setFrameY(_pokemon.direction);
	_pokemon.hurtImage->setFrameY(_pokemon.direction);
}

void enemy::enemyTileMove()
{
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
