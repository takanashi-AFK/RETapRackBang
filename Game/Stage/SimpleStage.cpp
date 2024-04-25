#include "SimpleStage.h"
#include "../../Engine/Model.h"
SimpleStage::SimpleStage(GameObject* parent):
	GameObject(parent,"SimpleStage")
{
}

void SimpleStage::Initialize()
{
	stageModelHandle_= Model::Load("Stage/SimpleStage.fbx");
	assert(stageModelHandle_ >= 0);
}

void SimpleStage::Update()
{
}

void SimpleStage::Draw()
{
	Model::SetTransform(stageModelHandle_, transform_);
	Model::Draw(stageModelHandle_);
}

void SimpleStage::Release()
{
}
