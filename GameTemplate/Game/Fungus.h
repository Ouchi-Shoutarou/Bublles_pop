#pragma once

class Fungus :public IGameObject
{

public:

	Fungus();
	~Fungus();

	prefab::CSkinModelRender* m_skin;


	void SetSkinModel();

	void Move();

	CVector3 fungus_position=CVector3::Zero;

	CVector3 fungus_Speed ;
};

