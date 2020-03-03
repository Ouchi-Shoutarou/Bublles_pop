#include "stdafx.h"
#include "Kfungus.h"



Kfungus::Kfungus()
{
}

Kfungus::~Kfungus()
{
}

bool Kfungus::Start()
{

	SetSkinModel();

	m_skin->Init(L"ModelData/kkin.cmo");

	return true;
}

void Kfungus::Update()
{

	Move();
}
