// Mdlg.cpp : implementation file
//

#include "stdafx.h"
#include "Snake.h"
#include "Mdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMdlg dialog


CMdlg::CMdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMdlg)
	m_s = _T("");
	//}}AFX_DATA_INIT
}


void CMdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMdlg)
	DDX_Text(pDX, IDC_EDIT1, m_s);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMdlg, CDialog)
	//{{AFX_MSG_MAP(CMdlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMdlg message handlers
