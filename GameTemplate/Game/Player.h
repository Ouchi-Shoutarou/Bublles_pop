#pragma once
class Player :public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();
	void Move();
	void Jump_Up();
	void Turn();
	CVector3 GetPos() {
		return m_position;
	}
	void SetPos(const CVector3& pos) {
		m_position = pos;
	}
	CVector3 GetRight() {
		return m_right;
	}

	CQuaternion GetRotation() {
		return qRot;
	}

private:
	prefab::CSkinModelRender* m_skinModelRender = nullptr; 
	CVector3 m_moveSpeed = CVector3::Zero;
	CCharacterController m_charaCon;
	//CQuaternion m_rotation = CQuaternion::Identity;
	CVector3 m_position = CVector3::Zero;
	CQuaternion qRot = CQuaternion::Identity;	//âÒì]ÅB

	//âÒì]çsóÒ
	CVector3 m_front;
	CVector3 m_right;
	CVector3 m_up;
};

