#include "raylib.h"
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

void add_function(lua_State *L, void *func_c, char *func_lua);

int mouse_getPosition(lua_State *L){
	lua_pushnumber(L, GetMouseX());
	lua_pushnumber(L, GetMouseY());
	return 2;
}

int mouse_isDown(lua_State *L){
	lua_pushboolean(L, IsMouseButtonDown(lua_tonumber(L, 1) - 1));
	return 1;
}

void mouse_init(lua_State *L){
	add_function(L, mouse_getPosition, "love.mouse.getPosition");
	add_function(L, mouse_isDown, "love.mouse.isDown");
}