#pragma once
class Fungus;
class Wire;
class Fungus_LIST:public IGameObject
{

public: 
	Fungus_LIST();
	~Fungus_LIST();

	bool Start();

	void Update();

	//////���ʂ̃��X�g���쐬�B

	void SetMove();

	void UpdateMove();

	std::vector<Fungus*> m_kinList;

	Wire* m_wire = nullptr;
	
	CVector3 NewSpeed = CVector3::Zero;

};

