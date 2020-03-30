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
	m_spriteRender->Init(L"sprite/真カーソル.dds", 1280, 720);
	m_spriteRender->SetPivot({0.5f, 0.5f});

	//プレイヤーのインスタンスを探す。
	m_player = FindGO<Player>("プレイヤー");

		//カメラを設定。
	MainCamera().SetTarget(CVector3::Zero);
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(10000.0f);
	MainCamera().SetPosition({ 0.0f, 70.0f, 200.0f });
	MainCamera().Update();




/////////プレイヤーの横方向を示すベクトルを求めます。


	CMatrix mRot;
	mRot.MakeRotationFromQuaternion(m_player->GetRotation());
	CVector3 Right = { mRot.m[0][0],mRot.m[0][1],mRot.m[0][2] };
	Right.Normalize();
	Right *= -150;


	/////////プレイヤーの前方向横方向を示すベクトルを求めます。
	

	CMatrix pRot;
	mRot.MakeRotationFromQuaternion(m_player->GetRotation());
	CVector3 forward = { pRot.m[2][0],pRot.m[2][1],pRot.m[2][2] };
	forward.Normalize();
	forward *= -500;


	///////////ターゲットとプレイヤーの距離を求めるベクトルを作成します。



	//////////プレイヤーの右方向に注視する点を作成します。
	to_P_T = {Right};

	/////////その後ろ方向にカメラの位置をセットします。

	to_P_C = {Right.x,40.0f,forward.z };


	return true;
}

void GameCamera::Update()
{


	CVector3 toCameraPosOld = to_P_T;

	//パッドの入力を使ってカメラを回す。
	float x = Pad(0).GetRStickXF();
	float y = Pad(0).GetRStickYF();

	x *=- 1.5;
	y *= 2;


	//Y軸周りの回転
	CQuaternion qRot;
	qRot.SetRotationDeg(CVector3::AxisY, 2.0f * x);
	qRot.Multiply(to_P_T);

	qRot.SetRotationDeg(CVector3::AxisY, 2.0f * x);
	qRot.Multiply(to_P_C);



	////X軸周りの回転。
	CVector3 axisX;
	axisX.Cross(CVector3::AxisY, to_P_T);
	axisX.Normalize();
	qRot.SetRotationDeg(axisX, 2.0f * y);
	qRot.Multiply(to_P_T);


	//カメラの回転の上限をチェックする。
	//注視点から視点までのベクトルを正規化する。
	//正規化すると、ベクトルの大きさが１になる。
	//大きさが１になるということは、ベクトルから強さがなくなり、方向のみの情報となるということ。
	CVector3 toPosDir = to_P_T;
	toPosDir.Normalize();
	if (toPosDir.y < -1.0f) {
		//カメラが上向きすぎ。
		to_P_T = toCameraPosOld;
	}
	else if (toPosDir.y > 1.0f) {
		//カメラが下向きすぎ。
		to_P_T = toCameraPosOld;
	}

	//視点を計算する。
	CVector3 Camera_Target = m_player->GetPos() + to_P_T;
	CVector3 Camerapos = m_player->GetPos() +to_P_C; 


	Camera_Target.y += 70.0f;

	//メインカメラに注視点と視点を設定する。
	MainCamera().SetTarget(Camera_Target);
	MainCamera().SetPosition(Camerapos);

	

	////カメラを更新。
	////注視点を計算する。
	//CVector3 target = m_player->GetPos();
	////プレイヤの足元からちょっと上を注視点とする。
	//target.y += 80.0f;
	//target += m_player->GetRight() * 30;

	//CVector3 toCameraPosOld = m_toCameraPos;
	////パッドの入力を使ってカメラを回す。
	//float x = Pad(0).GetRStickXF();
	//float y = Pad(0).GetRStickYF();
	////Y軸周りの回転
	//CQuaternion qRot;
	//qRot.SetRotationDeg(CVector3::AxisY, 4.0f * x);
	//qRot.Multiply(m_toCameraPos);
	////X軸周りの回転。
	//CVector3 axisX;
	//axisX.Cross(CVector3::AxisY, m_toCameraPos);
	//axisX.Normalize();
	//qRot.SetRotationDeg(axisX, 4.0f * y);
	//qRot.Multiply(m_toCameraPos);
	////カメラの回転の上限をチェックする。
	////注視点から視点までのベクトルを正規化する。
	////正規化すると、ベクトルの大きさが１になる。
	////大きさが１になるということは、ベクトルから強さがなくなり、方向のみの情報となるということ。
	//CVector3 toPosDir = m_toCameraPos;
	//toPosDir.Normalize();
	//if (toPosDir.y < -0.5f) {
	//	//カメラが上向きすぎ。
	//	m_toCameraPos = toCameraPosOld;
	//}
	//else if (toPosDir.y > 0.8f) {
	//	//カメラが下向きすぎ。
	//	m_toCameraPos = toCameraPosOld;
	//}

	////視点を計算する。
	//CVector3 pos = target + m_toCameraPos;
	////メインカメラに注視点と視点を設定する。
	////プレイヤーの横方向をとって、常にプレイヤーの右側にタゲが行くようにしようぜ

	
	//カメラの更新。
	MainCamera().Update();
}