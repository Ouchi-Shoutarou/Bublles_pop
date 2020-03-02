#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
class Title;
class Stage;
class Player;
class GameCamera;
 
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
	GameCamera* m_gameCamera = nullptr;

	prefab::CSpriteRender* m_sprite = nullptr;

};

