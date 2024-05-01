#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/Model.h"
#include "../../Engine/SceneManager.h"
#include "../../Engine/ImGui/imgui.h"
class SkySphere :
    public GameObject
{
    int hSkySphere;
public:

    SkySphere(GameObject* parent);
    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;
};

