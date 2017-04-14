
//���Windows������������ͷ�ļ�-------------------------------------------------
#include<windows.h>
//����ȫ�ֱ���--------------------------------------------------------------------------------
HINSTANCE		hInst;	
HWND 			hWnd;		
MSG			msg;
char lpszClassName[]="����";
char*ShowText;
//��������ԭ��--------------------------------------------------------------------------------------
ATOM			MyRegisterClass(HINSTANCE hInstance);//ע�ᴰ���ຯ��
BOOL			Create(HINSTANCE, int);     //����ʵ����ʼ������
int				Run();                          //��Ϣѭ������
LRESULT CALLBACK	WndProc(HWND, UINT, 
WPARAM, LPARAM); //���ں���
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
	
	MyRegisterClass(hInstance);        	//�����ע�ᴰ����
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
//�������ں�����ʵ��-----------------------------------------------------------------------------
BOOL Create(HINSTANCE hInstance, int nCmdShow)
{
	hWnd=CreateWindow(	lpszClassName,
						"Windows",
						WS_OVERLAPPEDWINDOW,
						400,300,180,160,
						NULL,
						NULL,
						hInstance,
						NULL);
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

//--------------------------------------------------------------------------------------------------