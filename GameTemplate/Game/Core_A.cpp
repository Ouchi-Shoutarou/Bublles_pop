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


	//�|�C���g���C�g�𐶐��B

	ptLight = NewGO<prefab::CPointLight>(0);
	//�|�C���g���C�g�̍��W��core_fun�̍��W�Ō��肷��B
	
	ptLight->SetPosition(fungus_position);
	//�|�C���g���C�g�̃J���[�������_���Ō��肷��B
	CVector3 color;
	color.x = CMath::Lerp((float)Random().GetRandDouble(), 300.0f, 1000.0f);
	color.y = CMath::Lerp((float)Random().GetRandDouble(), 300.0f, 1000.0f);
	color.z = CMath::Lerp((float)Random().GetRandDouble(), 300.0f, 1000.0f);
	ptLight->SetColor(color);
	//�|�C���g���C�g�̌����p�����[�^��ݒ肷��E
	CVector3 attn = CVector3::Zero;
	attn.x = 80.0f;		//5m�܂Ō��̉e����^����B
	attn.y = 5.0f;
	ptLight->SetAttn(attn);
	//�|�C���g���C�g�̃��X�g�ɐςށB
	m_pointLightList.push_back(ptLight);

}


void Core_A::Update()
{
	ptLight->SetPosition(fungus_position);
	Move();
}
