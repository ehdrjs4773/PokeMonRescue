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
	_battleTrun = playerTurn; //�׻� �������� ó���� �÷��̾� ��


	return S_OK;
}
void battleScene::release()
{

}
void battleScene::update()
{
	//�÷��̾����϶� (�̴��س����� ó���� ����)
	if (_battleTrun == playerTurn) 
	{
		//�÷��̾��� �ൿ������ ������ (�⺻����,��ų���,�÷��̾ �� Ÿ���� �̵�,�������� ���) 
		//���ʹ̶� �οﶧ�� ���� �����ϴ� ����� �Ӽ��� �ҷ��;��ϴ°ǰ�...?

		if (_player->getplayerAction() == playerMove)	
		{
			//�����̰� ���� �Ѱ���
			//_player->dungeonMove();

			_battleTrun = partnerTurn;
		}
		else if (_player->getplayerAction() == playerAttack)
		{
			//�����ϰ� ���� �Ѱ���
			//_player->
			_battleTrun = partnerTurn;
		}
		else if (_player->getplayerAction() == playerUseSkill)
		{
			//��ų���� �Ѱ���
			_battleTrun = partnerTurn;
		}
		else if (_player->getplayerAction() == playerUseItem)
		{
			//�����۾��� �Ѱ���
			_battleTrun = partnerTurn;
		}

	}
	//��Ʈ�����϶�
	else if (_battleTrun == partnerTurn) 
	{
		//��Ʈ���� �ൿ������ ������ (�÷��̾ ���� �̵�,�⺻����,��ų���,�־��� �������� ���) 
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
	//���ʹ����϶�
	else 
	{
		//���ʹ��� �ൿ������ ������ (�÷��̾�� A*�� �̵�,�⺻����,��ų�� ���)
		//���ʹ��� ���������� �ʵ忡 �����ϴ� ���ʹ��� ���� ã�Ƽ� ���Ϳ� �ְ� �� ���ʹ̵鿡�� ������ ������ �����ְ�
		//���ʹ̵��� ������� ���� ������ �������� �÷��̾�� ���� ���� �� �ִ�
		
		
	}
}
void battleScene::render()
{

}
