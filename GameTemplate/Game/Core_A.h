#pragma once
#include "Fungus.h"
class Core_A:public Fungus
{

public:

	/////このクラスは菌の核となる核菌を生成します。

	Core_A();
	~Core_A();


	bool Start();

	void Update();

	void SetALL();

	
	prefab::CPointLight* ptLight;
	std::vector<prefab::CPointLight*>	m_pointLightList;	//ポイントライトのリスト。


};



