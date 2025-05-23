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
	//�L�����R��������������
	m_characterController.Init(25.0f, 75.0f, m_position);
	m_player = FindGO<Player>("player");
	m_game = FindGO<Game>("game");
	m_rotation.SetRotationDegY(0);
	modelRender.SetRotation(m_rotation);

	modelRender.SetPosition(m_position);

	m_enemyState = enEnemyIdle;	//�X�e�[�g�̏������B
	return true;
}



void Enemy::Update()
{
	//�ړ������B
	Move();

	Rotation();

	//�A�j���[�V�����̍Đ�
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
	//�G�`������̍X�V�����B
	modelRender.Update();
}

void Enemy::Move()
{
	//xz�̈ړ����x��0.0f�ɂ���B
	/*m_moveSpeed.x = 0.0f;
	m_moveSpeed.z = 0.0f;*/

	//�n�ʂɕt���Ă��Ȃ�������B
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
		// �G�l�~�[����v���C���[�Ɍ������ĐL�т�x�N�g�����v�Z����B
		PtoELength = RangeCalcV1toV2(m_player->m_position, m_position);
		
		if (PtoELength.Length() < 800.0f) {
			m_enemyState = enEnemyRun;	//����X�e�[�g�Ɉڍs�B
		}
		break;
	case enEnemyRun:		
		//�^�C�}�[��p�ӂ�2�b�ԓ��������Ɉړ�����B3�b������������̍Čv�Z������B
		if (m_timer <= 0) {
			m_timer = 60.0f;//�t���[���v�Z�ɂȂ��Ă���̂ŁAdeltatime�ɏC�����Ă��������B

			m_forward = Vector3::AxisZ;



			//angle = 45 + (90 * 2);
			//angle = 0;
			//��]����Y���A�p�x����ŋ��߂��p�x�ɐݒ�B
			//dirRot.SetRotationDeg(Vector3::AxisY, angle);
			
			m_rotation = Quaternion::Identity;
			modelRender.SetRotation(m_rotation);
			modelRender.Update();
			//m_rotation.AddRotationDegY(angle);
			//m_rotation.SetRotationDegX(90.0f);


			//Apply�֐����g�p���đO�x�N�g���Ɋp�x�����Z����
			//m_forward;
			//4�������烉���_����1���������߂āA��]����ׂ��p�x�����߂�B1�����ڂ�45������n�܂�A90�x����]����4������ݒ�B
			dirNum = rand() % 8;
			float houkou = dirNum * 45.0f;
			m_rotation.SetRotationDeg(g_vec3AxisY, houkou);
			m_rotation.Apply(m_forward);

			//�x�N�g���𐳋K�����A��������݂̂ɂ���B
			m_forward.Normalize();//m_forward 0.0.1���A�v���O�����̓r����1,0,0�ɂ�����
			//0,0,-1�ɂ����肷��B
			
			//�v�Z�����O�x�N�g����500�{���A�i�߂�B
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
	//���f����`�悷��
	modelRender.Draw(rc);
}