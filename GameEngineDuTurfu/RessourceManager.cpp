#include <filesystem>
#include "RessourceManager.h"

LeTurfu::RessourceManager::RessourceManager()
{
	TCHAR buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, sizeof(buffer));

	// pour avoir le path absolue
	std::cout << std::filesystem::path(buffer).parent_path().string() << std::endl;

	
}

LeTurfu::RessourceManager* LeTurfu::RessourceManager::GetInstance()
{
	if (instance == nullptr) {
		instance = new RessourceManager();
	}
	return instance;
}
