//*** Windows Header Files ***
#include<windows.h>
#include<CommCtrl.h>



//*** Globle Function Declarations ***
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);     



//*** Local Variable Declarations ***
HWND hwndHScroolBar = NULL;
HWND hwndVScroolBar = NULL;
	


//*** Enrty-point Function ***
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	InitCommonControls();

	//*** Code ***
	HWND hwnd           = NULL;
	MSG msg;
	TCHAR szAppName[]   = TEXT("Tushar_Wagdare_Chi_Window");
	WNDCLASSEX wndclass;


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


	RECT desktopRect;
	GetClientRect(hwnd, &desktopRect);
	int scroolBArWidth = 15;
	int scroolBarHeight = 15;

	hwndVScroolBar = CreateWindowEx(0,
		WC_SCROLLBAR,
		NULL,
		WS_CHILD | WS_VISIBLE | SBS_VERT,
		desktopRect.right - scroolBArWidth,0,
		scroolBArWidth,desktopRect.bottom - scroolBarHeight,
		hwnd,
		nullptr,
		nullptr,
		nullptr);

	hwndHScroolBar = CreateWindowEx(0,
		WC_SCROLLBAR,
		NULL,
		WS_CHILD | WS_VISIBLE | SBS_HORZ,
		0, desktopRect.bottom - scroolBarHeight,
		desktopRect.right - scroolBArWidth, scroolBarHeight,
		hwnd,
		nullptr,
		nullptr,
		nullptr);

	SetScrollRange(hwndVScroolBar, SB_CTL, 0, 100, TRUE);
	SetScrollRange(hwndHScroolBar, SB_CTL, 0, 100, TRUE);


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
		SCROLLINFO si;
		si.cbSize = sizeof(SCROLLINFO);
		si.fMask = SIF_PAGE;
		si.nPage = LOWORD(lParam);
		SetScrollInfo(hwnd, SB_HORZ, &si, FALSE);

		RECT rc;
		GetClientRect(hwnd, &rc);
		si.nPage = rc.bottom - rc.top;

		SetScrollInfo(hwnd, SB_VERT, &si, TRUE);
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
		switch (LOWORD(wParam))
		{
		case SB_LINEUP:
			SetScrollPos((HWND)lParam, SB_CTL, 0, TRUE);
			break;

		case SB_LINEDOWN:
			SetScrollPos((HWND)lParam, SB_CTL, 100, TRUE);
			break;
		}
		break;

	case WM_VSCROLL:
		switch (LOWORD(wParam))
		{
		case SB_LINEUP:
			SetScrollPos((HWND)lParam, SB_CTL, 0, TRUE);
			break;

		case SB_LINEDOWN:
			SetScrollPos((HWND)lParam, SB_CTL, 100, TRUE);
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
