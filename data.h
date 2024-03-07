#ifndef _DATA_H_
#define _DATA_H_

//窗口的大小位置
extern const int windows_w;
extern const int windows_h;
extern const int windows_x;
extern const int windows_y;


//游戏界面大小位置
extern const int game_w;
extern const int game_h;
extern const int game_x;
extern const int game_y;

//物体大小
extern const int w_w;
extern const int w_h;

//横向，纵向格子数
extern const int nums_x;
extern const int nums_y;


//food的数量
extern const int foodnums;


//统一扣除绿色


//为不同的计时器添加id
extern const UINT startid;//计时器开始id


class CMapinfo
{
public:
	CBitmap btmap;//图片
	CDC memdc;///图片内存
	int w,h;
	int id;
	CMapinfo(){}
	CMapinfo(UINT id)
	{
        loadinfo(id);
	}
	void loadinfo(UINT id)
	{
	  btmap.LoadBitmap(id);
	  BITMAP mapsize;//图片大小
	  btmap.GetBitmap(&mapsize);
	  memdc.CreateCompatibleDC(NULL);
	  memdc.SelectObject(&btmap);
	  w=mapsize.bmWidth;
	  h=mapsize.bmHeight;
	  this->id=id;
	}
};



#endif