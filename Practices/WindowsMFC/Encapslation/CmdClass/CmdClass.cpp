// CmdClass.cpp : Defines the entry point for the application.
//

#include "stdafx.h"


//����ȫ�ֱ����ͺ���------------------------------------------------------------------------
HINSTANCE hInst;								
HINSTANCE hInstance;
MSG msg;
char lpszClassName[]="window_class";
char*ShowText;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, 
				WPARAM wParam, LPARAM lParam);
//CCmdTarget--------------------------------------------------------------------------------
class CCmdTarget
{
public:	
	int AfxWndProc(HWND, UINT, 
				WPARAM, LPARAM );
	void On_LButtonDown(HWND, UINT, 
				WPARAM, LPARAM );
	void On_Paint(HWND, UINT, 
				WPARAM, LPARAM );
	void On_Destroy(HWND, UINT, 
				WPARAM, LPARAM );
};
int CCmdTarget::AfxWndProc(HWND hWnd, UINT message, 
				WPARAM wParam, LPARAM lParam)
{
	switch (message) 
	{
		case WM_LBUTTONDOWN:	
			On_LButtonDown(hWnd, message, wParam, lParam);	
			break;
		case WM_PAINT:			
			On_Paint(hWnd, message,wParam, lParam);
			break;
		case WM_DESTROY:		
			On_Destroy(hWnd, message, wParam, lParam);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}


void CCmdTarget::On_LButtonDown(HWND hWnd, UINT message, 
				WPARAM wParam, LPARAM lParam)
{
	ShowText="Hello!  Hello!";
	InvalidateRect(hWnd,NULL,1); 
}
void CCmdTarget::On_Paint(HWND hWnd, UINT message, 
				WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	TextOut(hdc,50,50,ShowText,14);
	EndPaint(hWnd, &ps);
}
void CCmdTarget::On_Destroy(HWND hWnd, UINT message, 
				WPARAM wParam, LPARAM lParam)
{
	PostQuitMessage(0);
}

//������-----------------------------------------------------------------------------------------
class CFrameWnd:public CCmdTarget//��CCmd������
{		
public:
	HWND hWnd;
	int RegisterWindow();	
	void Create(LPCTSTR lpClassName,
				LPCTSTR lpWindowName
				);	
	void ShowWindow(int nCmdShow);
	void UpdateWindow();
};
//������ĳ�Ա����----------------------------------------------------------------
int CFrameWnd::RegisterWindow()
{	
	WNDCLASS wc;
	wc.style=0;
	wc.lpfnWndProc=WndProc;
	wc.cbClsExtra=0;
	wc.cbWndExtra=0;
	wc.hInstance=hInstance;
	wc.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	wc.hCursor=LoadCursor(NULL,IDC_ARROW);
	wc.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName=NULL;
	wc.lpszClassName=lpszClassName;
	return RegisterClass(&wc);
}
void CFrameWnd::Create(LPCTSTR lpClassName,
					   LPCTSTR lpWindowName)
{
	RegisterWindow();
	hInst = hInstance; 
	hWnd = CreateWindow(lpszClassName,
						lpWindowName, 
						WS_OVERLAPPEDWINDOW,
						CW_USEDEFAULT, 
						0, 
						CW_USEDEFAULT, 
						0, 
						NULL, 
						NULL, 
						hInstance, 
						NULL);
}
void CFrameWnd::ShowWindow(int nCmdShow)
{
	::ShowWindow(hWnd, nCmdShow);
}
void CFrameWnd::UpdateWindow()
{
	::UpdateWindow(hWnd);
}

//Ӧ�ó�����----------------------------------------------------------------------------------
class CWinApp:public CCmdTarget
{	
public:
	CWinApp*m_pCurrentWinApp;
public:
	CWinApp();
public:
	CFrameWnd*m_pMainWnd;
public:
	virtual BOOL InitInstance (int nCmdShow);
	int Run();
	~CWinApp();
};

CWinApp::CWinApp( )
{ m_pCurrentWinApp=this;}

BOOL CWinApp::InitInstance(int nCmdShow)
{
	m_pMainWnd=new CFrameWnd;
	m_pMainWnd->Create(NULL,"��װ��Windows����");
	m_pMainWnd->ShowWindow(nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}
int CWinApp::Run()
{
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
CWinApp::~CWinApp(){ delete m_pMainWnd; }
//����Ա�����Ĵ�����-----------------------------------------------------------------------
class CMyWnd:public CFrameWnd
{
public: 
};
//����Ա��CWinApp��������CMyApp��-----------------------------------------------
class CMyApp:public CWinApp
{
public:
	CMyWnd*pMainWnd;//Ӧ�ô���������ඨ�崰�����
public: 	
	BOOL InitInstance(int nCmdShow);
};
//������CMyApp�ĳ�Ա����---------------------------------------------------------------
CMyApp::InitInstance(int nCmdShow)
{
	pMainWnd=new CMyWnd ;
	pMainWnd->Create(NULL,"����CCmdTarget��ĳ���");
	pMainWnd->ShowWindow(nCmdShow);
	pMainWnd->UpdateWindow();
	m_pMainWnd=pMainWnd;//��CMyWnd��Ķ��󸳸�m_pMainWnd
	return TRUE;
}

//����Ա�����CWinApp�Ķ���MyApp--------------------------------------------------
CMyApp MyApp;

//ȫ�ֺ���AfxGetApp()----------------------------------------------------------------------
CWinApp*AfxGetApp()
{
	return MyApp.m_pCurrentWinApp;
}

//������------------------------------------------------------------------------------------------
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	int ResultCode=-1;
	CWinApp*pApp;
	pApp=AfxGetApp();
	pApp->InitInstance(nCmdShow);
	return ResultCode=pApp->Run();
}

//���ں���---------------------------------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, 
WPARAM wParam, LPARAM lParam)
{
	return AfxGetApp()->AfxWndProc(hWnd, message, wParam,lParam);
}








