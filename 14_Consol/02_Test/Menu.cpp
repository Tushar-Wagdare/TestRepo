//*** Windows Header Files ***
#include<windows.h>
#include<CommCtrl.h>

#include"Resource.h"
#include<stdio.h>
#include<iostream>


using namespace std;


//*** Globle Function Declarations ***
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

BOOL isConsoleRunning = FALSE;


void fireConsole(void)
{
	if (!AllocConsole())
	{
		return;
	}
	else
	{
		isConsoleRunning = TRUE;
	}
}

void RedirectStream(void)
{
	if (!isConsoleRunning)
	{
		return;
	}

	HANDLE hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hStdInput = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hStdErr = GetStdHandle(STD_ERROR_HANDLE);

	HANDLE hConsoleOut = CreateFile("CONOUT$", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hConsoleOut == INVALID_HANDLE_VALUE)
	{
		return;
	}

	HANDLE hConsolein = CreateFile("CONOUT$", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hConsolein == INVALID_HANDLE_VALUE)
	{
		return;
	}

	if (!SetStdHandle(STD_OUTPUT_HANDLE, hConsoleOut))
	{
		return;
	}

	HANDLE hDuplicateStdOutput;
	DuplicateHandle(GetCurrentProcess(), hStdOutput, GetCurrentProcess(), &hDuplicateStdOutput, 0, TRUE, DUPLICATE_SAME_ACCESS);

	if (!SetStdHandle(STD_ERROR_HANDLE, hConsoleOut))
	{
		return;
	}

	HANDLE hDuplicateStdError;
	DuplicateHandle(GetCurrentProcess(), hStdErr, GetCurrentProcess(), &hDuplicateStdError, 0, TRUE, DUPLICATE_SAME_ACCESS);
	if (freopen("CONIN$", "r", stdin) == NULL | freopen("CONOUT$", "w", stdout) == NULL | freopen("CONOUT$", "w", stderr) == NULL)
	{
		return;
	}

	SetConsoleMode(hConsoleOut, ENABLE_PROCESSED_OUTPUT | ENABLE_WRAP_AT_EOL_OUTPUT);
	CloseHandle(hDuplicateStdOutput);
	CloseHandle(hDuplicateStdError);

	return;
}


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
	wndclass.lpszMenuName  = MAKEINTRESOURCE(IDR_MENU);
	//wndclass.lpszMenuName  = NULL;
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


	//*** SHOW THE WINDOW ***
	ShowWindow(hwnd, iCmdShow);


	//*** PAINT/REDROW THE WINDOW ***
	UpdateWindow(hwnd);


	//*** MESSAGE LOOP ***
	int fps = 0;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (isConsoleRunning)
		{
			//std::cout << fps << std::endl;
		}
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		fps++;
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

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDM_FILE_EXIT:
			PostMessage(hwnd, WM_CLOSE, 0, 0);
			break;

		case IDM_TEST:
		{
			std::cout << "Test Output To cout" << std::endl;
			std::cerr << "Test output to cerr" << std::endl;
			std::clog << "Test output to clog" << std::endl;

			std::cout << "Enter an integer to Test cin" << std::endl;
			int iVar;
			std::cin >> iVar;
			std::cout << "You Have Entered " << iVar << std::endl;

			return(0);
		}
		break;

		case IDM_OPEN_CONSOLE:
			if (!isConsoleRunning)
			{
				fireConsole();
				RedirectStream();
			}
			break;

		case IDM_OPEN_RC:
			system("Resource.rc");
			break;

		case IDM_OPEN_H:
			system("Resource.h");
			break;

		case IDM_CLOSE:
			FreeConsole();
			isConsoleRunning = FALSE;
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
