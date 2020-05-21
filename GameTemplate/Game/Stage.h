#pragma once
#include "tkEngine/physics/tkPhysicsGhostObject.h"
class Stage : public IGameObject
{
public:
	Stage();
	~Stage();
	bool Start();
	void Update();
	CVector3 m_position = CVector3::Zero;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CPhysicsStaticObject ita;


	CVector3 Stage_Scale = CVector3::One;
	
};

