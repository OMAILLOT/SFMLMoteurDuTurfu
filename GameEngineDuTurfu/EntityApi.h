#pragma once
#include "Entity.h"
#include "SFML/Graphics.hpp"
#include "Rigibody.h"
#include "SpriteRendererComponent.h"
#include "CharacterController.h"

namespace LeTurfu {

class EntityApi
{
protected:
	Entity* entity;
public:
	EntityApi(Entity* entity);
	~EntityApi();
	LeTurfu::Rigibody* GetComponentRigibody();
	CharacterController* GetComponentCharacterController();
	SpriteRendererComponent* GetComponentSpriteRenderer();
	sf::Vector2f GetPosition();
	sf::Vector2f GetScale();
	std::string GetName();
	void setVectorPosition();
	Entity* GetEntity();
	void DestroyEntity();

};

}
