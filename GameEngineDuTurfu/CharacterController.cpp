#include "CharacterController.h"



LeTurfu::CharacterController::CharacterController()
{
}

void LeTurfu::CharacterController::Init()
{
    window = &LeTurfu::Application::GetInstance()->window;
    texture = LeTurfu::Application::instance->FindEntityparent(this)->GetComponent<SpriteRendererComponent>()->texture;
    transform = LeTurfu::Application::instance->FindEntityparent(this);
    rbMovement = &LeTurfu::Application::instance->FindEntityparent(this)->GetComponent<Rigibody>()->movement;
}



void LeTurfu::CharacterController::Update(float deltaTime)
{
    if (canMove) {
        MoveEntity(deltaTime);
        DetectBorder();
    }    
}

void LeTurfu::CharacterController::MoveEntity(float deltaTime)
{
    
    b2Vec2& rbMovement = LeTurfu::Application::instance->FindEntityparent(this)->GetComponent<Rigibody>()->movement;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && rbMovement.x >= -maxSpeed)
    {
        rbMovement += b2Vec2(-speed * deltaTime, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && rbMovement.x <= maxSpeed)
    {
        rbMovement += b2Vec2(speed * deltaTime, 0);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && rbMovement.y >= -maxSpeed)
    {
        rbMovement += b2Vec2(0, -speed * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && rbMovement.y <= maxSpeed)
    {
        rbMovement += b2Vec2(0, speed * deltaTime);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && rbMovement != b2Vec2(0, 0)) {
        if (rbMovement.x > 0)
            rbMovement += b2Vec2(-speed * deltaTime, 0);
        else
            rbMovement += b2Vec2(speed * deltaTime, 0);


        if (rbMovement.y > 0)
            rbMovement += b2Vec2(0, -speed * deltaTime);
        else
            rbMovement += b2Vec2(0, speed * deltaTime);
    }

    PlayerPosition = Application::GetInstance()->FindEntityparent(this)->getPosition();

    // LeTurfu::Application::instance->FindEntityparent(this)->move(baseMovement);

}

void LeTurfu::CharacterController::DetectBorder()
{
    //sf::RenderWindow& window = LeTurfu::Application::GetInstance()->window;

    //sf::Texture texture = LeTurfu::Application::instance->FindEntityparent(this)->GetComponent<SpriteRendererComponent>()->texture;
    //sf::Transformable* transform = LeTurfu::Application::instance->FindEntityparent(this);
    //b2Vec2& rbMovement = LeTurfu::Application::instance->FindEntityparent(this)->GetComponent<Rigibody>()->movement;


    if (transform->getPosition().x + (texture.getSize().x * transform->getScale().x) / 2 >= window->getView().getCenter().x + window->getView().getSize().x /2) {
        rbMovement->x *= -1;
        CoinTouch();
    }
    else if (transform->getPosition().x - (texture.getSize().x * transform->getScale().x) / 2 <= window->getView().getCenter().x - window->getView().getSize().x / 2) {
        rbMovement->x *= -1;
        CoinTouch();
    }

    if (transform->getPosition().y + (texture.getSize().y * transform->getScale().y) / 2 >= window->getView().getCenter().y + window->getView().getSize().y / 2) {
        rbMovement->y *= -1;
        CoinTouch();

    }
    else if (transform->getPosition().y - (texture.getSize().y * transform->getScale().y) / 2 <= window->getView().getCenter().y - window->getView().getSize().y / 2) {
        rbMovement->y *= -1;
        CoinTouch();
    } 
}

void LeTurfu::CharacterController::CoinTouch()
{
    LeTurfu::Application::GetInstance()->ChangeColorBackground();
}

void LeTurfu::CharacterController::GenerateID()
{
}