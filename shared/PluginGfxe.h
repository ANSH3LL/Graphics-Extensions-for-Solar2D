// ----------------------------------------------------------------------------
// 
// PluginGfxe.h
// 
// ----------------------------------------------------------------------------

#ifndef _SimulatorPluginLibrary_H__
#define _SimulatorPluginLibrary_H__

#include <CoronaLua.h>
#include <CoronaMacros.h>
#include <CoronaLibrary.h>
#include <CoronaGraphics.h>

#include <vector>
#include <cstring>

#include "qoi/qoi.h"

#include "webp/demux.h"
#include "webp/decode.h"

#include "resvg/resvg.h"
#include "stbi/stb_image.h"

// ----------------------------------------------------------------------------

CORONA_EXPORT int luaopen_plugin_gfxe(lua_State* L);

// ----------------------------------------------------------------------------

static int newStaticTexture(lua_State* L);
static int newScalableTexture(lua_State* L);
static int newAnimatedTexture(lua_State* L);

// ----------------------------------------------------------------------------

CoronaExternalBitmapFormat strToFmt(const char* format) {
    if(strcmp(format, "rgb") == 0) {
        return kExternalBitmapFormat_RGB;
    }
    else if(strcmp(format, "mask") == 0) {
        return kExternalBitmapFormat_Mask;
    }
    else {
        return kExternalBitmapFormat_RGBA;
    }
}

void premultiplyAlpha(unsigned char* buffer, size_t size) {
    for(size_t i = 0; i < size; i += 4) {
        unsigned int alpha = buffer[i + 3];

        buffer[i] = (unsigned char)((alpha * buffer[i]) / 255);
        buffer[i + 1] = (unsigned char)((alpha * buffer[i + 1]) / 255);
        buffer[i + 2] = (unsigned char)((alpha * buffer[i + 2]) / 255);
    }
}

// ----------------------------------------------------------------------------

static int PushCachedFunction(lua_State* L, lua_CFunction F) {
    lua_pushlightuserdata(L, (void*)F);
    lua_gettable(L, LUA_REGISTRYINDEX);

    if (!lua_iscfunction(L, -1)) {
        lua_pop(L, 1);
        lua_pushcfunction(L, F);
        lua_pushlightuserdata(L, (void*)F);

        lua_pushvalue(L, -2);
        lua_settable(L, LUA_REGISTRYINDEX);
    }

    return 1;
}

// ----------------------------------------------------------------------------

bool asBoolean(lua_State* L, int index, const char* key) {
    lua_getfield(L, index, key);
    bool bln = lua_toboolean(L, -1);

    lua_pop(L, 1);
    return bln;
}

double asDouble(lua_State* L, int index, const char* key) {
    lua_getfield(L, index, key);
    double num = 0;

    if(!lua_isnil(L, -1)) {
        num = lua_tonumber(L, -1);
    }

    lua_pop(L, 1);
    return num;
}

std::vector<double> asArray(lua_State* L, int index, const char* key) {
    lua_getfield(L, index, key);
    std::vector<double> array = {};

    if(lua_istable(L, -1)) {
        int len = lua_objlen(L, -1);

        for(int i = 1; i <= len; i++) {
            lua_rawgeti(L, -1, i);
            array.push_back(lua_tonumber(L, -1));
            lua_pop(L, 1);
        }
    }

    lua_pop(L, 1);
    return array;
}

const char* asString(lua_State* L, int index, const char* key) {
    lua_getfield(L, index, key);
    const char* str = NULL;

    if(!lua_isnil(L, -1)) {
        str = lua_tostring(L, -1);
    }

    lua_pop(L, 1);
    return str;
}

const char* asString(lua_State* L, int index, const char* key, size_t* length) {
    lua_getfield(L, index, key);
    const char* str = NULL;

    if(!lua_isnil(L, -1)) {
        str = lua_tolstring(L, -1, length);
    }

    lua_pop(L, 1);
    return str;
}

// ----------------------------------------------------------------------------

static int update(lua_State* L);
static int modify(lua_State* L);

static int trait(lua_State* L, void* context);
static int frames(lua_State* L, void* context);
static int completed(lua_State* L, void* context);

bool setupSVG(
    resvg_options* opts, resvg_fit_to* fit_to, resvg_transform* transform,
    int* width, int* height, double* multiplier,
    std::vector<double> r, std::vector<double> s, std::vector<double> t
);

// ----------------------------------------------------------------------------

#endif // _SimulatorPluginLibrary_H__
