//*** Windows Header Files ***
#define _CONSOLEWINDOW_H

#include<windows.h>
#include<CommCtrl.h>
#include<stdio.h>
#include<stdlib.h>

#include<io.h>
#include<iostream>
#include<fstream>
#include<fcntl.h>


#include"Resource.h"
#include<vector>



//*** Globle Function Declarations ***
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);



//***********************************************************************************************
//Console related code
//cONSOLE rELATED vARIABLES
WORD MAXCONSOLEROWS;
WORD MAXCONSOLECOLOMNS;

HANDLE hStdHandle;
FILE* filePointer;
char buf[1024];
std::vector<std::unique_ptr<std::fstream>> streams;


void initializeConsoleWindow(void)
{
	//code
	MAXCONSOLEROWS = 500;
	MAXCONSOLECOLOMNS = 500;
	hStdHandle = INVALID_HANDLE_VALUE;
}

bool consoleStatus()
{
	if (hStdHandle == INVALID_HANDLE_VALUE)
	{
		return(FALSE);
	}
	else
	{
		return(TRUE);
	}
}

//void redirectStream(DWORD streamType)
//{
//	HANDLE stdHandle = GetStdHandle(streamType);
//	if (stdHandle == INVALID_HANDLE_VALUE)
//	{
//		MessageBox(NULL, TEXT("Failed 5"), TEXT("Mwssage"), MB_OK);
//	}
//
//	int consoleHandle = _open_osfhandle((long)stdHandle, _O_TEXT);
//	if (consoleHandle == INVALID_HANDLE_VALUE)
//	{
//		//DWORD error = GetLastError();
//		MessageBox(NULL, TEXT("Failed 1"), TEXT("Mwssage"), MB_OK);
//	}
//
//	std::unique_ptr <std::fstream > fp(new std::fstream(consoleHandle), "w");
//	if (!fp)
//	{
//		MessageBox(NULL, TEXT("fp Failed 7"), TEXT("Mwssage"), MB_OK);
//	}
//
//	switch (streamType)
//	{
//	case STD_OUTPUT_HANDLE:
//		*stdout = *fp;
//		break;
//	case STD_INPUT_HANDLE:
//		*stdin = *fp;
//		break;
//	case STD_ERROR_HANDLE:
//		*stderr = *fp;
//		break;
//	}
//
//	setvbuf(fp.get(), nullptr, _IONBF, 0);
//	streams.emplace_back(std::move(fp));
//}

//void openConsoleWindow(void)
//{
//	// CODE
//
//	// 1.Cheak if the handle is invalid
//
//	if (hStdHandle != INVALID_HANDLE_VALUE)
//	{
//		//DWORD error = GetLastError();
//		MessageBox(NULL, TEXT("Failed 1"), TEXT("Mwssage"), MB_OK);
//	}
//
//
//	if (!AllocConsole())
//	{
//		//DWORD error = GetLastError();
//		MessageBox(NULL, TEXT("Failed 2"), TEXT("Mwssage"), MB_OK);
//	}
//
//	//Local Variables
//	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
//
//	// 2.Allocate to console for this application
//	
//
//	// 3.set the screen buffer to be big enough to let us scroll
//
//	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleInfo))
//	{
//		//DWORD error = GetLastError();
//		MessageBox(NULL, TEXT("Failed 3"), TEXT("Mwssage"), MB_OK);
//	}
//
//	consoleInfo.dwSize.Y = MAXCONSOLEROWS;
//	if (!SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), consoleInfo.dwSize))
//	{
//		//DWORD error = GetLastError();
//		MessageBox(NULL, TEXT("Failed 4"), TEXT("Mwssage"), MB_OK);
//	}
//
//	// 4.set the title of console
//	SetConsoleTitle("Debug Console");
//
//	redirectStream(STD_OUTPUT_HANDLE);
//	redirectStream(STD_INPUT_HANDLE);
//	redirectStream(STD_ERROR_HANDLE);
//
//	// 8.Make cOut(), wCout(), cIn(), wcIn(), wcerr(), cerr(), wclog(), clog(), point to the console as well
//	std::ios::sync_with_stdio();
//}


//void openConsoleWindow(void)
//{
//	// CODE
//
//	// 1.Cheak if the handle is invalid
//
//	if (hStdHandle == INVALID_HANDLE_VALUE)
//	{
//		//Local Variables
//		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
//
//		// 2.Allocate to console for this application
//		AllocConsole();
//
//		// 3.set the screen buffer to be big enough to let us scroll
//		HANDLE handleOfStandardConsole_out = GetStdHandle(STD_OUTPUT_HANDLE);
//		HANDLE handleOfStandardConsole_in = GetStdHandle(STD_INPUT_HANDLE);
//		HANDLE handleOfStandardConsole_error = GetStdHandle(STD_ERROR_HANDLE);
//
//		GetConsoleScreenBufferInfo(handleOfStandardConsole_out, &consoleInfo);
//
//		consoleInfo.dwSize.Y = MAXCONSOLEROWS;
//		SetConsoleScreenBufferSize(handleOfStandardConsole_out, consoleInfo.dwSize);
//
//		// 4.set the title of console
//		SetConsoleTitle("Debug Console");
//
//		// 5.Redirect unbufferwd STDOUT to the console
//		int handleOfDebugConsole_out = _open_osfhandle((intptr_t)handleOfStandardConsole_out, _O_TEXT);
//		filePointer = _fdopen(handleOfDebugConsole_out, "w");
//		*stdout = *filePointer;
//		setvbuf(stdout, NULL, _IONBF, 4096);
//
//		// 6.Redirect unbuffered STDIN to console
//		int handleOfDebugConsole_in = _open_osfhandle((intptr_t)handleOfStandardConsole_in, _O_TEXT);
//		filePointer = _fdopen(handleOfDebugConsole_in, "r");
//		*stdin = *filePointer;
//		setvbuf(stdin, NULL, _IONBF, 4096);
//
//
//		// 7.redirect unbuffered STDERR to the console
//		int handleOfStdDebugConsole_error = _open_osfhandle((intptr_t)handleOfStandardConsole_error, _O_TEXT);
//		filePointer = _fdopen(handleOfStdDebugConsole_error, "r");
//		*stderr = *filePointer;
//		setvbuf(stderr, NULL, _IONBF, 4096);
//
//		// 8.Make cOut(), wCout(), cIn(), wcIn(), wcerr(), cerr(), wclog(), clog(), point to the console as well
//		std::ios::sync_with_stdio();
//
//	}
//	else
//	{
//		MessageBox(NULL, TEXT("Failed"), TEXT("Success"), MB_OK | MB_ICONSTOP);
//	}
//
//
//
//}

void openConsoleWindow(void)
{
	// CODE

	// 1.Cheak if the handle is invalid

	if (hStdHandle == INVALID_HANDLE_VALUE)
	{
		//Local Variables
		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;

		// 2.Allocate to console for this application
		AllocConsole();

		// 3.set the screen buffer to be big enough to let us scroll
		HANDLE handleOfStandardConsole_out = GetStdHandle(STD_OUTPUT_HANDLE);
		HANDLE handleOfStandardConsole_in = GetStdHandle(STD_INPUT_HANDLE);
		HANDLE handleOfStandardConsole_error = GetStdHandle(STD_ERROR_HANDLE);

		GetConsoleScreenBufferInfo(handleOfStandardConsole_out, &consoleInfo);

		consoleInfo.dwSize.Y = MAXCONSOLEROWS;
		SetConsoleScreenBufferSize(handleOfStandardConsole_out, consoleInfo.dwSize);

		// 4.set the title of console
		SetConsoleTitle("Debug Console");

		// 5.Redirect unbufferwd STDOUT to the console
		int handleOfDebugConsole_out = _open_osfhandle((intptr_t)handleOfStandardConsole_out, _O_TEXT | _O_APPEND);
		filePointer = _fdopen(handleOfDebugConsole_out, "r");
		*stdout = *filePointer;
		setvbuf(filePointer, buf, _IOFBF, sizeof(buf));

		// 6.Redirect unbuffered STDIN to console
		int handleOfDebugConsole_in = _open_osfhandle((intptr_t)handleOfStandardConsole_in, _O_TEXT | _O_APPEND);
		filePointer = _fdopen(handleOfDebugConsole_in, "r");
		*stdin = *filePointer;
		setvbuf(filePointer, buf, _IOFBF, sizeof(buf));


		// 7.redirect unbuffered STDERR to the console
		int handleOfStdDebugConsole_error = _open_osfhandle((intptr_t)handleOfStandardConsole_error, _O_TEXT | _O_APPEND);
		filePointer = _fdopen(handleOfStdDebugConsole_error, "r");
		*stderr = *filePointer;
		setvbuf(filePointer, buf, _IOFBF, sizeof(buf));

		// 8.Make cOut(), wCout(), cIn(), wcIn(), wcerr(), cerr(), wclog(), clog(), point to the console as well
		std::ios::sync_with_stdio();

	}
	else
	{
		MessageBox(NULL, TEXT("Failed"), TEXT("Success"), MB_OK | MB_ICONSTOP);
	}



}

void closeConsoleWindow(void)
{
	//code
	if (hStdHandle != INVALID_HANDLE_VALUE)
	{
		FreeConsole();
		fclose(filePointer);
		hStdHandle = INVALID_HANDLE_VALUE;
	}
}

void uninitializeConsoleWindow(void)
{
	//code
	if (hStdHandle != INVALID_HANDLE_VALUE)
	{
		FreeConsole();
		fclose(filePointer);
	}
}

//******************************************************************************************



//*** Enrty-point Function ***
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//*** Local Variable Declarations ***
	WNDCLASSEX wndclass;
	HWND hwnd = NULL;
	MSG msg;
	TCHAR szAppName[] = TEXT("Tushar_Wagdare_Chi_Window");

	//initializeConsoleWindow();
	/*AllocConsole();
	if (freopen_s(&filePointer, "CONOUT$", "w", stdout) != NULL)
	{
		MessageBox(NULL, TEXT("Success"), TEXT("Success"), MB_OK | MB_ICONSTOP);
	}
	else
	{
		printf("Debug Console Fired\n");
	}*/

	if (AllocConsole())
	{
		/*freopen_s(&filePointer, "CONOUT$", "wb", stdout);
		freopen_s(&filePointer, "CONOUT$", "wb", stdin);
		freopen_s(&filePointer, "CONOUT$", "wb", stderr);*/
		freopen("CONOUT$", "wb", stdout);
		freopen("CONIN$", "wb", stdin);
		freopen("CONERR$", "wb", stderr);
	}
	
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
		switch (LOWORD(wParam))
		{
			//****************************************************************************************
		case IDM_FILE_EXIT:
			MessageBox(NULL, TEXT("Menu Item Selected"), TEXT("Success"), MB_OK | MB_ICONSTOP);
			PostMessage(hwnd, WM_CLOSE, 0, 0);
			break;

		case IDM_OPEN:
			openConsoleWindow();
			break;

		case IDM_TEST:
			std::cout << "Test Output To cout" << std::endl;
			std::cerr << "Test output to cerr" << std::endl;
			std::clog << "Test output to clog" << std::endl;

			std::cout << "Enter an integer to Test cin" << std::endl;
			int iVar;
			std::cin>>iVar;
			std::cout << "You Have Entered " << iVar << std::endl;
			//MessageBox(NULL, TEXT("Test Item Selected"), TEXT("Success"), MB_OK | MB_ICONSTOP);
			return(0);
			break;

		case IDM_CLOSE:
			//MessageBox(NULL, TEXT("Close Item Selected"), TEXT("Success"), MB_OK | MB_ICONSTOP);
			closeConsoleWindow();
			break;

		default:
			break;
			//****************************************************************************************
			return(0);
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


