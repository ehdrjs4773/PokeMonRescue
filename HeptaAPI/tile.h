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
	OBJECT_GAIN,
	OBJECT_RESPAWN,
	OBJECT_PORTAL,
	OBJECT_NONE
};

class tile
{
private:
	int			_mapNum;			//몇번째 방에 있나
	int			_whatTile;			//타일 자체는 무엇인가
	TILEKIND	_tileKind;			//타일의 종류는 무엇인가
	
	int			_idx;				//타일의 X 순서
	int			_idy;				//타일의 Y 순서
	int			_centerx;			//타일의 중심 X
	int			_centery;			//타일의 중심 Y
	int			_terrainFrameX;		//타일모음에서 순서
	int			_terrainFrameY;		//타일모음에서 순서

	OBJECT		_object;			//오브젝트는 무엇인가
	int			_objFrameX;			//오브젝트모음에서 순서
	int			_objFrameY;			//오브젝트모음에서 순서

	float		_totalcost;			//A*용
	float		_costFromStart;		//A*용
	float		_costToGoal;		//A*용
	bool		_isOpen;			//A*용
	bool		_isgo;				//갈 수 있는 타일검출용
	tile*		_parentNode;		//A*용

public:
	tile();
	~tile();

	HRESULT init(int idx, int idy);
	void release();
	void update();
	void render();

	//몇번째 방에 있나
	inline int getMapNum() { return _mapNum; }
	//몇번째 방에 있나
	inline void setMapNum(int mapnum) { _mapNum = mapnum; }

	//타일 자체는 무엇인가
	inline int getwhattile() { return _whatTile; }
	//타일 자체는 무엇인가
	inline void setwhattile(int whattile) { _whatTile |= whattile; }
	//타일 자체는 무엇인가
	inline void resetwhattile() { _whatTile = 0; }

	//타일의 종류는 무엇인가
	inline TILEKIND gettileKind() { return _tileKind; }
	//타일의 종류는 무엇인가
	inline void settileKind(TILEKIND tilekind) { _tileKind = tilekind; }

	//타일의 X 순서
	inline int getIndexX() { return _idx; }
	//타일의 X 순서
	inline void setIndexX(int idx) { _idx = idx; }

	//타일의 Y 순서
	inline int getIndexY() { return _idy; }
	//타일의 Y 순서
	inline void setIndexY(int idy) { _idy = idy; }

	//타일의 중심좌표 X
	inline int getCenterX() { return _centerx; }
	//타일의 중심좌표 X
	inline void setCenterX(int centerx) { _centerx = centerx; }

	//타일의 중심좌표 Y
	inline int	getCenterY() { return _centery; }
	//타일의 중심좌표 Y
	inline void setCenterY(int centery) { _centery = centery; }

	inline int getTarrainFrameX() { return _terrainFrameX; }
	inline void setTarrainFrameX(int terrainframex) { _terrainFrameX = terrainframex; }

	inline int getTarrainFrameY() { return _terrainFrameY; }
	inline void setTarrainFrameY(int terrainframey) { _terrainFrameY = terrainframey; }

	//_object
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

