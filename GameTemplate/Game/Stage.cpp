#include "stdafx.h"
#include "Stage.h"

Stage::Stage()
{

}

Stage::~Stage()
{
	DeleteGO(m_skinModelRender);
}

bool Stage::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/yokusou.cmo");
	m_position = { 0,0,0 };
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetScale(CVector3::One * 20.0f);
	ita.CreateMesh(CVector3::Zero, CQuaternion::Identity, CVector3::One * 20.0f, m_skinModelRender);
	return true;
}

void Stage::Update()
{
}
