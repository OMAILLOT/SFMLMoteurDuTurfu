#include "LuaScript.h"
#include <iostream>
#include "RessourceManager.h"
#include <lua.hpp>
#include <LuaBridge/LuaBridge.h>
#include "Application.h"

void LeTurfu::LuaScript::ReportError(lua_State* luaState, int status)
{
	if (status == 0) {
		return;
	}
	std::cerr << "[LUA ERROR] " << lua_tostring(luaState, -1) << std::endl;

	lua_pop(luaState, 1);
}

LeTurfu::LuaScript::LuaScript()
{
	luaState = luaL_newstate();
	luaL_openlibs(luaState);
	
	luabridge::getGlobalNamespace(luaState)
		.beginNamespace("LeTurfu")
		.beginClass<sf::Vector2f>("Vector2")
		.addProperty("x", &sf::Vector2f::x)
		.addProperty("y", &sf::Vector2f::y)
		.endClass()
		.endNamespace();

	luabridge::setGlobal(luaState, Application::GetInstance(), "app");
}

void LeTurfu::LuaScript::SetScript(std::string assetID)
{
	std::string path = RessourceManager::GetInstance()->GetScriptPathByID(assetID);

	int scriptLoadStatus = luaL_dofile(luaState, path.c_str());

	ReportError(luaState, scriptLoadStatus);
}
