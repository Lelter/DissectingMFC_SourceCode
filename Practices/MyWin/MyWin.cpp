// MyWin.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#define szWindowClass "MyClassName"
#define  szTitle "MyWindow"

ATOM MyRegisterClass(HINSTANCE hInstance);
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	MSG msg;
	HWND hWnd;
   //ע�ᴰ���� 
	MyRegisterClass(hInstance);
	//ʹ����ע��Ĵ����࣬����������
	hWnd = ::CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW|WS_BORDER,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }
   //��ʾ������
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

	// �ȴ��������ڣ�Ȼ�������Ϣѭ��
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
	}
	//�յ�WM_QUIT��Ϣ���˳�
	return msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 
	//��������
	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	//��������Ϣ�Ĵ��ڹ��̣�����ָ��ָ��WndProc()
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	//ʵ�����
	wcex.hInstance		= hInstance;
	//ͼ����
	wcex.hIcon			= NULL;
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	//����ˢ
	wcex.hbrBackground	= (HBRUSH)(COLOR_BACKGROUND+1);
	//���˵�
	wcex.lpszMenuName	=NULL;
	//������
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= NULL;
	//ע�ᴰ���� 
	return RegisterClassEx(&wcex);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//��������Ϣ�Ĵ��ڹ��̺���
	
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message) 
	{
	case WM_CREATE:
	case WM_SHOWWINDOW:
	case WM_KEYDOWN:
	case WM_COMMAND:
	//.........
		return ::DefWindowProc(hWnd, message, wParam, lParam);
	case WM_LBUTTONDOWN:
		int ScreenWidth;
		int ScreenLength;
		RECT rcWindow;
		
		::GetWindowRect(hWnd,&rcWindow);
		ScreenWidth=GetSystemMetrics(SM_CXSCREEN);
		 ScreenLength=GetSystemMetrics(SM_CYSCREEN);
		//��굥�������ô���λ��
		::SetWindowPos(hWnd,HWND_TOP,ScreenWidth/4,
			ScreenWidth/4,ScreenLength/2,ScreenLength/2,SWP_SHOWWINDOW);
		Sleep(300);

		::SetWindowPos(hWnd,HWND_TOP,ScreenWidth/3,
			ScreenWidth/3,ScreenLength/3,ScreenLength/3,SWP_SHOWWINDOW);
		Sleep(100);
		::SetWindowPos(hWnd,HWND_TOP,ScreenWidth/4,
			ScreenWidth/4,ScreenLength/2,ScreenLength/2,SWP_SHOWWINDOW);
		Sleep(100);
		::SetWindowPos(hWnd,HWND_TOP,rcWindow.left,rcWindow.top,
			rcWindow.right-rcWindow.left,rcWindow.bottom-rcWindow.top,
			SWP_SHOWWINDOW);


		
		return ::DefWindowProc(hWnd, message, wParam, lParam);


	case WM_RBUTTONDOWN:
	//��������Ҽ������ء���ʾ���� 
		ShowWindow(hWnd,SW_HIDE);
		Sleep(300);
		ShowWindow(hWnd,SW_SHOW);

         return ::DefWindowProc(hWnd, message, wParam, lParam);
	case WM_PAINT:
		//���ƴ���
			hdc = BeginPaint(hWnd, &ps);
			RECT rt;
			GetClientRect(hWnd, &rt);
			::SetBkColor(hdc,::GetSysColor(COLOR_BACKGROUND));
			::SetTextColor(hdc,RGB(255,255,255));
			DrawText(hdc, "My window created by win32 API",-1,&rt, DT_CENTER);

			EndPaint(hWnd, &ps);
			return ::DefWindowProc(hWnd, message, wParam, lParam);
			break;

	case WM_DESTROY:
		//�����ڹر�ʱ����UI�߳���Ϣѭ������WM_QUIT��Ϣ���߳��˳�����Ϊ0
			PostQuitMessage(0);
			break;
	default:
		//����ȱʡ����Ϣ������̴���ǰ��Ϣ
		return ::DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}





