#pragma once

class Fungus :public IGameObject
{

public:

	Fungus();
	~Fungus();

void SetSkinModel();

wchar_t SetText();

	void Move();

	void Bond();


	
	
//////�����ő�����ꂽ�e�ۂ̈ʒu����fungus_position�ɑ������B
	void SetPosition(const CVector3& pos) {
		fungus_position = pos;
	}


protected:

	prefab::CSkinModelRender* m_skin;

	int m_timer=0;

	CVector3 fungus_position=CVector3::Zero;

	CVector3 fungus_Speed ;
};

