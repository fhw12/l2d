#include <stdio.h>
#include "raylib.h"
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

#include "modules/graphics.h"
#include "modules/timer.h"

int main(){
	lua_State *L = luaL_newstate();
	luaL_loadfile(L, "main.lua");
	luaL_openlibs(L);

	luaL_dostring(L, "function none() end\nlove = { graphics = {}, timer={}, load = none, update = none, draw = none  }\nnone = nil");

	graphics_init(L);
	timer_init(L);

	lua_pcall(L, 0, 0, 0);
	luaL_dostring(L, "love.load()");
	
	InitWindow(800, 600, "l2d");

	while(!WindowShouldClose()){
		luaL_dostring(L, "love.update()");
		BeginDrawing();
			ClearBackground((Color){0, 0, 0});
			luaL_dostring(L, "love.draw()");
		EndDrawing();
	}

	CloseWindow();

	return 0;
}

void add_function(lua_State *L, void *func_c, char *func_lua){
	lua_pushcfunction(L, func_c);
	lua_setglobal(L, "lua_function");
	luaL_dostring(L, TextFormat("%s = lua_function", func_lua));
	luaL_dostring(L, "lua_function = nil");
}