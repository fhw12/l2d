#include <stdio.h>
#include "raylib.h"
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

int main(){
	lua_State *L = luaL_newstate();
	luaL_loadfile(L, "main.lua");
	luaL_openlibs(L);
	lua_pcall(L, 0, 0, 0);

	InitWindow(800, 600, "l2d");

	while(!WindowShouldClose()){
		BeginDrawing();
			ClearBackground((Color){0, 0, 0});
		EndDrawing();
	}

	CloseWindow();

	return 0;
}