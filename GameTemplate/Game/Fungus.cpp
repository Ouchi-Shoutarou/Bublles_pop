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
		if (kin->IsDead()) {
			return true;
		}


		//２点間の距離を計算する。
		CVector3 diff = kin->fungus_position - fungus_position;
		if (diff.Length() < 20.0f * 5.0f) {	//距離が2000以下になったら。


			m_kin = kin;

			////////生成モンスターの作成。

			//////////モンスターナンバーに応じてもんすーを召喚。


			////////////ｋ菌がいないとアクションはないので先に選別をしておく。

			if (result_monster_number==1&& kin->Get_Result_Monster_number() ==1) {
				


			/////////ｋ菌(mostere_number=1)とg菌(mostere_number=2)が融合すればゴキブリが生成されます。


				if (result_monster_number + kin->Get_Result_Monster_number() == 3) {
					///////ゴキブリを生成する。



				}
				/////////ｋ菌(mostere_number=1)とme菌(mostere_number=3)が融合すればカメムシが生成されます。


				if (result_monster_number + kin->Get_Result_Monster_number() == 4) {
					///////カメムシを生成する。



				}


				////////////この場合リストは廃棄される。
			    ///自分が所属しているリストにあるインスタンスも破棄します。
				if (k_list != nullptr) {
					for (int i = 0; i < k_list->m_kinList.size(); i++)
					{

						DeleteGO(k_list->m_kinList[i]);


					}
				}

				///相手が所属していたリストにあるインスタンスも破壊します。
				if (kin->Get_Belonging_List() != nullptr) {
					for (int i = 0; i < kin->Get_Belonging_List()->m_kinList.size(); i++)
					{

						DeleteGO(kin->Get_Belonging_List()->m_kinList[i]);


					}
				}


				/////////////相手が所属していたリストのワイヤーもすべて消去。

				for (int i = 0; i <k_list->m_wireList.size(); i++) {

					DeleteGO(k_list->m_wireList[i]);

				}


				/////////////相手が所属していたリストのワイヤーもすべて消去。

				for (int i = 0; i < kin->Get_Belonging_List()->m_wireList.size(); i++) {

						DeleteGO(kin->Get_Belonging_List()->m_wireList[i]);

				}


				///自分が所属しているリストを崩壊させます。
				DeleteGO(k_list);
				///相手が所属しているリストを崩壊します。

				DeleteGO(kin->k_list);
			
				return true;


			}


			m_wire = NewGO<Wire>(0, "wire");

			//座標の設定。
			m_wire->Set_position(fungus_position);


		

			/////////////自分と相手の距離をベクトル化します。

			CVector3 dir = { kin->GetPosition() - fungus_position };



			////このベクトルの長さを求めてます。

			float len = dir.Length();

			m_wire->SetScale({ 1.0f,len/100,1.0f });

		
			///////求めたベクトルを正規化して、

			dir.Normalize();
			////////今あるベクトルとの外積を求めます。

			CVector3 axisB;
			

			axisB.Cross(CVector3::AxisY, dir);
			axisB.Normalize();

			///////////////内積を求めます。

			float Inner_Product = CVector3::AxisY.Dot(dir);
			//念のための非数防止。
			Inner_Product = max(-1.0f, min(1.0f, Inner_Product));

			//cosθからラジアン単位に変換。
			float Inner_Product_A = acos(Inner_Product);
			
			//回転する方向を決める。
			float dirDot = CVector3::AxisX.Dot(dir);

			if (dirDot < 0.0f) {
				Inner_Product_A *= -1.0f;
			}

			CQuaternion q_Rot;
			q_Rot.SetRotation(axisB,Inner_Product_A);
			q_Rot.Multiply(CQuaternion::Identity);

			m_wire->Set_Rotation(q_Rot);

			///////////自分自身がグループに属しているか？

			/////いいえ

			if (k_list == nullptr) {
				
				////////////共通リストを作成します。

				k_list = NewGO<Fungus_LIST>(0, "list");

				k_list->m_kinList.push_back(this);
		

			}	
		  //////リストクラスのワイヤーのクラスに代入する。
			k_list->m_wireList.push_back(m_wire);


			////相手がリストに属しているか？
			///いいえ

			if (kin->Get_Belonging_List() == nullptr) {
				
				////自分が所属しているリストに相手のポインタを代入します。
			
				k_list->m_kinList.push_back(kin);


				///////相手のリストのポインタに自分のリストのポインタを代入します。
				//////相手に自分の所属先を伝える。

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

				

				}

				for (int i = 0; i < kin->Get_Belonging_List()->m_wireList.size(); i++) {

					k_list->m_wireList.push_back(

						kin->Get_Belonging_List()->m_wireList[i]
					);

					

				}	
				
				k_list->UpdateMove();

				/////古いグループを削除します。

				DeleteGO(kin->Get_Belonging_List());
				 

				/////

				for (int i = 0; i < k_list->m_kinList.size();i++) {


					//////再通知

					k_list->m_kinList[i]->k_list = k_list;
				}
			}

 

		

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

