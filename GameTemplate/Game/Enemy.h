#pragma once
class Player;
class Game;

//�G
class Enemy:public IGameObject
{
public:
	Enemy();
	~Enemy();

	 bool Start()override;
	//�X�V�֐�
	void Update() override;
	//�`��֐�
	void Render(RenderContext& rc) override;

	void Move();
	//��]
	void Rotation();
	
	//�X�e�[�g�Ǘ�
	void ManageState();
	//�A�j���[�V�����̍Đ�
	void EnemyAnimation();

	enum EnState {		//�A�j���[�V�����B
		enEnemyIdle,
		enEnemyRun,
		enEnemyNum,
	};

	void SetPosition(const Vector3& position)
	{
		m_position = position;
	}
	/// <summary>
	/// ���W���擾����B
	/// </summary>
	/// <returns>���W�B</returns>
	const Vector3& GetPosition() const
	{
		return m_position;
	}
	/// <summary>
	/// ���W���擾�B
	/// </summary>
	/// <returns>���W�B</returns>
	/// <summary>
	/// ��]��ݒ�B
	/// </summary>
	/// <param name="rotation">��]�B</param>
	void SetRotation(const Quaternion& rotation)
	{
		m_rotation = rotation;
	}
private:
	Vector3 RangeCalcV1toV2(const Vector3& v1,const Vector3& v2){
		// �G�l�~�[����v���C���[�Ɍ������ĐL�т�x�N�g�����v�Z����B
		Vector3 V1toV2 = v1 - v2;
		return V1toV2;
	}
	
	//�����o�ϐ�	
	Quaternion m_rotation=Quaternion::Identity;		//��]�p�ϐ�
	PhysicsStaticObject physicsStaticObject;
	AnimationClip animationClips[enEnemyNum];		//�A�j���[�V�����N���b�v�B
	CharacterController m_characterController;//�L�����N�^�[�R���g���[���[�B
	Vector3 m_position;		//�|�W�V����
	Vector3 firstPosition;		//�ŏ��̍��W�B
	Player* m_player;
	Enemy* m_enemy;
	Game* m_game;
	int m_enemyState;

	////����p�̕ϐ�////
	Vector3 m_moveSpeed;				//�ړ����x�B
	Vector3 m_forward = Vector3::AxisZ;	//�O�x�N�g���B
	float m_timer = 0.0f;


	ModelRender modelRender; //
	//Player* m_player = nullptr;
	int EnemyState = 0;
};

