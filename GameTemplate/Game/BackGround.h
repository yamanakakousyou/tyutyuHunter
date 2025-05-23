#pragma once

//�w�i
class BackGround:public IGameObject
{
public:
	BackGround();
	~BackGround();

	PhysicsStaticObject physicsStaticObject;

	//�`��֐�
	void Render(RenderContext& rc);

	//���f�������_�[
	ModelRender modelRender;


    void SetPosition(const Vector3& position)
    {
        m_position = position;
    }
    /// <summary>
    /// ���W���擾�B
    /// </summary>
    /// <returns>���W�B</returns>
    const Vector3& GetPosition() const
    {
        return m_position;
    }
    /// <summary>
    /// ��]��ݒ�B
    /// </summary>
    /// <param name="rotation">��]�B</param>
    void SetRotation(const Quaternion& rotation)
    {
        m_rotation = rotation;
    }

	Vector3 m_position;//�|�W�V����
	Quaternion m_rotation;//�N�H�[�^�j�I���B
};

