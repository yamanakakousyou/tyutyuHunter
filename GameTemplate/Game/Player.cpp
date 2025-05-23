#include "stdafx.h"
#include "Player.h"
#include "Game.h"

Player::Player()
{
	////アニメーションクリップをロードする。
	//animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
	//animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	//animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
	//animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	//animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
	//animationClips[enAnimationClip_Jump].SetLoopFlag(false);
	//animationClips[enAnimationClip_Run].Load("Assets/animData/run.tka");
	//animationClips[enAnimationClip_Run].SetLoopFlag(true);
	//animationClips[enAnimationClip_Catch].Load("Assets/animData/catch.tka");
	//animationClips[enAnimationClip_Catch].SetLoopFlag(false);
	////モデルを初期化する
	//modelRender.Init("Assets/modelData/unityChan.tkm", animationClips, enAnimationClip_Num, enModelUpAxisY);

	////キャラコンを初期化する
	//characterController.Init(25.0f, 75.0f, m_position);

	////game = FindGO<Game>("game");
}

bool Player::Start()
{
	//アニメーションクリップをロードする。
	animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
	animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
	animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
	animationClips[enAnimationClip_Jump].SetLoopFlag(false);
	animationClips[enAnimationClip_Run].Load("Assets/animData/run.tka");
	animationClips[enAnimationClip_Run].SetLoopFlag(true);
	animationClips[enAnimationClip_Catch].Load("Assets/animData/catch.tka");
	animationClips[enAnimationClip_Catch].SetLoopFlag(false);
	//モデルを初期化する
	modelRender.Init("Assets/modelData/unityChan.tkm", animationClips, enAnimationClip_Num, enModelUpAxisY);

	//キャラコンを初期化する
	characterController.Init(25.0f, 75.0f, m_position);

	//game = FindGO<Game>("game");
	return true;
}

Player::~Player()
{

}

void Player::Update()
{
	//移動処理
	Move();

	//回転処理
	Rotation();

	//ステート管理
	ManageState();

	//アニメーションの再生
	PlayAnimation();

	//モデルを更新する
	modelRender.Update();	
}

void Player::Move()
{
	//xzの移動速度を0.0fにする。
	moveSpeed.x = 0.0f;
	moveSpeed.z = 0.0f;

	//左スティックの入力量を取得。
	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	//カメラの前方向と右方向のベクトルを持ってくる。
	Vector3 forward = g_camera3D->GetForward();
	Vector3 right = g_camera3D->GetRight();
	//y方向には移動させない。
	forward.y = 0.0f;
	right.y = 0.0f;

	//左スティックの入力量と500.0fを乗算。
	right *= stickL.x * 500.0f;
	forward *= stickL.y * 500.0f;

	//移動速度にスティックの入力量を加算する。
	moveSpeed += right + forward;

	//地面に付いていたら。
	if (characterController.IsOnGround() == true)
	{
		//重力を無くす。
		moveSpeed.y = 0.0f;
		////Aボタンが押されたら。
		//if (g_pad[0]->IsTrigger(enButtonA))
		//{
		//	//ジャンプさせる。
		//	moveSpeed.y = 240.0f;
		//}
	}
	//地面に付いていなかったら。
	else
	{
		//重力を発生させる。
		moveSpeed.y -= 5.5f;
	}

	//キャラクターコントローラーを使って座標を移動させる。
	m_position = characterController.Execute(moveSpeed, 1.0f / 60.0f);
	
	//絵描きさんに座標を教える。

	modelRender.SetPosition(m_position);
}

void Player::Rotation()
{
	//xかzの移動速度があったら(スティックの入力があったら)。
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f)
	{
		//キャラクターの方向を変える。
		rotation.SetRotationYFromDirectionXZ(moveSpeed);
		//絵描きさんに回転を教える。
		modelRender.SetRotation(rotation);
	}
}

void Player::ManageState()
{
	////地面に付いていなかったら。
	//if (characterController.IsOnGround() == false)
	//{
	//	//ステートを1(ジャンプ中)にする。
	//	playerState = 1;
	//	modelRender.PlayAnimation(enAnimationClip_Jump);


	//	
	//	//ここでManageStateの処理を終わらせる。
	//	return;
	//}

	//地面に付いていたら。
	

	//xかzの移動速度があったら(スティックの入力があったら)。
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f)
	{
			//ステートを2(ダッシュ)にする。
			playerState = 2;
	
		//modelRender.PlayAnimation(enAnimationClip_Walk);
	}
	else
	{
		
		//ステートを0(待機)にする。
		playerState = 0;
		modelRender.PlayAnimation(enAnimationClip_Idle);
	}
	/*if (g_pad[0]->IsPress(enButtonB)) {
			playerState = 3;
			rot.SetRotationDegX(-90);
			modelRender.SetRotation(rot);
		}*/
}

void Player::PlayAnimation()
{
	switch (playerState)
	{
		//プレイヤーステートが0(待機)だったら。
	case 0:
		//待機アニメーションを再生する。
		modelRender.PlayAnimation(enAnimationClip_Idle);
		break;
		//プレイヤーステートが1(ジャンプ中)だったら。
	case 1:
		//ジャンプアニメーションを再生する。
		/*modelRender.PlayAnimation(enAnimationClip_Jump);*/
		break;
		//プレイヤーステートが2(走る)だったら。
	case 2:
		modelRender.PlayAnimation(enAnimationClip_Run);
		break;
	case 3:
		modelRender.PlayAnimation(enAnimationClip_Catch);
		break;
	}
}

void Player::Render(RenderContext& renderContext)
{
	modelRender.Draw(renderContext);
}