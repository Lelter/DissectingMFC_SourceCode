// SyncThrdView.cpp : implementation of the CSyncThrdView class
//

#include "stdafx.h"
#include "SyncThrd.h"

#include "SyncThrdDoc.h"
#include "SyncThrdView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//�Զ����Ŷ���
//CEvent eventObj;

//�ֹ����Ŷ���
//CEvent eventObj(FALSE,TRUE);

CCriticalSection criticalSection;//�����ٽ�ζ���

CMutex mutexObj(FALSE, "mutex1");//���廥�������

CSemaphore semaphorObj(2,3);//�ź���

/////////////////////////////////////////////////////////////////////////////
// CSyncThrdView

IMPLEMENT_DYNCREATE(CSyncThrdView, CView)

BEGIN_MESSAGE_MAP(CSyncThrdView, CView)
	//{{AFX_MSG_MAP(CSyncThrdView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSyncThrdView construction/destruction

CSyncThrdView::CSyncThrdView()
{
	// TODO: add construction code here

}

CSyncThrdView::~CSyncThrdView()
{
}

BOOL CSyncThrdView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSyncThrdView drawing

void CSyncThrdView::OnDraw(CDC* pDC)
{
	CSyncThrdDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSyncThrdView diagnostics

#ifdef _DEBUG
void CSyncThrdView::AssertValid() const
{
	CView::AssertValid();
}

void CSyncThrdView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSyncThrdDoc* CSyncThrdView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSyncThrdDoc)));
	return (CSyncThrdDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSyncThrdView message handlers

// �̺߳�����ȫ�ֻ��߾�̬����
UINT MessageThread1(LPVOID pParam)
{
	semaphorObj.Lock();
    char* pMessage ="Thread1 is started";
    CWnd* pMainWnd = AfxGetMainWnd( );
    ::MessageBox(pMainWnd->m_hWnd,
        pMessage, "Thread message", MB_OK);
	semaphorObj.Unlock( );
    return 0;
}
UINT MessageThread2(LPVOID pParam)
{
	semaphorObj.Lock( );
    char* pMessage ="Thread2 is started";
    CWnd* pMainWnd = AfxGetMainWnd( );
    ::MessageBox(pMainWnd->m_hWnd,
        pMessage, "Thread message", MB_OK);
	semaphorObj.Unlock( );
    return 0;
}
UINT MessageThread3(LPVOID pParam)
{
	semaphorObj.Lock( );
    char* pMessage ="Thread3 is started";
    CWnd* pMainWnd = AfxGetMainWnd( );
    ::MessageBox(pMainWnd->m_hWnd,
        pMessage, "Thread message", MB_OK);
	semaphorObj.Unlock( );
    return 0;
}
UINT MessageThread4(LPVOID pParam)
{
	semaphorObj.Lock( );
    char* pMessage ="Thread4 is started";
    CWnd* pMainWnd = AfxGetMainWnd( );
    ::MessageBox(pMainWnd->m_hWnd,
        pMessage, "Thread message", MB_OK);
	semaphorObj.Unlock( );
    return 0;
}

void CSyncThrdView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	AfxBeginThread (MessageThread1,"Thread is started");
	AfxBeginThread (MessageThread2,"Thread is started");
	AfxBeginThread (MessageThread3,"Thread is started");
	AfxBeginThread (MessageThread4,"Thread is started");
	
	CView::OnLButtonDown(nFlags, point);
}

void CSyncThrdView::OnRButtonDown(UINT nFlags, CPoint point) 
{

	
	CView::OnRButtonDown(nFlags, point);
}
