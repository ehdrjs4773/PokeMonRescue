#include "stdafx.h"
#include "battleScene.h"
#include "player.h"


battleScene::battleScene()
{
}

battleScene::~battleScene()
{
}


HRESULT battleScene::init()
{
	_battleTrun = playerTurn; //항상 던전들어가서 처음은 플레이어 턴


	return S_OK;
}
void battleScene::release()
{

}
void battleScene::update()
{
	//플레이어턴일때 (이닛해놨으니 처음은 여기)
	if (_battleTrun == playerTurn) 
	{
		//플레이어의 행동패턴의 종류는 (기본공격,스킬사용,플레이어가 한 타일을 이동,아이템을 사용) 
		//에너미랑 싸울때는 내가 공격하는 상대의 속성도 불러와야하는건가...?

		if (_player->getplayerAction() == playerMove)	
		{
			//움직이고 턴을 넘겨줌
			//_player->dungeonMove();

			_battleTrun = partnerTurn;
		}
		else if (_player->getplayerAction() == playerAttack)
		{
			//공격하고 턴을 넘겨줌
			//_player->
			_battleTrun = partnerTurn;
		}
		else if (_player->getplayerAction() == playerUseSkill)
		{
			//스킬쓰고 넘겨줌
			_battleTrun = partnerTurn;
		}
		else if (_player->getplayerAction() == playerUseItem)
		{
			//아이템쓰고 넘겨줌
			_battleTrun = partnerTurn;
		}

	}
	//파트너턴일때
	else if (_battleTrun == partnerTurn) 
	{
		//파트너의 행동패턴의 종류는 (플레이어를 따라서 이동,기본공격,스킬사용,주어진 아이템을 사용) 
		if (_partnerAction == partnerMove)
		{

			_battleTrun = enemyTurn;
		}
		else if (_partnerAction == partnerAttack)
		{

			_battleTrun = enemyTurn;
		}
		else if (_partnerAction == partnerUseSkill)
		{

			_battleTrun = enemyTurn;
		}

	}
	//에너미턴일때
	else 
	{
		//에너미의 행동패턴의 종류는 (플레이어에게 A*로 이동,기본공격,스킬을 사용)
		//에너미의 귀찮은점은 필드에 존재하는 에너미의 수를 찾아서 백터에 넣고 그 에너미들에게 움직일 순서를 정해주고
		//에너미들이 순서대로 전부 움직인 다음에야 플레이어에게 턴을 돌릴 수 있다
		
		
	}
}
void battleScene::render()
{

}
