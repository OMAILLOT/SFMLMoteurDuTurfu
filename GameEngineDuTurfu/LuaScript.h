#pragma once
#include "lua.h"
#include <string>

namespace LeTurfu {

class LuaScript
{
protected:
	
	lua_State* luaState;
	void ReportError(lua_State* luaState, int status);

public:
	LuaScript();
	void SetScript(std::string assetID);

};

}