#include "stdafx.h"
#include "playerPartner.h"

void playerPartner::valueInit()
{
	//아래 ( bottom )
	_bottomIdleCount = _bottomMoveCount = _bottomAttackCount = _bottomSpecialAttackCount = _bottomHurtCount = 0;
	_bottomIdleFrameX = _bottomMoveFrameX = _bottomAttackFrameX = _bottomSpecialAttackFrameX = _bottomHurtFrameX = 0;
	_bottomIdleFrameY = _bottomMoveFrameY = _bottomAttackFrameY = _bottomSpecialAttackFrameY = _bottomHurtFrameY = _partner.direction;
	//왼쪽 ( left )
	_leftIdleCount = _leftMoveCount = _leftAttackCount = _leftSpecialAttackCount = _leftHurtCount = 0;
	_leftIdleFrameX = _leftMoveFrameX = _leftAttackFrameX = _leftSpecialAttackFrameX = _leftHurtFrameX = 0;
	_leftIdleFrameY = _leftMoveFrameY = _leftAttackFrameY = _leftSpecialAttackFrameY = _leftHurtFrameY = _partner.direction;
	//오른쪽 ( right )
	_rightIdleCount = _rightMoveCount = _rightAttackCount = _rightSpecialAttackCount = _rightHurtCount = 0;
	_rightIdleFrameX = _rightMoveFrameX = _rightAttackFrameX = _rightSpecialAttackFrameX = _rightHurtFrameX = 0;
	_rightIdleFrameY = _rightMoveFrameY = _rightAttackFrameY = _rightSpecialAttackFrameY = _rightHurtFrameY = _partner.direction;
	//위 ( top )
	_topIdleCount = _topMoveCount = _topAttackCount = _topSpecialAttackCount = _topHurtCount = 0;
	_topIdleFrameX = _topMoveFrameX = _topAttackFrameX = _topSpecialAttackFrameX = _topHurtFrameX = 0;
	_topIdleFrameY = _topMoveFrameY = _topAttackFrameY = _topSpecialAttackFrameY = _topHurtFrameY = _partner.direction;
	//왼쪽아래 ( left , Bottom )
	_leftBottomIdleCount = _leftBottomMoveCount = _leftBottomAttackCount = _leftBottomSpecialAttackCount =
		_leftBottomHurtCount = 0;
	_leftBottomIdleFrameX = _leftBottomMoveFrameX = _leftBottomAttackFrameX = _leftBottomSpecialAttackFrameX = _leftBottomHurtFrameX = 0;
	_leftBottomIdleFrameY = _leftBottomMoveFrameY = _leftBottomAttackFrameY = _leftBottomSpecialAttackFrameY = _leftBottomHurtFrameY = _partner.direction;
	//왼쪽위 ( left , top )
	_leftTopIdleCount = _leftTopMoveCount = _leftTopAttackCount = _leftTopSpecialAttackCount = _leftTopHurtCount = 0;
	_leftTopIdleFrameX = _leftTopMoveFrameX = _leftTopAttackFrameX = _leftTopSpecialAttackFrameX = _leftTopHurtFrameX = 0;
	_leftTopIdleFrameY = _leftTopMoveFrameY = _leftTopAttackFrameY = _leftTopSpecialAttackFrameY = _leftTopHurtFrameY = _partner.direction;
	//오른쪽위 ( right , top )
	_rightTopIdleCount = _rightTopMoveCount = _rightTopAttackCount = _rightTopSpecialAttackCount = _rightTopHurtCount = 0;
	_rightTopIdleFrameX = _rightTopMoveFrameX = _rightTopAttackFrameX = _rightTopSpecialAttackFrameX = _rightTopHurtFrameX = 0;
	_rightTopIdleFrameY = _rightTopMoveFrameY = _rightTopAttackFrameY = _rightTopSpecialAttackFrameY = _rightTopHurtFrameY = _partner.direction;
	//오른쪽아래 ( right , bottom )
	_rightBottomIdleCount = _rightBottomMoveCount = _rightBottomAttackCount = _rightBottomSpecialAttackCount = _rightBottomHurtCount = 0;
	_rightBottomIdleFrameX = _rightBottomMoveFrameX = _rightBottomAttackFrameX = _rightBottomSpecialAttackFrameX = _rightBottomHurtFrameX = 0;
	_rightBottomIdleFrameY = _rightBottomMoveFrameY = _rightBottomAttackFrameY = _rightBottomSpecialAttackFrameY = _rightBottomHurtFrameY = _partner.direction;

}