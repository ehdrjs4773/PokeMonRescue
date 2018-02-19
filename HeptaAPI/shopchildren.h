#pragma once
#include "gameNode.h"
#include "Item.h"

class player;


struct shop
{
	RECT rc;				// ù ��° ���� â
	RECT rc2;				// �� ��° ���� â
	image* shopimage;		// ù ��° �̹���
	image* pointimage;		// ����Ʈ �̹���
	RECT point;				// ����Ʈ �ڽ�
	int x;					// â ��ǥ x
	int y;					// â ��ǥ y
	bool buy;				// ��� �����ߴ���?
	bool sell;				// �ȱ� �����ߴ���?
	bool allSell;			// ���� �ȱ� ���� �ߴ���?		
};


struct shopbuy
{
	RECT rc;
	RECT rc2;
	image* buyimage;
	image* buyimage2;
	int x;
	int y;
	int x2;
	int y2;
	bool buySelect;
};

enum shopinfo
{
	shopinfo_buy,		// ���� ���
	shopinfo_sell,		// ���� �ȱ�
	shopinfo_allSell,	// ���� ���� �ȱ�
	shopinfo_talk,		// ���� ����ϱ�
	shopinfo_exit,		// ���� ������
	shopinfo_END		// ���� ���� ��
};

enum shopClick
{
	shop_info,
	shop_buy,
	shop_sell,
	shop_allsell,
	shop_talk,
	shop_exit,
	shop_end
};

enum itembuy
{
	item_potion,
	item_ppPotion,
	item_skill,
	item_end
};


enum select
{
	buy,
	no,
	end
};

struct itemSelcet
{
	bool potionSelcet;
	bool ppPotionSelect;
	bool skillSelcet;
};


class shopchildren : public gameNode
{

private :

	select _sele;
	shopinfo _shopinfo;		// ���� ����
	shopClick _shopClick;	// ���� ����
	itembuy _itembuy;		// ������ ����
	itemSelcet _itemSelcet;
	player* _player;		// ���� �÷��̾� ����
	Item* _item;




	shopbuy _shopbuy;		// ���� ���
	shop _shop;				// ����

public:


	HRESULT init();
	void release();
	void update();
	void render();

	void keyMove();

	void setPlayerMemoryAdressLink(player* plays) { _player = plays; }

	shopchildren();
	~shopchildren();
};
