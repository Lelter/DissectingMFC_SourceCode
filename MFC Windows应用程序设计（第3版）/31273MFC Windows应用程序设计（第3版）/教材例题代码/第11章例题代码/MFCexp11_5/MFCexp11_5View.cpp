// MFCexp11_5View.cpp : implementation of the CMFCexp11_5View class
//

#include "stdafx.h"
#include "MFCexp11_5.h"

#include "MFCexp11_5Doc.h"
#include "MFCexp11_5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "afxdlgs.h"
/////////////////////////////////////////////////////////////////////////////
// CMFCexp11_5View

IMPLEMENT_DYNCREATE(CMFCexp11_5View, CView)

BEGIN_MESSAGE_MAP(CMFCexp11_5View, CView)
	//{{AFX_MSG_MAP(CMFCexp11_5View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCexp11_5View construction/destruction

CMFCexp11_5View::CMFCexp11_5View()
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

CMFCexp11_5View::~CMFCexp11_5View()
{
}

BOOL CMFCexp11_5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMFCexp11_5View drawing

void CMFCexp11_5View::OnDraw(CDC* pDC)
{
	CMFCexp11_5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CFont* oldFont = (CFont*)pDC->SelectObject(m_pFont);//������ѡ�뻷��
	pDC->SetTextColor(m_fontColor);	//����������ɫ
	pDC->TextOut(20, 60, "����һ������Ի���Ĳ��Գ���");
	pDC->SelectObject(oldFont);		//�ӻ�����ɾ������

}

/////////////////////////////////////////////////////////////////////////////
// CMFCexp11_5View diagnostics

#ifdef _DEBUG
void CMFCexp11_5View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCexp11_5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCexp11_5Doc* CMFCexp11_5View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCexp11_5Doc)));
	return (CMFCexp11_5Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCexp11_5View message handlers
void CMFCexp11_5View::OnLButtonDown(UINT nFlags, CPoint point) 
{
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
