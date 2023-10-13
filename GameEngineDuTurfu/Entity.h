#pragma once
#include <SFML/Graphics.hpp>
#include "AComponent.h"
#include <iostream>

namespace LeTurfu {
	class Entity : public sf::Transformable, public sf::Drawable 
	{
	protected:
		int ID = 0315665;

	public:
		
		std::vector<AComponent*> allComponents;
		void Awake();
		void Start();
		void Update(float deltaTime);
		void LateUpdate();
		Entity();
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		}
		//template <AComponent component>
		AComponent* addComponent(AComponent* component);
		AComponent* GetComponent(AComponent* component);


		template<typename T>
		inline T* GetComponent() {
	
			for (AComponent* component : allComponents) {
				T* test = dynamic_cast<T*>(component);
				if (test != nullptr) {
					return test;
				}
			}
			return nullptr;
		}

	};
}

