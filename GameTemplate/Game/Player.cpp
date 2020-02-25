#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

bool Player::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/unityChan.cmo");
	m_position = { 0,0,0 };
	m_skinModelRender->SetPosition(m_position);

	return true;
}

void Player::Update()
{
}
