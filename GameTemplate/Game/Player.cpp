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
	
	if (Pad(0).IsPress(enButtonRight)) {
		m_position.x -= 5.0f;
		qRot.SetRotationDeg(CVector3::AxisY, -90.0f);
	}
	if (Pad(0).IsPress(enButtonLeft)) {
		m_position.x += 5.0f;
		qRot.SetRotationDeg(CVector3::AxisY, 90.0f);
	}
	if (Pad(0).IsPress(enButtonUp)) {
		m_position.z -= 5.0f;
		qRot.SetRotationDeg(CVector3::AxisY, 180.0f);
	}
	if (Pad(0).IsPress(enButtonDown)) {
		m_position.z += 5.0f;
		qRot.SetRotationDeg(CVector3::AxisY, 0.0f);
	}

	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(qRot);
}


