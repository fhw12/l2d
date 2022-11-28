#include <string.h>
#include <stdlib.h>

#include "raylib.h"
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

struct Color color;

void add_function(lua_State *L, void *func_c, char *func_lua){
	lua_pushcfunction(L, func_c);
	lua_setglobal(L, "lua_function");
	luaL_dostring(L, TextFormat("%s = lua_function", func_lua));
	luaL_dostring(L, "lua_function = nil");
}

void graphics_setColor(lua_State *L){
	double r = lua_tonumber(L, 1);
	double g = lua_tonumber(L, 2);
	double b = lua_tonumber(L, 3);

	if(r > 1){r = 1;}
	if(g > 1){g = 1;}
	if(b > 1){b = 1;}

	color.r = (unsigned char)(r * 255);
	color.g = (unsigned char)(g * 255);
	color.b = (unsigned char)(b * 255);
}

void graphics_rectangle(lua_State *L){
	const char *rectangle_type = lua_tostring(L, 1);
	int x = lua_tonumber(L, 2);
	int y = lua_tonumber(L, 3);
	int width = lua_tonumber(L, 4);
	int height = lua_tonumber(L, 5);

	if(!strcmp(rectangle_type, "line")){
		DrawRectangleLines(x, y, width, height, color);
	} else if(!strcmp(rectangle_type, "fill")){
		DrawRectangle(x, y, width, height, color);
	}
}

int graphics_init(lua_State *L){
	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.a = 255;

	add_function(L, graphics_setColor, "love.graphics.setColor");
	add_function(L, graphics_rectangle, "love.graphics.rectangle");
}