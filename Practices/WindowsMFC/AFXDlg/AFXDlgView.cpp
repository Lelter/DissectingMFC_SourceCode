// AFXDlgView.cpp : implementation of the CAFXDlgView class
//

#include "stdafx.h"
#include "AFXDlg.h"

#include "AFXDlgDoc.h"
#include "AFXDlgView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAFXDlgView

IMPLEMENT_DYNCREATE(CAFXDlgView, CView)

BEGIN_MESSAGE_MAP(CAFXDlgView, CView)
	//{{AFX_MSG_MAP(CAFXDlgView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAFXDlgView construction/destruction

CAFXDlgView::CAFXDlgView()
{
	// TODO: add construction code here
	m_fontColor=RGB(0,0,0);		//����������ɫ
//���ṹm_logFont����Ա��ֵ��������Ĭ������
	m_logFont.lfHeight = 48;
	m_logFont.lfWidth = 0;
	m_logFont.lfEscapement = 0;
	m_logFont.lfOrientation = 0;
	m_logFont.lfWeight = FW_NORMAL;
	m_logFont.lfItalic = 0;
	m_logFont.lfUnderline = 0;
	m_logFont.lfStrikeOut = 0;
	m_logFont.lfCharSet = 16;
	m_logFont.lfOutPrecision = OUT_DEFAULT_PRECIS;
	m_logFont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	m_logFont.lfQuality = PROOF_QUALITY;
	m_logFont.lfPitchAndFamily = VARIABLE_PITCH | FF_ROMAN;
	strcpy(m_logFont.lfFaceName, "Times New Roman");    
	m_pFont = new CFont;						
	m_pFont->CreateFontIndirect(&m_logFont);//�����������
}

CAFXDlgView::~CAFXDlgView()
{
}

BOOL CAFXDlgView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CAFXDlgView drawing

void CAFXDlgView::OnDraw(CDC* pDC)
{
	CAFXDlgDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CFont* oldFont = (CFont*)pDC->SelectObject(m_pFont);//������ѡ�뻷��
	pDC->SetTextColor(m_fontColor);	//����������ɫ
	pDC->TextOut(20, 60, "����һ������Ի���Ĳ��Գ���");
	pDC->SelectObject(oldFont);		//�ӻ�����ɾ������
}

/////////////////////////////////////////////////////////////////////////////
// CAFXDlgView printing

BOOL CAFXDlgView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CAFXDlgView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CAFXDlgView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CAFXDlgView diagnostics

#ifdef _DEBUG
void CAFXDlgView::AssertValid() const
{
	CView::AssertValid();
}

void CAFXDlgView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAFXDlgDoc* CAFXDlgView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAFXDlgDoc)));
	return (CAFXDlgDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAFXDlgView message handlers

void CAFXDlgView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
/*	char*filters="Word�ĵ�(*.doc)|*.doc|λͼ(*.bmp)|*.bmp|ȫ���ļ�(*.*)|*.*";//�ļ��Ի���
	CFileDialog fileDlg(TRUE,NULL,"*.doc",NULL,filters);
	int result=fileDlg.DoModal();
	if(result=IDOK)
		m_openfileName=fileDlg.GetFileName();
*/

	CFontDialog fontDialog(&m_logFont);//��������Ի������
	int result = fontDialog.DoModal( );//��ʾ����Ի���
	if (result == IDOK)
	{
		delete m_pFont;					//ɾ�����������
		m_pFont = new CFont;	
		//�������������
    		m_pFont->CreateFontIndirect(&m_logFont); 
		//��ȡ�û�ѡ���������ɫ
		m_fontColor=fontDialog.GetColor(); 
		Invalidate();					//������ʾ
	}	

	CView::OnLButtonDown(nFlags, point);
}

void CAFXDlgView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	char*filters="Word�ĵ�(*.doc)|*.doc|λͼ(*.bmp)|*.bmp|ȫ���ļ�(*.*)|*.*";
	CFileDialog fileDlg(FALSE,NULL,"*.doc",
OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,filters);
	int result=fileDlg.DoModal();
	if(result=IDOK)
		m_saveFileName = fileDlg.GetFileName();

	CView::OnRButtonDown(nFlags, point);
}
