#include "LuaScript.h"
#include <iostream>
#include "RessourceManager.h"
#include <luabridge3/LuaBridge/LuaBridge.h>
#include "Application.h"
#include "Rigibody.h"
#include "box2d/b2_body.h"

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

}

void LeTurfu::LuaScript::Init()
{
	luaState = luaL_newstate();
	luaL_openlibs(luaState);

#pragma region import lua (DANGER: RISQUE D AVEUGLEMENT AIGUE)


	luabridge::getGlobalNamespace(luaState)
		.beginNamespace("LeTurfu")
		.beginClass<sf::Vector2f>("Vector2")
		.addProperty("x", &sf::Vector2f::x)
		.addProperty("y", &sf::Vector2f::y)
		.endClass()

		.beginClass<b2Vec2>("b2Vec2")
		.addProperty("x", &b2Vec2::x)
		.addProperty("y", &b2Vec2::y)
		.endClass()


		.beginClass<LeTurfu::AComponent>("AComponent")
		//.addConstructor<LeTurfu::AComponent>()
		.endClass()

		.beginClass<LeTurfu::Entity>("Entity")
		.addFunction("AddComponent", &LeTurfu::Entity::addComponent)
		.addFunction("GetName", &LeTurfu::Entity::GetName)
		.addFunction("GetPosition", &LeTurfu::Entity::getPosition)
		.addFunction("SetPosition", &LeTurfu::Entity::setVectorPosition)
		.endClass()

		//.beginClass<std::vector<LeTurfu::Entity*>>("vector")

		//.endClass()

		.beginClass<LeTurfu::Application>("Application")
		.addFunction("FindEntityparent", &LeTurfu::Application::FindEntityparent)
		.addFunction("GetEntityByName", &LeTurfu::Application::GetEntityByName)
		.addProperty("allEntity", &LeTurfu::Application::allEntity)
		.endClass()

		.beginClass<LeTurfu::Rigibody>("Rigibody")
		.addFunction("GetLinearVelocity", &LeTurfu::Rigibody::GetLinearVelocity)
		.addProperty("movement", &LeTurfu::Rigibody::movement)
		.endClass()

		.endNamespace();
#pragma endregion

	luabridge::setGlobal(luaState, Application::GetInstance()->FindEntityparent(this), "parent");
	luabridge::setGlobal(luaState, Application::GetInstance(), "app");
}

void LeTurfu::LuaScript::SetScript(std::string assetID)
{
	std::string path = RessourceManager::GetInstance()->GetScriptPathByID(assetID);

	int scriptLoadStatus = luaL_dofile(luaState, path.c_str());

	ReportError(luaState, scriptLoadStatus);
}

void LeTurfu::LuaScript::Update(float deltaTime)
{
	luabridge::LuaRef update = luabridge::getGlobal(luaState, "update");
	luabridge::LuaResult res = update(deltaTime);
	//update(deltaTime);
} 