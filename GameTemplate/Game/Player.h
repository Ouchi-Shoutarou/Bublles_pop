#pragma once
class Player :public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();
	void Move();
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
private:
	prefab::CSkinModelRender* m_skinModelRender = nullptr; 
	CVector3 m_moveSpeed = CVector3::Zero;
	CCharacterController m_charaCon;
	CQuaternion m_rotation = CQuaternion::Identity;	//��]�B
	CVector3 m_position = CVector3::Zero;
	CQuaternion qRot = CQuaternion::Identity;

	//��]�s��
	CVector3 m_front;
	CVector3 m_right;
	CVector3 m_up;
};

