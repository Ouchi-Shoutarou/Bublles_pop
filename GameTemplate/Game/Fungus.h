#pragma once

class Fungus :public IGameObject
{

public:

	Fungus();
	~Fungus();

	prefab::CSkinModelRender* m_skin;

	int m_timer=0;

	void SetSkinModel();

	void Move();

	CVector3 fungus_position=CVector3::Zero;

	CVector3 fungus_Speed ;
};

