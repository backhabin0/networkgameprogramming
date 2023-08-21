
#include "stdafx.h"
#include "resource.h"
#include "gameObj.h"

HINSTANCE hInst;
LPCTSTR lpszClass = L"NetGP Term Project";
LPCTSTR lpszWindowName = L"NetGP Term project";

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASSEX WndClass;
	hInst = hInstance;

	WndClass.cbSize = sizeof(WndClass);
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = NULL;
	WndClass.lpszClassName = lpszClass;
	WndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassEx(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszWindowName, WS_OVERLAPPEDWINDOW, 0, 0, WINDOW_WIDTH_SIZE, WINDOW_HEIGHT_SIZE, NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&Message, 0, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return Message.wParam;
}



// 플레이어 선언
Player* p1 = new Player();
PlatformObj* g1 = new PlatformObj();

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hDC = 0, hPlayerDC = 0, hGroundDC = 0;
	PAINTSTRUCT ps;
	

	switch (uMsg) {
	case WM_CREATE:
		
		
		break;

	case WM_KEYDOWN:
		// 키보드 입력(키 다운)

		switch (wParam)
		{
		case VK_ESCAPE:				// 종료키(ESC)
			exit(1);
			break;
		case VK_RIGHT:
			p1->xPos += 10;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_LEFT:
			p1->xPos -= 10;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 'S':
			SetTimer(hWnd, 1, GRAVITY_FORCE, NULL);
			break;
		}
		break;
	
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);

		p1->BuildPlayer(hDC, hPlayerDC, hInst, 101);
		g1->BuildPlatform(hDC, hGroundDC, hInst, 107);


		EndPaint(hWnd, &ps);
		break;


	
	case WM_TIMER:
		
		switch (wParam)
		{
		case 1:
			if (!p1->aabb())
			{
				p1->yPos += 5;
				break;
			}

		}

		InvalidateRect(hWnd, NULL, TRUE);
		break;

	case WM_DESTROY:
		

		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
