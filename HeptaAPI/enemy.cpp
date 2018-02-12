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
	idleIndex = 0;
	_count = 0;
	
	return S_OK;
}
void enemy::release()
{

}
void enemy::update() 
{
	//키입력등을 받아주는 함수 임시용이다 쓸데 없다.
	keyControl();
	//현재 상태를 받아서 한다.
	setState();

	//적의 움직임을 스위치로 관리한다 하지만 아직 각도가아닌 키입력이기에
	

	
	if (KEYMANAGER->isStayKeyDown('S'))
	{
		enemyMove();
		_pokemon.state = STATE_MOVE;
	}

}

void enemy::render() 
{

	switch (_pokemon.state)
	{
	case STATE_MOVE:
		_pokemon.moveImage->frameRender(getMemDC(), _pokemon.x - _pokemon.moveImage->getFrameHeight() / 2,
			_pokemon.y - _pokemon.moveImage->getFrameWidth() / 2);
		break;
	case STATE_HURT:
		_pokemon.hurtImage->frameRender(getMemDC(), _pokemon.x - _pokemon.hurtImage->getFrameHeight() / 2,
			_pokemon.y - _pokemon.hurtImage->getFrameWidth() / 2);
		break;
	case STATE_IDLE:
		_pokemon.idleImage->frameRender(getMemDC(), _pokemon.x - _pokemon.idleImage->getFrameHeight() / 2,
			_pokemon.y - _pokemon.idleImage->getFrameWidth() / 2);
		break;
	case STATE_ATTACK:
		_pokemon.atkImage->frameRender(getMemDC(), _pokemon.x - _pokemon.atkImage->getFrameHeight() / 2,
			_pokemon.y - _pokemon.atkImage->getFrameWidth() / 2);
		break;
	}

	


	//Rectangle(getMemDC(), _pokemon.x-12, _pokemon.y-12, _pokemon.x+12, _pokemon.y+12);
} 


void enemy::keyControl()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_pokemon.direction = LEFT;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_pokemon.direction = RIGHT;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_pokemon.direction = UP;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_pokemon.direction = DOWN;

	}
	_pokemon.idleImage->setFrameY(_pokemon.direction);
	_pokemon.moveImage->setFrameY(_pokemon.direction);
	_pokemon.atkImage->setFrameY(_pokemon.direction);
	_pokemon.hurtImage->setFrameY(_pokemon.direction);
}

void enemy::setState()
{
	_count++;
	if (_count % 20 == 0)
	{
		idleIndex++;
		_count = 0;
	}
	if (idleIndex > _pokemon.idleImage->getMaxFrameX())
	{
		idleIndex = 0;
	}




	_pokemon.idleImage->setFrameX(idleIndex);
	_pokemon.moveImage->setFrameX(idleIndex);
	_pokemon.atkImage->setFrameX(idleIndex);

	
}

void enemy::enemyMove()
{
	switch (_pokemon.direction)
	{
	case UP:
		_pokemon.y--;
		break;
	case LEFTUP:
		_pokemon.y--;
		_pokemon.x--;
		break;
	case LEFT:
		_pokemon.x--;
		break;
	case LEFTDOWN:
		_pokemon.y++;
		_pokemon.x--;
		break;
	case DOWN:
		_pokemon.y++;
		break;
	case RIGHTDOWN:
		_pokemon.x++;
		_pokemon.y++;
		break;
	case RIGHT:
		_pokemon.x++;
		break;
	case RIGHTUP:
		_pokemon.y--;
		_pokemon.x++;
		break;
	}
}