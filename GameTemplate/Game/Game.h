#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
class Title;
class Stage;
class Player;
class GameCamera;
class FungusGenerator;
 
class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//スキンモデルレンダラー。

	Title* m_title = nullptr;
	Stage* m_stage = nullptr;
	Player* m_player = nullptr;
	FungusGenerator* m_fungus_generator = nullptr;
	GameCamera* m_gameCamera = nullptr;

	char script_me[30];

	int fungus_number;

	int generator_timer = 0;

	prefab::CSpriteRender* m_sprite = nullptr;





};

