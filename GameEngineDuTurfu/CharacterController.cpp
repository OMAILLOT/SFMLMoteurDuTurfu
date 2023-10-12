#include "pch.h"
#include "CharacterController.h"

LeTurfu::CharacterController::CharacterController(Entity& entity)
{
    
}

void LeTurfu::CharacterController::Update(float deltaTime)
{
    DetectBorder();

    if (isRotate) {
        entityParent.rotate(rotateSpeed);
    }
    MoveEntity();
}

void LeTurfu::CharacterController::MoveEntity()
{
    if (baseMovement.x >= -maxSpeed && baseMovement.x <= maxSpeed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            baseMovement += sf::Vector2f(-.0001f, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            baseMovement += sf::Vector2f(.0001f, 0);
        }
    }

    if (baseMovement.y >= -maxSpeed && baseMovement.y <= maxSpeed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            baseMovement += sf::Vector2f(0, -0.0001f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            baseMovement += sf::Vector2f(0, 0.0001f);
        }
    }



    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && baseMovement != sf::Vector2f(0, 0)) {
        if (baseMovement.x > 0)
            baseMovement += sf::Vector2f(-0.0001f, 0);
        else
            baseMovement += sf::Vector2f(0.0001f, 0);


        if (baseMovement.y > 0)
            baseMovement += sf::Vector2f(0, -0.0001f);
        else
            baseMovement += sf::Vector2f(0, 0.0001f);
    }

    entityParent.move(baseMovement);
}

void LeTurfu::CharacterController::DetectBorder()
{
    sf::RenderWindow& window = LeTurfu::Application::GetInstance()->window;

    if (entityParent.getPosition().x + (texture.getSize().x * entityParent.getScale().x) / 2 >= window.getSize().x) {
        baseMovement.x *= -1;
        CoinTouch();
    }
    else if (entityParent.getPosition().x - (texture.getSize().x * entityParent.getScale().x) / 2 <= 0) {
        baseMovement.x *= -1;
        CoinTouch();
    }

    if (entityParent.getPosition().y + (texture.getSize().y * entityParent.getScale().y) / 2 >= window.getSize().y) {
        baseMovement.y *= -1;
        CoinTouch();

    }
    else if (entityParent.getPosition().y - (texture.getSize().y * entityParent.getScale().y) / 2 <= 0) {
        baseMovement.y *= -1;
        CoinTouch();
    }


}

void LeTurfu::CharacterController::CoinTouch()
{
    LeTurfu::Application::GetInstance()->ChangeColorBackground();

    if (baseMovement.x > 0) {
        if (baseMovement.y > 0) {
            baseMovement += sf::Vector2f(.01, .01);
        }
        else {
            baseMovement += sf::Vector2f(speedIncrease, -speedIncrease);
        }
    }
    else {
        if (baseMovement.y > 0) {
            baseMovement += sf::Vector2f(-speedIncrease, speedIncrease);
        }
        else {
            baseMovement += sf::Vector2f(-speedIncrease, -speedIncrease);
        }
    }

    isRotate = true;
}

void LeTurfu::CharacterController::GenerateID()
{
    ID = 98788974960;
}
