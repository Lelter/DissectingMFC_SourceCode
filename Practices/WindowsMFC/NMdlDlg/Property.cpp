// Property.cpp : implementation file
//

#include "stdafx.h"
#include "NMdlDlg.h"
#include "Property.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProperty dialog

IMPLEMENT_DYNAMIC(CProperty, CPropertySheet)

CProperty::CProperty(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{

}

CProperty::CProperty(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_textOptions);	//��������ҳ��Text Options
	AddPage(&m_bitmapOptions);	//��������ҳ��Bitmap Options
}

CProperty::~CProperty()
{
}


BEGIN_MESSAGE_MAP(CProperty, CPropertySheet)
	//{{AFX_MSG_MAP(CProperty)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProperty message handlers
