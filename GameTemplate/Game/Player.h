#pragma once
class Player :public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();

	prefab::CSkinModelRender* m_skinModelRender = nullptr; 
	CVector3 m_position = CVector3::Zero;
	CQuaternion qRot = CQuaternion::Identity;
};

