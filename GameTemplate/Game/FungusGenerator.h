#pragma once
class Fungus;
class FungusGenerator :public IGameObject
{

public : 



	bool  Start();

	void Update();
	void Generator_Fungus();

	CVector3 position = CVector3::Zero;

	char script_me[30];

	int fungus_number;

	//Fungus* m_fungus=nullptr;
	int generator_timer = 0;




};

