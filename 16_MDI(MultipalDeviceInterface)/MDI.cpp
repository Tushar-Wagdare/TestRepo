//*** Windows Header Files ***
#include<windows.h>
#include<CommCtrl.h>

#include"Resource.h"



//*** Globle Function Declarations ***
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK ChildProc(HWND, UINT, WPARAM, LPARAM);



//*** Global Variable Declaration
HWND hwndClient        = NULL;
TCHAR szMainAppName[]  = TEXT("Main Window Class");
TCHAR szChildAppName[] = TEXT("Child Window Class");
HINSTANCE hInst;


//*** Enrty-point Function ***
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	InitCommonControls();
	//*** Local Variable Declarations ***
	WNDCLASSEX wndclass;
	MSG msg;
	HWND hwnd              = NULL;
	hInst = hInstance;


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
	wndclass.lpszClassName = szMainAppName;
	wndclass.lpszMenuName  = MAKEINTRESOURCE(IDR_MENU);
	wndclass.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);


	//*** REGISTER WNDCLASSEX ***
	RegisterClassEx(&wndclass);

	//*** CREATE WINDOW ***
	hwnd = CreateWindow(szMainAppName,
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

	//*** WNDCLASSEX INITIALIZATION ***
	//wndclass.cbSize = sizeof(WNDCLASSEX);
	//wndclass.style = CS_HREDRAW | CS_VREDRAW;
	//wndclass.cbClsExtra = 0;
	//wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = ChildProc;
	//wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	//wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	//wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU);
	wndclass.lpszClassName = szChildAppName;
	wndclass.lpszMenuName = NULL;
	//wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);


	//*** REGISTER WNDCLASSEX ***
	RegisterClassEx(&wndclass);




	//*** MESSAGE LOOP ***
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateMDISysAccel(hwndClient, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}


	return((int)msg.wParam);
}




LRESULT CALLBACK ChildProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_CREATE:
		MessageBox(hwnd, TEXT("WM"), TEXT("Message"), MB_OK);
		break;
	default:
		break;
	}
	return(DefMDIChildProc(hwnd, iMsg, wParam, lParam));
}




//*** CALLBACK FUNCTION ***
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//*** Code ***
	switch (iMsg)
	{
	case WM_CREATE:
	{
		CLIENTCREATESTRUCT ccs;

		ccs.idFirstChild = ID_MDI_FIRSTCHILD;
		ccs.hWindowMenu = GetSubMenu((HMENU)IDR_MENU, 102);

		//*** CREATE WINDOW ***
		hwndClient = CreateWindowEx(
			WS_EX_CLIENTEDGE,
			"MDICLIENT",
			NULL,
			WS_CHILD | WS_CLIPCHILDREN | WS_HSCROLL | WS_VSCROLL,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			hwnd,
			(HMENU)IDR_MENU,
			hInst,
			(LPVOID)&ccs);

		if (!hwndClient)
		{
			MessageBox(hwnd, TEXT("Failed To Create Client Window"), TEXT("Message"), MB_OK);
		}
	}
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

			case IDM_ITEM3:
				MessageBox(NULL, TEXT("Menu Item Selected"), TEXT("Success"), MB_OK | MB_ICONSTOP);
				break;

			case IDM_FILE_NEW:
			{
				HWND hwndChild;
				CREATESTRUCT cs;
				ZeroMemory(&cs, sizeof(CREATESTRUCT));

				hwndChild = CreateWindowEx(
					WS_EX_MDICHILD,
					szChildAppName,
					TEXT("WS_EX_MDICHILD"),
					WS_OVERLAPPEDWINDOW,
					200,
					0,
					400,
					300,
					hwndClient,
					NULL,
					hInst,
					&cs);


				if (!hwndChild)
				{
					MessageBox(hwnd, TEXT("Failed To Create Child Window"), TEXT("Message"), MB_OK);
				}
				ShowWindow(hwndChild, SW_SHOW);
				UpdateWindow(hwndChild);
			}
			break;

			default:
				if (LOWORD(wParam) >= ID_MDI_FIRSTCHILD)
				{
					DefFrameProc(hwnd, hwndClient, iMsg, wParam, lParam);
				}
				else
				{
					HWND hChild;
					hChild = (HWND)SendMessage(hwndClient, WM_MDIGETACTIVE, 0, 0);
					if (hChild)
					{
						SendMessageA(hChild, WM_COMMAND, lParam, wParam);
					}
				}
		}
		return(0);

	break;



	case WM_DESTROY:
		PostQuitMessage(0);
		break;


	default:

		break;
	}


	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
