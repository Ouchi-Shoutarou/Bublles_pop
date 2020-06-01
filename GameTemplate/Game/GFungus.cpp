#include "stdafx.h"
#include "GFungus.h"



GFungus::GFungus()
{
}

GFungus::~GFungus()
{
}


bool GFungus::Start()
{
	SetSkinModel();

	m_skin->Init(L"ModelData/gkin.cmo");

	result_monster_number = 2;


	return true;

}

void GFungus::Update()
{
	Move();
	Bond();
}
