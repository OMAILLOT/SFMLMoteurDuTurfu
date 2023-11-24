#pragma once
#include "AComponent.h"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace LeTurfu {
	class Entity : public sf::Transformable, public sf::Drawable 
	{
	protected:
		int ID = 0315665;
		std::string name;
		

	public:
		
		std::vector<AComponent*> allComponents;
		void Awake();
		void Start();
		void Update(float deltaTime);
		void LateUpdate();
		void StartAllComponent();
		Entity(std::string name);
		~Entity();
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		}
		std::string GetName();
		//template <AComponent component>
		AComponent* addComponent(AComponent* component);
		void setVectorPosition(sf::Vector2f v);
		//AComponent* GetComponent(AComponent* component);

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

