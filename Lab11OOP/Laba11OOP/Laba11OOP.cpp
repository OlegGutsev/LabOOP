#include "stdafx.h"
#include "Laba11OOP.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;								// текущий экземпляр
TCHAR szTitle[MAX_LOADSTRING];					// Текст строки заголовка
TCHAR szWindowClass[MAX_LOADSTRING];			// имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: разместите код здесь.
	MSG msg;
	HACCEL hAccelTable;

	// Инициализация глобальных строк
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_LABA11OOP, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Выполнить инициализацию приложения:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LABA11OOP));

	// Цикл основного сообщения:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  НАЗНАЧЕНИЕ: регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LABA11OOP));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 5);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_LABA11OOP);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}


LRESULT CALLBACK ChildProc(HWND, UINT, WPARAM, LPARAM);
TCHAR ChildClassName[MAX_LOADSTRING] = _T("WinChild");

ATOM MyRegisterChildClass()
{
	WNDCLASSEX wcex = { 0 };
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.lpfnWndProc = ChildProc;
	wcex.hInstance = hInst;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszClassName = ChildClassName;
	return RegisterClassEx(&wcex);
}
//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   НАЗНАЧЕНИЕ: сохраняет обработку экземпляра и создает главное окно.
//
//   КОММЕНТАРИИ:
//
//        В данной функции дескриптор экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится на экран главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Сохранить дескриптор экземпляра в глобальной переменной

   hWnd = CreateWindow(szWindowClass, L"MY WINDOW", WS_OVERLAPPEDWINDOW | WS_HSCROLL | WS_VSCROLL,
      350, 100, 640, 480, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}


//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  НАЗНАЧЕНИЕ:  обрабатывает сообщения в главном окне.
//
//  WM_COMMAND	- обработка меню приложения
//  WM_PAINT	-Закрасить главное окно
//  WM_DESTROY	 - ввести сообщение о выходе и вернуться.
//
//
static int Width = 640;
static int Height = 480;
static HWND hChild[5];
static int numberWindow = 0;
int posX = 0, posY = 0;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	static int sx, sy;


	switch (message)
	{
	case WM_CREATE:
	{
		HBRUSH greenBrush = CreateSolidBrush(RGB(240, 255, 0));
		SetClassLong(hWnd, GCL_HBRBACKGROUND, (LONG)greenBrush);
	}break;
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Разобрать выбор в меню:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		UpdateWindow(hWnd);
		EndPaint(hWnd, &ps);
		break;
	case WM_CLOSE:
		if (IDOK == MessageBox(hWnd, L"Exit programm?", L"Close", MB_OKCANCEL | MB_ICONQUESTION | MB_DEFBUTTON2))
			SendMessage(hWnd, WM_DESTROY, NULL, NULL);
		break;
	//case WM_MOUSEMOVE:
	//{
	//	static POINT cp, ocp;
	//	GetCursorPos(&cp);
	//	hdc = GetDC(hWnd);
	//	LONG offset = cp.x - ocp.x;
	//	if (cp.x > ocp.x)
	//		MoveWindow(hWnd, cp.x - (Width += offset * 0.1) / 2, cp.y - (Height += offset * 0.1) / 2, Width, Height, FALSE/*TRUE*/);
	//	else if (cp.x < ocp.x)
	//		MoveWindow(hWnd, cp.x - (Width += offset * 0.1) / 2, cp.y - (Height += offset * 0.1) / 2, Width, Height, FALSE /*TRUE*/);
	//	else
	//		MoveWindow(hWnd, cp.x - (Width) / 2, cp.y - (Width) / 2, Width, Height,     FALSE /*TRUE*/);
	//	ocp = cp;
	//	ReleaseDC(hWnd, hdc);
	//}
	//	break;

	case WM_LBUTTONUP: 
	{
		if (numberWindow < 0)
		{
			numberWindow = 0;
			posX = 0; posY = 0;
		}
		wchar_t buf[25];
		wsprintfW(buf, L"%d", numberWindow + 1);
		MyRegisterChildClass();
		float a;
		if (numberWindow < 5)
		{	
			hChild[numberWindow] = CreateWindow(ChildClassName, (LPCWSTR)buf, WS_CHILD |
				WS_DLGFRAME | WS_VISIBLE | WS_CAPTION | WS_THICKFRAME | WS_SYSMENU, posX += 45, posY += 50, 60, 100, hWnd, NULL, hInst, NULL);
			sx = 60; //Ширина дочернего окна
			sy = 100; //Высота дочернего окна
			//MoveWindow(hChild[numberWindow], ((float)numberWindow)*sx, ((a = (float)numberWindow / 2.0 ))*sy, sx, sy, FALSE);
			UpdateWindow(hWnd);
			UpdateWindow(hChild[numberWindow]);
			numberWindow++;
		}
	}break;
	case WM_KEYDOWN:
	{
		if (numberWindow >= 0)
		{
			DestroyWindow(hChild[numberWindow]);
		}
		numberWindow--;
	}break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}


LRESULT CALLBACK ChildProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rt;
	switch (message)
	{

	case WM_CREATE:
		{
			HBRUSH Brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
			SetClassLong(hWnd, GCL_HBRBACKGROUND, (LONG)Brush);
	}break;
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
	} break;
	default: return DefWindowProc(hWnd, message, wParam, lParam);
	}
}
// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
