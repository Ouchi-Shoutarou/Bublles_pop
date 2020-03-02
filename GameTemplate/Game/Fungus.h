#pragma once
class Fungus :public IGameObject
{

public:

	Fungus();
	~Fungus();

	prefab::CSkinModelRender* m_skin;

	bool Start();

	void Update();

	CVector3 fungus_position=CVector3::Zero;

	CVector3 fungus_Speed ;
};

