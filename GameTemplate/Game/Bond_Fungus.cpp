#include "stdafx.h"
#include "Bond_Fungus.h"


Bond_Fungus::Bond_Fungus()
{
}

Bond_Fungus::~Bond_Fungus()
{
}

bool Bond_Fungus::Start()
{

	SetSkinModel();

	m_skin->Init(L"ModelData/bond.cmo");

	return true;
}

void  Bond_Fungus::Update()
{

	Move();

	Bond();
}
