// MFCexp11_6View.h : interface of the CMFCexp11_6View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCEXP11_6VIEW_H__DCD3D9C7_4CC1_11D8_B98F_0000E8D3C09B__INCLUDED_)
#define AFX_MFCEXP11_6VIEW_H__DCD3D9C7_4CC1_11D8_B98F_0000E8D3C09B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include"NonMdlDlg.h"

class CMFCexp11_6View : public CView
{
public:
	int m_pX;					//�����洢���xֵ�ı���
	int m_pY;					//�����洢���yֵ�ı���
	CNonMdlDlg* m_pNameDlg;	//�����Ի����ָ��

protected: // create from serialization only
	CMFCexp11_6View();
	DECLARE_DYNCREATE(CMFCexp11_6View)

// Attributes
public:
	CMFCexp11_6Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCexp11_6View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFCexp11_6View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCexp11_6View)
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCexp11_6View.cpp
inline CMFCexp11_6Doc* CMFCexp11_6View::GetDocument()
   { return (CMFCexp11_6Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCEXP11_6VIEW_H__DCD3D9C7_4CC1_11D8_B98F_0000E8D3C09B__INCLUDED_)
