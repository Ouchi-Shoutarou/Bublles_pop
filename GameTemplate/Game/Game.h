#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
class GameCamera;
class Player;
class Stage;
class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//スキンモデルレンダラー。
	Player* m_player = nullptr;
	GameCamera* m_gameCamera = nullptr;
	Stage* m_stage = nullptr;

	prefab::CSpriteRender* m_sprite = nullptr;

};

