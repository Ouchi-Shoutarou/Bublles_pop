#include "stdafx.h"
#include "GameSelect.h"
#include "Game.h"

GameSelect::GameSelect()
{
}

GameSelect::~GameSelect()
{

	DeleteGO(m_haikei);

	DeleteGO(m_select);

	DeleteGO(m_haikei2);


}

bool GameSelect::Start()
{

	m_haikei2 = NewGO<prefab::CSpriteRender>(0);
	m_haikei2->Init(L"sprite/title.dds", 1280.0f, 720.0f);


	m_select = NewGO<prefab::CSpriteRender>(0);
	m_select->Init(L"sprite/flame2.dds", 1280.0f, 720.0f);


	m_haikei = NewGO<prefab::CSpriteRender>(0);
	m_haikei->Init(L"sprite/gamen.dds", 1280.0f, 720.0f);



	m_scale_haikei *= 0.3;

	m_scale_haikei.y *= 0.8;

	m_select->SetScale(m_scale_haikei);



 
	flame_position_Game = {-30.0f,-20.0f,0.0f};

	 flame_position_Settei = { -30.0f,-120.0f,0.0f };
	 
	 flame_position_Modoru = { -30.0f,-210.0f,0.0f };




	return true;
}

void GameSelect::Update()
{
	if (Pad(0).IsTrigger(enButtonUp)) {

		flame_position_flag--;

		
		if (flame_position_flag == -1) {
			flame_position_flag = 2;

		}

	}

	if (Pad(0).IsTrigger(enButtonDown)) {


		flame_position_flag++;

if (flame_position_flag == 3) {
			flame_position_flag = 0;

		}
	
	}

	switch(flame_position_flag)
	{
	case 0 :

		flame_position = flame_position_Game;

		if (Pad(0).IsPress(enButtonA)) {

			DeleteGO(this);

			game = NewGO<Game>(0, "game");


		}

		break;

	case 1:

		flame_position = flame_position_Settei;
		break;

	case 2:

	
		flame_position = flame_position_Modoru;

		break;



	}



	m_select->SetPosition(flame_position);



}
