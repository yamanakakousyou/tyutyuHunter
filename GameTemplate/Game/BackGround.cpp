#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround()
{
	modelRender.Init("Assets/modelData/stage/stage3.tkm");
	modelRender.SetScale(0.45f,0.45f,0.45f);
	modelRender.Update();
	physicsStaticObject.CreateFromModel(modelRender.GetModel(),
	modelRender.GetModel().GetWorldMatrix());
	
	//“–‚½‚è”»’è‚ð•`‰æ‚·‚éB
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
}

BackGround::~BackGround()
{

}

void BackGround::Render(RenderContext& rc)
{
	//ƒ‚ƒfƒ‹‚ð•`‰æ‚·‚é
	modelRender.Draw(rc);
}