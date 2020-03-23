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


	
	
//////‚±‚±‚Å‘ã“ü‚³‚ê‚½Še‹Û‚ÌˆÊ’uî•ñ‚ğfungus_position‚É‘ã“ü‚·‚éB
	void SetPosition(const CVector3& pos) {
		fungus_position = pos;
	}


protected:

	prefab::CSkinModelRender* m_skin;

	int m_timer=0;

	CVector3 fungus_position=CVector3::Zero;

	CVector3 fungus_Speed ;
};

