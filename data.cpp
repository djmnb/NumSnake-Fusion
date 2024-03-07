#include "stdafx.h"
#include "data.h"

//窗口的大小位置
const int windows_w=1200+10;
const int windows_h=700+10;
const int windows_x=100;
const int windows_y=100;


//游戏界面大小位置
const int game_w=1080;
const int game_h=600+60;
const int game_x=0;
const int game_y=68-50;

//物体大小
const int w_w=30;
const int w_h=30;

//横向，纵向格子数
const int nums_x=game_w/w_w;
const int nums_y=game_h/w_h;


//food的数量
const int foodnums=15;


//统一扣除绿色


//为不同的计时器添加id
const UINT startid=10;//计时器开始id