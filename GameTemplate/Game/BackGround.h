#pragma once

//背景
class BackGround:public IGameObject
{
public:
	BackGround();
	~BackGround();

	PhysicsStaticObject physicsStaticObject;

	//描画関数
	void Render(RenderContext& rc);

	//モデルレンダー
	ModelRender modelRender;


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

	Vector3 m_position;//ポジション
	Quaternion m_rotation;//クォータニオン。
};

