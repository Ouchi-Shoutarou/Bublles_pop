#include "stdafx.h"
#include "Game.h"
#include  "Player.h"
#include "tkEngine/light/tkDirectionLight.h"

Game::Game()
{
}


Game::~Game()
{
}
bool Game::Start()
{
	NewGO<Player>(0);
	//ƒJƒƒ‰‚ğİ’èB
	MainCamera().SetTarget({ 0.0f, 70.0f, 0.0f });
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(10000.0f);
	MainCamera().SetPosition({ 0.0f, 70.0f, 200.0f });
	MainCamera().Update();
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/unityChan.cmo");

	m_sprite = NewGO<prefab::CSpriteRender>(0);
	m_sprite->Init(L"sprite/card-600x423.dds",1280.0f/2,720.0f/2);
	
	return true;
}

void Game::Update()
{
}