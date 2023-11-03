#include <filesystem>
#include "RessourceManager.h"


LeTurfu::RessourceManager* LeTurfu::RessourceManager::instance = nullptr;;
LeTurfu::RessourceManager::RessourceManager()
{
}

void LeTurfu::RessourceManager::Init()
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

std::string LeTurfu::RessourceManager::GetAssetPath(std::string localPath)
{
	TCHAR buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, sizeof(buffer));

	return std::filesystem::path(buffer).parent_path().string() + "\\Assets\\" + localPath;
}

std::string LeTurfu::RessourceManager::GetScriptPathByID(std::string localPath)
{
	TCHAR buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, sizeof(buffer));

	return std::filesystem::path(buffer).parent_path().string() + "\\Scripts\\" + localPath;
}

//LeTurfu::RessourceManager* LeTurfu::RessourceManager::GetInstance()
//{
//	if (instance == nullptr) {
//		instance = new RessourceManager();
//	}
//	return instance;
//}
