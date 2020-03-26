#pragma once
#include"Game.h"
class GameCamera :public IGameObject
{
public:
	GameCamera();
	~GameCamera();
	bool Start()override;
	void Update()override;
	prefab::CSpriteRender* m_spriteRender = nullptr;
	CVector3 m_position = CVector3::Zero;
	CQuaternion m_rotation = CQuaternion::Identity;
	CVector3 m_moveSpeed = CVector3::Zero;
	Player* m_player = nullptr;
	CVector3 m_toCameraPos;
};

