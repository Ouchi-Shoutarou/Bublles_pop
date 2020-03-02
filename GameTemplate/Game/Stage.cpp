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
	m_skinModelRender->Init(L"modelData/ita.cmo");
	m_position = { 0,0,0 };
	m_skinModelRender->SetPosition(m_position);
	ita.CreateMesh(CVector3::Zero, CQuaternion::Identity, CVector3::One, m_skinModelRender);
	return true;
}

void Stage::Update()
{
}
