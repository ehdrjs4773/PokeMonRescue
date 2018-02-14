#pragma once

#define TILESIZEX	24
#define TILESIZEY	24

#define WHATLEFT			1
#define WHATRIGHT			2
#define	WHATTOP				4
#define WHATBOTTOM			8
#define WHATLEFTTOP			16
#define WHATRIGHTTOP		32
#define WHATLEFTBOTTOM		64
#define WHATRIGHTBOTTOM		128

#define ISWHATLEFTTOP		5
#define ISWHATRIGHTTOP		6
#define ISWHATLEFTBOTTOM	9
#define ISWHATRIGHTBOTTOM	10

enum TILEKIND
{
	WALL,
	LAND,
	LAKE
};

enum OBJECT
{
	OBJECT_ITEM0,
	OBJECT_ITEM1,
	OBJECT_ITEM2,
	OBJECT_ITEM3,
	OBJECT_ITEM4,
	OBJECT_ITEM5,
	OBJECT_RESPAWN,
	OBJECT_PORTAL_UP,
	OBJECT_PORTAL_DOWN,
	OBJECT_NONE
};

class tile
{
private:
	int			_mapNum;			//���° �濡 �ֳ�
	int			_whatTile;			//Ÿ�� ��ü�� �����ΰ�
	TILEKIND	_tileKind;			//Ÿ���� ������ �����ΰ�
	
	int			_idx;				//Ÿ���� X ����
	int			_idy;				//Ÿ���� Y ����
	int			_centerx;			//Ÿ���� �߽� X
	int			_centery;			//Ÿ���� �߽� Y
	int			_terrainFrameX;		//Ÿ�ϸ������� ����
	int			_terrainFrameY;		//Ÿ�ϸ������� ����

	OBJECT		_object;			//������Ʈ�� �����ΰ�
	int			_objFrameX;			//������Ʈ�������� ����
	int			_objFrameY;			//������Ʈ�������� ����

	float		_totalcost;			//A*��
	float		_costFromStart;		//A*��
	float		_costToGoal;		//A*��
	bool		_isOpen;			//A*��
	bool		_isgo;				//�� �� �ִ� Ÿ�ϰ����
	tile*		_parentNode;		//A*��

public:
	tile();
	~tile();

	HRESULT init(int idx, int idy);
	void release();
	void update();
	void render();

	//���° �濡 �ֳ�
	inline int getMapNum() { return _mapNum; }
	//���° �濡 �ֳ�
	inline void setMapNum(int mapnum) { _mapNum = mapnum; }

	//Ÿ�� ��ü�� �����ΰ�
	inline int getwhattile() { return _whatTile; }
	//Ÿ�� ��ü�� �����ΰ�
	inline void setwhattile(int whattile) { _whatTile |= whattile; }
	//Ÿ�� ��ü�� �����ΰ�
	inline void resetwhattile() { _whatTile = 0; }

	//Ÿ���� ������ �����ΰ�
	inline TILEKIND gettileKind() { return _tileKind; }
	//Ÿ���� ������ �����ΰ�
	inline void settileKind(TILEKIND tilekind) { _tileKind = tilekind; }

	//Ÿ���� X ����
	inline int getIndexX() { return _idx; }
	//Ÿ���� X ����
	inline void setIndexX(int idx) { _idx = idx; }

	//Ÿ���� Y ����
	inline int getIndexY() { return _idy; }
	//Ÿ���� Y ����
	inline void setIndexY(int idy) { _idy = idy; }

	//Ÿ���� �߽���ǥ X
	inline int getCenterX() { return _centerx; }
	//Ÿ���� �߽���ǥ X
	inline void setCenterX(int centerx) { _centerx = centerx; }

	//Ÿ���� �߽���ǥ Y
	inline int	getCenterY() { return _centery; }
	//Ÿ���� �߽���ǥ Y
	inline void setCenterY(int centery) { _centery = centery; }

	inline int getTarrainFrameX() { return _terrainFrameX; }
	inline void setTarrainFrameX(int terrainframex) { _terrainFrameX = terrainframex; }

	inline int getTarrainFrameY() { return _terrainFrameY; }
	inline void setTarrainFrameY(int terrainframey) { _terrainFrameY = terrainframey; }

	inline int getobject() { return (int)_object; }
	inline void resetobject() { _object = OBJECT_NONE; }

	inline int getObjFrameX() { return _objFrameX; }
	inline void setObjFrameX(int objframex) { _objFrameX = objframex; }

	inline int getObjFrameY() { return _objFrameY; }
	inline void setObjFrameY(int objframey) { _objFrameY = objframey; }

	inline float getTotalCost() { return _totalcost; }
	inline void setTotalCost(float totalcost) { _totalcost = totalcost; }

	inline float getCostFromStart() { return _costFromStart; }
	inline void setCostFromStart(float costfromstart) { _costFromStart = costfromstart; }

	inline float getCostToGoal() { return _costToGoal; }
	inline void setCostToGoal(float costToGoal) { _costToGoal = costToGoal; }

	inline bool getIsOpen() { return _isOpen; }
	inline void setIsOpen(bool isopen) { _isOpen = isopen; }

	inline bool getIsGo() { return _isgo; }
	inline void setIsGo(bool isgo) { _isgo = isgo; }

	inline tile* getParentNode() { return _parentNode; }
	inline void setParentNode(tile* parentNode) { _parentNode = parentNode; }
};

