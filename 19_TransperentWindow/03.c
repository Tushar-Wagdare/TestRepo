//*** Windows Header Files ***
#include<windows.h>
#include<stdio.h>
#include<CommCtrl.h>

//*** Globle Function Declarations ***
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);     //CALLBACK he calling convetion ahe ani te right to left aste

//*** Local Variable Declaration ***
HDC hdc;
PAINTSTRUCT ps;
RECT rc;
TCHAR str[] = TEXT("Hello World !!!");
BOOL gbActive = FALSE;
HWND hwnd;
HWND staticTextHandle_01;
COLORREF rgb = RGB(0, 0, 0);


//*** Enrty-point Function ***
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	void display(void);


	//*** Local Variable Declarations ***
	WNDCLASSEX wndclass;
	MSG msg;
	BOOL bDone = FALSE;
	TCHAR szAppName[] = TEXT("Tushar_Wagdare_Chi_Window");

	float winWidth, winHeight;

	winWidth = GetSystemMetrics(SM_CXSCREEN);
	winHeight = GetSystemMetrics(SM_CYSCREEN);

	//*** Code ***
	//*** WNDCLASSEX INITIALIZATION ***
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//*** REGISTER WNDCLASSEX ***
	RegisterClassEx(&wndclass);

	//*** CREATE WINDOW ***
	hwnd = CreateWindowEx(WS_EX_LAYERED,
		szAppName,
		TEXT("Cheack Box Exampal"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	DWORD dwStyle;
	WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) };
	MONITORINFO mi = { sizeof(MONITORINFO) };

	dwStyle = GetWindowLong(hwnd, GWL_STYLE);
	if (dwStyle & WS_OVERLAPPEDWINDOW)
	{
		if (GetWindowPlacement(hwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(hwnd, MONITORINFOF_PRIMARY), &mi))
		{
			SetWindowLong(hwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);
			SetWindowPos(hwnd, HWND_TOP, 710, 20, 500, 150, SWP_NOZORDER | SWP_FRAMECHANGED);  //bringin WS_OVERLAPPEDWINDOW
		}
	}
	if (!SetLayeredWindowAttributes(hwnd, rgb, 10, LWA_COLORKEY | LWA_ALPHA))
	{
		exit(0);
	}
	//----- Static Text -----
	staticTextHandle_01 = CreateWindowEx(0,
		WC_STATIC,
		TEXT("aaa"),
		WS_CHILD | WS_VISIBLE,
		0, 0,
		450, 150,
		hwnd,
		NULL,
		NULL,
		NULL);

	HFONT hFont;
	hFont = CreateFont(150, 100, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, NULL);
	SendMessage(staticTextHandle_01, WM_SETFONT, (WPARAM)hFont, TRUE);

	//*** SHOW THE WINDOW ***
	ShowWindow(hwnd, iCmdShow);

	//*** PAINT/REDROW THE WINDOW ***
	UpdateWindow(hwnd);

	//*** Game LOOP ***
	while (bDone == FALSE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))       //PM_REMOVE - message queue rikama karto
		{
			if (msg.message == WM_QUIT)
				bDone = TRUE;
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			if (gbActive == TRUE)
			{
				//*** Render ***
				display();
			}
		}
	}

	return((int)msg.wParam);

}

//*** CALLBACK FUNCTION ***
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//*** Code ***
	switch (iMsg)
	{
	case WM_SETFOCUS:
		gbActive = TRUE;
		break;

	case WM_KILLFOCUS:
		gbActive = FALSE;
		break;

	case WM_PAINT:
		/*GetClientRect(hwnd, &rc);
		hdc = BeginPaint(hwnd, &ps);*/
		break;

	case WM_KEYDOWN:
		switch (LOWORD(wParam))
		{
		case VK_ESCAPE:
			DestroyWindow(hwnd);
			break;
		}
		break;

	case WM_DESTROY:
		//EndPaint(hwnd, &ps);
		PostQuitMessage(0);
		break;

	default:
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));

}


void display(void)
{
	SYSTEMTIME sysTime;

	GetLocalTime(&sysTime);
	/*SetBkColor(hdc, RGB(255, 255, 255));
	SetTextColor(hdc, RGB(0, 0, 0));

	if (sysTime.wHour > 12)
	{
		sprintf(str, "%d:%d:%d", sysTime.wHour - 12, sysTime.wMinute, sysTime.wSecond);
	}
	else
	{
		sprintf(str, "%d:%d:%d", sysTime.wHour, sysTime.wMinute, sysTime.wSecond);
	}

	DrawText(hdc, str, -1, &rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER);*/

	if (sysTime.wHour > 12)
	{
		sprintf(str, "%d:%d", sysTime.wHour - 12, sysTime.wMinute);
	}
	else
	{
		sprintf(str, "%d:%d", sysTime.wHour, sysTime.wMinute);
	}

	
	if ((sysTime.wSecond % 10) == 0)
	{
		SendMessage(staticTextHandle_01, WM_SETTEXT, 0, (LPARAM)str);
		UpdateWindow(hwnd);
		UpdateWindow(staticTextHandle_01);
	}
	

}


