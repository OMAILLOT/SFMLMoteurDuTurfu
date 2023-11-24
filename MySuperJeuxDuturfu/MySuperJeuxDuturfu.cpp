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
#include <LuaScript.h>

int main()
{
    LeTurfu::RessourceManager::GetInstance()->Init();
    LeTurfu::Application::GetInstance()->Init();

    

    //Player
    LeTurfu::Entity* playerEntity = LeTurfu::Application::GetInstance()->CreateEntity("PlayerEntity");
    LeTurfu::SpriteRendererComponent* playerSpriteRenderer = new LeTurfu::SpriteRendererComponent();
    playerSpriteRenderer->assetName = "DVD.png";
    playerEntity->addComponent(playerSpriteRenderer);
    playerSpriteRenderer->Init();

    LeTurfu::CharacterController* characterController = new LeTurfu::CharacterController();
    characterController->speedIncrease = 0.0f;
    characterController->maxSpeed = 10000;
    characterController->speed = 20;
    playerEntity->addComponent(characterController);
    playerEntity->setPosition(500, 500);

    LeTurfu::BoxCollider* playerBoxCollider = new LeTurfu::BoxCollider();
    playerBoxCollider->density = 0.3f;
    playerEntity->addComponent(playerBoxCollider);
    playerBoxCollider->Init();
    playerBoxCollider->SetShapeSize(1);
    
    LeTurfu::Rigibody* playerRbComponent = new LeTurfu::Rigibody();
    playerEntity->addComponent(playerRbComponent);
    playerRbComponent->Init();
    playerRbComponent->GetBody()->SetGravityScale(0);
    playerRbComponent->GetBody()->SetAwake(true);

    characterController->Init();

    LeTurfu::LuaScript* playerScript = new LeTurfu::LuaScript();
    playerEntity->addComponent(playerScript);
    playerScript->Init();
    playerScript->SetScript("player.lua");


    //Camera
    LeTurfu::Entity* cameraEntity = LeTurfu::Application::GetInstance()->CreateEntity("CameraEntity");
    LeTurfu::CameraComponent* cameraComponent = new LeTurfu::CameraComponent();
    cameraEntity->addComponent(cameraComponent);


    //Enemy
    LeTurfu::Entity* enemyEntity = LeTurfu::Application::GetInstance()->CreateEntity("EnemyEntity");
    enemyEntity->setPosition(1500, 1750);

    LeTurfu::SpriteRendererComponent* enemySpriteRenderer = new LeTurfu::SpriteRendererComponent();
    enemySpriteRenderer->assetName = "DVDEnemy.png";
    enemyEntity->addComponent(enemySpriteRenderer);
    enemySpriteRenderer->Init();

    LeTurfu::BoxCollider* enemyBoxCollider = new LeTurfu::BoxCollider();
    enemyBoxCollider->density = 0.0f;
    enemyEntity->addComponent(enemyBoxCollider);
    enemyBoxCollider->Init();
    enemyBoxCollider->SetShapeSize(100);

    LeTurfu::Rigibody* enemyRbComponent = new LeTurfu::Rigibody();
    enemyEntity->addComponent(enemyRbComponent);
    enemyRbComponent->Init();
    enemyRbComponent->GetBody()->SetAwake(true);

    LeTurfu::LuaScript* enemyMechant = new LeTurfu::LuaScript();
    enemyEntity->addComponent(enemyMechant);
    enemyMechant->Init();
    enemyMechant->SetScript("EnemyMechant.lua");
    
    LeTurfu::Entity* EnemyManager = new LeTurfu::Entity("EnemyManager");
    LeTurfu::LuaScript* luaEnemyManager = new LeTurfu::LuaScript();
    EnemyManager->addComponent(luaEnemyManager);
    luaEnemyManager->Init();
    luaEnemyManager->SetScript("EnemyMechantManager.lua");

    LeTurfu::Application::GetInstance()->AllUpdate();
}
