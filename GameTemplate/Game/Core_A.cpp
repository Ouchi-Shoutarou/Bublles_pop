#include "stdafx.h"
#include "Core_A.h"
#include "tkEngine/light/tkPointLight.h"

Core_A::Core_A()
{
}

Core_A::~Core_A()
{
}

bool Core_A::Start()
{
	SetALL();

	SetSkinModel();

	m_skin->Init(L"ModelData/kakukin.cmo");

	return true;
	
}


void Core_A::SetALL() {


	//ポイントライトを生成。

	ptLight = NewGO<prefab::CPointLight>(0);
	//ポイントライトの座標をcore_funの座標で決定する。
	
	ptLight->SetPosition(fungus_position);
	//ポイントライトのカラーをランダムで決定する。
	CVector3 color;
	color.x = CMath::Lerp((float)Random().GetRandDouble(), 300.0f, 1000.0f);
	color.y = CMath::Lerp((float)Random().GetRandDouble(), 300.0f, 1000.0f);
	color.z = CMath::Lerp((float)Random().GetRandDouble(), 300.0f, 1000.0f);
	ptLight->SetColor(color);
	//ポイントライトの減衰パラメータを設定する・
	CVector3 attn = CVector3::Zero;
	attn.x = 80.0f;		//5mまで光の影響を与える。
	attn.y = 5.0f;
	ptLight->SetAttn(attn);
	//ポイントライトのリストに積む。
	m_pointLightList.push_back(ptLight);

}


void Core_A::Update()
{
	ptLight->SetPosition(fungus_position);
	Move();
}
