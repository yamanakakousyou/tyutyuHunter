#pragma once

class Game;
class Player:public IGameObject
{
public:
	Player();
	~Player();
    //スタート
    bool Start();
	//更新処理
	void Update();
    //描画処理
    void Render(RenderContext& rc);
    //移動処理
    void Move();
    //回転処理
    void Rotation();
    //ステート管理
    void ManageState();
    //アニメーションの再生
    void PlayAnimation();

    //回転用変数
    Quaternion rot;
    //メンバ変数
    ModelRender modelRender;
    //座標
    //Vector3 position;

    enum EnAnimationClip {		//アニメーション。
        enAnimationClip_Idle,
        enAnimationClip_Walk,
        enAnimationClip_Jump,
        enAnimationClip_Run,
        enAnimationClip_Catch,
        enAnimationClip_Num,
    };

    void SetPosition(const Vector3& position)
    {
        m_position = position;
    }
    /// <summary>
    /// 座標を取得。
    /// </summary>
    /// <returns>座標。</returns>
    const Vector3& GetPosition() const
    {
        return m_position;
    }
    /// <summary>
    /// 回転を設定。
    /// </summary>
    /// <param name="rotation">回転。</param>
    void SetRotation(const Quaternion& rotation)
    {
        m_rotation = rotation;
    }
    AnimationClip animationClips[enAnimationClip_Num];		//アニメーションクリップ。
    CharacterController characterController;  //キャラクターコントローラー。

    Vector3 moveSpeed; //移動速度。
    Vector3 m_position;//ポジション
    Quaternion m_rotation;//クォータニオン。
    Game* game;
    Quaternion rotation; //クオータニオン
    int playerState = 0;//プレイヤーのステート
};

