// MFCexp4_2View.cpp : implementation of the CMFCexp4_2View class
//

#include "stdafx.h"
#include "MFCexp4_2.h"

#include "MFCexp4_2Doc.h"
#include "MFCexp4_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCexp4_2View

IMPLEMENT_DYNCREATE(CMFCexp4_2View, CView)

BEGIN_MESSAGE_MAP(CMFCexp4_2View, CView)
	//{{AFX_MSG_MAP(CMFCexp4_2View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCexp4_2View construction/destruction

CMFCexp4_2View::CMFCexp4_2View()
{
	// TODO: add construction code here

}

CMFCexp4_2View::~CMFCexp4_2View()
{
}

BOOL CMFCexp4_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMFCexp4_2View drawing

void CMFCexp4_2View::OnDraw(CDC* pDC)
{
	CMFCexp4_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	int red=0,green=0,blue=0;
	int width=2;
	int row=20;
	for(int s=0;s<8;s++)
	{
		int color=RGB(red,green,blue);
		CPen newPen(PS_SOLID,width,color);
		CPen*oldPen=pDC->SelectObject(&newPen);
		pDC->MoveTo(20,row);
		pDC->LineTo(300,row);
		pDC->SelectObject(oldPen);
		red+=32;
		green+=16;
		blue+=8;
		width+=2;
		row+=30;
	}
}


/////////////////////////////////////////////////////////////////////////////
// CMFCexp4_2View diagnostics

#ifdef _DEBUG
void CMFCexp4_2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCexp4_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCexp4_2Doc* CMFCexp4_2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCexp4_2Doc)));
	return (CMFCexp4_2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCexp4_2View message handlers
