#pragma once
#include "AComponent.h"
#include "SFML/Graphics.hpp"
#include "Application.h"
#include <iostream>

namespace LeTurfu {

	class SpriteRendererComponent : public AComponent
	{
	public:
		sf::Texture texture;
		sf::Sprite sprite;
		sf::Vector2f position = sf::Vector2f(500, 500);
		sf::Vector2f scale = sf::Vector2f(.1f, .1f);

		SpriteRendererComponent();
		virtual void Update(float deltaTime) override;
		virtual void GenerateID() override;
	};
}
