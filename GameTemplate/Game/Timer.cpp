#include "stdafx.h"
#include "Timer.h"
#include "Game.h"
#include "Gameover.h"

Timer::Timer()
{
}

Timer::~Timer()
{
}

void Timer::Update()
{
	wchar_t wcsbuf[256];
	swprintf_s(wcsbuf, 256, L"残り%d秒!!", int(m_timer));

	//表示するテキストを設定。
	m_fontRender.SetText(wcsbuf);
	//フォントの位置を設定。
	m_fontRender.SetPosition(Vector3(400.0f, 500.0f, 0.0f));
	//フォントの大きさを設定。
	m_fontRender.SetScale(2.0f);
	//フォントの色を設定。
	m_fontRender.SetColor({ 1.0f,0.0f,0.0f,1.0f });

	m_timer -= g_gameTime->GetFrameDeltaTime();

	if (m_timer <= 0.0f)
	{
		NewGO<Gameover>(0, "Gameover");
		DeleteGO(this);
		DeleteGO(m_game);
	}
}

void Timer::Render(RenderContext& rc)
{
	m_fontRender.Draw(rc);
}
