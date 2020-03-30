#pragma once

class Game;


class GameSelect :public IGameObject
{

public:

	GameSelect();
	~GameSelect();


	bool Start();

	void Update();


	Game* game = nullptr;


	prefab::CSpriteRender* m_select = nullptr;

	prefab::CSpriteRender* m_haikei = nullptr;

	prefab::CSpriteRender* m_haikei2 = nullptr;


	CVector3 m_scale_haikei = CVector3::One;

	CVector3 flame_position = CVector3::Zero;

	CVector3 flame_position_Game=CVector3 ::Zero;

	CVector3 flame_position_Settei = CVector3::Zero;

	CVector3 flame_position_Modoru = CVector3::Zero;


	int flame_position_flag = 0;


};

