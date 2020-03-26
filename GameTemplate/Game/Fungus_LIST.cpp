#include "stdafx.h"
#include "Fungus_LIST.h"
#include "Fungus.h"
#include "Wire.h"

Fungus_LIST::Fungus_LIST()
{

	m_wire = NewGO<Wire>(0, "wire");

	for (int d = 0; d < m_kinList.size(); d++) {

		 m_kinList[d]->Set_Belonging_List(this);

	}

}

Fungus_LIST::~Fungus_LIST()
{
}

bool Fungus_LIST::Start()
{

	////////リストに入っているポインタのインスタンスにそれをことを知らせる。




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



}


void Fungus_LIST::Update()
{

	SetMove();

}
