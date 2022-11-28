#include <string.h>

#include "raylib.h"
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

struct Color color;

void add_function(lua_State *L, void *func_c, char *func_lua);

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
	const char *draw_mode = lua_tostring(L, 1);
	int x = lua_tonumber(L, 2);
	int y = lua_tonumber(L, 3);
	int width = lua_tonumber(L, 4);
	int height = lua_tonumber(L, 5);

	if(!strcmp(draw_mode, "line")){
		DrawRectangleLines(x, y, width, height, color);
	} else if(!strcmp(draw_mode, "fill")){
		DrawRectangle(x, y, width, height, color);
	}
}

void graphics_circle(lua_State *L){
	const char *draw_mode = lua_tostring(L, 1);
	int x = lua_tonumber(L, 2);
	int y = lua_tonumber(L, 3);
	int r = lua_tonumber(L, 4);

	if(!strcmp(draw_mode, "line")){
		DrawCircleLines(x, y, r, color);
	} else if(!strcmp(draw_mode, "fill")){
		DrawCircle(x, y, r, color);
	}
}

void graphics_print(lua_State *L){
	const char *text = lua_tostring(L, 1);
	int x = lua_tonumber(L, 2);
	int y = lua_tonumber(L, 3);

	DrawText(text, x, y, 10, color);
}

void graphics_init(lua_State *L){
	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.a = 255;

	add_function(L, graphics_setColor, "love.graphics.setColor");
	add_function(L, graphics_rectangle, "love.graphics.rectangle");
	add_function(L, graphics_circle, "love.graphics.circle");
	add_function(L, graphics_print, "love.graphics.print");
}