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
	/////ステージの倍率を調整。

	Stage_Scale *= 4.0f;

	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
/////	m_skinModelRender->Init(L"modelData/yokusou.cmo");
	m_skinModelRender->SetScale( Stage_Scale );

	m_position = { 0,0,0 };
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetScale(CVector3::One * 20.0f);
	
	return true;
}

void Stage::Update()
{
	
}
