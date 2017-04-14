// MFCexp10_4View.h : interface of the CMFCexp10_4View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCEXP10_4VIEW_H__89CB538C_A533_46EB_AE32_5631602C47C9__INCLUDED_)
#define AFX_MFCEXP10_4VIEW_H__89CB538C_A533_46EB_AE32_5631602C47C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFCexp10_4View : public CView
{
protected: // create from serialization only
	CMFCexp10_4View();
	DECLARE_DYNCREATE(CMFCexp10_4View)
		CFont m_spinEditFont;				//�������
		CSpinButtonCtrl m_spin;			//΢���ؼ�����
		CEdit m_spinEdit;					//�༭��ؼ�����
		void InitSpinner( );					//΢�����ĳ�ʼ������
		CProgressCtrl m_progBar1,m_progBar2;//�������ؼ�
		void InitProgressBar( );				//�������ؼ��ĳ�ʼ������

// Attributes
public:
	CMFCexp10_4Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCexp10_4View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFCexp10_4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
		afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
		afx_msg void OnTimer(UINT nIDEvent);//��ʱ����Ӧ����

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCexp10_4View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCexp10_4View.cpp
inline CMFCexp10_4Doc* CMFCexp10_4View::GetDocument()
   { return (CMFCexp10_4Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCEXP10_4VIEW_H__89CB538C_A533_46EB_AE32_5631602C47C9__INCLUDED_)
