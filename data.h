#ifndef _DATA_H_
#define _DATA_H_

//���ڵĴ�Сλ��
extern const int windows_w;
extern const int windows_h;
extern const int windows_x;
extern const int windows_y;


//��Ϸ�����Сλ��
extern const int game_w;
extern const int game_h;
extern const int game_x;
extern const int game_y;

//�����С
extern const int w_w;
extern const int w_h;

//�������������
extern const int nums_x;
extern const int nums_y;


//food������
extern const int foodnums;


//ͳһ�۳���ɫ


//Ϊ��ͬ�ļ�ʱ�����id
extern const UINT startid;//��ʱ����ʼid


class CMapinfo
{
public:
	CBitmap btmap;//ͼƬ
	CDC memdc;///ͼƬ�ڴ�
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
	  BITMAP mapsize;//ͼƬ��С
	  btmap.GetBitmap(&mapsize);
	  memdc.CreateCompatibleDC(NULL);
	  memdc.SelectObject(&btmap);
	  w=mapsize.bmWidth;
	  h=mapsize.bmHeight;
	  this->id=id;
	}
};



#endif