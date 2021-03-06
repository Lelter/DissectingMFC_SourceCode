// MFCexp5_1_1View.cpp : implementation of the CMFCexp5_1_1View class
//

#include "stdafx.h"
#include "MFCexp5_1_1.h"

#include "MFCexp5_1_1Doc.h"
#include "MFCexp5_1_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCexp5_1_1View

IMPLEMENT_DYNCREATE(CMFCexp5_1_1View, CView)

BEGIN_MESSAGE_MAP(CMFCexp5_1_1View, CView)
	//{{AFX_MSG_MAP(CMFCexp5_1_1View)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCexp5_1_1View construction/destruction

CMFCexp5_1_1View::CMFCexp5_1_1View()
{
	// TODO: add construction code here

}

CMFCexp5_1_1View::~CMFCexp5_1_1View()
{
}

BOOL CMFCexp5_1_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMFCexp5_1_1View drawing

void CMFCexp5_1_1View::OnDraw(CDC* pDC)
{
	CMFCexp5_1_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	for(int i=0;i<pDoc->m_Rectag.GetSize();i++)
		pDC->Rectangle(pDoc->m_Rectag[i]);
}

/////////////////////////////////////////////////////////////////////////////
// CMFCexp5_1_1View printing

BOOL CMFCexp5_1_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCexp5_1_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCexp5_1_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMFCexp5_1_1View diagnostics

#ifdef _DEBUG
void CMFCexp5_1_1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCexp5_1_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCexp5_1_1Doc* CMFCexp5_1_1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCexp5_1_1Doc)));
	return (CMFCexp5_1_1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCexp5_1_1View message handlers

void CMFCexp5_1_1View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CMFCexp5_1_1Doc*pDoc=GetDocument();//获取文档指针	
	int r=rand()%50+5;
	CRect Ret(point.x-r,point.y-r,point.x+r,point.y+r);
	pDoc->m_Rectag.Add(Ret);//向文档中数组添加元素

//直接触发当前窗口的OnDraw函数
	//InvalidateRect(Ret,FALSE);//触发OnDraw()函数

//同步更新所有视图
	//pDoc->UpdateAllViews(NULL);//使用了更新所有视图的函数

//更新效率
		InvalidateRect(Ret,FALSE);//触发OnDraw()函数
	//传递无效区类对象
	pDoc->UpdateAllViews(this);	

	CView::OnLButtonDown(nFlags, point);
}
