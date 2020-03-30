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


	///////////�^�[�Q�b�g�ƃv���C���[�̋��������߂�x�N�g�����쐬���܂��B

	CVector3 forward = CVector3::AxisZ;
	CVector3 Right = CVector3::AxisX;


	//////////�v���C���[�̉E�����ɒ�������_���쐬���܂��B
	to_P_T = forward * 80.0f + Right * 30.0f;
	to_P_T.y += 70.0f;

	/////////���̌������ɃJ�����̈ʒu���Z�b�g���܂��B

	to_P_C = forward * -200.0f + Right * 100.0f;
	to_P_C.y += 70.0f;


	return true;
}

void GameCamera::Update()
{


	CVector3 toCameraPosOld = to_P_C;
	CVector3 toTarGetPosOld = to_P_T;

	//�p�b�h�̓��͂��g���ăJ�������񂷁B
	float x = Pad(0).GetRStickXF();
	float y = Pad(0).GetRStickYF();




	x *=- 1.5;
	y *= 2;


	//Y������̉�]
	CQuaternion qRot;
	qRot.SetRotationDeg(CVector3::AxisY, 2.0f * x);
	qRot.Multiply(to_P_T);

	qRot.SetRotationDeg(CVector3::AxisY, 2.0f * x);
	qRot.Multiply(to_P_C);



	////X������̉�]�B
	CVector3 axisX;
	CVector3 V = to_P_T - to_P_C;
	V.Normalize();

	axisX.Cross(CVector3::AxisY, V);
	axisX.Normalize();
	qRot.SetRotationDeg(axisX, 2.0f * y);
	qRot.Multiply(to_P_T);
	qRot.Multiply(to_P_C);


	////�J�����̉�]�̏�����`�F�b�N����B
	////�����_���王�_�܂ł̃x�N�g���𐳋K������B
	////���K������ƁA�x�N�g���̑傫�����P�ɂȂ�B
	////�傫�����P�ɂȂ�Ƃ������Ƃ́A�x�N�g�����狭�����Ȃ��Ȃ�A�����݂̂̏��ƂȂ�Ƃ������ƁB
	CVector3 toPosDir = to_P_T-to_P_C;
	toPosDir.Normalize();
	if (toPosDir.y < -0.8f) {
		//�J����������������B
		to_P_T = toTarGetPosOld;
		to_P_C = toCameraPosOld;
	}
	else if (toPosDir.y > 0.5f) {
		//�J�����������������B
		to_P_T = toTarGetPosOld;
		to_P_C = toCameraPosOld;
	}

	//���_���v�Z����B
	CVector3 Camera_Target = m_player->GetPos() + to_P_T;
	CVector3 Camerapos = m_player->GetPos() +to_P_C; 


	//Camera_Target.y += 70.0f;
	Camerapos += m_player->GetRight() * 30.0f;

	//���C���J�����ɒ����_�Ǝ��_��ݒ肷��B
	MainCamera().SetTarget(Camera_Target);
	MainCamera().SetPosition(Camerapos);

	

	////�J�������X�V�B
	////�����_���v�Z����B
	//CVector3 target = m_player->GetPos();
	////�v���C���̑������炿����Ə�𒍎��_�Ƃ���B
	//target.y += 80.0f;
	//target += m_player->GetRight() * 30;

	//CVector3 toCameraPosOld = m_toCameraPos;
	////�p�b�h�̓��͂��g���ăJ�������񂷁B
	//float x = Pad(0).GetRStickXF();
	//float y = Pad(0).GetRStickYF();
	////Y������̉�]
	//CQuaternion qRot;
	//qRot.SetRotationDeg(CVector3::AxisY, 4.0f * x);
	//qRot.Multiply(m_toCameraPos);
	////X������̉�]�B
	//CVector3 axisX;
	//axisX.Cross(CVector3::AxisY, m_toCameraPos);
	//axisX.Normalize();
	//qRot.SetRotationDeg(axisX, 4.0f * y);
	//qRot.Multiply(m_toCameraPos);
	////�J�����̉�]�̏�����`�F�b�N����B
	////�����_���王�_�܂ł̃x�N�g���𐳋K������B
	////���K������ƁA�x�N�g���̑傫�����P�ɂȂ�B
	////�傫�����P�ɂȂ�Ƃ������Ƃ́A�x�N�g�����狭�����Ȃ��Ȃ�A�����݂̂̏��ƂȂ�Ƃ������ƁB
	//CVector3 toPosDir = m_toCameraPos;
	//toPosDir.Normalize();
	//if (toPosDir.y < -0.5f) {
	//	//�J����������������B
	//	m_toCameraPos = toCameraPosOld;
	//}
	//else if (toPosDir.y > 0.8f) {
	//	//�J�����������������B
	//	m_toCameraPos = toCameraPosOld;
	//}

	////���_���v�Z����B
	//CVector3 pos = target + m_toCameraPos;
	////���C���J�����ɒ����_�Ǝ��_��ݒ肷��B
	////�v���C���[�̉��������Ƃ��āA��Ƀv���C���[�̉E���Ƀ^�Q���s���悤�ɂ��悤��

	
	//�J�����̍X�V�B
	MainCamera().Update();
}