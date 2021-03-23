#include "stdafx.h"
#include "Bullet.h"
Bullet::Bullet()
{
}


Bullet::~Bullet()
{
	DeleteGO(m_skinModelRender);
}
bool Bullet::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/tama.cmo");

	return true;
}

void Bullet::Update()
{
	m_position += m_moveSpeed * 30;// 30のスピードで飛ばす
	m_skinModelRender->SetPosition(m_position);

	m_timer++;
	if (m_timer == 50) {
		DeleteGO(this);
	}

}