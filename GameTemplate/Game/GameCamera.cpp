#include "stdafx.h"
#include "GameCamera.h"
#include"Player.h"

GameCamera :: GameCamera() 
{
}

GameCamera::~GameCamera()
{
}

bool GameCamera::start()
{
	
	//ƒJƒƒ‰‚ğİ’èB
	MainCamera().SetTarget({ 0.0f, 70.0f, 0.0f });
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(10000.0f);
	MainCamera().SetPosition({ 0.0f, 70.0f, 200.0f });
	MainCamera().Update();

	return true;
}

void GameCamera::Update()
{

}