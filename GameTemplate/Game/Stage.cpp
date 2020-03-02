#include "stdafx.h"
#include "Stage.h"

Stage::Stage()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/ita.cmo");
}

Stage::~Stage()
{
	DeleteGO(m_skinModelRender);
}
