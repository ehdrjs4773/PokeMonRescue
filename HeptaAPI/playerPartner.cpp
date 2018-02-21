#include "stdafx.h"
#include "playerPartner.h"
#include "player.h"
#include "Stage.h"


playerPartner::playerPartner()
{
}


playerPartner::~playerPartner()
{

}

HRESULT playerPartner::init()
{

	return S_OK;
}
HRESULT playerPartner::init(string charName)
{
	this->valueInit();

	tempNameIdle = charName + "_idle";
	tempNameMove = charName + "_move";
	tempNameAttack = charName + "_attack";
	tempNameSpecialAttack = charName + "_specialAttack";
	tempNameHurt = charName + "_hurt";

	_partnerStatus = new pokemon;
	_partnerStatus->pokemonStatus(charName, 1);


	_partner.angle = 0;


	return S_OK;
}
void playerPartner::release()
{

}
void playerPartner::update() 
{

	this->townMove();
	//this->dgMove();

	
}
void playerPartner::render() 
{
	this->draw();
	HDC hdc = CAMERAMANAGER->getMemDC();
	int x = CAMERAMANAGER->getX();
	int y = CAMERAMANAGER->getY();

	char str9[128];
	sprintf_s(str9, " _partner.angle °ª : %f ", _partner.angle * RAD2DEG);
	TextOut(hdc, x + 200, y + 250, str9, strlen(str9));
}

void playerPartner::townMove()
{
	this->frameUpdate();
	this->partnerTownMove();
}

void playerPartner::dgMove()
{
	this->frameUpdate();
	this->partnerDgMove();
}

void playerPartner::setPostion(float startX, float startY)
{
	_partner.direction = PARTNER_BOTTOM;
	_partner.state = PARTNER_IDLE;

	_partner.x = startX;
	_partner.y = startY;

	_partner.idx = _partner.x / 24;
	_partner.idy = _partner.y / 24;

	_partner.tileIndex = _partner.idx + (_partner.idy * _stage->gettileCountX());

	_partner.imageRc = RectMakeCenter(_partner.x, _partner.y, IMAGEMANAGER->findImage(tempNameIdle.c_str())->getFrameWidth(),
		IMAGEMANAGER->findImage(tempNameIdle.c_str())->getFrameHeight());

	_partner.rc = RectMakeCenter(_partner.x, _partner.y, 24, 24);

}