#pragma once
class GameCamera :public IGameObject
{
public:
	GameCamera();
	~GameCamera();
	bool start();
	void Update();
};

