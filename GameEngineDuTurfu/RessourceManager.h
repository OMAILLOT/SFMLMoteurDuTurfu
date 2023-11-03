#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>

namespace LeTurfu {
	class RessourceManager
	{
	private:
		static RessourceManager* instance;

	public:
		std::map<std::string, std::string> spritesPath;

		RessourceManager();
		void Init();
		static RessourceManager* GetInstance();
		std::string GetAssetPath(std::string localPath);
		std::string GetScriptPathByID(std::string localPath);
	};
}