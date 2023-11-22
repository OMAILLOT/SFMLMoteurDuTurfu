#pragma once
#include <string>
#include <lua.hpp>
#include "AComponent.h"

namespace LeTurfu {

class LuaScript : public AComponent
{
protected:
	
	lua_State* luaState;
	void ReportError(lua_State* luaState, int status);

public:
	LuaScript();
	void Init();
	void SetScript(std::string assetID);
	virtual void Update(float deltaTime) override;

};

}