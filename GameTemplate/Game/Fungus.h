#pragma once

class Fungus :public IGameObject
{

public:

	Fungus();
	~Fungus();

void SetSkinModel();


	void Move();

	void Bond();

	void Bond2();

	void Circle_cheak();
	
	
//////ここで代入された各菌の位置情報をfungus_positionに代入する。
	void SetPosition(const CVector3& pos) {
		fungus_position = pos;
	}


protected:

	prefab::CSkinModelRender* m_skin = nullptr;

	int m_timer=0;

	CVector3 fungus_position=CVector3::Zero;

	CVector3 fungus_Speed ;
};

