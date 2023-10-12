#include "SpriteRendererComponent.h"
#include "Application.h"


LeTurfu::SpriteRendererComponent::SpriteRendererComponent(Entity& entity)
{
    if (!texture.loadFromFile("DVD.png"))
    {
        std::cerr << "ERROR" << std::endl;
    }

    sprite.setTexture(texture);
    sprite.setPosition(position);
    sprite.setScale(scale);

    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
}

void LeTurfu::SpriteRendererComponent::Update(float deltaTime)
{
    LeTurfu::Application::GetInstance()->window.draw(sprite);
}

void LeTurfu::SpriteRendererComponent::GenerateID()
{
    ID = 2611584466;
}
