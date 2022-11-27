#include "raylib.h"
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

int graphics_rectangle(lua_State *L){
	double x = lua_tonumber(L, 1);
	double y = lua_tonumber(L, 2);
	double width = lua_tonumber(L, 3);
	double height = lua_tonumber(L, 4);

	DrawRectangle((int)x, (int)y, (int)width, (int)height, WHITE);
}