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

void mouse_init(lua_State *L){
	add_function(L, mouse_getPosition, "love.mouse.getPosition");
}