#pragma once

#include "Level3DRender/LevelRender.h"

class Player;
class BackGround;
class GameCamera;
class Timer;
class Enemy;
class MovingFloor;
class Map;

class Game : public IGameObject
{
public:
	Game() {}
	~Game();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

private:
	ModelRender m_modelRender;
	LevelRender m_levelRender;//ÉåÉxÉãÅB
	Vector3 m_pos;
	BackGround* m_backGround;
	Enemy* m_enemy;
	Game* m_game;
	Player* m_player;
	GameCamera* m_gamecamera;
	Timer* m_timer;
	MovingFloor* m_movingFloor = nullptr;
	Map* m_map = nullptr;
};

