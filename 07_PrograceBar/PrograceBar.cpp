//*** Windows Header Files ***
#include<windows.h>
#include<CommCtrl.h>
#include<math.h>



//*** Globle Function Declarations ***
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);     



//*** Globle Variable Declarations ***
HWND hwnd = NULL;
HWND prograceBarHandle[5];
UINT_PTR timer = 0;


//*** Enrty-point Function ***
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	void CALLBACK onTimerTick(HWND, UINT, UINT_PTR, DWORD);
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


	prograceBarHandle[0] = CreateWindowEx(0,
		PROGRESS_CLASS,
		nullptr,
		WS_CHILD | PBS_SMOOTH | WS_VISIBLE,
		50,50,
		200,25,
		hwnd,
		nullptr,
		nullptr,
		nullptr);

	prograceBarHandle[1] = CreateWindowEx(0,
		PROGRESS_CLASS,
		nullptr,
		WS_CHILD | PBS_MARQUEE | WS_VISIBLE,
		50, 50 * 2,
		200, 25,
		hwnd,
		nullptr,
		nullptr,
		nullptr);

	prograceBarHandle[2] = CreateWindowEx(0,
		PROGRESS_CLASS,
		nullptr,
		WS_CHILD | PBS_VERTICAL | WS_VISIBLE,
		400, 50 * 3,
		25, 200,
		hwnd,
		nullptr,
		nullptr,
		nullptr);


	prograceBarHandle[3] = CreateWindowEx(0,
		PROGRESS_CLASS,
		nullptr,
		WS_CHILD | PBS_MARQUEE | WS_VISIBLE,
		50, 50 * 4,
		200, 25,
		hwnd,
		nullptr,
		nullptr,
		nullptr);

	prograceBarHandle[4] = CreateWindowEx(0,
		PROGRESS_CLASS,
		nullptr,
		WS_CHILD | PBS_MARQUEE | WS_VISIBLE,
		50, 50 * 5,
		200, 25,
		hwnd,
		nullptr,
		nullptr,
		nullptr);


	//Setting The status of ProgressBar
	SendMessage(prograceBarHandle[0], PBM_SETPOS, 50, 0);

	//Setting the color of the porgress bar
	COLORREF barColor = RGB(0, 255, 0);
	SendMessage(prograceBarHandle[1], PBM_SETPOS, 50, 0);
	SendMessage(prograceBarHandle[4], PBM_SETRANGE32, 0, 500);

	SendMessage(prograceBarHandle[1], PBM_SETBARCOLOR, 0, (LPARAM)barColor);
	SendMessage(prograceBarHandle[2], PBM_SETBARCOLOR, 0, (LPARAM)barColor);
	SendMessage(prograceBarHandle[3], PBM_SETBARCOLOR, 0, (LPARAM)barColor);

	//Set Timer for Progress BAr
	timer = SetTimer(nullptr, 0, 50, onTimerTick);




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


	case WM_DESTROY:
		PostQuitMessage(0);
		break;


	default:
		break;
	}


	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}



void CALLBACK onTimerTick(HWND hwnd, UINT msg, UINT_PTR igEvent, DWORD time)
{
	static double position = 0.0;
	position = position < 100 ? position + 1 : 0;
	SendMessage(prograceBarHandle[2], PBM_SETPOS, position, 0);
	SendMessage(prograceBarHandle[3], PBM_SETPOS, position, 0);
	SendMessage(prograceBarHandle[4], PBM_SETPOS, position, 0);

	//SendMessage(prograceBarHandle[2], PBM_SETBARCOLOR, 0, (LPARAM)(RGB((sin(position)) * 255, (cos(position)) * 255, (sin(position)) * 255)));
}
