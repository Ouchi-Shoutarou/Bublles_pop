#pragma once
class GameCamera :public IGameObject
{
public:
	GameCamera();
	~GameCamera();
	bool Start()override;
	void Update()override;
	prefab::CSpriteRender* m_spriteRender = nullptr;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_moveSpeed = CVector3::Zero;
};

