#include "stdafx.h"
#include "Fungus_LIST.h"
#include "Fungus.h"
#include "Wire.h"

Fungus_LIST::Fungus_LIST()
{
	m_wire = NewGO<Wire>(0, "wire");
}

Fungus_LIST::~Fungus_LIST()
{
}

bool Fungus_LIST::Start()
{

	////////リストに入っているポインタのインスタンスにそれをことを知らせる。

	for (int i = 0; i < m_kinList.size()-1; i++) {

		CVector3 dir = {m_kinList[i]->GetPosition() - m_kinList[i + 1]->GetPosition()};

		float len = dir.Length();

		m_wire->SetScale({ 1.0f,len,1.0f });

	}





	return true;
}


void Fungus_LIST::SetMove()
{

}


void Fungus_LIST::UpdateMove() {
	
	/////このNewSpeedにリストに入っているスピードを代入する。

	for (int d = 0; d < m_kinList.size(); d++){

		NewSpeed += m_kinList[d]->Get_Speed();

	}
	
	NewSpeed /= m_kinList.size();


	for (int i = 0; i < m_kinList.size(); i++)
	{

		
		m_kinList[i]->Set_Speed(NewSpeed);

	}


	m_wire->Set_Wire_Speed(NewSpeed);
	
	
	



}


void Fungus_LIST::Update()
{

	SetMove();

}
