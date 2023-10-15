#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>

namespace LeTurfu {
	class RessourceManager
	{
	private:
		//RessourcesManager* instance;


	public:
		std::map<std::string, std::string> spritesPath;

		RessourceManager();
		RessourceManager* GetInstance();

	};


}