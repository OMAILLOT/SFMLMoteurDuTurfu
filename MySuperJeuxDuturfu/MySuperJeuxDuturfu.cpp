#pragma once
#include <Application.h>
#include <Entity.h>
#include <SpriteRendererComponent.h>
#include <CharacterController.h>
#include <CameraComponent.h>
#include <RessourceManager.h>

int main()
{

    LeTurfu::RessourceManager ressourceManager;

    LeTurfu::Entity* newEntity = LeTurfu::Application::GetInstance()->CreateEntity();
    LeTurfu::Application::GetInstance()->Init();

    LeTurfu::SpriteRendererComponent* spriteRenderer = new LeTurfu::SpriteRendererComponent();
    newEntity->addComponent(spriteRenderer);

    LeTurfu::CharacterController* characterController = new LeTurfu::CharacterController();
    newEntity->addComponent(characterController);
    newEntity->setPosition(500, 500);

    LeTurfu::Entity* cameraEntity = LeTurfu::Application::GetInstance()->CreateEntity();

    LeTurfu::CameraComponent* cameraComponent = new LeTurfu::CameraComponent();
    cameraEntity->addComponent(cameraComponent);
    
    LeTurfu::Application::GetInstance()->AllUpdate();
}
