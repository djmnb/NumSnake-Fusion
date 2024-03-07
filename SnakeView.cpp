// SnakeView.cpp : implementation of the CSnakeView class
//

#include "stdafx.h"
#include "Snake.h"
#include"windows.h"
#include "mmsystem.h"
#include "SnakeDoc.h"
#include "SnakeView.h"
#include "data.h"
#include "Mdlg.h"
#include "Operator.h"
#include "Resource.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSnakeView

IMPLEMENT_DYNCREATE(CSnakeView, CView)

BEGIN_MESSAGE_MAP(CSnakeView, CView)
	//{{AFX_MSG_MAP(CSnakeView)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSnakeView construction/destruction

CSnakeView::CSnakeView()
{
	// TODO: add construction code here
   loadallmap();
   creatway();
   CFood::initallfood();
   sndPlaySound("chuchang.wav", SND_ASYNC);
   op = new COperator();
   
   
   times = 0;
   ends=178;
   //ends=0;
   int w=100;
   int h=60;
   int x=game_x+game_w+10;
   int y=120;
   int temp=80+h;

   start = CRect(x,y,x+w,h+y);

   y+=temp;
   
   _mode = CRect(x,y,x+w,h+y);

   y+=temp;

   music = CRect(x,y,x+w,h+y);

   y+=temp;

   help = CRect(x,y,x+w,h+y);

   temp=0;
  
   x1=0;
   y1=temp;
   
   x2=game_w-150;
   y2=temp;

   x3=game_w/2-50;
   y3=temp;

   
}

CSnakeView::~CSnakeView()
{
}

BOOL CSnakeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSnakeView drawing

void CSnakeView::OnDraw(CDC* pDC)
{
	CSnakeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	startui();
	if(times<ends)
	{
		UINT id;
		if(times<=ends/4)id=startbt;
		else if(times<ends/4*2)id=startbt1;
		else if(times<ends/4*3)id=startbt2;
		else id=startbt3;
		CDC mendc1;
		mendc1.CreateCompatibleDC(NULL);
		CBitmap bm;
		bm.LoadBitmap(id);
		mendc1.SelectObject(&bm);
		BITMAP btsize;
		bm.GetBitmap(&btsize);
		pDC->StretchBlt(0,0,windows_w,windows_h,&mendc1,0,0,btsize.bmWidth,btsize.bmHeight,SRCCOPY);
		return;
    }
	CDC mendcall;
	CMapinfo* btmax = getmapinfo(bg_1);
    CBitmap bttemp;
	mendcall.CreateCompatibleDC(pDC);
	bttemp.CreateCompatibleBitmap(pDC,windows_w,windows_h);
	mendcall.SelectObject(&bttemp);
    mendcall.StretchBlt(0,0,windows_w,windows_h,&btmax->memdc,0,0,btmax->w,btmax->h,SRCCOPY);

	CDC mendc;
	CBitmap bt;

	mendc.CreateCompatibleDC(pDC);
	bt.CreateCompatibleBitmap(pDC, game_w, game_h);
	mendc.SelectObject(&bt);

    op->show(&mendc);
	mendc.SetBkMode(TRANSPARENT);
	mendc.SetTextColor(RGB(255,255,255));
    CFood::showallfoods(&mendc);

	mendcall.StretchBlt(game_x,game_y,game_w,game_h,&mendc,0,0,game_w,game_h,SRCCOPY);//把游戏区域画到mendcall上面

	showbutton(&mendcall);
	showdata(&mendcall);

	//mendcall.SetBkColor(RGB(255,255,255));
	pDC->StretchBlt(0,0,windows_w,windows_h,&mendcall,0,0,windows_w,windows_h,SRCCOPY);//把整个界面画出来


	whowin();
    


}

/////////////////////////////////////////////////////////////////////////////
// CSnakeView printing

BOOL CSnakeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSnakeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSnakeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSnakeView diagnostics

#ifdef _DEBUG
void CSnakeView::AssertValid() const
{
	CView::AssertValid();
}

void CSnakeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSnakeDoc* CSnakeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSnakeDoc)));
	return (CSnakeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSnakeView message handlers

void CSnakeView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(times<=ends)return;
	if(start.PtInRect(point))
	{
		handlestart();
	}
	else if(_mode.PtInRect(point))
	{
		
		if(op->gamemode==1)
		{
			if(op->isstarted&&!op->ispaused)
			handlestart();
			if(MessageBox("是否进入双人对战","模式选择",MB_OKCANCEL)==IDOK)
			{
				delete op;
				op = new COperator(2);
				Invalidate();
			}
		}
		else
		{
		   if(op->isstarted&&!op->ispaused)
		   handlestart();
		   if(MessageBox("是否进入人机对战","模式选择",MB_OKCANCEL)==IDOK)
		   {
				delete op;
				op = new COperator(1);
				Invalidate();
		   }
		}
	}
	else if(music.PtInRect(point))
	{
		if(op->openmusiced)
		{
			op->openmusiced=false;
            sndPlaySound(NULL, SND_SYNC);
		}
		else
		{
			op->openmusiced=true;
			if(op->isstarted&&!op->ispaused)
			sndPlaySound("backgroundmusic2.wav", SND_ASYNC|SND_LOOP);
		}
		Invalidate();
	}
	else if(help.PtInRect(point))
	{
		if(op->isstarted&&!op->ispaused)
		handlestart();
		CMdlg dg;
		dg.m_s=CString("                                                                       帮助系统 \r\n此游戏的机制为:系统随机给出一个数，需要吃食物里面的数字合成系统所给出的数字，谁先合成\r\n谁先赢\r\n\r\n人机对战:\r\n玩家可以操控WASD以及上下键操控蛇\r\n\r\n双人对战:\r\n一方用WASD操作蛇，一方用上下键操作蛇");
		UpdateData(false);
		dg.DoModal();
	}
	CView::OnLButtonDown(nFlags, point);
}

void CSnakeView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent==startid)
	{
		CRect rect(game_x,game_y,game_x+game_w,game_y+game_h);
	    op->run();
	    Invalidate();
	}
	else if(nIDEvent==20)
	{
		times++;
		Invalidate();
	}
	CView::OnTimer(nIDEvent);
}

void CSnakeView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if(times<=ends)return;
	// TODO: Add your message handler code here and/or call default
	if(op->gamemode==1)
	{
		if(nChar==VK_LEFT||nChar=='A')
		{
			if(op->snake[0]->d!=4)
			{
				op->snake[0]->d=3;
			}
		}
		else if(nChar==VK_RIGHT||nChar=='D')
		{
			if(op->snake[0]->d!=3)
			{
				op->snake[0]->d=4;
			}
		}
		else if(nChar==VK_UP||nChar=='W')
		{
			if(op->snake[0]->d!=2)
			{
				op->snake[0]->d=1;
			}
		}
		else if(nChar==VK_DOWN||nChar=='S')
		{
			if(op->snake[0]->d!=1)
			{
				op->snake[0]->d=2;
			}
		}
	}
	else
	{
		if(nChar==VK_LEFT)
		{
           if(op->snake[0]->d!=4)op->snake[0]->d=3;
		}
		else if(nChar==VK_RIGHT)
		{
			if(op->snake[0]->d!=3)op->snake[0]->d=4;
		}
		else if(nChar==VK_UP)
		{
			if(op->snake[0]->d!=2)op->snake[0]->d=1;
		}
		else if(nChar==VK_DOWN)
		{
			if(op->snake[0]->d!=1)op->snake[0]->d=2;
		}

		if(nChar=='A')
		{
           if(op->snake[1]->d!=4)op->snake[1]->d=3;
		}
		else if(nChar=='D')
		{
			if(op->snake[1]->d!=3)op->snake[1]->d=4;
		}
		else if(nChar=='W')
		{
			if(op->snake[1]->d!=2)op->snake[1]->d=1;
		}
		else if(nChar=='S')
		{
			if(op->snake[1]->d!=1)op->snake[1]->d=2;
		}
	}
	/*if(nChar==VK_SPACE)
	{
		
	}
	if(nChar==VK_NUMPAD5)
	{
        if(op->snake[0]->result==op->answer)
		{
			
			COperator* temp = op;
			op=new COperator(op->gamemode);
			KillTimer(startid);
			if(temp->gamemode==1)
			    MessageBox("玩家获胜");
			else
				MessageBox("玩家一获胜");
			delete temp;
			
			Invalidate();
		}
	}*/
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
void CSnakeView::showbutton(CDC* dc)
{
    dc->Rectangle(&start);
	dc->Rectangle(&_mode);
	dc->Rectangle(&help);
	dc->Rectangle(&music);
    dc->SetBkMode(TRANSPARENT);
	dc->SetTextColor(RGB(255,255,255));
	CMapinfo* mapinfo=getmapinfo(btall);
    dc->StretchBlt(start.left,start.top,start.Width(),start.Height(),&mapinfo->memdc,0,0,mapinfo->w,mapinfo->h,SRCCOPY);

	dc->StretchBlt(_mode.left,_mode.top,_mode.Width(),_mode.Height(),&mapinfo->memdc,0,0,mapinfo->w,mapinfo->h,SRCCOPY);
    
    //mapinfo=getmapinfo(musicbt);
	dc->StretchBlt(music.left,music.top,music.Width(),music.Height(),&mapinfo->memdc,0,0,mapinfo->w,mapinfo->h,SRCCOPY);

	dc->StretchBlt(help.left,help.top,help.Width(),help.Height(),&mapinfo->memdc,0,0,mapinfo->w,mapinfo->h,SRCCOPY);

    CRect temp=start;
	int hh=21;

	temp.top+=hh;

	if(op->isstarted==false)
	{
		dc->DrawText("开始游戏",&temp,DT_CENTER);
		//op->isstarted=true;
	}
	else if(op->ispaused==false)
	{
        dc->DrawText("暂停游戏",&temp,DT_CENTER);
	}
	else
	{
		dc->DrawText("继续游戏",&temp,DT_CENTER);
		//op->ispaused=false;
	}

	temp=_mode;
	temp.top+=hh;

	if(op->gamemode==2)
	{
        dc->DrawText("人机对战",&temp,DT_CENTER);
	}
	else
	{
		dc->DrawText("双人对战",&temp,DT_CENTER);
	}

	temp=music;
	temp.top+=hh;

	if(op->openmusiced)
	{
       dc->DrawText("关闭音乐",&temp,DT_CENTER);
	}
	else
	{
		dc->DrawText("打开音乐",&temp,DT_CENTER);
	}
    
	temp=help;
	temp.top+=hh;
	dc->DrawText("帮助",&temp,DT_CENTER);
}

void CSnakeView::handlestart()
{
   if(op->isstarted==false)
   {
		SetTimer(startid,200,NULL);
		op->isstarted=true;
		//"res\\backgroundmusic2.wav"
		if(op->openmusiced)
		 sndPlaySound("backgroundmusic2.wav", SND_ASYNC|SND_LOOP);
	}
	else if(op->ispaused==false)
	{
		KillTimer(startid);
		op->ispaused=true;
		Invalidate();
		if(op->openmusiced)
        sndPlaySound(NULL,SND_SYNC);
	}
	else
	{
		op->ispaused=false;
		SetTimer(startid,200,NULL);
		if(op->openmusiced)
		 sndPlaySound("backgroundmusic2.wav", SND_ASYNC|SND_LOOP);
	}
 
}

void CSnakeView::showdata(CDC* pDC)
{
	pDC->SetTextColor(RGB(255,0,0));
	CString str;
	if(op->gamemode==1)
        str.Format("玩家目前答案:%d",op->snake[0]->result);
	else
		str.Format("玩家1目前答案:%d",op->snake[0]->result);

	pDC->TextOut(x1,y1,str);

    str="1111";

	if(op->gamemode==1)
        str.Format("人机目前答案:%d",op->snake[1]->result);
	else
		str.Format("玩家2目前答案:%d",op->snake[1]->result);
    
	pDC->TextOut(x2,y2,str);
    pDC->TextOut(x3,y3,op->answerstr);

	str="";
	str.Format("待合成答案:%d",op->answer);
    pDC->TextOut(x3,y3,str);
}

void CSnakeView::whowin()
{
	if(op->gamemode==1)
	{
		if(op->answer==op->snake[0]->result&&op->answer==op->snake[1]->result)
		{
            COperator* temp = op;
	        op=new COperator(op->gamemode);
			op->btways=temp->btways-1;
			op->setbg();
		    delete temp;
		    KillTimer(startid);
		    MessageBox("平局");
		    Invalidate();
		}
		else if(op->answer==op->snake[1]->result)
		{
			COperator* temp = op;
	        op=new COperator(op->gamemode);
			op->btways=temp->btways-1;
			op->setbg();
		    delete temp;
		    KillTimer(startid);
		    MessageBox("人机获胜");
		    Invalidate();
		}
		else if(op->answer==op->snake[0]->result)
		{
            COperator* temp = op;
	        op=new COperator(op->gamemode);
			op->btways=temp->btways-1;
			op->setbg();
		    delete temp;
		    KillTimer(startid);
		    MessageBox("玩家获胜");
		    Invalidate();
		}
	}
	if(op->gamemode==2)
	{
		if(op->answer==op->snake[0]->result&&op->answer==op->snake[1]->result)
		{
            COperator* temp = op;
	        op=new COperator(op->gamemode);
			op->btways=temp->btways-1;
			op->setbg();
		    delete temp;
		    KillTimer(startid);
		    MessageBox("平局");
		    Invalidate();
		}
		else if(op->snake[1]->result==op->answer)
		{
			COperator* temp = op;
			op=new COperator(op->gamemode);
			op->btways=temp->btways-1;
			op->setbg();
			delete temp;
			KillTimer(startid);
			MessageBox("玩家二获胜");
			Invalidate();
			
		}
		else if(op->snake[0]->result==op->answer)
		{
			COperator* temp = op;
			op=new COperator(op->gamemode);
			op->btways=temp->btways-1;
			op->setbg();
			delete temp;
			KillTimer(startid);
			MessageBox("玩家一获胜");
			Invalidate();
		}
			
	}
}
void CSnakeView::startui()
{
	if(times==0)
	{
		SetTimer(20,100,NULL);
	}
	else if(times==ends+1)
	{
		times++;
        KillTimer(20);
	}
}

void CSnakeView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(times<=ends)return;
	op->setbg();
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}
