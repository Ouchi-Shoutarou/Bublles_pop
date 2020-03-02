#pragma once
class Stage : public IGameObject
{
public:
	Stage();
	~Stage();
	CVector3 m_position = CVector3::Zero;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
};

