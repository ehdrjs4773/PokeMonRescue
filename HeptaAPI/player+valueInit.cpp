#include "stdafx.h"
#include "player.h"

// =================
// ## ���� �ʱ�ȭ ## 
// =================
void player::valueInit()
{	
	//�Ʒ� ( bottom )
	_bottomIdleCount = _bottomMoveCount = _bottomAttackCount = 0;
	_bottomIdleFrameX = _bottomIdleFrameY = _bottomMoveFrameX = _bottomMoveFrameY = _bottomAttackFrameX = _bottomAttackFrameY = 0;
	//���� ( left )
	_leftIdleCount = _leftMoveCount = _leftAttackCount = 0;
	_leftIdleFrameX = _leftIdleFrameY = _leftMoveFrameX = _leftMoveFrameY = _leftAttackFrameX = _leftAttackFrameY = 0;
	//������ ( right )
	_rightIdleCount = _rightMoveCount = _rightAttackCount = 0;
	_rightIdleFrameX = _rightIdleFrameY = _rightMoveFrameX = _rightMoveFrameY = _rightAttackFrameX = _rightAttackFrameY = 0;
	//�� ( top )
	_topIdleCount = _topMoveCount = _topAttackCount = 0;
	_topIdleFrameX = _topIdleFrameY = _topMoveFrameX = _topMoveFrameY = _topAttackFrameX = _topAttackFrameY = 0;
	//���ʾƷ� ( left , Bottom )
	_leftBottomIdleCount = _leftBottomMoveCount = _leftBottomAttackCount = 0;
	_leftBottomIdleFrameX = _leftBottomIdleFrameY = _leftBottomMoveFrameX = _leftBottomMoveFrameY =
	_leftBottomAttackFrameX = _leftBottomAttackFrameY = 0;
	//������ ( left , top )
	_leftTopIdleCount = _leftTopMoveCount = _leftTopAttackCount = 0;
	_leftTopIdleFrameX = _leftTopIdleFrameY = _leftTopMoveFrameX = _leftTopMoveFrameY =
	_leftTopAttackFrameX = _leftTopAttackFrameY = 0;
	//�������� ( right , top )
	_rightTopIdleCount = _rightTopMoveCount = _rightTopAttackCount = 0;
	_rightTopIdleFrameX = _rightTopIdleFrameY = _rightTopMoveFrameX = _rightTopMoveFrameY =
	_rightTopAttackFrameX = _rightTopAttackFrameY = 0;
	//�����ʾƷ� ( right , bottom )
	_rightBottomIdleCount = _rightBottomMoveCount = _rightBottomAttackCount = 0;
	_rightBottomIdleFrameX = _rightBottomIdleFrameY = _rightBottomMoveFrameX = _rightBottomMoveFrameY =
	_rightBottomAttackFrameX = _rightBottomAttackFrameY = 0;

}