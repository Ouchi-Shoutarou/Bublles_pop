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

	CVector3 Camera_target = CVector3::Zero;
	CVector3 Camera_pos = CVector3::Zero;

	CVector3 to_P_T = {-1.0f,0.0f,0.0f};
	CVector3 to_T_C = CVector3::Zero;

	




};

