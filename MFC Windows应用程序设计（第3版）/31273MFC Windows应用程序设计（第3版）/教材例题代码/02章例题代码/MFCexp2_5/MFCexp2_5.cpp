//��Ҫ������ͷ�ļ�---------------------------------------------------------------------------
#include<afxwin.h>
//��CFrameWnd������CMyWnd��------------------------------------------------------
class CMyWnd:public CFrameWnd
{
private:
	char*ShowText;           //����һ���ַ���Ϊ���ݳ�Ա
public:
	afx_msg void OnPaint();//����WM_PAINT��Ϣ������
	afx_msg void OnLButtonDown();//����������������Ϣ������
	DECLARE_MESSAGE_MAP()	//������Ϣӳ��
};
//��Ϣӳ���ʵ��------------------------------------------------------------------------------
BEGIN_MESSAGE_MAP(CMyWnd,CFrameWnd)
		ON_WM_PAINT()
		ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP( )
//WM_PAINT��Ϣ��������ʵ��--------------------------------------------------------
void CMyWnd::OnPaint()
{
	CPaintDC dc(this);
	dc.TextOut(20,20,ShowText);
}
//WM_LBUTTONDOWMT��Ϣ��������ʵ��--------------------------------------
void CMyWnd::OnLButtonDown()
{
	ShowText="����Ϣӳ���ĳ���";	//����갴��ʱ�����ַ���
	InvalidateRect(NULL,TRUE);		//֪ͨ����
}
//����Ա��CWinApp������Ӧ�ó�����-------------------------------------------------
class CMyApp:public CWinApp
{
public:
	BOOL InitInstance();  
};
BOOL CMyApp::InitInstance()
{
	CMyWnd*pMainWnd=new CMyWnd;
	pMainWnd->Create(0,"MFC");
	pMainWnd->ShowWindow(m_nCmdShow);
	pMainWnd->UpdateWindow();
	m_pMainWnd=pMainWnd;
	return TRUE;
}
//����CMyApp�Ķ���MyApp--------------------------------------------------------------
CMyApp MyApp;
//---------------------------------------------------------------------------------------------------
