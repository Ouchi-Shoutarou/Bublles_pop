#include "stdafx.h"
#include "Game.h"
#include  "Player.h"
#include "Title.h"
#include"Stage.h"
#include "tkEngine/light/tkDirectionLight.h"
#include"GameCamera.h"
#include "FungusGenerator.h"

Game::Game()
{
}


Game::~Game()
{
	DeleteGO(m_gameCamera);
	DeleteGO(m_stage);
	DeleteGO(m_player);
	

}


bool Game::Start()
{
	m_gameCamera = NewGO<GameCamera>(0);
	m_stage = NewGO<Stage>(0);
	m_player = NewGO<Player>(0,"�v���C���[");

	m_fungus_generator = NewGO<FungusGenerator>(0, script_me);



	return true;
}

void Game::Update()
{

	if (Pad(0).IsTrigger(enButtonStart)) {
      m_title = NewGO<Title>(0);
	  DeleteGO(this);
	}


}


