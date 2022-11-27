#include <stdio.h>
#include "raylib.h"
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

#include "modules/graphics.h"

int main(){
	lua_State *L = luaL_newstate();
	luaL_loadfile(L, "main.lua");
	luaL_openlibs(L);
	lua_pcall(L, 0, 0, 0);

	luaL_dostring(L, "love = { graphics = {} }");
	lua_pushcfunction(L, graphics_rectangle);
	lua_setglobal(L, "graphics_rectangle");
	luaL_dostring(L, "love.graphics.rectangle = graphics_rectangle");
	
	InitWindow(800, 600, "l2d");

	while(!WindowShouldClose()){
		BeginDrawing();
			ClearBackground((Color){0, 0, 0});
			lua_getglobal(L, "update");
			lua_pcall(L, 0, 0, 0);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}