#ifndef _OPERATOR_H_
#define _OPERATOR_H_
#include"data.h"
#include<vector>
#include<time.h>
#include<map>
#include<stdlib.h>
#include "Resource.h"
#include <windows.h>
#pragma  comment(lib,"Msimg32.lib") //TransparentBlt函数包含的库文件

using namespace std;

//所有图片信息
static vector<CMapinfo*> Allmap;


//扣除颜色
static void TT(CDC* dc, CMapinfo* info, COLORREF color, CRect rect)
{

		(info->memdc).SetBkColor(color);
		CDC mask;
		mask.CreateCompatibleDC(NULL);
		CBitmap temp;
		temp.CreateBitmap(info->w, info->h, 1, 1, NULL);
		mask.SelectObject(&temp);
		mask.BitBlt(0, 0, info->w, info->h, &info->memdc, 0, 0, SRCCOPY);
		dc->StretchBlt(rect.left, rect.top, rect.Width(), rect.Height(), &info->memdc, 0, 0, info->w, info->h, SRCINVERT);
		dc->StretchBlt(rect.left, rect.top, rect.Width(), rect.Height(), &mask, 0, 0, info->w, info->h, SRCAND);
		dc->StretchBlt(rect.left, rect.top, rect.Width(), rect.Height(), &info->memdc, 0, 0, info->w, info->h, SRCINVERT);
		mask.DeleteDC();
}

//在这里加载所需要的图片信息
static void loadallmap()
{
	Allmap.push_back(new CMapinfo(head_right));
	Allmap.push_back(new CMapinfo(head_left));
    Allmap.push_back(new CMapinfo(head_down));
	Allmap.push_back(new CMapinfo(head_up));
    Allmap.push_back(new CMapinfo(body1));

	Allmap.push_back(new CMapinfo(head2_right));
	Allmap.push_back(new CMapinfo(head2_left));
    Allmap.push_back(new CMapinfo(head2_down));
	Allmap.push_back(new CMapinfo(head2_up));
    Allmap.push_back(new CMapinfo(body2));


	Allmap.push_back(new CMapinfo(food1));
	Allmap.push_back(new CMapinfo(food2));
	Allmap.push_back(new CMapinfo(food3));
	Allmap.push_back(new CMapinfo(food4));
	Allmap.push_back(new CMapinfo(food5));
    Allmap.push_back(new CMapinfo(bg1));
    Allmap.push_back(new CMapinfo(bg2));
    Allmap.push_back(new CMapinfo(bg3));
	Allmap.push_back(new CMapinfo(bg4));
	Allmap.push_back(new CMapinfo(bg5));

	Allmap.push_back(new CMapinfo(btall));
	Allmap.push_back(new CMapinfo(bg_1));

}

//根据id获得图片所有信息
static CMapinfo* getmapinfo(UINT id)
{
	for(int i=Allmap.size()-1;i>=0;i--)
	{
		if(Allmap[i]->id==id)return Allmap[i];
	}
	return NULL;
}

//蛇身备选方案
static vector<CMapinfo*> way[5];
static vector<CMapinfo*> btway;

// 生成备选方案
static void creatway()
{
	for(int i=0;i<5;i++)
	{
		way[i].push_back(NULL);
	}
	way[1].push_back(getmapinfo(head_up));
	way[1].push_back(getmapinfo(head_down));
	way[1].push_back(getmapinfo(head_left));
	way[1].push_back(getmapinfo(head_right));
    way[1].push_back(getmapinfo(body1));

    way[2].push_back(getmapinfo(head2_up));
	way[2].push_back(getmapinfo(head2_down));
	way[2].push_back(getmapinfo(head2_left));
	way[2].push_back(getmapinfo(head2_right));
    way[2].push_back(getmapinfo(body2));

	btway.push_back(getmapinfo(bg4));
	btway.push_back(getmapinfo(bg3));
	btway.push_back(getmapinfo(bg1));
	btway.push_back(getmapinfo(bg5));
	btway.push_back(getmapinfo(bg2));
	
	//btway.push_back(getmapinfo(bg5));
}


//食物类
class CFood;

//所有食物
static vector<CFood*> Allfood;


class CFood
{
public:

	CPoint food;
    CMapinfo* foodinfo;
    int nums;
    int flag;//0代表负数，1代表正数
	CFood(UINT id)
	{
		foodinfo=getmapinfo(id);
		flag=1;
	}
    
	//展示食物
    void show(CDC* dc)
	{
		//dc->StretchBlt(food.x,food.y,w_w,w_h,&foodinfo->memdc,0,0,foodinfo->w,foodinfo->h,SRCCOPY);
		CRect rect(food.x,food.y,food.x+w_w,food.y+w_h);
		TransparentBlt(dc->m_hDC,food.x,food.y,w_w,w_h,foodinfo->memdc.m_hDC,0,0,foodinfo->w,foodinfo->h,RGB(0,255,0));

		rect.top+=6;

		CString str;
		str.Format("%d",nums);

		dc->DrawText(str,&rect,DT_CENTER);
        rect.top-=6;
		//dc->StretchBlt(food.x,food.y,w_w,w_h,&foodinfo->memdc,0,0,foodinfo->w,foodinfo->h,SRCCOPY);
		//TT(dc,foodinfo,RGB(0,255,0),rect);
		//TansparentBlt(dc,food.x,food.y,w_w,w_h,&foodinfo->memdc,0,0,foodinfo->w,foodinfo->h,RGB(0,255,0));
		//dc->DrawText(
	}
    
    //创建食物位置
	void creatposition()
	{
		food=CPoint(0,0);
        
		if(flag)
        nums=1+rand()%100;
        else
			nums=rand()%50-50;
		srand(time(NULL));
		int x=rand()%nums_x*w_w;
		int y=rand()%nums_y*w_h;
		CPoint p(x,y);

		for(int i=Allfood.size()-1;i>=0;i--)
		{
			if(Allfood[i]!=this&&Allfood[i]->food==p)
			{
               	x=rand()%nums_x*w_w;
		        y=rand()%nums_y*w_h;
		        p=CPoint(x,y);
				i=Allfood.size();
			}
		}

		food=p;
	}
    
	static void initallfood()
	{
		for(int i=0;i<foodnums;i++)
		{
			CFood* food;
			if(i<5)
			{
				food = new CFood(food2);
			    food->flag=0;
			}
            else if(i<8)
			{
                food = new CFood(food1);
			}
			else if(i<10)
			{
				food = new CFood(food3);
			}
			else if(i<13)
			{
                food = new CFood(food4);
			}
			else
				food = new CFood(food5);
            food->creatposition();
			Allfood.push_back(food);
		}
	}

	static void showallfoods(CDC* dc)
	{
        for(int i=Allfood.size()-1;i>=0;i--)
		{
		     Allfood[i]->show(dc);
		}
	}
};



//用于蛇头移动
static CPoint point[5]=
{
	CPoint(),
	CPoint(0,w_h),
    CPoint(0,-w_h),
	CPoint(w_w,0),
    CPoint(-w_w,0)
};


class CSnake
{
public:
	CMapinfo* headinfo;//蛇头信息
	CMapinfo* bodyinfo;//身体信息
	int d;//方向
	vector<CPoint> snake;//位置
    int ways;//套装
	int result;//总和
	CSnake(int d=4,int ways=1)
	{
		this->ways=ways;
        result = 0;

		CPoint p;
		p.x=(4+rand()%(nums_x-4))*w_w;
		p.y=(4+rand()%(nums_y-4))*w_h;
		snake.push_back(p);

        for(int i=0;i<4;i++)
		{
           p+=point[d];
		   snake.push_back(p);
		}

        this->d=d;
	}
    
	void changeway(int way)
	{
		this->ways=way;
	}

	void setheadinfo()
	{
		headinfo=way[ways][d];
	}

	void setbodyinfo()
	{
		bodyinfo=way[ways][5];
	}

	void showbody(CDC* dc)
	{
	   for(int i=snake.size()-1;i>=0;i--)
	   {
		   //CRect rect(snake[i].x,snake[i].y,snake[i].x+w_w,snake[i].y+w_h);
		   dc->StretchBlt(snake[i].x,snake[i].y,w_w,w_h,&bodyinfo->memdc,0,0,bodyinfo->w,bodyinfo->h,SRCCOPY);;
		   //TT(dc,bodyinfo,RGB(0,255,0),rect);
	   }
	}

	void showhead(CDC* dc)
	{
		int i=0;
	    CRect rect(snake[i].x,snake[i].y,snake[i].x+w_w,snake[i].y+w_h);
        dc->StretchBlt(snake[i].x,snake[i].y,w_w,w_h,&headinfo->memdc,0,0,headinfo->w,headinfo->h,SRCCOPY);
		//TT(dc,headinfo,RGB(0,255,0),rect);
		//TransparentBlt(dc->m_hDC,snake[i].x,snake[i].y,w_w,w_h,headinfo->memdc.m_hDC,0,0,headinfo->w,headinfo->h,RGB(0,255,0));
	}

	void run()
	{
		CPoint newhead=snake[0]-point[d];//新蛇头位置

		int x=newhead.x;
		int y=newhead.y;
       
		//防止走出边界
		x=(x+game_w)%game_w;
		y=(y+game_h)%game_h;
		newhead=CPoint(x,y);

		snake.insert(snake.begin(),newhead);
        

		bool flag=true;//为真时删除蛇尾
		for(int i=Allfood.size()-1;i>=0;i--)
		{
            if(newhead==Allfood[i]->food)//蛇头碰到食物，重新产生食物位置
			{
				result+=Allfood[i]->nums;

				Allfood[i]->creatposition();
				flag=false;
				break;
			}
		}
		if(flag)snake.pop_back();
	}
};

static CString sign[2]=
{
	"+","*"
};

//用于计算
class node
{
public:
   int nums;
   char op;
   bool flag;//1代表数字，0代表字符
};

//把所有关于蛇，食物的操作封装成一个类
class COperator
{
public:

	CSnake* snake[2];//最多两条蛇

    CMapinfo* bgpicture;//背景图片
    int btways;

	bool isstarted;//游戏是否开始了
	bool ispaused;//游戏是否暂停
	bool openmusiced;//音乐开关
	int gamemode;//人机对战 或者 双人对战 1代表人机对战 2代表双人对战
	int answer;
	int still;
    CString answerstr;

    COperator(int mode=1)
	{
        
		still=5;
		gamemode=mode;
        isstarted=false;
		ispaused=false;
		openmusiced=true;
        btways=-1;
		int d=rand()%4+1;
		snake[0]=new CSnake(d);
		d=rand()%4+1;
		snake[1]=new CSnake(d,2);

		snake[0]->setheadinfo();
		snake[1]->setheadinfo();

		snake[0]->setbodyinfo();
		snake[1]->setbodyinfo();

		setbg();

		answer=50;
        //creatanswer();
		answer=1000+rand()%800;
	}
    
    void show(CDC* dc)
	{
		showbg(dc);

		//先画两条蛇的蛇尾，防止一条蛇的头进入另一条的蛇身时被覆盖
	   for(int i=0;i<2;i++)
	   {
		   snake[i]->showbody(dc);
	   }

	   for(i=0;i<2;i++)
	   {
		   snake[i]->showhead(dc);
	   }
      
	   CFood::showallfoods(dc);

	}
    
	void run()
	{
		if(gamemode==1)
		{
			autorun();
		}

		for(int i=0;i<2;i++)
		{
			snake[i]->run();
		}
        snake[0]->setheadinfo();
	    snake[1]->setheadinfo();

	}
 
	void setbg()
	{
		btways=(btways+1)%btway.size();
		bgpicture=btway[btways];
	}
   
	void showbg(CDC* dc)
	{
		dc->StretchBlt(0,0,game_w,game_h,&bgpicture->memdc,0,0,bgpicture->w,bgpicture->h,SRCCOPY);
	}

    void dfsfindway(int p,vector<int>& temp,vector<int>& ans,int& result,int tempresult)//
	{
       if(p>=Allfood.size())
	   {
          if(abs(answer-tempresult)<abs(answer-result))
		  {
			  ans=temp;
			  result=tempresult;
		  }
		  return;
       }
	   dfsfindway(p+1,temp,ans,result,tempresult);

	   temp.push_back(p);
	   dfsfindway(p+1,temp,ans,result,tempresult+Allfood[p]->nums);
	   temp.pop_back();
       
	}

    void autorun()
	{
        vector<int> ans,temps;
		int result=snake[1]->result;
		dfsfindway(0,temps,ans,result,result);
        if(ans.size()==0)
		{
			still--;
            if(still==0)
			{
				int d=rand()%4+1;
				if(abs(snake[1]->d-d)>1)
				{
					snake[1]->d=d;
				}
				still=5;
			}
			return;
		}
		int sum=10000000;
        CPoint minp;
		CPoint headp=snake[1]->snake[0];
		CPoint temp;
		for(int i=0;i<ans.size();i++)
		{
           temp = headp-Allfood[ans[i]]->food;
		   if((abs(temp.x)+abs(temp.y))<sum)
		   {
			   sum=abs(temp.x)+abs(temp.y);
			   minp=Allfood[ans[i]]->food;
		   }
		}
		temp=headp-minp;
		if(temp.x>0)
		{
			if(snake[1]->d!=4)
			snake[1]->d=3;
		}
		else if(temp.x<0)
		{
			if(snake[1]->d!=3)
			snake[1]->d=4;
		}
		else if(temp.y>0)
		{
			if(snake[1]->d!=2)
           snake[1]->d=1;
		}
		else if(temp.y<0)
		{
			if(snake[1]->d!=1)
			snake[1]->d=2;
		}
		
        
	}

    
	~COperator()
	{
 
	}

};
#endif
/*	void creatanswer()
	{
		CString temp;
		
		 node n;
		vector<node> stack;
		vector<node> queue;
       for(int i=0;i<7;i++)
	   {
		   if(i%2==0)
		   {
			   temp="";
			   int d=5+rand()%40;
			   temp.Format("%d",d);
			   answerstr+=temp;
			   n.flag=1;n.nums=d;
			   queue.push_back(n);
		   }
		   else
		   {
			   int nn=rand()%2;
			   answerstr+=sign[nn];	
			   node t;
			   t.flag=0;
			   t.op=sign[nn][0];
			   if(t.op=='*'||t.op=='/')
			   {
				  while(stack.size()>0)
				  {
					  if(stack.back().op=='*'||stack.back().op=='/')
					  {
                         queue.push_back(stack[stack.size()-1]);
					  }
				  }
				  stack.push_back(t);
			   }
			   else
			   {
				   while(stack.size()>0)
				   {
					   queue.push_back(stack[stack.size()-1]);
					   stack.pop_back();
				   }
				   stack.push_back(t);
			   }
		   }
	   }
	   while(stack.size()>0)
	   {
			 queue.push_back(stack.back());
			 stack.pop_back();
	   }
       for(int k=0;k<queue.size();k++)
	   {
		   if(queue[k].flag==1)
		   {
			   stack.push_back(queue[k]);
		   }
		   else
		   {
			   n.flag=1;
			   int nums2=stack.back().nums;
			   stack.pop_back();
			   int nums1=stack.back().nums;
			   stack.pop_back();
			   char ch=queue[k].op;
			   if(ch=='+')n.nums=nums1+nums2;
               if(ch=='-')n.nums=nums1-nums2;
			   if(ch=='*')n.nums=nums1*nums2;
			   if(ch=='/')n.nums=nums1/nums2;
			   stack.push_back(n);
		   }
	   }
       //answer=stack[0].nums;
	   if(stack.size()>0)
	   {
           answer=stack[0].nums;
	   }
	   //if(answer<1000||answer>3000)creatanswer();
	}*/