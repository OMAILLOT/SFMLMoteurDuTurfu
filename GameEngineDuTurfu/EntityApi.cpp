#include "EntityApi.h"


LeTurfu::EntityApi::EntityApi(Entity* _entity)
{
    entity = _entity;
}

LeTurfu::EntityApi::~EntityApi()
{
}

LeTurfu::Rigibody* LeTurfu::EntityApi::GetComponentRigibody()
{
    return entity->GetComponent<Rigibody>();
}

LeTurfu::CharacterController* LeTurfu::EntityApi::GetComponentCharacterController()
{
    return entity->GetComponent<CharacterController>();
}

LeTurfu::SpriteRendererComponent* LeTurfu::EntityApi::GetComponentSpriteRenderer()
{
    return entity->GetComponent<SpriteRendererComponent>();
}

sf::Vector2f LeTurfu::EntityApi::GetPosition()
{
    return entity->getPosition();
}

sf::Vector2f LeTurfu::EntityApi::GetScale()
{
    return entity->getScale();
}

std::string LeTurfu::EntityApi::GetName()
{
    return entity->GetName();
}

void LeTurfu::EntityApi::setVectorPosition()
{

}

LeTurfu::Entity* LeTurfu::EntityApi::GetEntity()
{
    return entity;
}

void LeTurfu::EntityApi::DestroyEntity()
{
    for (AComponent* comp : entity->allComponents) {
        comp->~AComponent();
    }
    entity->~Entity();
    this->~EntityApi();
}
