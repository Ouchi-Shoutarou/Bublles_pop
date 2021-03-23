#include "stdafx.h"
#include "GameCamera.h"
#include"Player.h"


GameCamera :: GameCamera() 
{
}

GameCamera::~GameCamera()
{
	DeleteGO(m_spriteRender);

}

bool GameCamera::Start()
{
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/�^�J�[�\��.dds", 1280, 720);
	m_spriteRender->SetPivot({0.5f, 0.5f});
	m_spriteRender->SetPosition({0.0f,150.0f,0.0f});
	//�v���C���[�̃C���X�^���X��T���B
	m_player = FindGO<Player>("�v���C���[");

		//�J������ݒ�B
	MainCamera().SetTarget(CVector3::Zero);
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(10000.0f);
	MainCamera().SetPosition({ 0.0f, 70.0f, 200.0f });
	MainCamera().Update();




///////////�v���C���[�̉������������x�N�g�������߂܂��B
//
//
//	CMatrix mRot;
//	mRot.MakeRotationFromQuaternion(m_player->GetRotation());
//	CVector3 Right = { mRot.m[0][0],mRot.m[0][1],mRot.m[0][2] };
//	Right.Normalize();
//
//
//	/////////�v���C���[�̑O�����������������x�N�g�������߂܂��B
//	
//
//	CVector3 forward = { mRot.m[2][0],mRot.m[2][1],mRot.m[2][2] };
//	forward.Normalize();

	to_P_T *= 150.0f;


	to_P_T.y -= 30.0f;

	return true;
}

void GameCamera::Update()
{


	//�p�b�h�̓��͂��g���ăJ�������񂷁B


	float x = Pad(0).GetRStickXF();
    float y = Pad(0).GetRStickYF();



	

	//Y������̉�]
	CQuaternion qRot;
	qRot.SetRotationDeg(CVector3::AxisY, 2.0f * x);
	qRot.Multiply(to_P_T);


	///////�^�[�Q�b�g�ƃv���C���[�ɐ����ȃx�N�g�����쐬�������ɃJ�����̈ʒu�����܂����B

	/////�O��

	/////[y1z2-z1y2],[z1x2-x1z2],[x1y2-y1x2]

	to_T_C =
	{
		to_P_T.y * 0.0f -to_P_T.z * 1.0f,
		to_P_T.z * 0.0f - to_P_T.x * 0.0f,
		to_P_T.x * 1.0f - to_P_T.y * 0.0f
	};


		 /////////����������ʒu�Ɋg�傷��B


	 to_T_C *= 2.0f;



	//////X������̉�]�B
	//CVector3 axisX;
	//CVector3 V = to_P_T - to_P_C;
	//V.Normalize();

	//axisX.Cross(CVector3::AxisY, V);
	//axisX.Normalize();
	//qRot.SetRotationDeg(axisX, 2.0f * y);
	//qRot.Multiply(to_P_T);
	//qRot.Multiply(to_P_C);


	//////�J�����̉�]�̏�����`�F�b�N����B
	//////�����_���王�_�܂ł̃x�N�g���𐳋K������B
	//////���K������ƁA�x�N�g���̑傫�����P�ɂȂ�B
	//////�傫�����P�ɂȂ�Ƃ������Ƃ́A�x�N�g�����狭�����Ȃ��Ȃ�A�����݂̂̏��ƂȂ�Ƃ������ƁB
	//CVector3 toPosDir = to_P_T-to_P_C;
	//toPosDir.Normalize();
	//if (toPosDir.y < -0.8f) {
	//	//�J����������������B
	//	to_P_T = toTarGetPosOld;
	//	to_P_C = toCameraPosOld;
	//}
	//else if (toPosDir.y > 0.5f) {
	//	//�J�����������������B
	//	to_P_T = toTarGetPosOld;
	//	to_P_C = toCameraPosOld;
	//}

	


	 ////////////�v���C���[�̈ʒu��p�Ƃ����������̂��^�[�Q�b�g
	 ////////////��̌��ʂɂ����𑫂������̂��J�����̈ʒu�B

	
 
     Camera_target = m_player->GetPos() - to_P_T;
	 Camera_pos = Camera_target +to_T_C; 


	 Camera_pos.y += 50.0f;
	 

	 y *= 3;

	 hight += y;

	 Camera_target.y += hight;

	//���C���J�����ɒ����_�Ǝ��_��ݒ肷��B
	MainCamera().SetTarget(Camera_target);
	MainCamera().SetPosition(Camera_pos);

	
	
	//�J�����̍X�V�B
	MainCamera().Update();
}