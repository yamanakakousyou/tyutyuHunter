#pragma once
class Game;
class Title : public IGameObject
{
public:
    Title();
    ~Title();
    void Update();
    //�`��֐��B
    void Render(RenderContext& rc);
    //�X�v���C�g�����_�\�B
    SpriteRender spriteRender;
    Game* m_game;
};
