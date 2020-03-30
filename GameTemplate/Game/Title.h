#pragma once

class GameSelect;

class Title : public IGameObject
{
public :

	Title();
	~Title();


	prefab::CSpriteRender* m_sprite;
	prefab::CSpriteRender* m_sprite_bottom;
	

	GameSelect* m_gameselect = nullptr;


	bool Start();


	void Update();


	bool Sbottom_Flag = false;

	int m_timer = 0;

};

