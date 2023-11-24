#pragma once
#include <string>
#include <lua.hpp>
#include "AComponent.h"
#include "ApplicationApi.h"

namespace LeTurfu {

class LuaScript : public AComponent
{
protected:
	ApplicationApi* appApi;
	lua_State* luaState;
	void ReportError(lua_State* luaState, int status);

public:
	LuaScript();
	void Init();
	void SetScript(std::string assetID);
	virtual void Update(float deltaTime) override;
	virtual void Start() override;

	void OnBeginContact();

};

}