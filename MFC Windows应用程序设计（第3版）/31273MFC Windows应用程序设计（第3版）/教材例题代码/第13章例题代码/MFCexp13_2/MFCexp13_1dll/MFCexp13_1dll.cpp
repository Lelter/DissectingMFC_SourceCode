#include <windows.h>
BOOL APIENTRY DllMain( 	HANDLE hModule, 
                       		DWORD  ul_reason_for_call, 
                       		LPVOID lpReserved )
{
    return TRUE;
}
int ShowHello(void)			//��Ҫ�����ĺ���
{
	MessageBox(NULL,"Hello World!","",MB_YESNO);
	return TRUE;
}
