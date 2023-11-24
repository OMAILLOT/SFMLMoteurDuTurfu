#pragma once
#include "EntityApi.h"
#include "SFML/Graphics.hpp"
#include "Application.h"

namespace LeTurfu {

	class ApplicationApi
	{
		Application* app;
	public:
		sf::RenderWindow* window;

		ApplicationApi(Application* _app);
		LeTurfu::EntityApi* FindEntityParent(AComponent* currentComponent);
		LeTurfu::EntityApi* GetEntityByName(std::string name);
		void CloseWindow();

	};

}