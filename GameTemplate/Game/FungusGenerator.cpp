#include "stdafx.h"
#include "FungusGenerator.h"
#include "Kfungus.h"
#include "MeFungus.h"
#include "TFungus.h"
#include "GFungus.h"
#include "Core_A.h"
#include "Bond_Fungus.h"

bool FungusGenerator::Start()
{////ここでレベルしました。
	m_level.Init(L"level/kinlevelme.tkl", [&](LevelObjectData& objData) {


		
		if (objData.EqualObjectName(L"kamekin") == true) {

			me_position=objData.position;

			return true;
		}

		if (objData.EqualObjectName(L"gkin") == true) {

			g_position = objData.position;

			return true;
		}

		if (objData.EqualObjectName(L"kkin") == true) {

			k_position = objData.position;

			return true;
		}

		if (objData.EqualObjectName(L"Tkin") == true) {

			t_position = objData.position;

			return true;
		}

		return false;
		});



	return true;
}

void FungusGenerator::Update()
{
	/*sprintf(script_me, "%d \n", fungus_number);
	fungus_number++;*/
	generator_timer++;


	if (generator_timer % 40 == 0) {
		Generator_Fungus();
	}

	if (generator_timer == 90000) {
		generator_timer = 0;
	}
}

void FungusGenerator::Generator_Fungus()
{

	/////完成したものをいじる。


	/////ジェネレータで各菌のクラスを作成する際に、逐一SetPosition関数を呼び出して、各菌のポジションを代入する。
	
	
	Kfungus* k_fungus=NewGO<Kfungus>(0, "fungus");
	k_fungus->SetPosition(k_position);
	

	fungus_number++;

	MeFungus* me_fungus = NewGO<MeFungus>(0, "fungus");
	me_fungus->SetPosition (me_position);


	fungus_number++;

	TFungus* t_fungus = NewGO<TFungus>(0, "fungus");
	t_fungus->SetPosition (t_position);


	fungus_number++;

	GFungus* g_fungus = NewGO<GFungus>(0, "fungus");
	g_fungus->SetPosition (g_position); 
	

	fungus_number++;

	//Core_A* core_fungus = NewGO<Core_A>(0, "fungus");
	//core_fungus->SetPosition (core_position);

	Bond_Fungus* bond_fungus = NewGO<Bond_Fungus>(0, "fungus");
	bond_fungus->SetPosition(bond_position);

}
