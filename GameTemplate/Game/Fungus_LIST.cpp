#include "stdafx.h"
#include "Fungus_LIST.h"
#include "Fungus.h"
#include "Wire.h"

Fungus_LIST::Fungus_LIST()
{
}

Fungus_LIST::~Fungus_LIST()
{
}

bool Fungus_LIST::Start()
{

	for (int i = 0; i < m_kinList.size()-1; i++) {

		CVector3 dir = {m_kinList[i]->GetPosition() - m_kinList[i + 1]->GetPosition()};

		float len = dir.Length();

		m_wire->SetScale({ 1.0f,len/100.0f,1.0f });

	}





	return true;
}


void Fungus_LIST::SetMove()
{

}


void Fungus_LIST::UpdateMove() {

	m_wire = NewGO<Wire>(0, "wire");

	//////この関数が呼ばれるということは、新しく菌がこのリストにpushbackされたということである。

	/////////wireのポジションを設定する。

	//////////接触判定したインスタンスがリストの何番目にあるか探査するプログラムがいる。

	////////////０番目に入っているポインタのインスタンスからポジションを確保する。

	m_wire->Set_Wire_Position(m_kinList[m_kinList.size()-1]->GetPosition());  ////////////////これで新しい菌が今あるグループもしくは菌に接触した場合、
	/////////////インスタンス（接触判定をしたインスタンス）から最後のインスタンス（新しく追加されたインスタンス）にベクトルが伸びて距離を把握することができる。）

	//////////１番目に入っているポインタのインスタンスからポジションを確保して、回す。

	

	//////////接触判定したインスタンスとされたインスタンス同士をつなぐようにしてワイヤーを生成する。





	NewSpeed = CVector3::Zero;
	
	/////このNewSpeedにリストに入っているスピードを代入する。

	for (int d = 0; d < m_kinList.size(); d++){

		NewSpeed += m_kinList[d]->Get_Speed();

	}

	////////////////スピードを代入する。

	for (int i = 0; i < m_wireList.size(); i++) {
		m_wire->Set_Wire_Speed(NewSpeed);
	}
	
	NewSpeed /= m_kinList.size();


	for (int i = 0; i < m_kinList.size(); i++)
	{	
		m_kinList[i]->Set_Speed(NewSpeed);

	}





}


void Fungus_LIST::Update()
{

	SetMove();

}
