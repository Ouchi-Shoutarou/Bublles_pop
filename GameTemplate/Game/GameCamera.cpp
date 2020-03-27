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
	//注視点から視点までのベクトルを設定。
	m_toCameraPos.Set(0.0f, 50.0f, 100.0f);
	//プレイヤーのインスタンスを探す。
	m_player = FindGO<Player>("プレイヤー");

		//カメラを設定。
	MainCamera().SetTarget(CVector3::Zero);
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(10000.0f);
	MainCamera().SetPosition({ 0.0f, 70.0f, 200.0f });
	MainCamera().Update();

	return true;
}

void GameCamera::Update()
{

	//カメラを更新。
	//注視点を計算する。
	CVector3 target = m_player->GetPos();
	//プレイヤの足元からちょっと上を注視点とする。
	target.y += 80.0f;
	target += m_player->GetRight() * 30;

	CVector3 toCameraPosOld = m_toCameraPos;
	//パッドの入力を使ってカメラを回す。
	float x = Pad(0).GetRStickXF();
	float y = Pad(0).GetRStickYF();
	//Y軸周りの回転
	CQuaternion qRot;
	qRot.SetRotationDeg(CVector3::AxisY, 4.0f * x);
	qRot.Multiply(m_toCameraPos);
	//X軸周りの回転。
	CVector3 axisX;
	axisX.Cross(CVector3::AxisY, m_toCameraPos);
	axisX.Normalize();
	qRot.SetRotationDeg(axisX, 4.0f * y);
	qRot.Multiply(m_toCameraPos);
	//カメラの回転の上限をチェックする。
	//注視点から視点までのベクトルを正規化する。
	//正規化すると、ベクトルの大きさが１になる。
	//大きさが１になるということは、ベクトルから強さがなくなり、方向のみの情報となるということ。
	CVector3 toPosDir = m_toCameraPos;
	toPosDir.Normalize();
	if (toPosDir.y < -0.5f) {
		//カメラが上向きすぎ。
		m_toCameraPos = toCameraPosOld;
	}
	else if (toPosDir.y > 0.8f) {
		//カメラが下向きすぎ。
		m_toCameraPos = toCameraPosOld;
	}

	//視点を計算する。
	CVector3 pos = target + m_toCameraPos;
	//メインカメラに注視点と視点を設定する。
	//プレイヤーの横方向をとって、常にプレイヤーの右側にタゲが行くようにしようぜ
	MainCamera().SetTarget(target);
	MainCamera().SetPosition(pos);
	
	//カメラの更新。
	MainCamera().Update();
}