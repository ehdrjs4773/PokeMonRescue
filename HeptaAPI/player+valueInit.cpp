#include "stdafx.h"
#include "player.h"

// =================
// ## ���� �ʱ�ȭ ## 
// =================
void player::valueInit()
{	
	//�Ʒ� ( bottom )
	_bottomIdleCount = _bottomMoveCount = _bottomAttackCount = _bottomSpecialAttackCount = _bottomHurtCount = 0;
	_bottomIdleFrameX = _bottomMoveFrameX = _bottomAttackFrameX = _bottomSpecialAttackFrameX = _bottomHurtFrameX = 0;
	_bottomIdleFrameY = _bottomMoveFrameY = _bottomAttackFrameY = _bottomSpecialAttackFrameY = _bottomHurtFrameY = _player.direction;
	//���� ( left )
	_leftIdleCount = _leftMoveCount = _leftAttackCount = _leftSpecialAttackCount = _leftHurtCount = 0;
	_leftIdleFrameX = _leftMoveFrameX = _leftAttackFrameX = _leftSpecialAttackFrameX = _leftHurtFrameX = 0;
	_leftIdleFrameY = _leftMoveFrameY = _leftAttackFrameY = _leftSpecialAttackFrameY = _leftHurtFrameY = _player.direction;
	//������ ( right )
	_rightIdleCount = _rightMoveCount = _rightAttackCount = _rightSpecialAttackCount = _rightHurtCount = 0;
	_rightIdleFrameX = _rightMoveFrameX = _rightAttackFrameX =_rightSpecialAttackFrameX = _rightHurtFrameX = 0;
	_rightIdleFrameY = _rightMoveFrameY = _rightAttackFrameY = _rightSpecialAttackFrameY = _rightHurtFrameY = _player.direction;
	//�� ( top )
	_topIdleCount = _topMoveCount = _topAttackCount = _topSpecialAttackCount = _topHurtCount = 0;
	_topIdleFrameX = _topMoveFrameX = _topAttackFrameX = _topSpecialAttackFrameX = _topHurtFrameX = 0;
	_topIdleFrameY = _topMoveFrameY = _topAttackFrameY = _topSpecialAttackFrameY = _topHurtFrameY = _player.direction;
	//���ʾƷ� ( left , Bottom )
	_leftBottomIdleCount = _leftBottomMoveCount = _leftBottomAttackCount = _leftBottomSpecialAttackCount =
	_leftBottomHurtCount = 0;
	_leftBottomIdleFrameX = _leftBottomMoveFrameX =_leftBottomAttackFrameX = _leftBottomSpecialAttackFrameX =_leftBottomHurtFrameX = 0;
	_leftBottomIdleFrameY = _leftBottomMoveFrameY = _leftBottomAttackFrameY = _leftBottomSpecialAttackFrameY = _leftBottomHurtFrameY = _player.direction;
	//������ ( left , top )
	_leftTopIdleCount = _leftTopMoveCount = _leftTopAttackCount = _leftTopSpecialAttackCount = _leftTopHurtCount = 0;
	_leftTopIdleFrameX = _leftTopMoveFrameX =_leftTopAttackFrameX = _leftTopSpecialAttackFrameX = _leftTopHurtFrameX = 0;
	_leftTopIdleFrameY = _leftTopMoveFrameY = _leftTopAttackFrameY = _leftTopSpecialAttackFrameY = _leftTopHurtFrameY = _player.direction;
	//�������� ( right , top )
	_rightTopIdleCount = _rightTopMoveCount = _rightTopAttackCount = _rightTopSpecialAttackCount = _rightTopHurtCount = 0;
	_rightTopIdleFrameX = _rightTopMoveFrameX = _rightTopAttackFrameX = _rightTopSpecialAttackFrameX =_rightTopHurtFrameX = 0;
	_rightTopIdleFrameY = _rightTopMoveFrameY = _rightTopAttackFrameY = _rightTopSpecialAttackFrameY = _rightTopHurtFrameY = _player.direction;
	//�����ʾƷ� ( right , bottom )
	_rightBottomIdleCount = _rightBottomMoveCount = _rightBottomAttackCount = _rightBottomSpecialAttackCount = _rightBottomHurtCount = 0;
	_rightBottomIdleFrameX = _rightBottomMoveFrameX = _rightBottomAttackFrameX = _rightBottomSpecialAttackFrameX = _rightBottomHurtFrameX = 0;
	_rightBottomIdleFrameY = _rightBottomMoveFrameY = _rightBottomAttackFrameY = _rightBottomSpecialAttackFrameY = _rightBottomHurtFrameY = _player.direction;

	_isAttack = false;	//�����޴�?
	_onceMove = false;	//���������� �ѹ��� �����̰Ŷ�
}

void player::dgMoveValueInit()
{
	//�����̵��� �ʿ��� �Ұ�
	_isBottomMove = _isLeftBottomMove = _isLeftMove = _isLeftTopMove = _isTopMove = _isRightTopMove =
		_isRightMove = _isRightBottomMove = true;
}