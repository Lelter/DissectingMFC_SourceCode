// Win1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

//FORWARD declare WndProc
//�������ں���ԭ��
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
//---------------------------------------------------------------------------------------------
//������
int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE PreInstance,
				   LPSTR lpCmdLine,
				   int nCmdShow)
{
	HWND hwnd;
	MSG  msg;
	char lpszClassName[]="����";
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

	RegisterClass(&wc);

	hwnd=CreateWindow(	lpszClassName,
						"Windows",
						WS_OVERLAPPEDWINDOW,
						120,50,800,600,
						NULL,
						NULL,
						hInstance,
						NULL);

	ShowWindow(hwnd,nCmdShow);
	UpdateWindow(hwnd);

	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

//------------------------------------------------------
//WndProc
//������Ϣ�Ĵ��ں���
LRESULT CALLBACK WndProc(HWND hwnd,
						 UINT message,
						 WPARAM wParam,
						 LPARAM lParam)
{
	switch(message)
	{
	case WM_LBUTTONDOWN:                               //������������Ϣ
		{
			MessageBeep(0);                            //���������ģ��Уɺ���
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd,message,wParam,lParam);
	}
	return 0;
}
//-----------------------------------------------------------------------------------------

