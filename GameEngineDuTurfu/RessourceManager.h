#pragma once
#include <Windows.h>
#include <iostream>
#include <SFML/Graphics.hpp>

namespace LeTurfu {
	class RessourceManager
	{
	private:
		RessourcesManager* instance;


	public:
		std::map<std::string, std::string> spritesPath;

		RessourceManager();
		RessourceManager* GetInstance();

	};


}