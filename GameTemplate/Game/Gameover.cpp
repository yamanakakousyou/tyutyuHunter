#include "stdafx.h"
#include "Gameover.h"
#include "Title.h"
#include "Game.h"
#include "Enemy.h"

Gameover::Gameover()
{
	
}



Gameover::~Gameover()
{

}

bool Gameover::Start()
{
	//�Q�[���I�[�o�[�̉摜��ǂݍ���
	spriteRender.Init("Assets/sprite/nezumiGameOver2psd.dds", 1920.0f, 1080.0f);
	m_game = FindGO<Game>("game");
	return true;
}

//�X�V����
void Gameover::Update()
{
	//A�{�^���������ꂽ��
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		//�^�C�g���̃I�u�W�F�N�g������
		NewGO<Title>(0, "title");
		//���g���폜����
		DeleteGO(this);
		DeleteGO(m_game);
	}
}

//�`�揈��
void Gameover::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}
