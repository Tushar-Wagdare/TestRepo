//*** Windows Header Files ***
#include<windows.h>
#include<CommCtrl.h>



//*** Globle Function Declarations ***
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);     //CALLBACK he calling convetion ahe ani te right to left aste


HWND hwndStatusBar;


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

	hwndStatusBar = CreateWindowEx(0,
		STATUSCLASSNAME,
		NULL,
		WS_CHILD | WS_VISIBLE | SBS_SIZEGRIP,
		0, 0,
		0, 0,
		hwnd,
		NULL,
		NULL,
		NULL);

	//Desired width        100  100  100  100
	int iStatusWidth[4] = {100, 200, 300, 400};
	SendMessage(hwndStatusBar, SB_SETPARTS, 4, (LPARAM)iStatusWidth);
 	SendMessage(hwndStatusBar, SB_SETTEXT, 0, (LPARAM)"Colomn 1");
	SendMessage(hwndStatusBar, SB_SETTEXT, 1, (LPARAM)"Colomn 2");
	SendMessage(hwndStatusBar, SB_SETTEXT, 2, (LPARAM)"Colomn 3");
	SendMessage(hwndStatusBar, SB_SETTEXT, 3, (LPARAM)"Colomn 4");


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
		SendMessage(hwndStatusBar, WM_SIZE, 0, 0);
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


	case WM_DESTROY:
		PostQuitMessage(0);
		break;


	default:
		break;
	}


	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
