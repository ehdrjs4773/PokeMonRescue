#include "stdafx.h"
#include "playerPartner.h"
#include "player.h"
#include "Stage.h"


void playerPartner::partnerTownMove()
{
	_partner.state = PARTNER_IDLE;

	if (50 < getDistance(_partner.x, _partner.y, _player->getX(), _player->getY()))
	{
		_partner.state = PARTNER_MOVE;

		_partner.angle = getAngle(_partner.x, _partner.y, _player->getX(), _player->getY());

	}
	if (_partner.state == PARTNER_MOVE)
	{
		_partner.x += cosf(_partner.angle) * 5;
		_partner.y += -sinf(_partner.angle) * 5;
	}

	//�ޱ۰��� ���� ��Ʈ�� ���Ⱚ ����
	if (_partner.angle <= 360 * DEG2RAD && _partner.angle >= 337.5 * DEG2RAD || 
		_partner.angle >= 0 && _partner.angle < 22.5 * DEG2RAD)
	{
		_partner.direction = PARTNER_RIGHT;
	}
	if (_partner.angle >= 22.5 * DEG2RAD && _partner.angle < 67.5 * DEG2RAD)
	{
		_partner.direction = PARTNER_RIGHT_TOP;
	}
	if (_partner.angle >= 67.5 * DEG2RAD && _partner.angle < 112.5 * DEG2RAD)
	{
		_partner.direction = PARTNER_TOP;
	}
	if (_partner.angle >= 112.5 * DEG2RAD && _partner.angle < 157.5 * DEG2RAD)
	{
		_partner.direction = PARTNER_LEFT_TOP;
	}
	if (_partner.angle >= 157.5 * DEG2RAD && _partner.angle < 202.5 * DEG2RAD)
	{
		_partner.direction = PARTNER_LEFT;
	}
	if (_partner.angle >= 202.5 * DEG2RAD && _partner.angle < 247.5 * DEG2RAD)
	{
		_partner.direction = PARTNER_LEFT_BOTTOM;
	}
	if (_partner.angle >= 247.5 * DEG2RAD && _partner.angle < 292.5 * DEG2RAD)
	{
		_partner.direction = PARTNER_BOTTOM;
	}
	if (_partner.angle >= 292.5 * DEG2RAD && _partner.angle < 337.5 * DEG2RAD)
	{
		_partner.direction = PARTNER_RIGHT_BOTTOM;
	}
	
}
void playerPartner::partnerDgMove()
{

}