#pragma once
#include <iostream>
#include "Entity.h"
#include "Physics.h"

namespace LeTurfu {

	class Application
	{
	private:
		Physics* physics;
		int genericID;

	public:
		std::vector<LeTurfu::AComponent> allComponent;
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
		Application();
		int Init();
		void AllUpdate();
		void OpenWindow();
		void CloseWindow();
		Entity* CreateEntity();
		void CreateComponent();
		void ChangeColorBackground();
		Physics* GetPhysics();

		Entity* FindEntityparent(AComponent* currentComponent);
		int GenerateID();

	private:

		sf::Clock Clock;
	};
}

