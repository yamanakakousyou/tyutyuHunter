#pragma once
class Game;
class Enemy;
//�Q�[���N���A
class GameClear :public IGameObject
{
public:
	GameClear();
	~GameClear();

	bool Start()override;
	//�X�V����
	void Update();
	//�`�揈��
	void Render(RenderContext& rc);

	//�����o�ϐ�
	SpriteRender spriteRender; //�X�v���C�g�����_�[
	Game* m_game;
	Enemy* m_enemy;
};

