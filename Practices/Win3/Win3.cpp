// Win3.cpp : Defines the entry point for the application.
//

#include "stdafx.h"


//����ȫ�ֱ���--------------------------------------------------------------------------------
HINSTANCE		hInst;	
HWND 			hWnd;		
MSG			msg;
char lpszClassName[]="����";
char lpszClassName1[]="����1";
char lpszClassName2[]="����2";
char*ShowText;
//��������ԭ��--------------------------------------------------------------------------------------
ATOM			MyRegisterClass(HINSTANCE hInstance);//ע�ᴰ���ຯ��
ATOM            MyRegisterClass1(HINSTANCE hInstance);
ATOM            MyRegisterClass2(HINSTANCE hInstance);
BOOL			Create(HINSTANCE, int);     //����ʵ����ʼ������
int				Run();                          //��Ϣѭ������
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM); //���ں���

//��Ϣ������
void OnLButtonDown(HWND hWnd, UINT message, 
				WPARAM wParam, LPARAM lParam);
void OnPaint(HWND hWnd, UINT message, 
				WPARAM wParam, LPARAM lParam);
void OnDestroy(HWND hWnd, UINT message, 
				WPARAM wParam, LPARAM lParam);
//������-----------------------------------------------------------------------------------------
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	
	MyRegisterClass2(hInstance);        	//�����ע�ᴰ����
	//	MyRegisterClass(hInstance);
	Create(hInstance, nCmdShow);  		//��������
	ShowWindow(hWnd, nCmdShow);   	//��ʾ����
	UpdateWindow(hWnd);            	//������Ļ��ʾ
	return Run();                     	//��Ϣѭ��
}
//ע�ᴰ���ຯ����ʵ��--------------------------------------------------------------------------
ATOM MyRegisterClass(HINSTANCE hInstance)
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

ATOM MyRegisterClass1(HINSTANCE hInstance)
{
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
	return RegisterClass(&wc1);
}

ATOM MyRegisterClass2(HINSTANCE hInstance)
{
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

	return RegisterClass(&wc2);
}
//�������ں�����ʵ��-----------------------------------------------------------------------------
BOOL Create(HINSTANCE hInstance, int nCmdShow)
{
	hWnd=CreateWindow(	lpszClassName2,
						"Windows",
						WS_OVERLAPPEDWINDOW,
						200,130,500,300,
						NULL,
						NULL,
						hInstance,
						NULL);
//	hWnd=CreateWindow(	lpszClassName,"Windows",WS_OVERLAPPEDWINDOW,400,300,180,160,NULL,NULL,hInstance,NULL);
   return TRUE;
}
//��Ϣѭ��������ʵ��-----------------------------------------------------------------------------
int Run( )
{
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
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
	ShowText="Hello,Shirley!";
	InvalidateRect(hWnd,NULL,1);
}
void OnPaint(HWND hWnd, UINT message, 
				WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	TextOut(hdc,50,50,ShowText,14);
	EndPaint(hWnd, &ps);
}
void OnDestroy(HWND hWnd, UINT message, 
				WPARAM wParam, LPARAM lParam)
{
	PostQuitMessage(0);
}

//--------------------------------------------------------------------------------------------------


