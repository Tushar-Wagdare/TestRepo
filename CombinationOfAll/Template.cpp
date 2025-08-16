//*** Windows Header Files ***
#include<windows.h>
#include<CommCtrl.h>


//*** Globle Function Declarations ***
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


//*** Global Variable Declarations ***
HWND hwnd = NULL;
HWND buttonHandle_01 = NULL;
HWND buttonHandle_02 = NULL;
HWND checkBoxHandle_01 = NULL;
HWND checkBoxHandle_02 = NULL;
HWND checkBoxHandle_03 = NULL;
HWND checkBoxHandle_04 = NULL;
HWND checkBoxHandle_05 = NULL;

HWND trackBarHandle_01 = NULL;
HWND trackBarHandle_02 = NULL;
HWND trackBarHandle_03 = NULL;
HWND trackBarHandle_04 = NULL;

HWND comboBoxHandle_01 = NULL;
HWND comboBoxHandle_02 = NULL;
HWND comboBoxHandle_03 = NULL;
HWND comboBoxHandle_04 = NULL;
// UI Related Variables
int spacing = 25;
int buttonX = 50;
int buttonY = 50;
int buttonWidth = 130;
int buttonHeight = 100;



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

	//Buttons And CheckBox
	buttonHandle_01 = CreateWindowEx(0,
		WC_BUTTON,
		TEXT("Button_01"),
		WS_CHILD | WS_VISIBLE,
		buttonX, buttonY,
		buttonWidth, buttonHeight,
		hwnd,
		nullptr,
		nullptr,
		nullptr
	);

	buttonHandle_02 = CreateWindowEx(0,
		WC_BUTTON,
		TEXT("Button_02"),
		WS_CHILD | WS_VISIBLE,
		buttonX + spacing + buttonWidth, buttonY,
		buttonWidth, buttonHeight,
		hwnd,
		nullptr,
		nullptr,
		nullptr
	);

	checkBoxHandle_01 = CreateWindowEx(0,
		WC_BUTTON,
		TEXT("CheckBox_01"),
		WS_CHILD | BS_CHECKBOX | WS_VISIBLE,
		buttonX + (spacing + buttonWidth) * 2, buttonY,
		buttonWidth, buttonHeight,
		hwnd,
		nullptr,
		nullptr,
		nullptr
	);

	checkBoxHandle_02 = CreateWindowEx(0,
		WC_BUTTON,
		TEXT("CheckBox_02"),
		WS_CHILD | BS_AUTOCHECKBOX | WS_VISIBLE,
		buttonX + (spacing + buttonWidth) * 3, buttonY,
		buttonWidth, buttonHeight,
		hwnd,
		nullptr,
		nullptr,
		nullptr
	);

	checkBoxHandle_03 = CreateWindowEx(0,
		WC_BUTTON,
		TEXT("CheckBox_03"),
		WS_CHILD | BS_AUTO3STATE | WS_VISIBLE,
		buttonX + (spacing + buttonWidth) * 4, buttonY,
		buttonWidth, buttonHeight,
		hwnd,
		nullptr,
		nullptr,
		nullptr
	);

	checkBoxHandle_04 = CreateWindowEx(0,
		WC_BUTTON,
		TEXT("CheckBox_04"),
		WS_CHILD | BS_AUTOCHECKBOX | BS_PUSHLIKE | WS_VISIBLE,
		buttonX + (spacing + buttonWidth) * 5, buttonY,
		buttonWidth, buttonHeight,
		hwnd,
		nullptr,
		nullptr,
		nullptr
	);

	checkBoxHandle_05 = CreateWindowEx(0,
		WC_BUTTON,
		TEXT("CheckBox_05"),
		WS_CHILD | BS_AUTO3STATE | BS_PUSHLIKE | WS_VISIBLE,
		buttonX + (spacing + buttonWidth) * 6, buttonY,
		buttonWidth, buttonHeight,
		hwnd,
		nullptr,
		nullptr,
		nullptr
	);

	//--- Create ComboBox 01 ---//
	comboBoxHandle_01 = CreateWindowEx(0,
		WC_COMBOBOX,
		TEXT("ComboBox_01"),
		WS_CHILD | WS_VISIBLE | CBS_DROPDOWN,
		20, 20,
		220, 120,
		hwnd,
		nullptr,
		nullptr,
		nullptr);
	char* list_01[] = { "Item_1" ,"Item_2", "Item_3", "Item_4", "Item_5" };
	for (int i = 0; i < 5; i++)
	{
		SendMessage(comboBoxHandle_01, CB_ADDSTRING, 0, (LPARAM)list_01[i]);
	}
	//Make Default Selection
	SendMessage(comboBoxHandle_01, CB_SETCURSEL, 0, 0);


	//--- Create ComboBox 02 ---//
	comboBoxHandle_02 = CreateWindowEx(0,
		WC_COMBOBOX,
		TEXT("ComboBox_02"),
		WS_CHILD | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWN,
		250, 20,
		220, 120,
		hwnd,
		nullptr,
		nullptr,
		nullptr);
	char* list_02[] = { "Item_1" ,"Item_2", "Item_3", "Item_4", "Item_5" };
	for (int i = 0; i < 5; i++)
	{
		SendMessage(comboBoxHandle_02, CB_ADDSTRING, 0, (LPARAM)list_02[i]);
	}
	//Make Default Selection
	SendMessage(comboBoxHandle_02, CB_SETCURSEL, 1, 0);


	//--- Create ComboBox 03 ---//
	comboBoxHandle_03 = CreateWindowEx(0,
		WC_COMBOBOX,
		TEXT("ComboBox_03"),
		WS_CHILD | WS_VISIBLE | CBS_SIMPLE,
		250 + 250, 20,
		220, 120,
		hwnd,
		nullptr,
		nullptr,
		nullptr);
	char* list_03[] = { "Item_1" ,"Item_2", "Item_3", "Item_4", "Item_5", "Item_6", "Item_7" };
	for (int i = 0; i < 7; i++)
	{
		SendMessage(comboBoxHandle_03, CB_ADDSTRING, 0, (LPARAM)list_03[i]);
	}
	//Make Default Selection
	SendMessage(comboBoxHandle_03, CB_SETCURSEL, 2, 0);



	//--- Create ComboBox 04 ---//
	comboBoxHandle_04 = CreateWindowEx(0,
		WC_COMBOBOX,
		TEXT("ComboBox_03"),
		WS_CHILD | WS_VISIBLE | CBS_SIMPLE | WS_VSCROLL,
		250 + 250 + 250, 20,
		220, 120,
		hwnd,
		nullptr,
		nullptr,
		nullptr);
	for (int i = 0; i < 7; i++)
	{
		SendMessage(comboBoxHandle_04, CB_ADDSTRING, 0, (LPARAM)list_03[i]);
	}
	//Make Default Selection
	SendMessage(comboBoxHandle_04, CB_SETCURSEL, 3, 0);

	//--- TRACKBAR 01 ---//
	trackBarHandle_01 = CreateWindowEx(0,
		TRACKBAR_CLASS,
		TEXT("TrackBar"),
		WS_CHILD | TBS_HORZ | TBS_TOP | TBS_TOOLTIPS | TBS_TRANSPARENTBKGND | WS_VISIBLE,
		buttonX, buttonY,
		150, 50,
		hwnd,
		nullptr,
		nullptr,
		nullptr);
	SendMessage(trackBarHandle_01, TBM_SETRANGEMIN, 1, -100);
	SendMessage(trackBarHandle_01, TBM_SETRANGEMAX, 1, 100);
	SendMessage(trackBarHandle_01, TBM_SETPOS, 1, 50);


	//--- TRACKBAR 02 ---//
	trackBarHandle_02 = CreateWindowEx(0,
		TRACKBAR_CLASS,
		TEXT("TrackBar"),
		WS_CHILD | TBS_VERT | TBS_LEFT | TBS_NOTICKS | TBS_TOOLTIPS | WS_VISIBLE,
		buttonX + (spacing + buttonWidth) * 1, buttonY,
		50, 150,
		hwnd,
		nullptr,
		nullptr,
		nullptr);

	//--- TRACKBAR 03 ---//
	trackBarHandle_03 = CreateWindowEx(0,
		TRACKBAR_CLASS,
		TEXT("TrackBar"),
		WS_CHILD | TBS_HORZ | TBS_AUTOTICKS | TBS_TOOLTIPS | WS_VISIBLE,
		buttonX + (spacing + buttonWidth) * 2, buttonY,
		150, 50,
		hwnd,
		nullptr,
		nullptr,
		nullptr);


	//--- TRACKBAR 04 ---//
	trackBarHandle_04 = CreateWindowEx(0,
		TRACKBAR_CLASS,
		TEXT("TrackBar"),
		WS_CHILD | TBS_VERT | TBS_AUTOTICKS | TBS_TOOLTIPS | WS_VISIBLE,
		buttonX + (spacing + buttonWidth) * 3, buttonY,
		50, 150,
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

		//Perform This Action Only value has CHANGED!!!
		if (HIWORD(wParam) == CBN_SELCHANGE)
		{
			if (lParam == (LPARAM)comboBoxHandle_01)
			{
				int comboBoxHandleState_01 = SendMessage(comboBoxHandle_01, CB_GETCURSEL, 0, 0);
				switch (comboBoxHandleState_01)
				{
				case 0:
					MessageBox(hwnd, TEXT("1 Selected"), TEXT("Message"), MB_OK);
					break;
				case 1:
					MessageBox(hwnd, TEXT("2 Selected"), TEXT("Message"), MB_OK);
					break;
				case 2:
					MessageBox(hwnd, TEXT("3 Selected"), TEXT("Message"), MB_OK);
					break;
				case 3:
					MessageBox(hwnd, TEXT("4 Selected"), TEXT("Message"), MB_OK);
					break;
				case 4:
					MessageBox(hwnd, TEXT("5 Selected"), TEXT("Message"), MB_OK);
					break;
				}
			}
			else if (lParam == (LPARAM)comboBoxHandle_02)
			{
				int comboBoxHandleState_02 = SendMessage(comboBoxHandle_02, CB_GETCURSEL, 0, 0);
				switch (comboBoxHandleState_02)
				{
				case 0:
					MessageBox(hwnd, TEXT("1 Selected"), TEXT("Message"), MB_OK);
					break;
				case 1:
					MessageBox(hwnd, TEXT("2 Selected"), TEXT("Message"), MB_OK);
					break;
				case 2:
					MessageBox(hwnd, TEXT("3 Selected"), TEXT("Message"), MB_OK);
					break;
				case 3:
					MessageBox(hwnd, TEXT("4 Selected"), TEXT("Message"), MB_OK);
					break;
				case 4:
					MessageBox(hwnd, TEXT("5 Selected"), TEXT("Message"), MB_OK);
					break;
				}
			}
			else if (lParam == (LPARAM)comboBoxHandle_03)
			{
				int comboBoxHandleState_03 = SendMessage(comboBoxHandle_03, CB_GETCURSEL, 0, 0);
				switch (comboBoxHandleState_03)
				{
				case 0:
					MessageBox(hwnd, TEXT("1 Selected"), TEXT("Message"), MB_OK);
					break;
				case 1:
					MessageBox(hwnd, TEXT("2 Selected"), TEXT("Message"), MB_OK);
					break;
				case 2:
					MessageBox(hwnd, TEXT("3 Selected"), TEXT("Message"), MB_OK);
					break;
				case 3:
					MessageBox(hwnd, TEXT("4 Selected"), TEXT("Message"), MB_OK);
					break;
				case 4:
					MessageBox(hwnd, TEXT("5 Selected"), TEXT("Message"), MB_OK);
					break;
				case 5:
					MessageBox(hwnd, TEXT("6 Selected"), TEXT("Message"), MB_OK);
					break;
				case 6:
					MessageBox(hwnd, TEXT("7 Selected"), TEXT("Message"), MB_OK);
					break;
				}
			}
			else if (lParam == (LPARAM)comboBoxHandle_04)
			{
				int comboBoxHandleState_04 = SendMessage(comboBoxHandle_04, CB_GETCURSEL, 0, 0);
				switch (comboBoxHandleState_04)
				{
				case 0:
					MessageBox(hwnd, TEXT("1 Selected"), TEXT("Message"), MB_OK);
					break;
				case 1:
					MessageBox(hwnd, TEXT("2 Selected"), TEXT("Message"), MB_OK);
					break;
				case 2:
					MessageBox(hwnd, TEXT("3 Selected"), TEXT("Message"), MB_OK);
					break;
				case 3:
					MessageBox(hwnd, TEXT("4 Selected"), TEXT("Message"), MB_OK);
					break;
				case 4:
					MessageBox(hwnd, TEXT("5 Selected"), TEXT("Message"), MB_OK);
					break;
				case 5:
					MessageBox(hwnd, TEXT("6 Selected"), TEXT("Message"), MB_OK);
					break;
				case 6:
					MessageBox(hwnd, TEXT("7 Selected"), TEXT("Message"), MB_OK);
					break;
				}
			}
		}
		break;

		case WM_HSCROLL:
			if (lParam == (LPARAM)trackBarHandle_01)
			{
				//MessageBox(hwnd, TEXT("Value Tracked For TrackBar_01"), TEXT("Message"), MB_OK);
			}
			break;


		case WM_VSCROLL:
			if (lParam == (LPARAM)trackBarHandle_02)
			{
				//MessageBox(hwnd, TEXT("Value Tracked For TrackBar_02"), TEXT("Message"), MB_OK);
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
