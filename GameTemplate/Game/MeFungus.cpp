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

	result_monster_number = 3;

	return true;

}

void MeFungus::Update()
{

	Move();
	Bond();
}



