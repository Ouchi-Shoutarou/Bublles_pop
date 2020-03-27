#pragma once
class Kfungus;
class MeFungus;
class TFungus;
class GFungus;
class FungusGenerator :public IGameObject
{

public : 

	bool  Start();

	void Update();
	void Generator_Fungus();

	
protected:
	
	CVector3 k_position = CVector3::Zero;
	CVector3 me_position = CVector3::Zero;
	CVector3 g_position = CVector3::Zero;
	CVector3 t_position = CVector3::Zero;
	CVector3 core_position = CVector3::Zero;
	CVector3 bond_position = CVector3::Zero;

	char script_me[30];

	//Fungus* m_fungus=nullptr;
	int generator_timer = 0;

	CLevel m_level;

	//////fungusを識別するナンバーを作成します。

	int fungus_number = 0;


};

