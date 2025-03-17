#include "SplashScene.h"

SplashScene::SplashScene(GameObject* parent):
	GameObject(parent, "SplashScene"),
	splashImageHandle_(-1)
{
}

void SplashScene::Initialize()
{
	//画像データのロード
	splashImageHandle_ = Image::Load("Scene/SplashImage/Splash.png");
	assert(splashImageHandle_ >= 0);

}

void SplashScene::Update()
{
	static int frame;

#ifdef _DEBUG
	/*ImGui::Begin("rueausu");
	ImGui::Text("Splash");*/

	if (ImGui::Button("SceneChange") || frame > 120) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE, TID_BLACKOUT, 0.5f);
	}
	ImGui::End();
#endif // _DEBUG

	if (frame > 120) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE, TID_BLACKOUT, 0.5f);
	}
	Image::SetAlpha(splashImageHandle_, frame * 10);
	frame++;
}

void SplashScene::Draw()
{
	Image::SetTransform(splashImageHandle_, transform_);
	Image::Draw(splashImageHandle_);
}

void SplashScene::Release()
{
}
