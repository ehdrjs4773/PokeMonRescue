#pragma once
#include "gameNode.h"
#include "Item.h"
#include <vector>




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
	item_loop,
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
	bool loopSelcet;
};

class player;
class inventoryChiled;


class shopchildren : public gameNode
{

private :

	vector<Item*> _vitem;
	vector<Item*>::iterator _viItem;

	select _sele;
	shopinfo _shopinfo;		// ���� ����
	shopClick _shopClick;	// ���� ����
	itembuy _itembuy;		// ������ ����
	itemSelcet _itemSelcet;
	player* _player;		// ���� �÷��̾� ����
	Item _item;
	inventoryChiled* _inven; // �κ��丮 ����	



	shopbuy _shopbuy;		// ���� ���
	shop _shop;				// ����

public:


	HRESULT init();
	void release();
	void update();
	void render();

	void keyMove();

	void setPlayerMemoryAdressLink(player* plays) { _player = plays; }
	void setInventoryMemoryAdressLink(inventoryChiled* inven) { _inven = inven; }


	shopchildren();
	~shopchildren();
};

