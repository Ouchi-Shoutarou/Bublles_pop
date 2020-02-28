#include "stdafx.h"
#include "Game.h"
#include  "Player.h"
#include"GameCamera.h"
#include "tkEngine/light/tkDirectionLight.h"

Game::Game()
{
}


Game::~Game()
{
}
bool Game::Start()
{
	m_player = NewGO<Player>(0);
	m_gameCamera = NewGO<GameCamera>(0);
	return true;
}

void Game::Update()
{
}