#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround()
{
	modelRender.Init("Assets/modelData/stage/stage3.tkm");
	modelRender.SetScale(0.45f,0.45f,0.45f);
	modelRender.Update();
	physicsStaticObject.CreateFromModel(modelRender.GetModel(),
	modelRender.GetModel().GetWorldMatrix());
	
	//�����蔻���`�悷��B
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
}

BackGround::~BackGround()
{

}

void BackGround::Render(RenderContext& rc)
{
	//���f����`�悷��
	modelRender.Draw(rc);
}