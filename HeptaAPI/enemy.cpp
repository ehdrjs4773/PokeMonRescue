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


	//�𷺼��� �⺻������ �Ʒ��� �ٶ���
	_pokemon.direction = UP;

	//�⺻����
	_pokemon.state = STATE_IDLE;

	//�����ӹ�ȣ�� ī��Ʈ�� �ʱ�ȭ
	idleIndex = 0;
	_count = 0;
	
	return S_OK;
}
void enemy::release()
{

}
void enemy::update() 
{
	//Ű�Էµ��� �޾��ִ� �Լ� �ӽÿ��̴� ���� ����.
	keyControl();
	//���� ���¸� �޾Ƽ� �Ѵ�.
	setState();

	//���� �������� ����ġ�� �����Ѵ� ������ ���� �������ƴ� Ű�Է��̱⿡
	

	
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