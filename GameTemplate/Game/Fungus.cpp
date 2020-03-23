#include "stdafx.h"
#include "Fungus.h"
#include "Kfungus.h"

Fungus::Fungus()
{



}

Fungus::~Fungus()
{
	DeleteGO(m_skin);
}



void Fungus::SetSkinModel()
{	
	
	m_skin = NewGO<prefab::CSkinModelRender>(0);

	m_skin->SetPosition(fungus_position);

	float t = Random().GetRandDouble();
	float k = Random().GetRandDouble();
	float h = Random().GetRandDouble();

	fungus_Speed.x = CMath::Lerp(t, -7.0f, 7.0f);
	fungus_Speed.y = CMath::Lerp(k, -7.0f, 7.0f);
	fungus_Speed.z = CMath::Lerp(h, -7.0f, 7.0f);
}


void Fungus::Move()
{

	fungus_position += fungus_Speed;

	m_skin->SetPosition(fungus_position);

	m_timer++;


	if (m_timer == 300) {

		DeleteGO(this);
	}
}



void Fungus::Bond() {

	//CVector3 Length=fungus_position-
	//if()



}