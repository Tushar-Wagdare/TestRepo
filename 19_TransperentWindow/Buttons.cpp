//*** Windows Header Files ***
#include<windows.h>
#include <CommCtrl.h>


HWND hwnd              = NULL;
HWND buttonHandle_01   = NULL;
HWND buttonHandle_02   = NULL;
HWND checkBoxHandle_01 = NULL;
HWND checkBoxHandle_02 = NULL;
HWND checkBoxHandle_03 = NULL;
HWND checkBoxHandle_04 = NULL;
HWND checkBoxHandle_05 = NULL;
// UI Related Variables
int spacing            = 25;
int buttonX            = 50;
int buttonY            = 50;
int buttonWidth        = 130;
int buttonHeight       = 100;


//*** Globle Function Declarations ***
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);     //CALLBACK he calling convetion ahe ani te right to left aste

//*** Enrty-point Function ***
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//*** Local Variable Declarations ***
	WNDCLASSEX wndclass;
	MSG msg;
	TCHAR szAppName[] = TEXT("Tushar_Wagdare_Chi_Window");
	
	

	//MessageBox(hwnd, TEXT("MB"), TEXT("Message !"), MB_OK);

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
	hwnd = CreateWindowEx(WS_EX_APPWINDOW | WS_EX_LAYERED,
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


	COLORREF rgb = RGB(0,0,0);

	
	if (!SetLayeredWindowAttributes(hwnd, rgb, 10, LWA_ALPHA))
	{
		exit(0);
	}

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
		//MessageBox(hwnd, TEXT("WM_CREATE Arrived !"), TEXT("Message"), MB_OK);
		break;

	case WM_SIZE:
		//MessageBox(hwnd, TEXT("WM_SIZE Arrived !"), TEXT("Message !"), MB_OK);
		break;

	case WM_KEYDOWN:
		switch (LOWORD(wParam))
		{
		case VK_ESCAPE:
			//MessageBox(hwnd, TEXT("WM_KEYDOWN-VK Arrived !"), TEXT("Message !"), MB_OK);
			break;
		}
		break;

	case WM_CHAR:
		switch (LOWORD(wParam))
		{	
		}
		break;

	case WM_COMMAND:
		if (lParam == (LPARAM)buttonHandle_01)
		{
			MessageBox(hwnd, TEXT("BottonHandle_01 Pressed"), TEXT("Message"), MB_OK);
		}
		else if (lParam == (LPARAM)buttonHandle_02)
		{
			
		}
		else if (lParam == (LPARAM)checkBoxHandle_01)
		{
			
		}
		else if (lParam == (LPARAM)checkBoxHandle_02)
		{
			int checkBoxState = SendMessage(checkBoxHandle_02, BM_GETCHECK, 0, 0);

			switch (checkBoxState)
			{
			case BST_UNCHECKED:
				MessageBox(hwnd, TEXT("checkBoxHandle_02 Is Unchecked"), TEXT("Message"), MB_OK);
				break;

			case BST_CHECKED:
				MessageBox(hwnd, TEXT("checkBoxHandle_02 Is Checked"), TEXT("Message"), MB_OK);
				break;
			}
		}
		else if (lParam == (LPARAM)checkBoxHandle_03)
		{
			int checkBoxState = SendMessage(checkBoxHandle_03, BM_GETCHECK, 0, 0);

			switch (checkBoxState)
			{
			case BST_UNCHECKED:
				MessageBox(hwnd, TEXT("checkBoxHandle_03 Is Unchecked"), TEXT("Message"), MB_OK);
				break;

			case BST_INDETERMINATE:
				MessageBox(hwnd, TEXT("checkBoxHandle_03 Is INDETERMINATE"), TEXT("Message"), MB_OK);
				break;

			case BST_CHECKED:
				MessageBox(hwnd, TEXT("checkBoxHandle_03 Is Checked"), TEXT("Message"), MB_OK);
				break;
			}
		}
		else if (lParam == (LPARAM)checkBoxHandle_04)
		{
			int checkBoxState = SendMessage(checkBoxHandle_04, BM_GETCHECK, 0, 0);

			switch (checkBoxState)
			{
			case BST_UNCHECKED:
				MessageBox(hwnd, TEXT("checkBoxHandle_04 Is Unchecked"), TEXT("Message"), MB_OK);
				break;

			case BST_CHECKED:
				MessageBox(hwnd, TEXT("checkBoxHandle_04 Is Checked"), TEXT("Message"), MB_OK);
				break;
			}
		}
		else if (lParam == (LPARAM)checkBoxHandle_05)
		{
			int checkBoxState = SendMessage(checkBoxHandle_05, BM_GETCHECK, 0, 0);

			switch (checkBoxState)
			{
			case BST_UNCHECKED:
				MessageBox(hwnd, TEXT("checkBoxHandle_05 Is Unchecked"), TEXT("Message"), MB_OK);
				break;

			case BST_INDETERMINATE:
				MessageBox(hwnd, TEXT("checkBoxHandle_05 Is INDETERMINATE"), TEXT("Message"), MB_OK);
				break;

			case BST_CHECKED:
				MessageBox(hwnd, TEXT("checkBoxHandle_05 Is Checked"), TEXT("Message"), MB_OK);
				break;
			}
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


