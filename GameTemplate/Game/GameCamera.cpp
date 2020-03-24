#include "stdafx.h"
#include "GameCamera.h"

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
	m_spriteRender->Init(L"sprite/�^�J�[�\��.dds", 1280, 720, true);
	CQuaternion Rot2D;
	Rot2D.SetRotationDeg(CVector3::AxisY, 180);
	m_spriteRender->SetRotation(Rot2D);
	m_spriteRender->SetPivot({ 0.5f,0.5f });
	//m_position = { -20,80,0 };
	//m_spriteRender->SetPosition(m_position);

	//�����_���王�_�܂ł̃x�N�g����ݒ�B
	m_toCameraPos.Set(0.0f, 50.0f, 100.0f);
	//�v���C���[�̃C���X�^���X��T���B
	m_player = FindGO<Player>("�v���C���[");

		//�J������ݒ�B
	MainCamera().SetTarget(CVector3::Zero);
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(10000.0f);
	MainCamera().SetPosition({ 0.0f, 70.0f, 200.0f });
	MainCamera().Update();

	return true;
}

void GameCamera::Update()
{
	/*m_spriteRender->SetPosition(m_position);

	m_moveSpeed.x = Pad(0).GetRStickXF() * -7.0f;

	m_moveSpeed.y = Pad(0).GetRStickYF() * 7.0f;

	m_position += m_moveSpeed;

	m_spriteRender->SetPosition(m_position);

	CVector3 position = m_position;
	position.y += 0.0f;
	position.z += 300.0f;
	MainCamera().SetTarget(m_position);
	MainCamera().SetPosition(position);
	MainCamera().Update();*/

	//�J�������X�V�B
	//�����_���v�Z����B
	CVector3 target = m_player->m_position;
	//�v���C���̑������炿����Ə�𒍎��_�Ƃ���B
	target.y += 50.0f;

	CVector3 toCameraPosOld = m_toCameraPos;
	//�p�b�h�̓��͂��g���ăJ�������񂷁B
	float x = Pad(0).GetRStickXF();
	float y = Pad(0).GetRStickYF();
	//Y������̉�]
	CQuaternion qRot;
	qRot.SetRotationDeg(CVector3::AxisY, 2.0f * x);
	qRot.Multiply(m_toCameraPos);
	//X������̉�]�B
	CVector3 axisX;
	axisX.Cross(CVector3::AxisY, m_toCameraPos);
	axisX.Normalize();
	qRot.SetRotationDeg(axisX, 2.0f * y);
	qRot.Multiply(m_toCameraPos);
	//�J�����̉�]�̏�����`�F�b�N����B
	//�����_���王�_�܂ł̃x�N�g���𐳋K������B
	//���K������ƁA�x�N�g���̑傫�����P�ɂȂ�B
	//�傫�����P�ɂȂ�Ƃ������Ƃ́A�x�N�g�����狭�����Ȃ��Ȃ�A�����݂̂̏��ƂȂ�Ƃ������ƁB
	CVector3 toPosDir = m_toCameraPos;
	toPosDir.Normalize();
	if (toPosDir.y < -0.5f) {
		//�J����������������B
		m_toCameraPos = toCameraPosOld;
	}
	else if (toPosDir.y > 0.8f) {
		//�J�����������������B
		m_toCameraPos = toCameraPosOld;
	}

	//���_���v�Z����B
	CVector3 pos = target + m_toCameraPos;
	//���C���J�����ɒ����_�Ǝ��_��ݒ肷��B
	MainCamera().SetTarget(target);
	MainCamera().SetPosition(pos);

	//�J�����̍X�V�B
	MainCamera().Update();
}