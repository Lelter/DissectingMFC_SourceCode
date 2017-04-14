// MFCexp10_5View.h : interface of the CMFCexp10_5View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCEXP10_5VIEW_H__51BE7012_4BEC_43E9_BBFC_EB40E8ABDD76__INCLUDED_)
#define AFX_MFCEXP10_5VIEW_H__51BE7012_4BEC_43E9_BBFC_EB40E8ABDD76__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFCexp10_5View : public CView
{
protected: // create from serialization only
	CMFCexp10_5View();
	DECLARE_DYNCREATE(CMFCexp10_5View)

// Attributes
public:
	CMFCexp10_5Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCexp10_5View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFCexp10_5View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CImageList m_lrgImageList;		//����Сͼ���б�ؼ�
	CImageList m_smlImageList;		//������ͼ���б�ؼ�
	void InitListView( );			//�����б�ؼ��ĳ�ʼ������
	CListCtrl m_listView;			//�����б���ͼ�ؼ�
	void CreateListColumns( );		//�������б���ͼ�ؼ�����еĺ���
	void AddListItems( );			//�������б���ͼ�ؼ������Ŀ�ĺ���
	afx_msg void OnBigIcon( );		//�˵�"��ͼ��"ѡ�����Ϣ������
	afx_msg void OnSmlIcon( );		//�˵�"Сͼ��"ѡ�����Ϣ������
	afx_msg void OnList( );			//�˵�"�б�"ѡ�����Ϣ������
	afx_msg void OnReport( );		//�˵�"����"ѡ�����Ϣ������
	//˫���б�ؼ�����Ŀͼ�����Ϣ������
	afx_msg void OnListViewDblClk(NMHDR* pNMHDR, LRESULT* pResult);

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCexp10_5View)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCexp10_5View.cpp
inline CMFCexp10_5Doc* CMFCexp10_5View::GetDocument()
   { return (CMFCexp10_5Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCEXP10_5VIEW_H__51BE7012_4BEC_43E9_BBFC_EB40E8ABDD76__INCLUDED_)
