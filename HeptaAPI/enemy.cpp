#include "enemy.h"
#include "player.h"
#include "Stage.h"



enemy::enemy()
	:_ast(NULL)
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

	_pokemoName = PokemonName.pokemonName;
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
	_pokemon.direction = DOWN;
	//�⺻����
	_pokemon.state = STATE_IDLE;





	//�����ӹ�ȣ�� ī��Ʈ�� �ʱ�ȭ
	_idleIndex	= 0;
	_moveIndex	= 0;
	_atkIndex	= 0;
	_hurtIndex	= 0;
	
	
	_bossIndex = 0;
	_beamIndex = 0;
	_ringIndex = 0;



	_distance	= 0;
	_target		= 0;
	_count		= 0;
	_hurtTimer	= 0;

	_idleReverse	=		false;
	_moveReverse	=		false;
	_hurtReverse	=		false;
	_atkReverse		=		false;
	_isMove			=		false;
	_myTrun			=		false;
	_cheackTrun		=		false;
	_needAstar		=		false;

	_beamReady = false;
	
	
	
	return S_OK;
}
void enemy::release()
{

}
void enemy::update() 
{
	//���� ���¸� �޾Ƽ� �Ѵ�.
	setState();
	//���� �������� ����ġ�� �����Ѵ� ������ ���� �������ƴ� Ű�Է��̱⿡
	
	_pokemon.rc = RectMakeCenter(_pokemon.x, _pokemon.y, 20, 20);
	if (_pokemon.state == STATE_IDLE)
		enemyAngleSetting();
	
	if (KEYMANAGER->isOnceKeyDown('S'))
	{
		damageToHP(10);
	}
	if (_isMove)
	{
		enemyTileMove();
	}

	
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
	case STATE_SKILL:
		IMAGEMANAGER->findImage("�ܵ��⽺ų")->frameRender(CAMERAMANAGER->getMemDC(), _pokemon.x -24,
			_pokemon.y -60, _atkIndex , _pokemon.direction);
		break;
	case STATE_BEAM:
		IMAGEMANAGER->findImage("HyperBeam")->frameRender(CAMERAMANAGER->getMemDC(), _pokemon.x - 48,
			_pokemon.y - 60, _bossIndex, 0);
		IMAGEMANAGER->findImage("Ring")->frameRender(CAMERAMANAGER->getMemDC(), _pokemon.x - 48,
			_pokemon.y - 60, _bossIndex, 0);
		if (_beamReady)
		{
			IMAGEMANAGER->findImage("Beam")->frameRender(CAMERAMANAGER->getMemDC(), _pokemon.x - 48,
				_pokemon.y, 0, _beamIndex);
		}
		break;
	}

	//Rectangle(getMemDC(), _pokemon.x - 5, _pokemon.y - 5, _pokemon.x + 5, _pokemon.y + 5);

} 


//�ֵ��� ������ �������� ����ϴ� �Լ�
void enemy::setState()
{
	_count++;

	if (_count % 15 == 0)
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

				_hurtTimer += TIMEMANAGER->getElapsedTime();
				if (_hurtTimer >= 0.05)
				{
					_pokemon.state = STATE_IDLE;
				}
				_hurtIndex = 0;
			_idleIndex = 0;
			_moveIndex = 0;
			_atkIndex = 0;
			break;

		case STATE_SKILL:
			if (0 != IMAGEMANAGER->findImage("�ܵ��⽺ų")->getMaxFrameX())
			{
				_atkIndex++;
			}
			_idleIndex = 0;
			_moveIndex = 0;
			_hurtIndex = 0;
			break;

		case STATE_BEAM:
				if (!_beamReady)
				{
					_bossIndex++;
					_ringIndex++;
				}
				if (_beamReady)
				{
					_beamIndex++;
					_ringIndex++;
				}

			_idleIndex = 0;
			_moveIndex = 0;
			_hurtIndex = 0;
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
		if (_atkIndex >= _pokemon.atkImage->getMaxFrameX()+1)
		{
			_atkIndex = 0;
			_pokemon.state = STATE_IDLE;
			_myTrun = false;
		}
	
		if (_bossIndex >= 2)
		{
			_beamReady = true;
		}

		if (_beamReady && _beamIndex >=4)
		{
			_bossIndex = 0;
			_beamIndex = 0;
			_ringIndex = 0;
			_pokemon.state = STATE_IDLE;
			_beamReady = false;
			_myTrun = false;
		}

	//Ÿ�ݰ���
		if (_hurtIndex >= _pokemon.hurtImage->getMaxFrameX()) { _hurtReverse = true; }
		else if (_hurtIndex <= 0) { _hurtReverse = false; }

}


void enemy::enemyAngleSetting()
{

	if (getDistance(_pokemon.x, _pokemon.y, _pl->getX(), _pl->getY()) <= TILESIZEX*2)
	{
		_target = getAngle(_pokemon.x, _pokemon.y, _pl->getX(), _pl->getY());
	}
	else
	{
		if (_vCloseList.size() <= 0) return;

		RECT temp = RectMakeCenter(_vCloseList[_vCloseList.size() - 1].getCenterX(), _vCloseList[_vCloseList.size() - 1].getCenterY(), TILESIZEX, TILESIZEY);

		_target = getAngle(_pokemon.x, _pokemon.y, _vCloseList[_vCloseList.size() - 1].getCenterX(), _vCloseList[_vCloseList.size() - 1].getCenterY());
	}
	
	


	
	
	if(_target <= PI8 && _target >=0 || _target >= PI8*15 && _target <= PI8 * 16)
	{
		_pokemon.direction = RIGHT;
	}
	if (PI8 < _target && PI8*3 > _target)
	{
		_pokemon.direction = RIGHTUP;
	}
	if (PI8 * 3 <= _target && PI8 * 5 >= _target)
	{
		_pokemon.direction = UP;
	}
	if (PI8 * 5 < _target && PI8 * 7 > _target)
	{
		_pokemon.direction = LEFTUP;
	}
	if (PI8 * 7 <= _target && PI8 * 9 >= _target)
	{
		_pokemon.direction = LEFT;
	}
	if (PI8 * 9< _target && PI8 * 11 > _target)
	{
		_pokemon.direction = LEFTDOWN;
	}
	if (PI8 * 11 <= _target && PI8 * 13 >= _target)
	{
		_pokemon.direction = DOWN;
	}
	if (PI8 * 13 < _target && PI8 * 15 > _target)
	{
		_pokemon.direction = RIGHTDOWN;
	}
}


void enemy::enemyASTARStart()
{
	if (getDistance(_pokemon.x, _pokemon.y, _pl->getX(), _pl->getY()) > 96) return;
	tile start;
	tile end;

	for (int i = 0; i < _stage->gettileCountX()* _stage->gettileCountY(); ++i)
	{
		RECT temp = RectMakeCenter(_stage->getTileAdress()[i]->getCenterX(),
			_stage->getTileAdress()[i]->getCenterY(), TILESIZEX, TILESIZEY);
		if (PtInRect(&temp, PointMake(_pokemon.x, _pokemon.y)))
		{
			start = *_stage->getTileAdress()[i];
			break;
		}
	}

	for (int i = 0; i < _stage->gettileCountX()* _stage->gettileCountY(); ++i)
	{
		RECT temp = RectMakeCenter(_stage->getTileAdress()[i]->getCenterX(),
			_stage->getTileAdress()[i]->getCenterY(), TILESIZEX, TILESIZEY);
		if (PtInRect(&temp, PointMake(_pl->getX(), _pl->getY())))
		{
			if (!_stage->getTileAdress()[i]->getIsOpen()) return;
			end = (*_stage->getTileAdress()[i]);
			break;
		}
	}

	if (_ast == NULL)
		_ast = new aStar;
	_ast->init(_stage->getTileAdress(), _stage->gettileCountX(), _stage->gettileCountY(), start, end);
	_vCloseList = _ast->pathFinder(start);
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
		_myTrun = false;
		_pokemon.speed = _tempSpeed;
		return;
	}
	if (_distance == 24)
	{
		_distance = 0;
		_isMove = false;
		_myTrun = false;
		
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



void enemy::enemyskillSign()
{
	if(_pokemoName =="�ܵ���")
	_pokemon.state = STATE_SKILL;
}
void enemy::enemyBeamSign()
{
	if (_pokemoName == "�ܵ���")
		_pokemon.state = STATE_BEAM;
}
void enemy::enemyHurtMotion()
{
	if (_pokemon.state != STATE_HURT)
	{
		_hurtTimer = 0;
	}
	_pokemon.state = STATE_HURT;
}




void enemy::enemyMoveSign()
{
	if (_pokemonName == "������")
	{
		return;
	}
	if (_pokemoName == "Ǫ��")
	{
		float volumedisTance = getDistance(_pokemon.x, _pokemon.y, _pl->getX(), _pl->getY()) / 200;
		float volume = 1 / volumedisTance / 2;
		SOUNDMANAGER->setVolume("Ǫ���ǳ뷡", volume);
		if (!SOUNDMANAGER->isPlaySound("Ǫ���ǳ뷡"))
			SOUNDMANAGER->play("Ǫ���ǳ뷡", volume, true);

	}



	if (getDistance(_pokemon.x, _pokemon.y, _pl->getX(), _pl->getY()) > 96)
	{
		_myTrun = false;
		return;
	}

	_isMove = true;
}
