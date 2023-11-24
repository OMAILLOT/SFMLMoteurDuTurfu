#pragma once
#include <iostream>
#include "AComponent.h"
#include "Physics.h"
#include "SFML/Graphics.hpp"

namespace LeTurfu {
	class Entity;
	class EntityApi;
	
	class Application
	{
	private:
		Physics* physics;
		int genericID;

	public:
		std::vector<LeTurfu::AComponent*> allComponent;
		sf::RenderWindow window;
		std::vector<sf::Color> allColor{
			sf::Color::Magenta,
			sf::Color::Blue,
			sf::Color::Cyan,
			sf::Color::White,
			sf::Color::Green,
			sf::Color::Red,
			sf::Color::Yellow
		};
		sf::Color currentColor = sf::Color::White;

		static Application* instance;
		static Application* GetInstance();

		std::vector<Entity*> allEntity;
		std::vector<EntityApi*> allEntityApi;
		Application();		
		int Init();
		void AllUpdate();
		void OpenWindow();
		void CloseWindow();
		Entity* CreateEntity(std::string name);
		void CreateComponent();
		void ChangeColorBackground();
		Physics* GetPhysics();

		Entity* FindEntityparent(AComponent* currentComponent);
		EntityApi* FindEntityApiParent(AComponent* currentComponent);
		Entity* GetEntityByName(std::string name);
		EntityApi* GetEntityApiByName(std::string name);
		int GenerateID();

	private:

		sf::Clock Clock;
	};
}

