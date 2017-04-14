// MFCexp8_3View.h : interface of the CMFCexp8_3View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCEXP8_3VIEW_H__B004A32C_1F8D_4F11_977A_0FD703D30ECD__INCLUDED_)
#define AFX_MFCEXP8_3VIEW_H__B004A32C_1F8D_4F11_977A_0FD703D30ECD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFCexp8_3View : public CView
{
protected: // create from serialization only
	CMFCexp8_3View();
	DECLARE_DYNCREATE(CMFCexp8_3View)

// Attributes
public:
	CMFCexp8_3Doc* GetDocument();
 	BOOL m_nOption1;
	BOOL m_nOption2;
	BOOL m_nOption3;//�������ݳ�Ա���洢�˵�ѡ���״̬

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCexp8_3View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFCexp8_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	afx_msg void OnXuanx1( );//ѡ��1����Ϣ��Ӧ����
	afx_msg void OnUpdateXuanx1(CCmdUI*pCmdUI);//ѡ��1��UI����
	afx_msg void OnXuanx2( ); //ѡ��2����Ϣ��Ӧ����
	afx_msg void OnUpdateXuanx2(CCmdUI*pCmdUI); //ѡ��2��UI����
	afx_msg void OnXuanx3( ); //ѡ��3����Ϣ��Ӧ����
	afx_msg void OnUpdateXuanx3(CCmdUI*pCmdUI); //ѡ��3��UI����

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCexp8_3View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCexp8_3View.cpp
inline CMFCexp8_3Doc* CMFCexp8_3View::GetDocument()
   { return (CMFCexp8_3Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCEXP8_3VIEW_H__B004A32C_1F8D_4F11_977A_0FD703D30ECD__INCLUDED_)
