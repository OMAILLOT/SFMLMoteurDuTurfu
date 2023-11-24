#include "LuaScript.h"
#include <iostream>
#include "RessourceManager.h"
#include <luabridge3/LuaBridge/LuaBridge.h>
#include "Application.h"
#include "Rigibody.h"
#include "box2d/b2_body.h"
#include "ApplicationApi.h"
#include "EntityApi.h"
#include "CharacterController.h"
#include "SpriteRendererComponent.h"

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

	appApi = new ApplicationApi(Application::GetInstance());

#pragma region import lua (DANGER: RISQUE D AVEUGLEMENT AIGUE)


	luabridge::getGlobalNamespace(luaState)
		.beginNamespace("LeTurfu")
		//Vector2f SFML
		.beginClass<sf::Vector2f>("Vector2f")
		.addProperty("x", &sf::Vector2f::x)
		.addProperty("y", &sf::Vector2f::y)
		.endClass()

		//Vector2u
		.beginClass<sf::Vector2u>("Vector2u")
		.addProperty("x", &sf::Vector2u::x)
		.addProperty("y", &sf::Vector2u::y)
		.endClass()

		//Vector2 rigibody
		.beginClass<b2Vec2>("b2Vec2")
		.addProperty("x", &b2Vec2::x)
		.addProperty("y", &b2Vec2::y)
		.endClass()

		//Color
		.beginClass<sf::Color>("Color")
		.addConstructor<void (*) (int, int, int, int)>()
		.addProperty("r", &sf::Color::r)
		.addProperty("g", &sf::Color::g)
		.addProperty("b", &sf::Color::b)
		.addProperty("a", &sf::Color::a)
		.endClass()

		.beginClass<sf::Sprite>("Sprite")
		.addFunction("setColor", &sf::Sprite::setColor)
		.endClass()
		
		//RenderWindow
		.beginClass<sf::RenderWindow>("RenderWindow")
		.addFunction("getView", &sf::RenderWindow::getView)
		.addFunction("getSize", &sf::RenderWindow::getSize)
		.endClass()

		//View
		.beginClass<sf::View>("View")
		.addFunction("getCenter", &sf::View::getCenter)
		.addFunction("getSize", &sf::View::getSize)
		.endClass()

		//Transformable
		.beginClass<sf::Transformable>("Transformable")
		.addFunction("getScale", &sf::Transformable::getScale)
		.addFunction("getPosition", &sf::Transformable::getPosition)
		.endClass()

		//Texture
		.beginClass<sf::Texture>("Texture")
		.addFunction("getSize", &sf::Texture::getSize)
		.endClass()

		//AComponent
		.beginClass<LeTurfu::AComponent>("AComponent")
		//.addConstructor<LeTurfu::AComponent>()
		.endClass()

		//EntityApi
		.beginClass<LeTurfu::EntityApi>("EntityApi")
		.addFunction("getName", &LeTurfu::EntityApi::GetName)
		.addFunction("getPosition", &LeTurfu::EntityApi::GetPosition)
		.addFunction("getScale", &LeTurfu::EntityApi::GetScale)
		.addFunction("getComponentRigibody", &LeTurfu::EntityApi::GetComponentRigibody)
		.addFunction("getComponentCharacterController", &LeTurfu::EntityApi::GetComponentCharacterController)
		.addFunction("getComponentSpriteRenderer", &LeTurfu::EntityApi::GetComponentSpriteRenderer)
		.addFunction("destroyEntity", &LeTurfu::EntityApi::DestroyEntity)
		.endClass()

		//ApplicationAPi
		.beginClass<LeTurfu::ApplicationApi>("app")
		.addFunction("FindEntityparent", &LeTurfu::ApplicationApi::FindEntityParent)
		.addFunction("GetEntityByName", &LeTurfu::ApplicationApi::GetEntityByName)
		.addFunction("CloseWindow", &LeTurfu::ApplicationApi::CloseWindow)
		.addProperty("window", &LeTurfu::ApplicationApi::window)
		.endClass()

		//Rigibody
		.beginClass<LeTurfu::Rigibody>("Rigibody")
		.addFunction("GetLinearVelocity", &LeTurfu::Rigibody::GetLinearVelocity)
		.addProperty("movement", &LeTurfu::Rigibody::movement)
		.endClass()

		//CharacterController
		.beginClass<LeTurfu::CharacterController>("CharacterController")
		.addProperty("canMove", &LeTurfu::CharacterController::canMove)
		.endClass()

		//SpriteRendererComponents
		.beginClass<LeTurfu::SpriteRendererComponent>("SpriteRendererComponent")
		.addProperty("texture", &LeTurfu::SpriteRendererComponent::texture)
		.addProperty("sprite", &LeTurfu::SpriteRendererComponent::sprite)
		.endClass()

		.endNamespace();
#pragma endregion

	luabridge::setGlobal(luaState, appApi->FindEntityParent(this), "parent");
	luabridge::setGlobal(luaState, appApi, "app");
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
}
void LeTurfu::LuaScript::Start()
{
	luabridge::LuaRef start = luabridge::getGlobal(luaState, "start");
	luabridge::LuaResult res = start();
}

void LeTurfu::LuaScript::OnBeginContact()
{
	luabridge::LuaRef onBeginContact = luabridge::getGlobal(luaState, "onBeginContact");
	luabridge::LuaResult res = onBeginContact();
}
