// MFCexp8_4Doc.h : interface of the CMFCexp8_4Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCEXP8_4DOC_H__A01E31D2_2548_486C_9294_44D7D9121BCD__INCLUDED_)
#define AFX_MFCEXP8_4DOC_H__A01E31D2_2548_486C_9294_44D7D9121BCD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFCexp8_4Doc : public CDocument
{
protected: // create from serialization only
	CMFCexp8_4Doc();
	DECLARE_DYNCREATE(CMFCexp8_4Doc)

// Attributes
public:
	CBitmap m_Bitmap;		//λͼ����
	int m_nWidth;				//�洢λͼ������ݳ�Ա
	int m_nHeight;			//�洢λͼ�ߵ����ݳ�Ա

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCexp8_4Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFCexp8_4Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCexp8_4Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCEXP8_4DOC_H__A01E31D2_2548_486C_9294_44D7D9121BCD__INCLUDED_)
