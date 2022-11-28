#include "raylib.h"
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

void add_function(lua_State *L, void *func_c, char *func_lua);

int timer_getFPS(lua_State *L){
	lua_pushnumber(L, GetFPS());
	return 1;
}

void timer_init(lua_State *L){
	add_function(L, timer_getFPS, "love.timer.getFPS");
}