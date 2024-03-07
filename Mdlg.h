#if !defined(AFX_MDLG_H__5923ED90_AAE0_4565_8220_218130CF7017__INCLUDED_)
#define AFX_MDLG_H__5923ED90_AAE0_4565_8220_218130CF7017__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Mdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMdlg dialog

class CMdlg : public CDialog
{
// Construction
public:
	CMdlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMdlg)
	enum { IDD = IDD_DIALOG1 };
	CString	m_s;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMdlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MDLG_H__5923ED90_AAE0_4565_8220_218130CF7017__INCLUDED_)
