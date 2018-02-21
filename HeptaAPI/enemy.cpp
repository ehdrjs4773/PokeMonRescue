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

	//구조체에 묶어두었던 포켓몬의 이름을 받아오며 스테이터스 초기화

	_pokemoName = PokemonName.pokemonName;
	pokemonStatus(PokemonName.pokemonName, level);

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


	_pokemon.rc = RectMakeCenter(_pokemon.x, _pokemon.y, 20, 20);
	//Rectangle(getMemDC(), _pokemon.x - 5, _pokemon.y - 5, _pokemon.x + 5, _pokemon.y + 5);
	_pokemon.speed = 2;
	//디렉션은 기본적으로 아래를 바라보자
	_pokemon.direction = UP;
	//기본상태
	_pokemon.state = STATE_IDLE;





	//프레임번호와 카운트의 초기화
	_idleIndex	= 0;
	_moveIndex	= 0;
	_atkIndex	= 0;
	_hurtIndex	= 0;
	
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

		//기본렌더
	case STATE_IDLE:
		_pokemon.idleImage->frameRender(CAMERAMANAGER->getMemDC(), _pokemon.x - _pokemon.idleImage->getFrameHeight() / 2,
			_pokemon.y - _pokemon.idleImage->getFrameWidth() / 2,_idleIndex, _pokemon.direction);
		break;

		//이동렌더
	case STATE_MOVE:
		_pokemon.moveImage->frameRender(CAMERAMANAGER->getMemDC(), _pokemon.x - _pokemon.moveImage->getFrameHeight() / 2,
			_pokemon.y - _pokemon.moveImage->getFrameWidth() / 2, _moveIndex, _pokemon.direction);
		break;
		
		//고옹격렌더
	case STATE_ATTACK:
		_pokemon.atkImage->frameRender(CAMERAMANAGER->getMemDC(), _pokemon.x - _pokemon.atkImage->getFrameHeight() / 2,
			_pokemon.y - _pokemon.atkImage->getFrameWidth() / 2, _atkIndex, _pokemon.direction);
		break;

		//타격렌더
	case STATE_HURT:
		_pokemon.hurtImage->frameRender(CAMERAMANAGER->getMemDC(), _pokemon.x - _pokemon.hurtImage->getFrameHeight() / 2,
			_pokemon.y - _pokemon.hurtImage->getFrameWidth() / 2,_hurtIndex, _pokemon.direction);
		break;
	case STATE_SKILL:
		IMAGEMANAGER->findImage("단데기스킬")->frameRender(CAMERAMANAGER->getMemDC(), _pokemon.x -24,
			_pokemon.y -60, _atkIndex , _pokemon.direction);
		break;
	}

	//Rectangle(getMemDC(), _pokemon.x - 5, _pokemon.y - 5, _pokemon.x + 5, _pokemon.y + 5);

} 


//애들의 상태의 프레임을 계산하는 함수
void enemy::setState()
{
	_count++;

	if (_count % 15 == 0)
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
			if (0 != IMAGEMANAGER->findImage("단데기스킬")->getMaxFrameX())
			{
				_atkIndex++;
			}
			_idleIndex = 0;
			_moveIndex = 0;
			_hurtIndex = 0;
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
		if (_atkIndex >= _pokemon.atkImage->getMaxFrameX()+1)
		{
			_atkIndex = 0;
			_pokemon.state = STATE_IDLE;
			_myTrun = false;
		}


	//타격관련
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
	if (getDistance(_pokemon.x, _pokemon.y, _pl->getX(), _pl->getY()) > 480) return;
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
	if(_pokemoName =="단데기")
	_pokemon.state = STATE_SKILL;
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
	if (getDistance(_pokemon.x, _pokemon.y, _pl->getX(), _pl->getY()) > 480) return;
	_isMove = true;
}
