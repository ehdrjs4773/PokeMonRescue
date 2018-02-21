#include "stdafx.h"
#include "player.h"

// =================
// ## 변수 초기화 ## 
// =================
void player::valueInit()
{	
	_idleCount = _moveCount = _attackCount = _S_AttackCount = _S_AttackCount_2 = _S_AttackCount_3 = _S_AttackCount_4 =_hurtCount = 0;
	_idleFrameX = _moveFrameX = _attackFrameX = _S_AttackFrameX = _S_AttackFrameX_2 = _S_AttackFrameX_3 
		= _S_AttackFrameX_4 = _hurtFrameX = 0;
	_idleFrameY = _moveFrameY = _attackFrameY = _S_AttackFrameY = _S_AttackFrameY_2 = _S_AttackFrameY_3 
		= _S_AttackFrameY_4 = _hurtFrameY = _player.direction;

	_isAttack = false;	//공격햇늬?
	_onceMove = false;	//던전에서는 한번만 움직이거라
}

void player::dgMoveValueInit()
{
	//던전이동에 필요한 불값
	_isBottomMove = _isLeftBottomMove = _isLeftMove = _isLeftTopMove = _isTopMove = _isRightTopMove =
		_isRightMove = _isRightBottomMove = true;
}