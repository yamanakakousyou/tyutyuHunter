#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"
#include "Game.h"
#include "Enemy.h"

GameClear::GameClear()
{

}

GameClear::~GameClear()
{

}

bool GameClear::Start()
{
	
	spriteRender.Init("Assets/sprite/GameClear.dds", 1920.0f, 1080.0f);
	m_game = FindGO<Game>("game");
	return true;
}

//�X�V����
void GameClear::Update()
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
void GameClear::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}