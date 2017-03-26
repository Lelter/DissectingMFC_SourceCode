// Win2.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

//�������ں���ԭ��
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
//---------------------------------------------------------------------------------------------
//������
int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE PreInstance,
				   LPSTR lpCmdLine,
				   int nCmdShow)
{
	HWND hwnd1;						//Windows1�Ĵ��ھ��
	HWND hwnd2;						//Windows2�Ĵ��ھ��
	HWND hwnd3;						//Windows3�Ĵ��ھ��

	MSG  msg;

//���塢ע�ᴰ����"����1"
	char lpszClassName1[]="����1";
	WNDCLASS wc1;
	wc1.style=0;
	wc1.lpfnWndProc=WndProc;
	wc1.cbClsExtra=0;
	wc1.cbWndExtra=0;
	wc1.hInstance=hInstance;
	wc1.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	wc1.hCursor=LoadCursor(NULL,IDC_ARROW);
	wc1.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);//��ɫ
	wc1.lpszMenuName=NULL;
	wc1.lpszClassName=lpszClassName1;

	RegisterClass(&wc1);
	
	//���塢ע�ᴰ����"����2"
	char lpszClassName2[]="����2";
	WNDCLASS wc2;
	wc2.style=0;
	wc2.lpfnWndProc=WndProc;
	wc2.cbClsExtra=0;
	wc2.cbWndExtra=0;
	wc2.hInstance=hInstance;
	wc2.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	wc2.hCursor=LoadCursor(NULL,IDC_ARROW);
	wc2.hbrBackground=(HBRUSH)GetStockObject(GRAY_BRUSH);//��ɫ
	wc2.lpszMenuName=NULL;
	wc2.lpszClassName=lpszClassName2;

	RegisterClass(&wc2);

	hwnd1=CreateWindow(	lpszClassName1,	//����Windows1����
						"Windows1",
						WS_OVERLAPPEDWINDOW,
						120,50,700,500,
						NULL,
						NULL,
						hInstance,
						NULL);

	hwnd2=CreateWindow(	lpszClassName2,	//����Windows2����
						"Windows2",
						WS_OVERLAPPEDWINDOW,
						150,80,750,550,
						NULL,
						NULL,
						hInstance,
						NULL);

	hwnd3=CreateWindow(	lpszClassName1,	//����Windows3����
						"Windows3",
						WS_OVERLAPPEDWINDOW,
						200,130,500,300,,
						NULL,
						NULL,
						hInstance,
						NULL);

	ShowWindow(hwnd1,nCmdShow);		//��ʾWindows1
	UpdateWindow(hwnd1);

	ShowWindow(hwnd2,nCmdShow);		//��ʾWindows2
	UpdateWindow(hwnd2);

	ShowWindow(hwnd3,nCmdShow);		//��ʾWindows3
	UpdateWindow(hwnd3);

	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
//---------------------------------------------------------------------------------------------
//������Ϣ�Ĵ��ں���
LRESULT CALLBACK WndProc(HWND hwnd,
						 UINT message,
						 WPARAM wParam,
						 LPARAM lParam)
{
	switch(message)
	{
	case WM_LBUTTONDOWN:   //������������Ϣ
		{
			MessageBeep(0);
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


