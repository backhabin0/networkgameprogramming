
#include "gameObj.h"
#include "stdafx.h"

GameObj::~GameObj()
{
}

bool GameObj::aabb()
{
	return false;
}



////////////////////////////////////////////////////////////////
// 바닥

PlatformObj::~PlatformObj()
{
}

void PlatformObj::BuildPlatform(HDC hDC, HDC hPlayerDC, HINSTANCE hInst, int playernum)
{
	plateform1 = LoadBitmap(hInst, MAKEINTRESOURCE(playernum));
	hPlayerDC = CreateCompatibleDC(hDC);
	SelectObject(hPlayerDC, plateform1);
	TransparentBlt(hDC, xPos, yPos, 1300, 1000, hPlayerDC, 0, 0, 1300, 1000, RGB(243, 6, 255));
	DeleteDC(hPlayerDC);
}



////////////////////////////////////////////////////////////////
// 플레이어 

Player::~Player()
{
	DeleteObject(player1);
}

void Player::BuildPlayer(HDC hDC, HDC hPlayerDC, HINSTANCE hInst, int playernum)
{
	player1 = LoadBitmap(hInst, MAKEINTRESOURCE(playernum));
	hPlayerDC = CreateCompatibleDC(hDC);
	SelectObject(hPlayerDC, player1);
	TransparentBlt(hDC, xPos, yPos, 60, 60, hPlayerDC, 0, 0, 800, 850, RGB(243, 6, 255));
	DeleteDC(hPlayerDC);
}
