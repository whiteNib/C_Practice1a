#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpszCmdLine, int nCmdShow)
{
	HWND hwnd;
	MSG msg;
	WNDCLASSEX WndClass;

	WndClass.cbSize = sizeof(WNDCLASSEX);
	WndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	WndClass.lpfnWndProc = WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = NULL;
	WndClass.lpszClassName = "EasyText";
	WndClass.hIconSm = 0;

	RegisterClassEx(&WndClass);

	hwnd = CreateWindow(
		"EasyText",
		"Practice1a",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) 
{
	HDC hdc;
	RECT rect;
	PAINTSTRUCT ps;
	LPCSTR szMsg1 = "I love Window Programming!";
	LPCSTR szMsg2 = "Ű���尡 ���������ϴ�.";
	LPCSTR szMsg3 = "Ű���尡 ���������ϴ�.";

	switch (message)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 10, 10, szMsg1, strlen(szMsg1));
		EndPaint(hwnd, &ps);
		break;
	case WM_KEYDOWN:
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, szMsg2, strlen(szMsg2), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		ReleaseDC(hwnd, hdc);
		break;
	case WM_KEYUP:
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, szMsg3, strlen(szMsg3), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		ReleaseDC(hwnd, hdc);
		break;
	case WM_LBUTTONDBLCLK:
		MessageBox(hwnd, "���콺 ����Ŭ��!", "���콺 �޼���", MB_OK | MB_ICONASTERISK);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;

}