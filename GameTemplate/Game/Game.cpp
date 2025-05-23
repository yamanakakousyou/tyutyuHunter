#include "stdafx.h"
#include "Game.h"
#include "BackGround.h"
#include "Player.h"
#include "GameCamera.h"
#include "Gameover.h"
#include "Title.h"
#include "Enemy.h"
#include "Timer.h"
#include "GameClear.h"




bool Game::Start()
{
	//m_backGround = NewGO<BackGround>(0, "backGround");
	/*m_modelRender.Init("Assets/modelData/unityChan.tkm");*/
	//m_player = NewGO<Player>(0, "player");
	//NewGO<Player>(0, "player");
	//NewGO<Enemy>(0, "enemy");
	m_timer = NewGO<Timer>(0, "timer");
	//NewGO<BackGround>(0, "background");
	m_gamecamera = NewGO<GameCamera>(0, "gamecamera");

	//return true;
	//Game.cpp/Game::Start()
	//レベルを構築する//レベルを構築する。
	m_levelRender.Init("Assets/modelData/stage/stage2e.tkl", [&](LevelObjectData& objData) {
		//名前がunityChanだったら。
		if (objData.EqualObjectName(L"unityChan") == true) {//②unityChan
			//プレイヤーのオブジェクトを作成する。
			m_player = NewGO<Player>(0, "player");
			//座標を設定する。
			m_player->SetPosition(objData.position);
			//回転を設定する。
			m_player->SetRotation(objData.rotation);
			//trueにすると、レベルの方でモデルが読み込まれない。
			return true;
		}
		//名前がenemyだったら。
		else if (objData.ForwardMatchName(L"Ch14_nonPBR") == true) {//①敵
			//エネミーのオブジェクトを作成する。
			m_enemy = NewGO<Enemy>(0, "enemy");
			/*m_enemy1->m_position = { 292.6f,88.0f,1310.0f };*/
			//m_enemy1->firstPosition = m_enemy1->m_position;
			//Enemy* m_enemy2 = NewGO<Enemy>(0, "enemy");
			//Enemy* m_enemy3 = NewGO<Enemy>(0, "enemy");
			//座標を設定する。
			m_enemy->SetPosition(objData.position);
			//m_enemy2->SetPosition(objData.position);
			//m_enemy3->SetPosition(objData.position);
			//回転を設定する。
			m_enemy->SetRotation(objData.rotation);
			///HPを5に設定する。
			//m_enemy->SetHP(5);
			//作成したエネミーの数を数えたいので、+1する。
			//m_enemy1++;
			//trueにすると、レベルの方でモデルが読み込まれない。
			return true;
		}
		//名前がbackgroundだったら。
		else if (objData.EqualObjectName(L"stage") == true) {
			//背景オブジェクトを作成する。
			m_backGround = NewGO<BackGround>(0, "backGround");
			//座標を設定する。
			m_backGround->SetPosition(objData.position);
			//大きさを設定する。
			//m_backGround->SetScale(objData.scale);
			//回転を設定する。
			m_backGround->SetRotation(objData.rotation);
			return true;
		}

		});
	return true;
}


 Game::~Game()
{
	//プレイヤーを削除する
	DeleteGO(m_player);
	//敵を削除する
	DeleteGO(m_enemy);
	//ゲームカメラを削除する
	DeleteGO(m_gamecamera);
	//背景を削除する
	DeleteGO(m_backGround);
	//タイマーを削除する
	DeleteGO(m_timer);
}

void Game::Update()
{
	// g_renderingEngine->DisableRaytracing();
	m_modelRender.Update();
}


void Game::Render(RenderContext& rc)
{
	//m_modelRender.Draw(rc);
}