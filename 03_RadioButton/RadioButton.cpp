//*** Windows Header Files ***
#include<windows.h>
#include<CommCtrl.h>



//*** Globle Function Declarations ***
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);   



//*** Global Variable Declaration
HWND hwnd;
HWND radioButtonHandle[6];



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



	//Radio Button
	for (int i = 0; i < 5; i++)
	{
		radioButtonHandle[i] = CreateWindowEx(0,
			WC_BUTTON,
			TEXT("RadioButton"),
			WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
			50, 80 * i,
			150, 50,
			hwnd,
			nullptr,
			nullptr,
			nullptr);
	}

	radioButtonHandle[5] = CreateWindowEx(0,
		WC_BUTTON,
		TEXT("RadioButton"),
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | BS_PUSHLIKE,
		50, 80 * 5,
		150, 50,
		hwnd,
		nullptr,
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
		if (lParam == (LPARAM)radioButtonHandle[0])
		{
			MessageBox(radioButtonHandle[0], TEXT("Checked 1!"), TEXT("Message"), MB_OK);
		}
		else if (lParam == (LPARAM)radioButtonHandle[1])
		{
			MessageBox(radioButtonHandle[1], TEXT("Checked 2!"), TEXT("Message"), MB_OK);
		}
		else if (lParam == (LPARAM)radioButtonHandle[2])
		{
			MessageBox(radioButtonHandle[2], TEXT("Checked 3!"), TEXT("Message"), MB_OK);
		}
		else if (lParam == (LPARAM)radioButtonHandle[3])
		{
			MessageBox(radioButtonHandle[3], TEXT("Checked 4!"), TEXT("Message"), MB_OK);
		}
		else if (lParam == (LPARAM)radioButtonHandle[4])
		{
			MessageBox(radioButtonHandle[4], TEXT("Checked 5!"), TEXT("Message"), MB_OK);
		}
		else if (lParam == (LPARAM)radioButtonHandle[5])
		{
			MessageBox(radioButtonHandle[5], TEXT("Checked 6!"), TEXT("Message"), MB_OK);
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
