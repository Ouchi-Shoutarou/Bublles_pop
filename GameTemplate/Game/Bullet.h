#pragma once
#include"Game.h"
class Bullet : public IGameObject
{
public:
	Bullet();
	~Bullet();
	bool Start();
	void Update();
	void SetPosition(CVector3& pos) {  //bullet�̔����ʒu�����߂�
			m_position = pos;
	}
	void SetDirection(CVector3& pos) { //bullet�̕��������߂�
		m_moveSpeed = pos;
	}
	CVector3 m_position = CVector3::Zero;
	CVector3 m_moveSpeed = CVector3::Zero;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	int m_timer = 0;

};

