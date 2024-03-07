// SnakeView.h : interface of the CSnakeView class
//
/////////////////////////////////////////////////////////////////////////////


#if !defined(AFX_SNAKEVIEW_H__B07BE01C_583C_4FEB_AF33_A0C7B4E308E9__INCLUDED_)
#define AFX_SNAKEVIEW_H__B07BE01C_583C_4FEB_AF33_A0C7B4E308E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include  "data.h"
#include "Operator.h"

class CSnakeView : public CView
{
protected: // create from serialization only
	CSnakeView();
	DECLARE_DYNCREATE(CSnakeView);

// Attributes
public:
	
	CSnakeDoc* GetDocument();

	COperator* op;

	CRect start;//开始游戏按钮
	CRect music;//声音按钮
	CRect _mode;//模式选择按钮
	CRect help;//帮助按钮

	int x1,y1;//一号蛇答案位置
	int x2,y2;//二号蛇答案位置
	int x3,y3;//题目位置

	int times;//控制开始加载图片
	int ends;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSnakeView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSnakeView();
	void showbutton(CDC*);
	void handlestart();
	void showdata(CDC*);
	void whowin();
	void startui();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSnakeView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SnakeView.cpp
inline CSnakeDoc* CSnakeView::GetDocument()
   { return (CSnakeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNAKEVIEW_H__B07BE01C_583C_4FEB_AF33_A0C7B4E308E9__INCLUDED_)
