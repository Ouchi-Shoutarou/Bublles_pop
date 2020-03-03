#include "stdafx.h"
#include "TFungus.h"

TFungus::TFungus()
{
}

TFungus::~TFungus()
{
}

bool TFungus::Start()
{
	SetSkinModel();

	m_skin->Init(L"ModelData/Tkin.cmo");

	return true;

}

void TFungus::Update()
{	
	Move();
}






