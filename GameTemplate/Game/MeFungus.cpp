#include "stdafx.h"
#include "MeFungus.h"

MeFungus::MeFungus()
{
}

MeFungus::~MeFungus()
{
}

bool MeFungus::Start()
{
	SetSkinModel();

	m_skin->Init(L"ModelData/kamekin.cmo");

	return true;

}

void MeFungus::Update()
{

	Move();
}



