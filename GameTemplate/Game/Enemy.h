#pragma once
class Player;
class Game;

//敵
class Enemy:public IGameObject
{
public:
	Enemy();
	~Enemy();

	 bool Start()override;
	//更新関数
	void Update() override;
	//描画関数
	void Render(RenderContext& rc) override;

	void Move();
	//回転
	void Rotation();
	
	//ステート管理
	void ManageState();
	//アニメーションの再生
	void EnemyAnimation();

	enum EnState {		//アニメーション。
		enEnemyIdle,
		enEnemyRun,
		enEnemyNum,
	};

	void SetPosition(const Vector3& position)
	{
		m_position = position;
	}
	/// <summary>
	/// 座標を取得する。
	/// </summary>
	/// <returns>座標。</returns>
	const Vector3& GetPosition() const
	{
		return m_position;
	}
	/// <summary>
	/// 座標を取得。
	/// </summary>
	/// <returns>座標。</returns>
	/// <summary>
	/// 回転を設定。
	/// </summary>
	/// <param name="rotation">回転。</param>
	void SetRotation(const Quaternion& rotation)
	{
		m_rotation = rotation;
	}
private:
	Vector3 RangeCalcV1toV2(const Vector3& v1,const Vector3& v2){
		// エネミーからプレイヤーに向かって伸びるベクトルを計算する。
		Vector3 V1toV2 = v1 - v2;
		return V1toV2;
	}
	
	//メンバ変数	
	Quaternion m_rotation=Quaternion::Identity;		//回転用変数
	PhysicsStaticObject physicsStaticObject;
	AnimationClip animationClips[enEnemyNum];		//アニメーションクリップ。
	CharacterController m_characterController;//キャラクターコントローラー。
	Vector3 m_position;		//ポジション
	Vector3 firstPosition;		//最初の座標。
	Player* m_player;
	Enemy* m_enemy;
	Game* m_game;
	int m_enemyState;

	////動作用の変数////
	Vector3 m_moveSpeed;				//移動速度。
	Vector3 m_forward = Vector3::AxisZ;	//前ベクトル。
	float m_timer = 0.0f;


	ModelRender modelRender; //
	//Player* m_player = nullptr;
	int EnemyState = 0;
};

