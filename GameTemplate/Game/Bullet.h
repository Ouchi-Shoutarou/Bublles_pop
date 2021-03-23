#pragma once
#include"Game.h"
class Bullet : public IGameObject
{
public:
	Bullet();
	~Bullet();
	bool Start();
	void Update();
	void SetPosition(CVector3& pos) {  //bulletの発生位置を決める
			m_position = pos;
	}
	void SetDirection(CVector3& pos) { //bulletの方向をきめる
		m_moveSpeed = pos;
	}
	CVector3 m_position = CVector3::Zero;
	CVector3 m_moveSpeed = CVector3::Zero;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	int m_timer = 0;

};

