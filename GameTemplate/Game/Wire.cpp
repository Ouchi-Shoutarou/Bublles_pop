#include "stdafx.h"
#include "Wire.h"

Wire::Wire()
{



}

Wire::~Wire()
{
}

bool Wire::Start()
{

	m_skin_wire = NewGO < prefab::CSkinModelRender >(0);
	m_skin_wire->Init(L"ModelData/flame.cmo");

	m_skin_wire->SetPosition(wire_position);


	return true;
}

void Wire::UpDate()
{

	


}
