// MFCexp9_6Doc.cpp : implementation of the CMFCexp9_6Doc class
//

#include "stdafx.h"
#include "MFCexp9_6.h"

#include "MFCexp9_6Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCexp9_6Doc

IMPLEMENT_DYNCREATE(CMFCexp9_6Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFCexp9_6Doc, CDocument)
	//{{AFX_MSG_MAP(CMFCexp9_6Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCexp9_6Doc construction/destruction

CMFCexp9_6Doc::CMFCexp9_6Doc()
{
	// TODO: add one-time construction code here

}

CMFCexp9_6Doc::~CMFCexp9_6Doc()
{
}

BOOL CMFCexp9_6Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMFCexp9_6Doc serialization

void CMFCexp9_6Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
	m_LetterList.Serialize(ar);
}
void CMFCexp9_6Doc::NewLetter(int x,int y)
{
	CLetter* pLetterItem = new CLetter('m',x,y);//�����¶���
	m_LetterList.AddTail(pLetterItem);		//���¶����������β��
	SetModifiedFlag( );  					//�����ĵ��޸ı�־
}
void CMFCexp9_6Doc::DrawLetter(CDC*pDC )
{
	POSITION pos=m_LetterList.GetHeadPosition();//�������ͷλ��	
	while(pos!=NULL)
	{
		CLetter*Letter=m_LetterList.GetNext(pos);//�������Ԫ��
		pDC->TextOut(Letter->m_X-5,			//��ʾ
			Letter->m_Y-12,
			Letter->m_sLetter);
	}
}
/////////////////////////////////////////////////////////////////////////////
// CMFCexp9_6Doc diagnostics

#ifdef _DEBUG
void CMFCexp9_6Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCexp9_6Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCexp9_6Doc commands









