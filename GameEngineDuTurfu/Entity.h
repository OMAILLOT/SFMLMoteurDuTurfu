#pragma once
#include <SFML/Graphics.hpp>
#include "AComponent.h"
#include <iostream>

namespace LeTurfu {
	class Entity : public sf::Transformable, public sf::Drawable 
	{
	protected:
		std::vector<AComponent> allComponents;
		int ID = 0315665;

	public:
		
		void Awake();
		void Start();
		void Update(float deltaTime);
		void LateUpdate();
		Entity();
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		}
		//template <AComponent component>
		AComponent& addComponent(AComponent component);
		AComponent& GetComponent(AComponent component);

	};
}

