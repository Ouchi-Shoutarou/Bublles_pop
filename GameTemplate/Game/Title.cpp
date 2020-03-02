#include "stdafx.h"
#include "Title.h"



Title::Title()
{
	m_sprite = NewGO<prefab::CSpriteRender>(0);
	m_sprite->Init(L"sprite/title.dds",1280.0f,720.0f);
}

Title::~Title()
{
	DeleteGO(m_sprite);
	DeleteGO(m_sprite_bottom);

}

bool Title::Start()
{
	return true;
}

void Title::Update()
{
	if (Pad(0).IsPress(enButtonA)) {Sbottom_Flag = true;}
	if (Sbottom_Flag == true&&m_timer<30) {DeleteGO(this);}

	m_timer++;


	if (m_timer == 1) {
		m_sprite_bottom = NewGO<prefab::CSpriteRender>(0);
		m_sprite_bottom->Init(L"sprite/bottom.dds", 210.0f, 210.0f);
		m_sprite_bottom->SetPosition({ 480.0f,-300.0f ,0.0f});
	}
	
	else if (m_timer==30) {
		DeleteGO(m_sprite_bottom);}

	else if (m_timer==60) {m_timer = 0;}

}
