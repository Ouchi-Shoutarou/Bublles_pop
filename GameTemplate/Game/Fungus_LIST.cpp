#include "stdafx.h"
#include "Fungus_LIST.h"
#include "Fungus.h"
#include "Wire.h"

Fungus_LIST::Fungus_LIST()
{
}

Fungus_LIST::~Fungus_LIST()
{
}

bool Fungus_LIST::Start()
{





	return true;
}


void Fungus_LIST::SetMove()
{

}


void Fungus_LIST::UpdateMove() {


	NewSpeed = CVector3::Zero;
	
	/////����NewSpeed�Ƀ��X�g�ɓ����Ă���X�s�[�h��������B

	for (int d = 0; d < m_kinList.size(); d++){

		NewSpeed += m_kinList[d]->Get_Speed();

	}



	////////////////�X�s�[�h��������B



	
	NewSpeed /= m_kinList.size();


	///////�ۂɊւ��鏈����
	/////�����ɋۂ̃C���X�^���X�����X�ƂɐςށB


	

	for (int i = 0; i < m_kinList.size(); i++)
	{	
		m_kinList[i]->Set_Speed(NewSpeed);
		
	}

	for (int i = 0; i < m_wireList.size(); i++) {

		m_wireList[i]->Set_Wire_Speed(NewSpeed);

	}




}

void Fungus_LIST::UpdateSet()
{
}


void Fungus_LIST::Update()
{

	SetMove();

}
