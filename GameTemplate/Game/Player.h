#pragma once

class Game;
class Player:public IGameObject
{
public:
	Player();
	~Player();
    //�X�^�[�g
    bool Start();
	//�X�V����
	void Update();
    //�`�揈��
    void Render(RenderContext& rc);
    //�ړ�����
    void Move();
    //��]����
    void Rotation();
    //�X�e�[�g�Ǘ�
    void ManageState();
    //�A�j���[�V�����̍Đ�
    void PlayAnimation();

    //��]�p�ϐ�
    Quaternion rot;
    //�����o�ϐ�
    ModelRender modelRender;
    //���W
    //Vector3 position;

    enum EnAnimationClip {		//�A�j���[�V�����B
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
    AnimationClip animationClips[enAnimationClip_Num];		//�A�j���[�V�����N���b�v�B
    CharacterController characterController;  //�L�����N�^�[�R���g���[���[�B

    Vector3 moveSpeed; //�ړ����x�B
    Vector3 m_position;//�|�W�V����
    Quaternion m_rotation;//�N�H�[�^�j�I���B
    Game* game;
    Quaternion rotation; //�N�I�[�^�j�I��
    int playerState = 0;//�v���C���[�̃X�e�[�g
};

