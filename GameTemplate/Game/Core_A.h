#pragma once
#include "Fungus.h"
class Core_A:public Fungus
{

public:

	/////���̃N���X�͋ۂ̊j�ƂȂ�j�ۂ𐶐����܂��B

	Core_A();
	~Core_A();


	bool Start();

	void Update();

	void SetALL();

	
	prefab::CPointLight* ptLight;
	std::vector<prefab::CPointLight*>	m_pointLightList;	//�|�C���g���C�g�̃��X�g�B


};



