#include "stdafx.h"
#include "Fungus.h"
#include "Kfungus.h"
#include "Wire.h"
#include "Fungus_LIST.h"

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

		//////マイナンバーに応じて動きが確定する。
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

		//////リストに積まれたポインタが既に使われているかどうかを判定します。
		//////既に自分のリストに入っているものは省きます。
		if (k_list != nullptr) {
			auto itr = std::find(k_list->m_kinList.begin(), k_list->m_kinList.end(), kin);    //  リストの中から
			if (itr != k_list->m_kinList.end()) {     // 発見した場合

					/////////強制停止

				return true;

			}

		}
		

		if (this->IsDead()) {
			return false;
		}


		//２点間の距離を計算する。
		CVector3 diff = kin->fungus_position - fungus_position;
		if (diff.Length() < 20.0f * 3.0f) {	//距離が2000以下になったら。
			//接触後の処理
			/*if(!kin->IsDead()){
				DeleteGO(kin);
			}*/
			m_kin = kin;

			///////////自分自身がグループに属しているか？

			/////いいえ

			if (k_list == nullptr) {
				
				////////////共通リストを作成します。

				k_list = NewGO<Fungus_LIST>(0, "list");

				k_list->m_kinList.push_back(this);
			
				

			}
		

	

			////相手がリストに属しているか？
			///いいえ

			if (kin->Get_Belonging_List() == nullptr) {
				
				////自分が所属しているリストに相手のポインタを代入します。
			
				k_list->m_kinList.push_back(kin);
				kin->k_list = k_list;



				k_list->UpdateMove();

			}

			else {

				/////相手のリストの中のすべての要素を書き出します。

				for (int i = 0; i < kin->Get_Belonging_List()->m_kinList.size(); i++)
				{
					k_list->m_kinList.push_back
					(
						kin->Get_Belonging_List()->m_kinList[i]
					);

					k_list->UpdateMove();

				}
				/////古いグループを削除します。

				DeleteGO(kin->Get_Belonging_List());

				for (int i = 0; i < k_list->m_kinList.size();i++) {


					//////再通知

					k_list->m_kinList[i]->k_list = k_list;
				}
			}

 

		

		

		/*	DeleteGO(this);*/
			return false;
		}
		return true;
		}
	);
}

void Fungus::Access_To_LIST()
{
}

void Fungus::Cheak_Belonging_List()
{
	

}

void Fungus::Set_Belonging_List(Fungus_LIST* list_A)
{

	Belonging_List = list_A;

}




void Fungus::Bond2() {


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

