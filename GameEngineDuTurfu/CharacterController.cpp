#include "CharacterController.h"
#include "Rigibody.h"


LeTurfu::CharacterController::CharacterController()
{
}

void LeTurfu::CharacterController::Update(float deltaTime)
{
    DetectBorder();

   /* if (isRotate) {
        entityParent.rotate(rotateSpeed);
    }*/
    MoveEntity();
}

void LeTurfu::CharacterController::MoveEntity()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && baseMovement.x >= -maxSpeed)
    {
        baseMovement += sf::Vector2f(-speed, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && baseMovement.x <= maxSpeed)
    {
        baseMovement += sf::Vector2f(speed, 0);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && baseMovement.y >= -maxSpeed)
    {
        baseMovement += sf::Vector2f(0, -speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && baseMovement.y <= maxSpeed)
    {
        baseMovement += sf::Vector2f(0, speed);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && baseMovement != sf::Vector2f(0, 0)) {
        if (baseMovement.x > 0)
            baseMovement += sf::Vector2f(-speed, 0);
        else
            baseMovement += sf::Vector2f(speed, 0);


        if (baseMovement.y > 0)
            baseMovement += sf::Vector2f(0, -speed);
        else
            baseMovement += sf::Vector2f(0, speed);
    }

    // LeTurfu::Application::instance->FindEntityparent(this)->move(baseMovement);
    b2Vec2 movement = b2Vec2(baseMovement.x, baseMovement.y);
    LeTurfu::Application::instance->FindEntityparent(this)->GetComponent<Rigibody>()->SetLinearVelocity(movement);
}

void LeTurfu::CharacterController::DetectBorder()
{
    sf::RenderWindow& window = LeTurfu::Application::GetInstance()->window;

    sf::Texture texture = LeTurfu::Application::instance->FindEntityparent(this)->GetComponent<SpriteRendererComponent>()->texture;
    sf::Transformable* transform = LeTurfu::Application::instance->FindEntityparent(this);

    if (transform->getPosition().x + (texture.getSize().x * transform->getScale().x) / 2 >= window.getView().getCenter().x + window.getView().getSize().x /2) {
        baseMovement.x *= -1;
        CoinTouch();
    }
    else if (transform->getPosition().x - (texture.getSize().x * transform->getScale().x) / 2 <= window.getView().getCenter().x - window.getView().getSize().x / 2) {
        baseMovement.x *= -1;
        CoinTouch();
    }

    if (transform->getPosition().y + (texture.getSize().y * transform->getScale().y) / 2 >= window.getView().getCenter().y + window.getView().getSize().y / 2) {
        baseMovement.y *= -1;
        CoinTouch();

    }
    else if (transform->getPosition().y - (texture.getSize().y * transform->getScale().y) / 2 <= window.getView().getCenter().y - window.getView().getSize().y / 2) {
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
}
