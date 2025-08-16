//*** Windows Header Files ***
#include<windows.h>
#include<CommCtrl.h>


//*** Globle Function Declarations ***
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);     //CALLBACK he calling convetion ahe ani te right to left aste


//*** Global Variable Declaration
HWND hwnd              = NULL;
HWND trackBarHandle_01 = NULL;
HWND trackBarHandle_02 = NULL;
HWND trackBarHandle_03 = NULL;
HWND trackBarHandle_04 = NULL;
// UI Related Variables
int spacing            = 25;
int buttonX            = 50;
int buttonY            = 50;
int buttonWidth        = 150;
int buttonHeight       = 50;


//*** Enrty-point Function ***
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//*** Local Variable Declarations ***
	WNDCLASSEX wndclass;
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


	//--- TRACKBAR 01 ---//
	trackBarHandle_01 = CreateWindowEx(0,
		TRACKBAR_CLASS,
		TEXT("TrackBar"),
		WS_CHILD | TBS_HORZ | TBS_TOP | TBS_TOOLTIPS | TBS_TRANSPARENTBKGND | WS_VISIBLE,
		buttonX, buttonY,
		150, 50,
		hwnd,
		nullptr,
		nullptr,
		nullptr);
	SendMessage(trackBarHandle_01, TBM_SETRANGEMIN, 1, -100);
	SendMessage(trackBarHandle_01, TBM_SETRANGEMAX, 1, 100);
	SendMessage(trackBarHandle_01, TBM_SETPOS, 1, 50);


	//--- TRACKBAR 02 ---//
	trackBarHandle_02 = CreateWindowEx(0,
		TRACKBAR_CLASS,
		TEXT("TrackBar"),
		WS_CHILD | TBS_VERT | TBS_LEFT | TBS_NOTICKS | TBS_TOOLTIPS |WS_VISIBLE,
		buttonX + (spacing + buttonWidth) * 1, buttonY,
		50, 150,
		hwnd,
		nullptr,
		nullptr,
		nullptr);


	//--- TRACKBAR 03 ---//
	trackBarHandle_03 = CreateWindowEx(0,
		TRACKBAR_CLASS,
		TEXT("TrackBar"),
		WS_CHILD | TBS_HORZ | TBS_AUTOTICKS | TBS_TOOLTIPS | WS_VISIBLE,
		buttonX + (spacing + buttonWidth) * 2, buttonY,
		150, 50,
		hwnd,
		nullptr,
		nullptr,
		nullptr);


	//--- TRACKBAR 04 ---//
	trackBarHandle_04 = CreateWindowEx(0,
		TRACKBAR_CLASS,
		TEXT("TrackBar"),
		WS_CHILD | TBS_VERT | TBS_AUTOTICKS | TBS_TOOLTIPS | WS_VISIBLE,
		buttonX + (spacing + buttonWidth) * 3, buttonY,
		50, 150,
		hwnd,
		nullptr,
		nullptr,
		nullptr);


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


	case WM_HSCROLL:
		if (lParam == (LPARAM)trackBarHandle_01)
		{
			//MessageBox(hwnd, TEXT("Value Tracked For TrackBar_01"), TEXT("Message"), MB_OK);
		}
		break;


	case WM_VSCROLL:
		if (lParam == (LPARAM)trackBarHandle_02)
		{
			//MessageBox(hwnd, TEXT("Value Tracked For TrackBar_02"), TEXT("Message"), MB_OK);
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
