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

	result_monster_number = 1;

	return true;
}

void Kfungus::Update()
{
	
	Move();
	Bond();


	//////自分がme菌と結合した場合。




	////自分がg菌と結合した場合。




}
