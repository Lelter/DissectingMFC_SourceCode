// Demo1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

//FORWARD declare WndProc
//声明窗口函数原型
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
//---------------------------------------------------------------------------------------------
//主函数
int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE PreInstance,
				   LPSTR lpCmdLine,
				   int nCmdShow)
{
	HWND hwnd;		//定义窗口句柄
	MSG  msg;
	char lpszClassName[]="窗口";
	WNDCLASS wc;		//定义窗口变量
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
	
	RegisterClass(&wc);		//注册窗口类型
	
	hwnd=CreateWindow(	lpszClassName,		//创建窗口
		"Windows",
		WS_OVERLAPPEDWINDOW,
		120,50,800,600,
		NULL,
		NULL,
		hInstance,
		NULL);
	
	ShowWindow(hwnd,nCmdShow);		//显示窗口
	UpdateWindow(hwnd);
	
	while(GetMessage(&msg,NULL,0,0))		//消息循环
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

//------------------------------------------------------
//WndProc
//处理消息的窗口函数
LRESULT CALLBACK WndProc(HWND hwnd,
						 UINT message,
						 WPARAM wParam,
						 LPARAM lParam)
{
	switch(message)
	{
	case WM_LBUTTONDOWN:                               //鼠标左键按下消息
		{
			MessageBeep(0);                            //发出声音的ＡＰＩ函数
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


