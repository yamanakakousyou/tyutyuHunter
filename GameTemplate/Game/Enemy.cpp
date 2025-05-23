#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"
#include "Gameover.h"
#include "Game.h"
#include "time.h"
#include "GameClear.h"

Enemy::Enemy()
{

}

Enemy::~Enemy()
{

}

bool Enemy::Start()
{
	srand(time(nullptr));
	animationClips[enEnemyIdle].Load("Assets/animData/enemyidle.tka");
	animationClips[enEnemyIdle].SetLoopFlag(true);
	animationClips[enEnemyRun].Load("Assets/animData/enemyrun.tka");
	animationClips[enEnemyRun].SetLoopFlag(true);
	modelRender.Init("Assets/modelData/stage/enemy.tkm" ,animationClips, enEnemyNum);
	//modelRender.SetPosition(Vector3(10.0f, 10.0f, 10.0f));
	modelRender.SetScale(1.0f, 1.0f, 1.0f);
	//キャラコンを初期化する
	m_characterController.Init(25.0f, 75.0f, m_position);
	m_player = FindGO<Player>("player");
	m_game = FindGO<Game>("game");
	m_rotation.SetRotationDegY(0);
	modelRender.SetRotation(m_rotation);

	modelRender.SetPosition(m_position);

	m_enemyState = enEnemyIdle;	//ステートの初期化。
	return true;
}



void Enemy::Update()
{
	//移動処理。
	Move();

	Rotation();

	//アニメーションの再生
	EnemyAnimation();

	
	

	Vector3 diff = m_player->m_position - m_position;
	if (diff.Length() <= 60.0f)
	{
		NewGO<GameClear>(0, "GameClear");
		DeleteGO(m_game);
	}
	
	m_position = m_characterController.Execute(m_moveSpeed, 1.0f / 60.0f);
	modelRender.SetRotation(m_rotation);
	modelRender.SetPosition(m_position);
	//絵描きさんの更新処理。
	modelRender.Update();
}

void Enemy::Move()
{
	//xzの移動速度を0.0fにする。
	/*m_moveSpeed.x = 0.0f;
	m_moveSpeed.z = 0.0f;*/

	//地面に付いていなかったら。
	if (m_characterController.IsOnGround() == false) {
		m_moveSpeed.y -= 0.5f;
		return;
	}

	Vector3 PtoELength = Vector3::Zero;
	int dirNum = 0;
	Quaternion dirRot = Quaternion::Identity;
	float angle = 0.0f;
	switch (m_enemyState){
	case enEnemyIdle:
		// エネミーからプレイヤーに向かって伸びるベクトルを計算する。
		PtoELength = RangeCalcV1toV2(m_player->m_position, m_position);
		
		if (PtoELength.Length() < 800.0f) {
			m_enemyState = enEnemyRun;	//走るステートに移行。
		}
		break;
	case enEnemyRun:		
		//タイマーを用意し2秒間同じ方向に移動する。3秒たったら方向の再計算をする。
		if (m_timer <= 0) {
			m_timer = 60.0f;//フレーム計算になっているので、deltatimeに修正してください。

			m_forward = Vector3::AxisZ;



			//angle = 45 + (90 * 2);
			//angle = 0;
			//回転軸をY軸、角度を上で求めた角度に設定。
			//dirRot.SetRotationDeg(Vector3::AxisY, angle);
			
			m_rotation = Quaternion::Identity;
			modelRender.SetRotation(m_rotation);
			modelRender.Update();
			//m_rotation.AddRotationDegY(angle);
			//m_rotation.SetRotationDegX(90.0f);


			//Apply関数を使用して前ベクトルに角度を加算する
			//m_forward;
			//4方向からランダムに1方向を決めて、回転するべき角度を求める。1方向目は45°から始まり、90度ずつ回転して4方向を設定。
			dirNum = rand() % 8;
			float houkou = dirNum * 45.0f;
			m_rotation.SetRotationDeg(g_vec3AxisY, houkou);
			m_rotation.Apply(m_forward);

			//ベクトルを正規化し、情報を方向のみにする。
			m_forward.Normalize();//m_forward 0.0.1を、プログラムの途中で1,0,0にしたり
			//0,0,-1にしたりする。
			
			//計算した前ベクトルを500倍し、進める。
			m_moveSpeed = m_forward * 500.0f;
		}
		
		if (m_timer > 0)
		{
			m_timer--;
		}
	default:
		break;
	}	
}

void Enemy::Rotation()
{

}

void Enemy::ManageState()
{

}

void Enemy::EnemyAnimation()
{
	switch (m_enemyState){
	case enEnemyIdle:
		modelRender.PlayAnimation(enEnemyIdle);
		break;
	case enEnemyRun:
		modelRender.PlayAnimation(enEnemyRun);
		break;
	default:
		break;
	}
}

	

void Enemy::Render(RenderContext& rc)
{
	//モデルを描画する
	modelRender.Draw(rc);
}