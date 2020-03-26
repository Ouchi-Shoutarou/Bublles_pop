#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
	DeleteGO(m_skinModelRender);
}

bool Player::Start()
{
	//�L�����N�^�[�R���g���[���[���������B
	m_charaCon.Init(
		20.0,			//���a�B 
		50.0f,			//�����B
		m_position		//�����ʒu�B
	);

	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/unityChan.cmo");
	m_position = { 0,0,0 };
	m_skinModelRender->SetPosition(m_position);
	
	return true;
}

void Player::Move()
{
	//���X�e�B�b�N�̓��͗ʂ��󂯎��B
	float lStick_x = Pad(0).GetLStickXF();
	float lStick_y = Pad(0).GetLStickYF();
	//�J�����̑O�������ƉE�������擾�B
	CVector3 cameraForward = MainCamera().GetForward();
	CVector3 cameraRight = MainCamera().GetRight();
	//XZ���ʂł̑O�������A�E�����ɕϊ�����B
	cameraForward.y = 0.0f;
	cameraForward.Normalize();
	cameraRight.y = 0.0f;
	cameraRight.Normalize();
	//XZ�����̈ړ����x���N���A�B
	m_moveSpeed.x = 0.0f;
	m_moveSpeed.z = 0.0f;
	m_moveSpeed.y -= 980.0f * GameTime().GetFrameDeltaTime();
	m_moveSpeed += cameraForward * lStick_y * 200.0f;	//�������ւ̈ړ����x�����Z�B
	m_moveSpeed += cameraRight * lStick_x * 200.0f;		//�E�����ւ̈ړ����x�����Z�B

	if (Pad(0).IsTrigger(enButtonA) //A�{�^���������ꂽ��
		&& m_charaCon.IsOnGround()  //���A�n�ʂɋ�����
		) {
		//�W�����v����B
		m_moveSpeed.y = 400.0f;	//������ɑ��x��ݒ肵�āA
	}

	m_position = m_charaCon.Execute(m_moveSpeed);
}



void Player::Update()
{
	CMatrix mRot;
	mRot.MakeRotationFromQuaternion(qRot);
	m_front.Set(mRot.m[2][0], mRot.m[2][1], mRot.m[2][2]);
	m_front.Normalize();
	m_right.Set(mRot.m[0][0], mRot.m[0][1], mRot.m[0][2]);
	m_right.Normalize();
	m_up.Set(mRot.m[1][0], mRot.m[1][1], mRot.m[1][2]);
	m_up.Normalize();
	/*m_moveSpeed.x = Pad(0).GetLStickXF() * -7.0f;

	m_moveSpeed.z = Pad(0).GetLStickYF() * 7.0f;

	m_position += m_moveSpeed;

	m_skinModelRender->SetPosition(m_position);*/

	//�ړ������B
	Move();

	//���[���h�s����X�V�B
	CQuaternion qBias;
	qBias.SetRotationDeg(CVector3::AxisX, 180.0f);	//3dsMax�Őݒ肳��Ă���A�j���[�V�����ŃL��������]���Ă���̂ŁA�␳������B
	m_skinModelRender->SetPosition(m_position);
	//m_skinModelRender->SetRotation(qBias);

}


