#pragma once
class Wire;
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
	
	
//////‚±‚±‚Å‘ã“ü‚³‚ê‚½Še‹Û‚ÌˆÊ’uî•ñ‚ğfungus_position‚É‘ã“ü‚·‚éB
	void SetPosition(const CVector3& pos) {
		fungus_position = pos;
	}


protected:

	prefab::CSkinModelRender* m_skin = nullptr;

	int m_timer=0;

	CVector3 fungus_position=CVector3::Zero;

	CVector3 fungus_Speed ;

	Wire* m_wire = nullptr;
};

