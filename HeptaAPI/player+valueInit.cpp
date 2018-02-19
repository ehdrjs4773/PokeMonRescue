#include "stdafx.h"
#include "player.h"

// =================
// ## ���� �ʱ�ȭ ## 
// =================
void player::valueInit()
{	
	//�Ʒ� ( bottom )
	_bottomIdleCount = _bottomMoveCount = _bottomAttackCount = _bottomSpecialAttackCount = _bottomHurtCount = 0;
	_bottomIdleFrameX = _bottomIdleFrameY = _bottomMoveFrameX = _bottomMoveFrameY = _bottomAttackFrameX = 
	_bottomAttackFrameY = _bottomSpecialAttackFrameX = _bottomSpecialAttackFrameY = _bottomHurtFrameX =
	_bottomHurtFrameY = 0;
	//���� ( left )
	_leftIdleCount = _leftMoveCount = _leftAttackCount = _leftSpecialAttackCount = _leftHurtCount = 0;
	_leftIdleFrameX = _leftIdleFrameY = _leftMoveFrameX = _leftMoveFrameY = _leftAttackFrameX = _leftAttackFrameY =
	_leftSpecialAttackFrameX = _leftSpecialAttackFrameY = _leftHurtFrameX = _leftHurtFrameY = 0;
	//������ ( right )
	_rightIdleCount = _rightMoveCount = _rightAttackCount = _rightSpecialAttackCount = _rightHurtCount = 0;
	_rightIdleFrameX = _rightIdleFrameY = _rightMoveFrameX = _rightMoveFrameY = _rightAttackFrameX = _rightAttackFrameY =
	_rightSpecialAttackFrameX = _rightSpecialAttackFrameY = _rightHurtFrameX = _rightHurtFrameY = 0;
	//�� ( top )
	_topIdleCount = _topMoveCount = _topAttackCount = _topSpecialAttackCount = _topHurtCount = 0;
	_topIdleFrameX = _topIdleFrameY = _topMoveFrameX = _topMoveFrameY = _topAttackFrameX = _topAttackFrameY = 
	_topSpecialAttackFrameX = _topSpecialAttackFrameY = _topHurtFrameX = _topHurtFrameY = 0;
	//���ʾƷ� ( left , Bottom )
	_leftBottomIdleCount = _leftBottomMoveCount = _leftBottomAttackCount = _leftBottomSpecialAttackCount =
	_leftBottomHurtCount = 0;
	_leftBottomIdleFrameX = _leftBottomIdleFrameY = _leftBottomMoveFrameX = _leftBottomMoveFrameY =
	_leftBottomAttackFrameX = _leftBottomAttackFrameY = _leftBottomSpecialAttackFrameX = _leftBottomSpecialAttackFrameY =
	_leftBottomHurtFrameX = _leftBottomHurtFrameY = 0;
	//������ ( left , top )
	_leftTopIdleCount = _leftTopMoveCount = _leftTopAttackCount = _leftTopSpecialAttackCount = _leftTopHurtCount = 0;
	_leftTopIdleFrameX = _leftTopIdleFrameY = _leftTopMoveFrameX = _leftTopMoveFrameY =
	_leftTopAttackFrameX = _leftTopAttackFrameY = _leftTopSpecialAttackFrameX = _leftTopSpecialAttackFrameY = 
	_leftTopHurtFrameX = _leftTopHurtFrameY = 0;
	//�������� ( right , top )
	_rightTopIdleCount = _rightTopMoveCount = _rightTopAttackCount = _rightTopSpecialAttackCount = _rightTopHurtCount = 0;
	_rightTopIdleFrameX = _rightTopIdleFrameY = _rightTopMoveFrameX = _rightTopMoveFrameY =
	_rightTopAttackFrameX = _rightTopAttackFrameY = _rightTopSpecialAttackFrameX = _rightTopSpecialAttackFrameY =
	_rightTopHurtFrameX = _rightTopHurtFrameY = 0;
	//�����ʾƷ� ( right , bottom )
	_rightBottomIdleCount = _rightBottomMoveCount = _rightBottomAttackCount = _rightBottomSpecialAttackCount = _rightBottomHurtCount = 0;
	_rightBottomIdleFrameX = _rightBottomIdleFrameY = _rightBottomMoveFrameX = _rightBottomMoveFrameY =
	_rightBottomAttackFrameX = _rightBottomAttackFrameY = _rightBottomSpecialAttackFrameX = _rightBottomSpecialAttackFrameY =
	_rightBottomHurtFrameX = _rightBottomHurtFrameY = 0;

	_isAttack = false;	//�����޴�?
	_onceMove = false;	//���������� �ѹ��� �����̰Ŷ�
}

void player::dgMoveValueInit()
{
	//�����̵��� �ʿ��� �Ұ�
	_isBottomMove = _isLeftBottomMove = _isLeftMove = _isLeftTopMove = _isTopMove = _isRightTopMove =
		_isRightMove = _isRightBottomMove = true;
}