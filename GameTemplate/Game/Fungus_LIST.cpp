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

	for (int i = 0; i < m_kinList.size()-1; i++) {

		CVector3 dir = {m_kinList[i]->GetPosition() - m_kinList[i + 1]->GetPosition()};

		float len = dir.Length();

		m_wire->SetScale({ 1.0f,len/100.0f,1.0f });

	}





	return true;
}


void Fungus_LIST::SetMove()
{

}


void Fungus_LIST::UpdateMove() {

	m_wire = NewGO<Wire>(0, "wire");

	//////���̊֐����Ă΂��Ƃ������Ƃ́A�V�����ۂ����̃��X�g��pushback���ꂽ�Ƃ������Ƃł���B

	/////////wire�̃|�W�V������ݒ肷��B

	//////////�ڐG���肵���C���X�^���X�����X�g�̉��Ԗڂɂ��邩�T������v���O����������B

	////////////�O�Ԗڂɓ����Ă���|�C���^�̃C���X�^���X����|�W�V�������m�ۂ���B

	m_wire->Set_Wire_Position(m_kinList[m_kinList.size()-1]->GetPosition());  ////////////////����ŐV�����ۂ�������O���[�v�������͋ۂɐڐG�����ꍇ�A
	/////////////�C���X�^���X�i�ڐG����������C���X�^���X�j����Ō�̃C���X�^���X�i�V�����ǉ����ꂽ�C���X�^���X�j�Ƀx�N�g�����L�тċ�����c�����邱�Ƃ��ł���B�j

	//////////�P�Ԗڂɓ����Ă���|�C���^�̃C���X�^���X����|�W�V�������m�ۂ��āA�񂷁B

	

	//////////�ڐG���肵���C���X�^���X�Ƃ��ꂽ�C���X�^���X���m���Ȃ��悤�ɂ��ă��C���[�𐶐�����B





	NewSpeed = CVector3::Zero;
	
	/////����NewSpeed�Ƀ��X�g�ɓ����Ă���X�s�[�h��������B

	for (int d = 0; d < m_kinList.size(); d++){

		NewSpeed += m_kinList[d]->Get_Speed();

	}

	////////////////�X�s�[�h��������B

	for (int i = 0; i < m_wireList.size(); i++) {
		m_wire->Set_Wire_Speed(NewSpeed);
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
