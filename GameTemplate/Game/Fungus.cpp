#include "stdafx.h"
#include "Fungus.h"
#include "Kfungus.h"

Fungus::Fungus()
{



}

Fungus::~Fungus()
{
	DeleteGO(m_skin);
}



void Fungus::SetSkinModel()
{	
	
	m_skin = NewGO<prefab::CSkinModelRender>(0);

	m_skin->SetPosition(fungus_position);

	float t = Random().GetRandDouble();
	float k = Random().GetRandDouble();
	float h = Random().GetRandDouble();

	fungus_Speed.x = CMath::Lerp(t, -7.0f, 7.0f);
	fungus_Speed.y = CMath::Lerp(k, -7.0f, 7.0f);
	fungus_Speed.z = CMath::Lerp(h, -7.0f, 7.0f);
}


void Fungus::Move()
{

	fungus_position += fungus_Speed;

	m_skin->SetPosition(fungus_position);

	m_timer++;


	if (m_timer == 400) {

		DeleteGO(this);
	}
}



void Fungus::Bond() {	
	//PlayerBulletという名前のゲームオブジェクトに対してクエリ(問い合わせ)を行う。
	QueryGOs<Fungus>("fungus", [&](Fungus* kin) {
		if (kin == this) {
			return true;
		}
		if (this->IsDead()) {
			return false;
		}
		//２点間の距離を計算する。
		CVector3 diff = kin->fungus_position - fungus_position;
		if (diff.Length() < 20.0f) {	//距離が2000以下になったら。
			//死亡。
			if(!kin->IsDead()){
				DeleteGO(kin);
			}
			DeleteGO(this);
			return false;
		}
		return true;
		}
	);
}


void Fungus::Bond2() {


	//FindGO<Fungus>("fungus", 0);



	//PlayerBulletという名前のゲームオブジェクトに対してクエリ(問い合わせ)を行う。
	QueryGOs<Fungus>("fungus", [&](Fungus* kin) {
		if (kin == this) {
			return true;
		}
		if (this->IsDead()) {
			return false;
		}
		//２点間の距離を計算する。
		CVector3 diff = kin->fungus_position - fungus_position;
		if (diff.Length() < 20.0f) {	//距離が2000以下になったら。
			//死亡。
			if (!kin->IsDead()) {
				DeleteGO(kin);
			}
			DeleteGO(this);
			return false;
		}
		return true;
		}
	);
}

















/////////////////////////近いうちに必ず軽量化させます。！！！！！！！！！！！！

void Fungus::Circle_cheak()
{


	//CVector3 Length = fungus_position;
	//
	//float len = Length.x * Length.x+ Length.y* Length.y+ Length.z* Length.z;
	//

	//
	//////三角形の中で一番近い点を算出します。

	////////外心の座標を算出します。

	//CVector3 OUTHeat ={
	//	(sin(2) * Length.x) / (sin(2) + sin(2) + sin(2))
	//	(sin(2) * Length.y) / (sin(2) + sin(2) + sin(2))
	//	(sin(2) * Length.z) / (sin(2) + sin(2) + sin(2))
	//};

	//
}
