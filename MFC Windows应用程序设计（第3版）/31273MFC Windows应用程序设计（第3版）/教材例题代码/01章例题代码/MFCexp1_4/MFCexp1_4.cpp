//���Windows������������ͷ�ļ�------------------------------------------------
#include<windows.h>
//����ȫ�ֱ���-------------------------------------------------------------------------------
HINSTANCE		hInst;	
HWND 			hWnd;		
MSG			msg;
char lpszClassName [ ]="����";
char*ShowText;

//��������ԭ��-------------------------------------------------------------------------------
ATOM			MyRegisterClass(HINSTANCE hInstance);//ע�ᴰ���ຯ��
BOOL			Create(HINSTANCE, int);  //����ʵ����ʼ������
int				Run( );                  //��Ϣѭ������

LRESULT CALLBACK	WndProc(			//���ں���
HWND, UINT, 
WPARAM, LPARAM);
 						
void OnLButtonDown(			// WM_LBUTTONDOWN��Ϣ������
HWND hWnd, 
UINT message, 
		WPARAM wParam, 
LPARAM lParam);

void OnPaint(					// WM_PAINT��Ϣ������
HWND hWnd, 
UINT message, 
		WPARAM wParam, 
LPARAM lParam);

void OnDestroy(				// WM_DESTROY��Ϣ������
HWND hWnd, 
UINT message, 
		WPARAM wParam, 
LPARAM lParam);

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
//ע�ᴰ���ຯ����ʵ��-------------------------------------------------------------
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
//�������ں�����ʵ��----------------------------------------------------------------------
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
//��Ϣѭ��������ʵ��----------------------------------------------------------------------
int Run( )
{
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
//���ں�����ʵ��-----------------------------------------------------------------------------
#define DECLARE_MESSAGE_MAP( ) \
struct MSGMAP_ENTRY  _messageEntres[ ];\

#define BEGIN_MESSAGE_MAP( ) \
struct MSGMAP_ENTRY  _messageEntres[ ] = \
{ \

#define ON_WM(messageID,msgFuc) \
	messageID,msgFuc,
#define END_MESSAGE_MAP( ) \
};\

void On_LButtonDown(HWND, UINT, WPARAM, LPARAM);
void On_Paint(HWND, UINT, WPARAM, LPARAM);
void On_Destroy(HWND, UINT, WPARAM, LPARAM);
struct MSGMAP_ENTRY
{
	UINT nMessage;
	void (*pfn)(HWND, UINT, WPARAM, LPARAM );
};

DECLARE_MESSAGE_MAP( )
BEGIN_MESSAGE_MAP( )
ON_WM(WM_LBUTTONDOWN,On_LButtonDown)
ON_WM(WM_PAINT,On_Paint)
ON_WM(WM_DESTROY,On_Destroy)
END_MESSAGE_MAP( )

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, 
WPARAM wParam, LPARAM lParam)
{
int i;
	int n = sizeof ( _messageEntres)/sizeof(_messageEntres[0] );
	for (i = 0; i < n; i ++)
	{
		if (message == _messageEntres [ i ] . nMessage )
			( *_messageEntres [ i ] . pfn )( hWnd, message, wParam, lParam);
	}
	
	return DefWindowProc(hWnd, message, wParam, lParam);
}


//������������Ϣ��������ʵ��---------------------------------------------------
void On_LButtonDown(HWND hWnd, UINT message, 
				WPARAM wParam, LPARAM lParam)
{
	ShowText="Hello!";
	InvalidateRect(hWnd,NULL,1);
}
//�ػ洰���û�ȥ��Ϣ��������ʵ��------------------------------------------------
void On_Paint(HWND hWnd, UINT message, 
				WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	TextOut(hdc,50,50,ShowText,6);
	EndPaint(hWnd, &ps);
}
//���ٴ�����Ϣ��������ʵ��----------------------------------------------------------
void On_Destroy(HWND hWnd, UINT message, 
				WPARAM wParam, LPARAM lParam)
{
	PostQuitMessage(0);
}
//----------------------------------------------------------------------------------------------
