//*** Windows Header Files ***
#include<windows.h>
#include<CommCtrl.h>

#include"Resource.h"



//*** Globle Function Declarations ***
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);   



//*** Global Variable Declaration
HWND hwnd;
HWND radioButtonHandle[6];

HWND groupBoxHandle_01;
HWND groupBoxHandle_02;


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
	/*hwnd = CreateWindow(szAppName,
		TEXT("Tushar Tulshiram Wagdare"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);*/

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,
		szAppName,
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


	groupBoxHandle_01 = CreateWindowEx(
		0,
		TEXT("BUTTON"),
		TEXT("Group Box 1"),
		WS_VISIBLE | WS_CHILD | BS_GROUPBOX,
		50, 10,
		250, 400,
		hwnd,
		NULL,
		hInstance,
		NULL
	);

	groupBoxHandle_02 = CreateWindowEx(
		0,
		TEXT("BUTTON"),
		TEXT("Group Box 2"),
		WS_VISIBLE | WS_CHILD | BS_GROUPBOX,
		350, 10,
		250, 400,
		hwnd,
		NULL,
		hInstance,
		NULL
	);



	//Radio Button
	radioButtonHandle[0] = CreateWindowEx(0,
		WC_BUTTON,
		TEXT("RadioButton"),
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP,
		50, 50,
		150, 50,
		groupBoxHandle_01,
		(HMENU)IDB_RADIO01,
		nullptr,
		nullptr);

	radioButtonHandle[1] = CreateWindowEx(0,
		WC_BUTTON,
		TEXT("RadioButton"),
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP,
		50, 150,
		150, 50,
		groupBoxHandle_01,
		(HMENU)IDB_RADIO02,
		nullptr,
		nullptr);

	radioButtonHandle[2] = CreateWindowEx(0,
		WC_BUTTON,
		TEXT("RadioButton"),
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP,
		50, 250,
		150, 50,
		groupBoxHandle_01,
		(HMENU)IDB_RADIO03,
		nullptr,
		nullptr);
		
	//-----------------------------------------

	radioButtonHandle[3] = CreateWindowEx(0,
		WC_BUTTON,
		TEXT("RadioButton"),
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP,
		50, 50,
		150, 50,
		groupBoxHandle_02,
		(HMENU)IDB_RADIO04,
		nullptr,
		nullptr);

	radioButtonHandle[4] = CreateWindowEx(0,
		WC_BUTTON,
		TEXT("RadioButton"),
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP,
		50, 150,
		150, 50,
		groupBoxHandle_02,
		(HMENU)IDB_RADIO05,
		nullptr,
		nullptr);

	SendMessage(radioButtonHandle[2], BM_SETCHECK, BST_CHECKED, 0);
	


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

	case WM_COMMAND:
	{
		MessageBox(NULL, TEXT("Checked 1!"), TEXT("Message"), MB_OK);
		//Cheak if the message is from a radio button
		if (LOWORD(wParam) >= IDB_RADIO01 && LOWORD(wParam) <= IDB_RADIO05)
		{
			//Identify the selected radio button
			int selectedButtonId = LOWORD(wParam);

			//Handle the selection based on button id
			switch (selectedButtonId)
			{
			case IDB_RADIO01:
				MessageBox(NULL, TEXT("Checked 1!"), TEXT("Message"), MB_OK);
				break;

			case IDB_RADIO02:
				MessageBox(NULL, TEXT("Checked 2!"), TEXT("Message"), MB_OK);
				break;

			case IDB_RADIO03:
				MessageBox(NULL, TEXT("Checked 3!"), TEXT("Message"), MB_OK);
				break;

			case IDB_RADIO04:
				MessageBox(NULL, TEXT("Checked 4!"), TEXT("Message"), MB_OK);
				break;

			case IDB_RADIO05:
				MessageBox(NULL, TEXT("Checked 5!"), TEXT("Message"), MB_OK);
				break;
			}
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
