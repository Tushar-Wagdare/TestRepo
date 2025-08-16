//*** Windows Header Files ***
#include<windows.h>
#include<CommCtrl.h>


//*** Globle Function Declarations ***
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);     



//Global VariAable Declaration
HWND hwnd = NULL;
HWND staticTextHandle_01;
HWND textBoxHandle_01;



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


	//----- Static Text -----
	staticTextHandle_01 = CreateWindowEx(0,
		WC_STATIC,
		TEXT("StaticText_01"),
		WS_CHILD | WS_VISIBLE,
		50, 50,
		150, 50,
		hwnd,
		nullptr,
		nullptr,
		nullptr);


	//----- Text Box -----//
	textBoxHandle_01 = CreateWindowEx(WS_EX_CLIENTEDGE,
		WC_EDIT,
		TEXT("Text Box"),
		WS_CHILD | WS_VISIBLE,
		50,150,
		150,50,
		hwnd,
		nullptr,
		nullptr,
		nullptr);

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
		if (lParam == (LPARAM)textBoxHandle_01)
		{
			if (HIWORD(wParam) == EN_CHANGE)
			{
				/*MessageBox(hwnd, TEXT("Text Box"), TEXT("Message"), MB_OK);*/

				//*** Add On Edit Text Fun Here ***
				//i)Make Space for storing that text
				size_t size = SendMessage(textBoxHandle_01, WM_GETTEXTLENGTH, 0, 0);
				WCHAR* text = new WCHAR[size + 1];

				//1-Get The Text
				SendMessage(textBoxHandle_01, WM_GETTEXT, size + 1, (LPARAM)text);
				if (text == '\0')
				{
					break;
				}

				//1-Set The Text
				SendMessage(staticTextHandle_01, WM_SETTEXT, 0, (LPARAM)text);
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
