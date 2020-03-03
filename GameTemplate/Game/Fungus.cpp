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
{	m_skin = NewGO<prefab::CSkinModelRender>(0);

	m_skin->SetPosition(fungus_position);
}

void Fungus::Move()
{
	fungus_Speed.x = 3.0f;
	fungus_Speed.y = 3.0f;
	fungus_Speed.z = 3.0f;


	fungus_position += fungus_Speed;

	m_skin->SetPosition(fungus_position);


}
