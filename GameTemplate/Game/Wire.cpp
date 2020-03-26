#include "stdafx.h"
#include "Wire.h"

Wire::Wire()
{



}

Wire::~Wire()
{

	DeleteGO(m_skin_wire);
}

bool Wire::Start()
{

	m_skin_wire = NewGO < prefab::CSkinModelRender >(0);
	m_skin_wire->Init(L"ModelData/flame.cmo");

	m_skin_wire->SetPosition(wire_position);


	return true;
}

void Wire::Update()
{



	wire_position += wire_Speed;

	m_skin_wire->SetPosition(wire_position);
	
m_timer++;

if(m_timer == 400){DeleteGO(this);}



}
