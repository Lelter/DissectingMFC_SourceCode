#include <afxwin.h>
// ��CWinApp������Ӧ�ó���������
class MyApp : public CWinApp
{
public:
    BOOL InitInstance();      //����InitInstance()����
};
// ����Ӧ�ó������ȫ�ֶ���
MyApp theApp;
//InitInstance������ʵ��
MyApp::InitInstance()
{
    CFrameWnd*pMainWnd=new CFrameWnd;//������ܴ�����Ķ���
	pMainWnd->Create(NULL, "Basic MFC Application");
    pMainWnd->ShowWindow(m_nCmdShow);//��ʾ����
	pMainWnd->UpdateData();
	m_pMainWnd=pMainWnd;
    return TRUE;
}
