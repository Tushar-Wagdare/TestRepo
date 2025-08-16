//*** Windows Header Files ***
#include<windows.h>
#include<CommCtrl.h>


#include"Resource.h"


//*** Globle Function Declarations ***
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);   
LRESULT CALLBACK splashScreenWndProc(HWND, UINT, WPARAM, LPARAM);

//*** Local Variable Declarations ***
WNDCLASSEX wndclass;
WNDCLASSEX splashWindowClass;
HWND hwnd = NULL;
HBITMAP hSplashScreenBmp;
HWND splashScreenhwnd = NULL;
MSG msg;
TCHAR szAppName[] = TEXT("Tushar_Wagdare_Chi_Window");

TCHAR splashScreenWindowClassName[] = TEXT("SplashScreenWindowClass");
HDC hSplashScreenDC;
HDC hMemoryDC;

BITMAP bitmap;


//*** Enrty-point Function ***
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
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


	splashWindowClass.cbSize        = sizeof(WNDCLASSEX);
	splashWindowClass.style         = 0;
	splashWindowClass.cbClsExtra    = 0;
	splashWindowClass.cbWndExtra    = 0;
	splashWindowClass.lpfnWndProc   = (WNDPROC)splashScreenWndProc;
	splashWindowClass.hInstance     = hInstance;
	splashWindowClass.hIcon         = NULL;
	splashWindowClass.hIconSm       = NULL;
	splashWindowClass.hCursor       = LoadCursor(NULL, IDC_ARROW);
	splashWindowClass.lpszClassName = splashScreenWindowClassName;
	splashWindowClass.lpszMenuName  = NULL;
	splashWindowClass.hbrBackground = NULL;


	//*** REGISTER WNDCLASSEX ***
	if (!RegisterClassEx(&splashWindowClass))
	{
		MessageBox(NULL, TEXT("Failed To Register Splash Window Class"), TEXT("Error"), MB_OK | MB_ICONERROR);
		return(0);
	}
	
	

	RECT DesktopRect;
	GetWindowRect(GetDesktopWindow(), &DesktopRect);

	hSplashScreenBmp = LoadBitmap(hInstance, MAKEINTRESOURCE(SPLASHSCREEN_ID));
	if (!hSplashScreenBmp)
	{
		MessageBox(NULL, TEXT("Failed To Load BMP"), TEXT("Error"), MB_OK | MB_ICONERROR);
		return(0);
	}

	
	GetObject(hSplashScreenBmp, sizeof(BITMAP), &bitmap);
	

	splashScreenhwnd = CreateWindowEx(0,
		splashScreenWindowClassName,
		TEXT("SplashScreen"),
		WS_POPUP,
		(DesktopRect.right - bitmap.bmWidth) / 2,
		(DesktopRect.bottom - bitmap.bmHeight) / 2,
		bitmap.bmWidth,
		bitmap.bmHeight,
		NULL,
		NULL,
		hInstance,
		NULL);


	hSplashScreenDC = GetDC(splashScreenhwnd);
	hMemoryDC = CreateCompatibleDC(hSplashScreenDC);
	SelectObject(hMemoryDC, (HGDIOBJ)hSplashScreenBmp);
	
	ShowWindow(splashScreenhwnd, SW_SHOW);
	UpdateWindow(splashScreenhwnd);

	//*** SHOW THE WINDOW ***
	//ShowWindow(hwnd, iCmdShow);


	//*** PAINT/REDROW THE WINDOW ***
	//UpdateWindow(hwnd);


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


	case WM_DESTROY:
		PostQuitMessage(0);
		break;


	default:
		break;
	}


	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

LRESULT CALLBACK splashScreenWndProc(HWND hwnd_Splash, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_ERASEBKGND:
		BitBlt((HDC)wParam, 0, 0, bitmap.bmWidth, bitmap.bmHeight, hMemoryDC, 0, 0, SRCCOPY);
		break;

		case WM_LBUTTONDOWN:
			DeleteObject(hSplashScreenBmp);
			ReleaseDC(hwnd_Splash, hSplashScreenDC);
			ReleaseDC(hwnd_Splash, hMemoryDC);
			DestroyWindow(hwnd_Splash);

			ShowWindow(hwnd, SW_SHOW);
			UpdateWindow(hwnd);
			SetForegroundWindow(hwnd);
			break;

		default:
			break;
	}

	return(DefWindowProc(hwnd_Splash, iMsg, wParam, lParam));
}
