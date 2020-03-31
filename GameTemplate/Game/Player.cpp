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
	//キャラクターコントローラーを初期化。
	m_charaCon.Init(
		20.0,			//半径。 
		50.0f,			//高さ。
		m_position		//初期位置。
	);

	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/unityChan.cmo");
	m_position = { 0,0,0 };
	m_skinModelRender->SetPosition(m_position);
	
	return true;
}

void Player::Move()
{
	//左スティックの入力量を受け取る。
	float lStick_x = Pad(0).GetLStickXF();
	float lStick_y = Pad(0).GetLStickYF();




	//カメラの前方方向と右方向を取得。
	CVector3 cameraForward = MainCamera().GetForward();
	CVector3 cameraRight = MainCamera().GetRight();
	//XZ平面での前方方向、右方向に変換する。
	cameraForward.y = 0.0f;
	cameraForward.Normalize();
	cameraRight.y = 0.0f;
	cameraRight.Normalize();
	//XZ成分の移動速度をクリア。
	m_moveSpeed.x = 0.0f;
	m_moveSpeed.z = 0.0f;
	m_moveSpeed.y -= 980.0f * GameTime().GetFrameDeltaTime();
	m_moveSpeed += cameraForward * lStick_y * 200.0f;	//奥方向への移動速度を加算。
	m_moveSpeed += cameraRight * lStick_x * 200.0f;		//右方向への移動速度を加算。

	if (Pad(0).IsTrigger(enButtonA) //Aボタンが押されたら
		&& m_charaCon.IsOnGround()  //かつ、地面に居たら
		) {
		//ジャンプする。
		m_moveSpeed.y = 400.0f;	//上方向に速度を設定して、
	}

	m_position = m_charaCon.Execute(m_moveSpeed);
}

void Player::Jump_Up()
{

	if (Pad(0).IsPress(enButtonB)) {
		//エフェクトを作成。
		prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
		//エフェクトを再生。
		effect->Play(L"effect/awa2.efk");
		CVector3 emitPos = m_position;
		CVector3 emitscale = CVector3::One;
	
		emitPos.y = 10.0f;
		effect->SetPosition(emitPos);
		effect->SetScale(emitscale);
		m_moveSpeed.y = 0.0f;
		m_moveSpeed.y += 0.0f;

		////////////////とちゅうでBボタンが押されなくなったら今ある泡をすべてデリートしたい。



	}



}

void Player::Turn()
{


	CVector3 cFront = MainCamera().GetForward();
	cFront.y = 0.0f;
	cFront.Normalize();

	//内積から角度を求める。
	float res = m_front.Dot(cFront);
	//念のための非数防止。
	res = max(-1.0f, min(1.0f, res));

	//cosθからラジアン単位に変換。
	float rad = acos(res);

	//回転する方向を決める。
	float dir = m_right.Dot(cFront);

	if (dir < 0.0f) {
		rad *= -1.0f;
	}


	//カメラの方向へ回転。
	CQuaternion r;
	r.SetRotation(CVector3::AxisY, rad);

	//回転の乗算。
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


	//移動処理。
	Move();
	Turn();
	Jump_Up();
	//ワールド行列を更新。
	CQuaternion qBias;
	qBias.SetRotationDeg(CVector3::AxisX, 180.0f);	//3dsMaxで設定されているアニメーションでキャラが回転しているので、補正を入れる。
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(qRot);


}


