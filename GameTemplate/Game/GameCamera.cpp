#include "stdafx.h"
#include "GameCamera.h"
#include"Player.h"

GameCamera :: GameCamera() 
{
}

GameCamera::~GameCamera()
{
	DeleteGO(m_spriteRender);

}

bool GameCamera::Start()
{
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/真カーソル.dds", 1280, 720, true);
	CQuaternion Rot2D;
	Rot2D.SetRotationDeg(CVector3::AxisY, 180);
	m_spriteRender->SetRotation(Rot2D);
	m_spriteRender->SetPivot({ 0.5f,0.5f });
	//m_position = { -20,80,0 };
	//m_spriteRender->SetPosition(m_position);

		//カメラを設定。
	MainCamera().SetTarget(CVector3::Zero);
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(10000.0f);
	MainCamera().SetPosition({ 0.0f, 70.0f, 200.0f });
	MainCamera().Update();

	return true;
}

void GameCamera::Update()
{
	m_spriteRender->SetPosition(m_position);

	m_moveSpeed.x = Pad(0).GetRStickXF() * -7.0f;

	m_moveSpeed.y = Pad(0).GetRStickYF() * 7.0f;

	m_position += m_moveSpeed;

	m_spriteRender->SetPosition(m_position);

	CVector3 position = m_position;
	position.y += 0.0f;
	position.z += 300.0f;
	MainCamera().SetTarget(m_position);
	MainCamera().SetPosition(position);
	MainCamera().Update();

	
}