#include "stdafx.h"
#include "Player.h"
#include "Game.h"

Player::Player()
{
	////�A�j���[�V�����N���b�v�����[�h����B
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
	////���f��������������
	//modelRender.Init("Assets/modelData/unityChan.tkm", animationClips, enAnimationClip_Num, enModelUpAxisY);

	////�L�����R��������������
	//characterController.Init(25.0f, 75.0f, m_position);

	////game = FindGO<Game>("game");
}

bool Player::Start()
{
	//�A�j���[�V�����N���b�v�����[�h����B
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
	//���f��������������
	modelRender.Init("Assets/modelData/unityChan.tkm", animationClips, enAnimationClip_Num, enModelUpAxisY);

	//�L�����R��������������
	characterController.Init(25.0f, 75.0f, m_position);

	//game = FindGO<Game>("game");
	return true;
}

Player::~Player()
{

}

void Player::Update()
{
	//�ړ�����
	Move();

	//��]����
	Rotation();

	//�X�e�[�g�Ǘ�
	ManageState();

	//�A�j���[�V�����̍Đ�
	PlayAnimation();

	//���f�����X�V����
	modelRender.Update();	
}

void Player::Move()
{
	//xz�̈ړ����x��0.0f�ɂ���B
	moveSpeed.x = 0.0f;
	moveSpeed.z = 0.0f;

	//���X�e�B�b�N�̓��͗ʂ��擾�B
	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	//�J�����̑O�����ƉE�����̃x�N�g���������Ă���B
	Vector3 forward = g_camera3D->GetForward();
	Vector3 right = g_camera3D->GetRight();
	//y�����ɂ͈ړ������Ȃ��B
	forward.y = 0.0f;
	right.y = 0.0f;

	//���X�e�B�b�N�̓��͗ʂ�500.0f����Z�B
	right *= stickL.x * 500.0f;
	forward *= stickL.y * 500.0f;

	//�ړ����x�ɃX�e�B�b�N�̓��͗ʂ����Z����B
	moveSpeed += right + forward;

	//�n�ʂɕt���Ă�����B
	if (characterController.IsOnGround() == true)
	{
		//�d�͂𖳂����B
		moveSpeed.y = 0.0f;
		////A�{�^���������ꂽ��B
		//if (g_pad[0]->IsTrigger(enButtonA))
		//{
		//	//�W�����v������B
		//	moveSpeed.y = 240.0f;
		//}
	}
	//�n�ʂɕt���Ă��Ȃ�������B
	else
	{
		//�d�͂𔭐�������B
		moveSpeed.y -= 5.5f;
	}

	//�L�����N�^�[�R���g���[���[���g���č��W���ړ�������B
	m_position = characterController.Execute(moveSpeed, 1.0f / 60.0f);
	
	//�G�`������ɍ��W��������B

	modelRender.SetPosition(m_position);
}

void Player::Rotation()
{
	//x��z�̈ړ����x����������(�X�e�B�b�N�̓��͂���������)�B
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f)
	{
		//�L�����N�^�[�̕�����ς���B
		rotation.SetRotationYFromDirectionXZ(moveSpeed);
		//�G�`������ɉ�]��������B
		modelRender.SetRotation(rotation);
	}
}

void Player::ManageState()
{
	////�n�ʂɕt���Ă��Ȃ�������B
	//if (characterController.IsOnGround() == false)
	//{
	//	//�X�e�[�g��1(�W�����v��)�ɂ���B
	//	playerState = 1;
	//	modelRender.PlayAnimation(enAnimationClip_Jump);


	//	
	//	//������ManageState�̏������I��点��B
	//	return;
	//}

	//�n�ʂɕt���Ă�����B
	

	//x��z�̈ړ����x����������(�X�e�B�b�N�̓��͂���������)�B
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f)
	{
			//�X�e�[�g��2(�_�b�V��)�ɂ���B
			playerState = 2;
	
		//modelRender.PlayAnimation(enAnimationClip_Walk);
	}
	else
	{
		
		//�X�e�[�g��0(�ҋ@)�ɂ���B
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
		//�v���C���[�X�e�[�g��0(�ҋ@)��������B
	case 0:
		//�ҋ@�A�j���[�V�������Đ�����B
		modelRender.PlayAnimation(enAnimationClip_Idle);
		break;
		//�v���C���[�X�e�[�g��1(�W�����v��)��������B
	case 1:
		//�W�����v�A�j���[�V�������Đ�����B
		/*modelRender.PlayAnimation(enAnimationClip_Jump);*/
		break;
		//�v���C���[�X�e�[�g��2(����)��������B
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