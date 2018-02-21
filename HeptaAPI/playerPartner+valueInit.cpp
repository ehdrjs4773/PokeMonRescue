#include "stdafx.h"
#include "playerPartner.h"

void playerPartner::valueInit()
{
	_idleCount = _moveCount = _attackCount = _S_AttackCount = _S_AttackCount_2 = _hurtCount = 0;
	_idleFrameX = _moveFrameX = _attackFrameX = _S_AttackFrameX = _S_AttackFrameX_2 = _hurtFrameX = 0;
	_idleFrameY = _moveFrameY = _attackFrameY = _S_AttackFrameY = _S_AttackFrameY_2 = _hurtFrameY = _partner.direction;

}