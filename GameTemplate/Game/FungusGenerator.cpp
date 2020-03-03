#include "stdafx.h"
#include "FungusGenerator.h"
#include "Kfungus.h"
#include "MeFungus.h"
#include "TFungus.h"
#include "GFungus.h"

bool FungusGenerator::Start()
{
	return true;
}

void FungusGenerator::Update()
{
	sprintf(script_me, "%d \n", fungus_number);
	fungus_number++;
	generator_timer++;


	if (generator_timer % 30 == 0) {
		Generator_Fungus();
	}

	if (generator_timer == 90000) {
		generator_timer = 0;
	}
}

void FungusGenerator::Generator_Fungus()
{
	Kfungus* k_fungus=NewGO<Kfungus>(0, script_me);
	k_fungus->fungus_position = k_position;

	MeFungus* me_fungus = NewGO<MeFungus>(0, script_me);
	me_fungus->fungus_position = me_position;

	TFungus* t_fungus = NewGO<TFungus>(0, script_me);
	t_fungus->fungus_position = t_position;

	GFungus* g_fungus = NewGO<GFungus>(0, script_me);
	g_fungus->fungus_position = g_position;
}
