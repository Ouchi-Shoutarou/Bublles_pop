#pragma once
class Stage;
class Player;
class Title : public IGameObject
{
public :

	Title();
	~Title();


	prefab::CSpriteRender* m_sprite;
	prefab::CSpriteRender* m_sprite_bottom;
	

	Stage* m_stage = nullptr;
	Player* m_player = nullptr;

	bool Start();


	void Update();


	bool Sbottom_Flag = false;

	int m_timer = 0;

};

