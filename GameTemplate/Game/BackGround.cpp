#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround()
{
	modelRender.Init("Assets/modelData/stage/stage3.tkm");
	modelRender.SetScale(0.45f,0.45f,0.45f);
	modelRender.Update();
	physicsStaticObject.CreateFromModel(modelRender.GetModel(),
	modelRender.GetModel().GetWorldMatrix());
	
	//当たり判定を描画する。
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
}

BackGround::~BackGround()
{

}

void BackGround::Render(RenderContext& rc)
{
	//モデルを描画する
	modelRender.Draw(rc);
}