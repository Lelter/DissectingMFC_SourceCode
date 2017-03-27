// Win3_3.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

//����ȫ�ֱ����ͺ���------------------------------------------------------------------------
HINSTANCE hInst;								
HINSTANCE hInstance;
MSG msg;
char lpszClassName[]="window_class";
char*ShowText;
//��������ԭ��--------------------------------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);//���ں���
void OnLButtonDown(HWND hWnd, UINT message, 
				WPARAM wParam, LPARAM lParam);
void OnPaint(HWND hWnd, UINT message, 
				WPARAM wParam, LPARAM lParam);
void OnDestroy(HWND hWnd, UINT message, 
				WPARAM wParam, LPARAM lParam);
//������-----------------------------------------------------------------------------------------
class CFrameWnd
{		
public:	
	HWND hWnd;
public:
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
class CWinApp
{	
public:
	CWinApp * m_pCurrentWinApp;
public:
	CWinApp( );
	~ CWinApp( ); 
public:
	CFrameWnd * m_pMainWnd;
public:
	virtual BOOL InitInstance (int nCmdShow);
	int Run( );
};

CWinApp::CWinApp( )
{ m_pCurrentWinApp = this;}

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
CWinApp::~ CWinApp( ) { delete m_pMainWnd; }

//����Ա�����Ĵ�����-----------------------------------------------------------------------
class CMyWnd:public CFrameWnd
{
};

//����Ա��CWinApp��������CMyApp��-----------------------------------------------
class CMyApp:public CWinApp
{
public:
	BOOL InitInstance(int nCmdShow);
};
//������CMyApp�ĳ�Ա����---------------------------------------------------------------
CMyApp::InitInstance(int nCmdShow)
{
	CMyWnd*pMainWnd=new CMyWnd;//Ӧ�ô���������ඨ�崰�����
	pMainWnd->Create(NULL,"Ӧ�ô����������ĳ���");
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
int APIENTRY WinMain(HINSTANCE 	hInstance,
                     HINSTANCE 	hPrevInstance,
                     LPSTR     	lpCmdLine,
                     int       		nCmdShow)
{
	int ResultCode=-1;
	CWinApp*pApp;
	pApp=AfxGetApp();
	pApp->InitInstance(nCmdShow);
	return ResultCode=pApp->Run();
}
//���ں�����ʵ��--------------------------------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, 
WPARAM wParam, LPARAM lParam)
{
	switch (message) 
	{
	case WM_LBUTTONDOWN:	OnLButtonDown(hWnd, message, wParam, lParam);	
		break;
	case WM_PAINT:			OnPaint(hWnd, message,wParam, lParam);
		break;
	case WM_DESTROY:		OnDestroy(hWnd, message, wParam, lParam);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}
void OnLButtonDown(HWND hWnd, UINT message, 
				WPARAM wParam, LPARAM lParam)
{
	ShowText="Hello!";
	InvalidateRect(hWnd,NULL,1);
}
void OnPaint(HWND hWnd, UINT message, 
				WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	TextOut(hdc,50,50,ShowText,6);
	EndPaint(hWnd, &ps);
}
void OnDestroy(HWND hWnd, UINT message, 
				WPARAM wParam, LPARAM lParam)
{
	PostQuitMessage(0);
}
//-------------------------------------------------------------------------------------------



