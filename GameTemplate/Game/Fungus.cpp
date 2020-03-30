#include "stdafx.h"
#include "Fungus.h"
#include "Kfungus.h"
#include "Wire.h"
#include "Fungus_LIST.h"

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

		//////�}�C�i���o�[�ɉ����ē������m�肷��B
	fungus_position += fungus_Speed;

		m_skin->SetPosition(fungus_position);

		m_timer++;


		if (m_timer == 400) {

			DeleteGO(this);
		}



}



void Fungus::Bond() {	
	//PlayerBullet�Ƃ������O�̃Q�[���I�u�W�F�N�g�ɑ΂��ăN�G��(�₢���킹)���s���B
	QueryGOs<Fungus>("fungus", [&](Fungus* kin) {
		
		
		if (kin == this) {
			return true;
		}

		//////���X�g�ɐς܂ꂽ�|�C���^�����Ɏg���Ă��邩�ǂ����𔻒肵�܂��B
		//////���Ɏ����̃��X�g�ɓ����Ă�����̂͏Ȃ��܂��B
		if (k_list != nullptr) {
			auto itr = std::find(k_list->m_kinList.begin(), k_list->m_kinList.end(), kin);    //  ���X�g�̒�����
			if (itr != k_list->m_kinList.end()) {     // ���������ꍇ

					/////////������~

				return true;

			}

		}
		

		if (this->IsDead()) {
			return false;
		}


		//�Q�_�Ԃ̋������v�Z����B
		CVector3 diff = kin->fungus_position - fungus_position;
		if (diff.Length() < 20.0f * 3.0f) {	//������2000�ȉ��ɂȂ�����B
			//�ڐG��̏���
			/*if(!kin->IsDead()){
				DeleteGO(kin);
			}*/
			m_kin = kin;

			///////////�������g���O���[�v�ɑ����Ă��邩�H

			/////������

			if (k_list == nullptr) {
				
				////////////���ʃ��X�g���쐬���܂��B

				k_list = NewGO<Fungus_LIST>(0, "list");

				k_list->m_kinList.push_back(this);
			
				

			}
		

	

			////���肪���X�g�ɑ����Ă��邩�H
			///������

			if (kin->Get_Belonging_List() == nullptr) {
				
				////�������������Ă��郊�X�g�ɑ���̃|�C���^�������܂��B
			
				k_list->m_kinList.push_back(kin);
				kin->k_list = k_list;



				k_list->UpdateMove();

			}

			else {

				/////����̃��X�g�̒��̂��ׂĂ̗v�f�������o���܂��B

				for (int i = 0; i < kin->Get_Belonging_List()->m_kinList.size(); i++)
				{
					k_list->m_kinList.push_back
					(
						kin->Get_Belonging_List()->m_kinList[i]
					);

					k_list->UpdateMove();

				}
				/////�Â��O���[�v���폜���܂��B

				DeleteGO(kin->Get_Belonging_List());

				for (int i = 0; i < k_list->m_kinList.size();i++) {


					//////�Ēʒm

					k_list->m_kinList[i]->k_list = k_list;
				}
			}

 

		

		

		/*	DeleteGO(this);*/
			return false;
		}
		return true;
		}
	);
}

void Fungus::Access_To_LIST()
{
}

void Fungus::Cheak_Belonging_List()
{
	

}

void Fungus::Set_Belonging_List(Fungus_LIST* list_A)
{

	Belonging_List = list_A;

}




void Fungus::Bond2() {


	//PlayerBullet�Ƃ������O�̃Q�[���I�u�W�F�N�g�ɑ΂��ăN�G��(�₢���킹)���s���B
	QueryGOs<Fungus>("fungus", [&](Fungus* kin) {
		if (kin == this) {
			return true;
		}
		if (this->IsDead()) {
			return false;
		}
		//�Q�_�Ԃ̋������v�Z����B
		CVector3 diff = kin->fungus_position - fungus_position;
		if (diff.Length() < 20.0f) {	//������2000�ȉ��ɂȂ�����B
			//���S�B
			if (!kin->IsDead()) {
				DeleteGO(kin);
			}
			DeleteGO(this);
			return false;
		}
		return true;
		}
	);
}

















/////////////////////////�߂������ɕK���y�ʉ������܂��B�I�I�I�I�I�I�I�I�I�I�I�I

void Fungus::Circle_cheak()
{


	//CVector3 Length = fungus_position;
	//
	//float len = Length.x * Length.x+ Length.y* Length.y+ Length.z* Length.z;
	//

	//
	//////�O�p�`�̒��ň�ԋ߂��_���Z�o���܂��B

	////////�O�S�̍��W���Z�o���܂��B

	//CVector3 OUTHeat ={
	//	(sin(2) * Length.x) / (sin(2) + sin(2) + sin(2))
	//	(sin(2) * Length.y) / (sin(2) + sin(2) + sin(2))
	//	(sin(2) * Length.z) / (sin(2) + sin(2) + sin(2))
	//};

	//
}

