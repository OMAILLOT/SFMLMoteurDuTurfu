#pragma once
#include <Application.h>
#include <Entity.h>
#include <SpriteRendererComponent.h>
#include <CharacterController.h>
#include <CameraComponent.h>
#include <RessourceManager.h>
#include <BoxCollider.h>
#include <Rigibody.h>
#include <CollisionListener.h>

int main()
{
    LeTurfu::RessourceManager::GetInstance()->Init();
    LeTurfu::Application::GetInstance()->Init();

    

    //Player
    LeTurfu::Entity* playerEntity = LeTurfu::Application::GetInstance()->CreateEntity();
    LeTurfu::SpriteRendererComponent* playerSpriteRenderer = new LeTurfu::SpriteRendererComponent();
    playerSpriteRenderer->assetName = "DVD.png";
    playerSpriteRenderer->Init();
    playerEntity->addComponent(playerSpriteRenderer);

    LeTurfu::CharacterController* characterController = new LeTurfu::CharacterController();
    characterController->speedIncrease = 0.0f;
    characterController->maxSpeed = 100;
    characterController->speed = .15f;
    playerEntity->addComponent(characterController);
    playerEntity->setPosition(500, 500);

    LeTurfu::BoxCollider* playerBoxCollider = new LeTurfu::BoxCollider();
    playerBoxCollider->density = 0.3f;
    playerBoxCollider->Init();
    playerBoxCollider->SetShapeSize(1);
    playerEntity->addComponent(playerBoxCollider);
    
    LeTurfu::Rigibody* playerRbComponent = new LeTurfu::Rigibody();
    playerEntity->addComponent(playerRbComponent);
    playerRbComponent->Init();
    playerRbComponent->GetBody()->SetGravityScale(0);
    playerRbComponent->GetBody()->SetAwake(true);
    //Camera
    LeTurfu::Entity* cameraEntity = LeTurfu::Application::GetInstance()->CreateEntity();

    LeTurfu::CameraComponent* cameraComponent = new LeTurfu::CameraComponent();
    cameraEntity->addComponent(cameraComponent);


    //Enemy
    LeTurfu::Entity* enemyEntity = LeTurfu::Application::GetInstance()->CreateEntity();
    enemyEntity->setPosition(500, 750);


    LeTurfu::SpriteRendererComponent* enemySpriteRenderer = new LeTurfu::SpriteRendererComponent();
    enemySpriteRenderer->assetName = "DVDEnemy.png";
    enemySpriteRenderer->Init();
    enemyEntity->addComponent(enemySpriteRenderer);


    LeTurfu::BoxCollider* enemyBoxCollider = new LeTurfu::BoxCollider();
    enemyBoxCollider->density = 0.0f;
    enemyBoxCollider->Init();
    enemyBoxCollider->SetShapeSize(100);
    enemyEntity->addComponent(enemyBoxCollider);

    LeTurfu::Rigibody* enemyRbComponent = new LeTurfu::Rigibody();
    enemyEntity->addComponent(enemyRbComponent);
    enemyRbComponent->Init();
    enemyRbComponent->GetBody()->SetAwake(true);
    
    LeTurfu::Application::GetInstance()->AllUpdate();
}
