#pragma once
class Player;
class GameCamera : public IGameObject
{
public:
	GameCamera();
	~GameCamera();
	bool Start();
	//�X�V����
	void Update();

	//�v���C���[
	Player* player;
	//�X�e�[�g
	int state = 0;
	//�����_���王�_�Ɍ������x�N�g���B
	Vector3 toCameraPos;
};


