#include "stdafx.h"
#include "player.h"
#include "Stage.h"

// ===============
// ## Ÿ�� ���� ##
// ===============
void player::tileCheak()
{
	//�Ʒ�
	if (_stage->getTileAdress()[_player.tileIndex + _stage->gettileCountX()]->gettileKind() == LAND)
		_isBottomMove = true;
	else _isBottomMove = false;

	//���ʾƷ�
	if (_stage->getTileAdress()[_player.tileIndex - 1]->gettileKind() == LAND &&
		(_stage->getTileAdress()[_player.tileIndex - 1 + _stage->gettileCountX()]->gettileKind() == LAND) &&
		(_stage->getTileAdress()[_player.tileIndex + _stage->gettileCountX()]->gettileKind() == LAND))
		_isLeftBottomMove = true;
	else _isLeftBottomMove = false;

	//����
	if (_stage->getTileAdress()[_player.tileIndex - 1]->gettileKind() == LAND)
		_isLeftMove = true;
	else _isLeftMove = false;

	//������
	if (_stage->getTileAdress()[_player.tileIndex - 1]->gettileKind() == LAND &&
		(_stage->getTileAdress()[_player.tileIndex - 1 - _stage->gettileCountX()]->gettileKind() == LAND) &&
		(_stage->getTileAdress()[_player.tileIndex - _stage->gettileCountX()]->gettileKind() == LAND))
		_isLeftTopMove = true;
	else _isLeftTopMove = false;

	//��
	if (_stage->getTileAdress()[_player.tileIndex - _stage->gettileCountX()]->gettileKind() == LAND)
		_isTopMove = true;
	else _isTopMove = false;

	//��������
	if (_stage->getTileAdress()[_player.tileIndex + 1]->gettileKind() == LAND &&
		(_stage->getTileAdress()[_player.tileIndex + 1 - _stage->gettileCountX()]->gettileKind() == LAND) &&
		(_stage->getTileAdress()[_player.tileIndex - _stage->gettileCountX()]->gettileKind() == LAND))
		_isRightTopMove = true;
	else _isRightTopMove = false;

	//������
	if (_stage->getTileAdress()[_player.tileIndex + 1]->gettileKind() == LAND)
		_isRightMove = true;
	else _isRightMove = false;

	//�����ʾƷ�
	if (_stage->getTileAdress()[_player.tileIndex + 1]->gettileKind() == LAND &&
		(_stage->getTileAdress()[_player.tileIndex + 1 + _stage->gettileCountX()]->gettileKind() == LAND) &&
		(_stage->getTileAdress()[_player.tileIndex + _stage->gettileCountX()]->gettileKind() == LAND))
		_isRightBottomMove = true;
	else _isRightBottomMove = false;

	//switch (_player.direction)
	//{
	//case PLAYER_BOTTOM:
	//	if (_stage->getTileAdress()[_player.tileIndex + _stage->gettileCountX()]->gettileKind() == LAND)
	//		_isBottomMove = true;
	//	else _isBottomMove = false;
	//	break;
	//case PLAYER_LEFT_BOTTOM:
	//	if (_stage->getTileAdress()[_player.tileIndex - 1]->gettileKind() == LAND &&
	//		(_stage->getTileAdress()[_player.tileIndex - 1 + _stage->gettileCountX()]->gettileKind() == LAND) &&
	//		(_stage->getTileAdress()[_player.tileIndex + _stage->gettileCountX()]->gettileKind() == LAND))
	//		_isLeftBottomMove = true;
	//	else _isLeftBottomMove = false;
	//	break;
	//case PLAYER_LEFT:
	//	if (_stage->getTileAdress()[_player.tileIndex - 1]->gettileKind() == LAND) 
	//		_isLeftMove = true;
	//	else _isLeftMove = false;
	//	break;
	//case PLAYER_LEFT_TOP:
	//	if (_stage->getTileAdress()[_player.tileIndex - 1]->gettileKind() == LAND &&
	//		(_stage->getTileAdress()[_player.tileIndex - 1 - _stage->gettileCountX()]->gettileKind() == LAND) &&
	//		(_stage->getTileAdress()[_player.tileIndex - _stage->gettileCountX()]->gettileKind() == LAND)) 
	//		_isLeftTopMove = true;
	//	else _isLeftTopMove = false;
	//	break;
	//case PLAYER_TOP:
	//	if (_stage->getTileAdress()[_player.tileIndex - _stage->gettileCountX()]->gettileKind() == LAND) 
	//		_isTopMove = true;
	//	else _isTopMove = false;
	//	break;
	//case PLAYER_RIGHT_TOP:
	//	if (_stage->getTileAdress()[_player.tileIndex + 1]->gettileKind() == LAND &&
	//		(_stage->getTileAdress()[_player.tileIndex + 1 - _stage->gettileCountX()]->gettileKind() == LAND) &&
	//		(_stage->getTileAdress()[_player.tileIndex - _stage->gettileCountX()]->gettileKind() == LAND)) 
	//		_isRightTopMove = true;
	//	else _isRightTopMove = false;
	//	break;
	//case PLAYER_RIGHT:
	//	if (_stage->getTileAdress()[_player.tileIndex + 1]->gettileKind() == LAND) 
	//		_isRightMove = true;
	//	else _isRightMove = false;
	//	break;
	//case PLAYER_RIGHT_BOTTOM:
	//	if (_stage->getTileAdress()[_player.tileIndex + 1]->gettileKind() == LAND &&
	//		(_stage->getTileAdress()[_player.tileIndex + 1 + _stage->gettileCountX()]->gettileKind() == LAND) &&
	//		(_stage->getTileAdress()[_player.tileIndex + _stage->gettileCountX()]->gettileKind() == LAND)) 
	//		_isRightBottomMove = true;
	//	else _isRightBottomMove = false;
	//	break;
	//}
}