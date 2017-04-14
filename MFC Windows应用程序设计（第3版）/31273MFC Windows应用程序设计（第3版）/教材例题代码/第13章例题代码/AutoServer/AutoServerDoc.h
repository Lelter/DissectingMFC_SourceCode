// AutoServerDoc.h : interface of the CAutoServerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_AUTOSERVERDOC_H__1FF404B4_D6D5_4E7F_8287_DEF1BCE3057C__INCLUDED_)
#define AFX_AUTOSERVERDOC_H__1FF404B4_D6D5_4E7F_8287_DEF1BCE3057C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CAutoServerSrvrItem;

class CAutoServerDoc : public COleServerDoc
{
public:
		UINT m_yPos;		//�洢԰��y�᷽���λ�õĳ�Ա����
		UINT m_xPos;		//�洢԰��x�᷽���λ�õĳ�Ա����
		UINT m_diameter;		//�洢԰�뾶�ĳ�Ա����

protected: // create from serialization only
	CAutoServerDoc();
	DECLARE_DYNCREATE(CAutoServerDoc)

// Attributes
public:
	CAutoServerSrvrItem* GetEmbeddedItem()
		{ return (CAutoServerSrvrItem*)COleServerDoc::GetEmbeddedItem(); }

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutoServerDoc)
	protected:
	virtual COleServerItem* OnGetEmbeddedItem();
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAutoServerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAutoServerDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTOSERVERDOC_H__1FF404B4_D6D5_4E7F_8287_DEF1BCE3057C__INCLUDED_)
