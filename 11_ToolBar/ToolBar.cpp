//*** Windows Header Files ***
#include <windows.h>
#include <CommCtrl.h>
#include "Resource.h"	



//*** Globle Function Declarations ***
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);     


//Global Variable Declaration
HWND hwndToolBar = NULL;



//*** Enrty-point Function ***
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//*** Local Variable Declarations ***
	WNDCLASSEX wndclass;
	HWND hwnd = NULL;
	MSG msg;
	TCHAR szAppName[] = TEXT("Tushar_Wagdare_Chi_Window");


	//*** Code ***
	//*** WNDCLASSEX INITIALIZATION ***
	wndclass.cbSize        = sizeof(WNDCLASSEX);
	wndclass.style         = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra    = 0;
	wndclass.cbWndExtra    = 0;
	wndclass.lpfnWndProc   = WndProc;
	wndclass.hInstance     = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName  = NULL;
	wndclass.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);


	//*** REGISTER WNDCLASSEX ***
	RegisterClassEx(&wndclass);


	//*** CREATE WINDOW ***
	hwnd = CreateWindow(szAppName,
		TEXT("Tushar Tulshiram Wagdare"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	TBBUTTON buttons[3];
	TBADDBITMAP tbab;

	hwndToolBar = CreateWindowEx(0,
		TOOLBARCLASSNAME,
		NULL,
		WS_CHILD | WS_VISIBLE | TBSTYLE_WRAPABLE,
		0, 0,
		0, 0,
		hwnd,
		nullptr,
		nullptr,
		nullptr);

	SendMessage(hwndToolBar, TB_BUTTONSTRUCTSIZE, (WPARAM)sizeof(TBBUTTON), 0);
	SendMessage(hwndToolBar, TB_SETBITMAPSIZE, 0, (LPARAM)MAKELONG(20,20));

	tbab.hInst = HINST_COMMCTRL;
	//tbab.nID = IDB_TOOLBARBITMAP;
	tbab.nID = IDB_STD_SMALL_COLOR;

	SendMessage(hwndToolBar, TB_ADDBITMAP, 0, (LPARAM)&tbab);

	ZeroMemory(buttons, sizeof(TBBUTTON));

	buttons[0].iBitmap = STD_FILENEW;
	buttons[0].idCommand = TB_TEST1;
	buttons[0].fsState = TBSTATE_ENABLED;
	buttons[0].fsStyle = BTNS_BUTTON;

	buttons[1].fsState = STD_FILESAVE;
	buttons[1].idCommand = TB_TEST2;
	buttons[1].fsState = TBSTATE_ENABLED;
	buttons[1].fsStyle = BTNS_BUTTON;

	buttons[2].iBitmap = STD_FILEOPEN;
	buttons[2].idCommand = TB_TEST3;
	buttons[2].fsState = TBSTATE_ENABLED;
	buttons[2].fsStyle = BTNS_BUTTON;

	SendMessage(hwndToolBar, TB_ADDBUTTONS, sizeof(buttons)/sizeof(TBBUTTON), (LPARAM)&buttons);


	//*** SHOW THE WINDOW ***
	ShowWindow(hwnd, iCmdShow);


	//*** PAINT/REDROW THE WINDOW ***
	UpdateWindow(hwnd);


	//*** MESSAGE LOOP ***
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}


	return((int)msg.wParam);
}

//*** CALLBACK FUNCTION ***
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//*** Code ***
	switch (iMsg)
	{
	case WM_CREATE:
		break;


	case WM_SIZE:
		//hwndToolBar = GetDlgItem(hwnd, IDC_MAIN_TOOL);
		break;


	case WM_KEYDOWN:
		switch (LOWORD(wParam))
		{
		case VK_ESCAPE:
			break;
		}
		break;


	case WM_CHAR:
		switch (LOWORD(wParam))
		{
		case 'F':
			break;
		}
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
			case TB_TEST1:
				MessageBox(hwndToolBar, TEXT("Button 1"), TEXT("Message"), MB_OK);
				break;
			case TB_TEST2:
				MessageBox(hwndToolBar, TEXT("Button 2"), TEXT("Message"), MB_OK);
				break;
			case TB_TEST3:
				MessageBox(hwndToolBar, TEXT("Button 3"), TEXT("Message"), MB_OK);
				break;
		}
		break;


	case WM_DESTROY:
		PostQuitMessage(0);
		break;


	default:
		break;
	}


	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
