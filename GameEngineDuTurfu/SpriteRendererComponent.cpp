#include "SpriteRendererComponent.h"
#include "RessourceManager.h"


LeTurfu::SpriteRendererComponent::SpriteRendererComponent()
{
}

void LeTurfu::SpriteRendererComponent::Init()
{
    if (!texture.loadFromFile(LeTurfu::RessourceManager::GetInstance()->GetAssetPath(assetName)))
    {
        std::cerr << "ERROR" << std::endl;
    }

    sprite.setTexture(texture);
    sprite.setPosition(LeTurfu::Application::instance->FindEntityparent(this)->getPosition());
    sprite.setScale(scale);

    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
}

void LeTurfu::SpriteRendererComponent::Update(float deltaTime)
{
    sprite.setPosition(LeTurfu::Application::instance->FindEntityparent(this)->getPosition());
    LeTurfu::Application::GetInstance()->window.draw(sprite);
}

void LeTurfu::SpriteRendererComponent::Draw()
{
}
