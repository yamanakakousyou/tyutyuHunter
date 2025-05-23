#include "stdafx.h"
#include "Game.h"
#include "BackGround.h"
#include "Player.h"
#include "GameCamera.h"
#include "Gameover.h"
#include "Title.h"
#include "Enemy.h"
#include "Timer.h"
#include "GameClear.h"




bool Game::Start()
{
	//m_backGround = NewGO<BackGround>(0, "backGround");
	/*m_modelRender.Init("Assets/modelData/unityChan.tkm");*/
	//m_player = NewGO<Player>(0, "player");
	//NewGO<Player>(0, "player");
	//NewGO<Enemy>(0, "enemy");
	m_timer = NewGO<Timer>(0, "timer");
	//NewGO<BackGround>(0, "background");
	m_gamecamera = NewGO<GameCamera>(0, "gamecamera");

	//return true;
	//Game.cpp/Game::Start()
	//���x�����\�z����//���x�����\�z����B
	m_levelRender.Init("Assets/modelData/stage/stage2e.tkl", [&](LevelObjectData& objData) {
		//���O��unityChan��������B
		if (objData.EqualObjectName(L"unityChan") == true) {//�AunityChan
			//�v���C���[�̃I�u�W�F�N�g���쐬����B
			m_player = NewGO<Player>(0, "player");
			//���W��ݒ肷��B
			m_player->SetPosition(objData.position);
			//��]��ݒ肷��B
			m_player->SetRotation(objData.rotation);
			//true�ɂ���ƁA���x���̕��Ń��f�����ǂݍ��܂�Ȃ��B
			return true;
		}
		//���O��enemy��������B
		else if (objData.ForwardMatchName(L"Ch14_nonPBR") == true) {//�@�G
			//�G�l�~�[�̃I�u�W�F�N�g���쐬����B
			m_enemy = NewGO<Enemy>(0, "enemy");
			/*m_enemy1->m_position = { 292.6f,88.0f,1310.0f };*/
			//m_enemy1->firstPosition = m_enemy1->m_position;
			//Enemy* m_enemy2 = NewGO<Enemy>(0, "enemy");
			//Enemy* m_enemy3 = NewGO<Enemy>(0, "enemy");
			//���W��ݒ肷��B
			m_enemy->SetPosition(objData.position);
			//m_enemy2->SetPosition(objData.position);
			//m_enemy3->SetPosition(objData.position);
			//��]��ݒ肷��B
			m_enemy->SetRotation(objData.rotation);
			///HP��5�ɐݒ肷��B
			//m_enemy->SetHP(5);
			//�쐬�����G�l�~�[�̐��𐔂������̂ŁA+1����B
			//m_enemy1++;
			//true�ɂ���ƁA���x���̕��Ń��f�����ǂݍ��܂�Ȃ��B
			return true;
		}
		//���O��background��������B
		else if (objData.EqualObjectName(L"stage") == true) {
			//�w�i�I�u�W�F�N�g���쐬����B
			m_backGround = NewGO<BackGround>(0, "backGround");
			//���W��ݒ肷��B
			m_backGround->SetPosition(objData.position);
			//�傫����ݒ肷��B
			//m_backGround->SetScale(objData.scale);
			//��]��ݒ肷��B
			m_backGround->SetRotation(objData.rotation);
			return true;
		}

		});
	return true;
}


 Game::~Game()
{
	//�v���C���[���폜����
	DeleteGO(m_player);
	//�G���폜����
	DeleteGO(m_enemy);
	//�Q�[���J�������폜����
	DeleteGO(m_gamecamera);
	//�w�i���폜����
	DeleteGO(m_backGround);
	//�^�C�}�[���폜����
	DeleteGO(m_timer);
}

void Game::Update()
{
	// g_renderingEngine->DisableRaytracing();
	m_modelRender.Update();
}


void Game::Render(RenderContext& rc)
{
	//m_modelRender.Draw(rc);
}