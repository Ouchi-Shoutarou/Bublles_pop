#include "stdafx.h"
#include "FungusGenerator.h"
#include "Kfungus.h"

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
	k_fungus->fungus_position = position;

	
}
