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
	
	




//////ここで代入された各菌の位置情報をfungus_positionに代入する。
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



	//////wireクラスを作成します。

	Wire* m_wire = nullptr;


	//////このクラスに対応したリストクラスを作成します。

	Fungus_LIST* k_list = nullptr;
	

	//////この基底クラスを指し示すポインタを作成します。

	Fungus* m_kin = nullptr;

	//////どのリストに属しているか判別する。

	Fungus_LIST* Belonging_List = nullptr;


};

