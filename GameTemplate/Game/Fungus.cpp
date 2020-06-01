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
		if (kin->IsDead()) {
			return true;
		}


		//�Q�_�Ԃ̋������v�Z����B
		CVector3 diff = kin->fungus_position - fungus_position;
		if (diff.Length() < 20.0f * 5.0f) {	//������2000�ȉ��ɂȂ�����B


			m_kin = kin;

			////////���������X�^�[�̍쐬�B

			//////////�����X�^�[�i���o�[�ɉ����Ă��񂷁[�������B


			////////////���ۂ����Ȃ��ƃA�N�V�����͂Ȃ��̂Ő�ɑI�ʂ����Ă����B

			if (result_monster_number==1&& kin->Get_Result_Monster_number() ==1) {
				


			/////////����(mostere_number=1)��g��(mostere_number=2)���Z������΃S�L�u������������܂��B


				if (result_monster_number + kin->Get_Result_Monster_number() == 3) {
					///////�S�L�u���𐶐�����B



				}
				/////////����(mostere_number=1)��me��(mostere_number=3)���Z������΃J�����V����������܂��B


				if (result_monster_number + kin->Get_Result_Monster_number() == 4) {
					///////�J�����V�𐶐�����B



				}


				////////////���̏ꍇ���X�g�͔p�������B
			    ///�������������Ă��郊�X�g�ɂ���C���X�^���X���j�����܂��B
				if (k_list != nullptr) {
					for (int i = 0; i < k_list->m_kinList.size(); i++)
					{

						DeleteGO(k_list->m_kinList[i]);


					}
				}

				///���肪�������Ă������X�g�ɂ���C���X�^���X���j�󂵂܂��B
				if (kin->Get_Belonging_List() != nullptr) {
					for (int i = 0; i < kin->Get_Belonging_List()->m_kinList.size(); i++)
					{

						DeleteGO(kin->Get_Belonging_List()->m_kinList[i]);


					}
				}


				/////////////���肪�������Ă������X�g�̃��C���[�����ׂď����B

				for (int i = 0; i <k_list->m_wireList.size(); i++) {

					DeleteGO(k_list->m_wireList[i]);

				}


				/////////////���肪�������Ă������X�g�̃��C���[�����ׂď����B

				for (int i = 0; i < kin->Get_Belonging_List()->m_wireList.size(); i++) {

						DeleteGO(kin->Get_Belonging_List()->m_wireList[i]);

				}


				///�������������Ă��郊�X�g����󂳂��܂��B
				DeleteGO(k_list);
				///���肪�������Ă��郊�X�g����󂵂܂��B

				DeleteGO(kin->k_list);
			
				return true;


			}


			m_wire = NewGO<Wire>(0, "wire");

			//���W�̐ݒ�B
			m_wire->Set_position(fungus_position);


		

			/////////////�����Ƒ���̋������x�N�g�������܂��B

			CVector3 dir = { kin->GetPosition() - fungus_position };



			////���̃x�N�g���̒��������߂Ă܂��B

			float len = dir.Length();

			m_wire->SetScale({ 1.0f,len/100,1.0f });

		
			///////���߂��x�N�g���𐳋K�����āA

			dir.Normalize();
			////////������x�N�g���Ƃ̊O�ς����߂܂��B

			CVector3 axisB;
			

			axisB.Cross(CVector3::AxisY, dir);
			axisB.Normalize();

			///////////////���ς����߂܂��B

			float Inner_Product = CVector3::AxisY.Dot(dir);
			//�O�̂��߂̔񐔖h�~�B
			Inner_Product = max(-1.0f, min(1.0f, Inner_Product));

			//cos�Ƃ��烉�W�A���P�ʂɕϊ��B
			float Inner_Product_A = acos(Inner_Product);
			
			//��]������������߂�B
			float dirDot = CVector3::AxisX.Dot(dir);

			if (dirDot < 0.0f) {
				Inner_Product_A *= -1.0f;
			}

			CQuaternion q_Rot;
			q_Rot.SetRotation(axisB,Inner_Product_A);
			q_Rot.Multiply(CQuaternion::Identity);

			m_wire->Set_Rotation(q_Rot);

			///////////�������g���O���[�v�ɑ����Ă��邩�H

			/////������

			if (k_list == nullptr) {
				
				////////////���ʃ��X�g���쐬���܂��B

				k_list = NewGO<Fungus_LIST>(0, "list");

				k_list->m_kinList.push_back(this);
		

			}	
		  //////���X�g�N���X�̃��C���[�̃N���X�ɑ������B
			k_list->m_wireList.push_back(m_wire);


			////���肪���X�g�ɑ����Ă��邩�H
			///������

			if (kin->Get_Belonging_List() == nullptr) {
				
				////�������������Ă��郊�X�g�ɑ���̃|�C���^�������܂��B
			
				k_list->m_kinList.push_back(kin);


				///////����̃��X�g�̃|�C���^�Ɏ����̃��X�g�̃|�C���^�������܂��B
				//////����Ɏ����̏������`����B

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

				

				}

				for (int i = 0; i < kin->Get_Belonging_List()->m_wireList.size(); i++) {

					k_list->m_wireList.push_back(

						kin->Get_Belonging_List()->m_wireList[i]
					);

					

				}	
				
				k_list->UpdateMove();

				/////�Â��O���[�v���폜���܂��B

				DeleteGO(kin->Get_Belonging_List());
				 

				/////

				for (int i = 0; i < k_list->m_kinList.size();i++) {


					//////�Ēʒm

					k_list->m_kinList[i]->k_list = k_list;
				}
			}

 

		

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

