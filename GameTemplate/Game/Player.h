#pragma once
class Player :public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();
	void Move();

	prefab::CSkinModelRender* m_skinModelRender = nullptr; 
	CVector3 m_moveSpeed = CVector3::Zero;
	CCharacterController m_charaCon;
	CVector3 m_position = CVector3::Zero;
	CQuaternion qRot = CQuaternion::Identity;

	//âÒì]çsóÒ
	CVector3 m_front;
	CVector3 m_right;
	CVector3 m_up;
};

