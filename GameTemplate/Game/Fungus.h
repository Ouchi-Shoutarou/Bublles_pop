#pragma once
class Wire;
class Fungus_LIST;
class Fungus :public IGameObject
{

public:

	Fungus();
	~Fungus();

void SetSkinModel();


	void Move();

	void Bond();
	
	void Access_To_LIST();

	void Cheak_Belonging_List();

	void Set_Belonging_List(Fungus_LIST* list_A);

	Fungus_LIST* Get_Belonging_List() {

		return k_list;
	}



	void Bond2();

	void Circle_cheak();
	
	




//////�����ő�����ꂽ�e�ۂ̈ʒu����fungus_position�ɑ������B
	void SetPosition(const CVector3& pos) {
		fungus_position = pos;
	}


	CVector3 Get_Speed() {

		return fungus_Speed;


	}


	void Set_Speed(CVector3 speed) {

		fungus_Speed = speed;

	}

	CVector3 GetPosition() {

		return fungus_position;

	}


protected:

	prefab::CSkinModelRender* m_skin = nullptr;

	int m_timer=0;

	CVector3 fungus_position=CVector3::Zero;
	CVector3 midlle_speed;
	CVector3 fungus_Speed ;

	CVector3 NewSpeed;



	//////wire�N���X���쐬���܂��B

	Wire* m_wire = nullptr;


	//////���̃N���X�ɑΉ��������X�g�N���X���쐬���܂��B

	Fungus_LIST* k_list = nullptr;
	

	//////���̊��N���X���w�������|�C���^���쐬���܂��B

	Fungus* m_kin = nullptr;

	//////�ǂ̃��X�g�ɑ����Ă��邩���ʂ���B

	Fungus_LIST* Belonging_List = nullptr;


};

