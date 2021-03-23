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
	m_spriteRender->SetPosition({0.0f,150.0f,0.0f});
	//プレイヤーのインスタンスを探す。
	m_player = FindGO<Player>("プレイヤー");

		//カメラを設定。
	MainCamera().SetTarget(CVector3::Zero);
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(10000.0f);
	MainCamera().SetPosition({ 0.0f, 70.0f, 200.0f });
	MainCamera().Update();




///////////プレイヤーの横方向を示すベクトルを求めます。
//
//
//	CMatrix mRot;
//	mRot.MakeRotationFromQuaternion(m_player->GetRotation());
//	CVector3 Right = { mRot.m[0][0],mRot.m[0][1],mRot.m[0][2] };
//	Right.Normalize();
//
//
//	/////////プレイヤーの前方向横方向を示すベクトルを求めます。
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


	//パッドの入力を使ってカメラを回す。


	float x = Pad(0).GetRStickXF();
    float y = Pad(0).GetRStickYF();



	

	//Y軸周りの回転
	CQuaternion qRot;
	qRot.SetRotationDeg(CVector3::AxisY, 2.0f * x);
	qRot.Multiply(to_P_T);


	///////ターゲットとプレイヤーに垂直なベクトルを作成しそこにカメラの位置を取りますｌ。

	/////外積

	/////[y1z2-z1y2],[z1x2-x1z2],[x1y2-y1x2]

	to_T_C =
	{
		to_P_T.y * 0.0f -to_P_T.z * 1.0f,
		to_P_T.z * 0.0f - to_P_T.x * 0.0f,
		to_P_T.x * 1.0f - to_P_T.y * 0.0f
	};


		 /////////これをいい位置に拡大する。


	 to_T_C *= 2.0f;



	//////X軸周りの回転。
	//CVector3 axisX;
	//CVector3 V = to_P_T - to_P_C;
	//V.Normalize();

	//axisX.Cross(CVector3::AxisY, V);
	//axisX.Normalize();
	//qRot.SetRotationDeg(axisX, 2.0f * y);
	//qRot.Multiply(to_P_T);
	//qRot.Multiply(to_P_C);


	//////カメラの回転の上限をチェックする。
	//////注視点から視点までのベクトルを正規化する。
	//////正規化すると、ベクトルの大きさが１になる。
	//////大きさが１になるということは、ベクトルから強さがなくなり、方向のみの情報となるということ。
	//CVector3 toPosDir = to_P_T-to_P_C;
	//toPosDir.Normalize();
	//if (toPosDir.y < -0.8f) {
	//	//カメラが上向きすぎ。
	//	to_P_T = toTarGetPosOld;
	//	to_P_C = toCameraPosOld;
	//}
	//else if (toPosDir.y > 0.5f) {
	//	//カメラが下向きすぎ。
	//	to_P_T = toTarGetPosOld;
	//	to_P_C = toCameraPosOld;
	//}

	


	 ////////////プレイヤーの位置にpとぉたしたものがターゲット
	 ////////////上の結果にｔｃを足したものがカメラの位置。

	
 
     Camera_target = m_player->GetPos() - to_P_T;
	 Camera_pos = Camera_target +to_T_C; 


	 Camera_pos.y += 50.0f;
	 

	 y *= 3;

	 hight += y;

	 Camera_target.y += hight;

	//メインカメラに注視点と視点を設定する。
	MainCamera().SetTarget(Camera_target);
	MainCamera().SetPosition(Camera_pos);

	
	
	//カメラの更新。
	MainCamera().Update();
}