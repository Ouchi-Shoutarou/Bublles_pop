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

	//////共通のリストを作成。

	void SetMove();

	void UpdateMove();

	void UpdateSet();

	std::vector<Fungus*> m_kinList;

	std::vector<Wire*> m_wireList;

	Wire* m_wire = nullptr;
	
	CVector3 NewSpeed = CVector3::Zero;

};

