#include "stdafx.h"
#include "Fungus.h"


Fungus::Fungus()
{


}

Fungus::~Fungus()
{
	DeleteGO(m_skin);
}

bool Fungus::Start()
{	
	

	m_skin = NewGO<prefab::CSkinModelRender>(0);
	m_skin->Init(L"ModelData/kamekin.cmo");
	m_skin->SetPosition(fungus_position);
	return true;
}

void Fungus::Update()
{

	fungus_Speed.x = 3.0f;
	fungus_Speed.y = 3.0f;
	fungus_Speed.z = 3.0f;


	fungus_position += fungus_Speed;

	m_skin->SetPosition(fungus_position);
}
