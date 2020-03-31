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

void Player::Jump_Up()
{

	if (Pad(0).IsPress(enButtonB)) {
		//�G�t�F�N�g���쐬�B
		prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
		//�G�t�F�N�g���Đ��B
		effect->Play(L"effect/awa2.efk");
		CVector3 emitPos = m_position;
		CVector3 emitscale = CVector3::One;
	
		emitPos.y = 10.0f;
		effect->SetPosition(emitPos);
		effect->SetScale(emitscale);
		m_moveSpeed.y = 0.0f;
		m_moveSpeed.y += 0.0f;

		////////////////�Ƃ��イ��B�{�^����������Ȃ��Ȃ����獡����A�����ׂăf���[�g�������B



	}



}

void Player::Turn()
{


	CVector3 cFront = MainCamera().GetForward();
	cFront.y = 0.0f;
	cFront.Normalize();

	//���ς���p�x�����߂�B
	float res = m_front.Dot(cFront);
	//�O�̂��߂̔񐔖h�~�B
	res = max(-1.0f, min(1.0f, res));

	//cos�Ƃ��烉�W�A���P�ʂɕϊ��B
	float rad = acos(res);

	//��]������������߂�B
	float dir = m_right.Dot(cFront);

	if (dir < 0.0f) {
		rad *= -1.0f;
	}


	//�J�����̕����։�]�B
	CQuaternion r;
	r.SetRotation(CVector3::AxisY, rad);

	//��]�̏�Z�B
	qRot.Multiply(r);





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


	//�ړ������B
	Move();
	Turn();
	Jump_Up();
	//���[���h�s����X�V�B
	CQuaternion qBias;
	qBias.SetRotationDeg(CVector3::AxisX, 180.0f);	//3dsMax�Őݒ肳��Ă���A�j���[�V�����ŃL��������]���Ă���̂ŁA�␳������B
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(qRot);


}


