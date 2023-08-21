#pragma once
#include "stdafx.h"

class GameObj
{
public:
	GameObj() {}
	virtual ~GameObj();

public:
	bool aabb();
};

class PlatformObj : public GameObj
{
public:
	PlatformObj() {}
	~PlatformObj();


public:
	HBITMAP			plateform1 = NULL;

	int				xPos;
	int				yPos = 550;

public:
	void BuildPlatform(HDC hDC, HDC hPlayerDC, HINSTANCE hInst, int playernum);
	
};

class Player : public GameObj
{
public:
	Player() {}
	~Player();


public:
	HBITMAP			player1 = NULL;
	
	int				xPos;
	int				yPos;


public:
	void BuildPlayer(HDC hDC, HDC hPlayerDC, HINSTANCE hInst, int playernum);
	
};