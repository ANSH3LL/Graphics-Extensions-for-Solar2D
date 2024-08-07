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

#include <stdio.h>
#include <sys/stat.h>

#include "qoi/qoi.h"

#include "webp/demux.h"
#include "webp/decode.h"

#include "resvg/resvg.h"
#include "stbi/stb_image.h"

#ifdef _WIN32
    #define fstat _fstat
    #define stat_struct struct _stat
#else
    #define stat_struct struct stat
#endif

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

// https://arxiv.org/pdf/2202.02864v1.pdf
// Thanks to @StarCrunch on the Solar2D forums
inline void premultiplyAlpha(uint32_t* buffer, size_t size) {
    for(size_t i = 0; i < size; ++i, ++buffer) {
        uint32_t rb, ga;
        uint32_t color = *buffer;
        uint32_t alpha = color >> 24;
        color |= 0xff000000;
        rb = color & 0x00ff00ff;
        rb *= alpha;
        rb += 0x00800080;
        rb += (rb >> 8) & 0x00ff00ff;
        rb &= 0xff00ff00;
        ga = (color >> 8) & 0x00ff00ff;
        ga *= alpha;
        ga += 0x00800080;
        ga += (ga >> 8) & 0x00ff00ff;
        ga &= 0xff00ff00;
        *buffer = ga | (rb >> 8);
    }
}

void* readFile(const char* filename, size_t* length) {
    void* buffer;
    size_t file_size;

    size_t bytes_read;
    FILE* fp = fopen(filename, "rb");

    if(!fp) {
        return NULL;
    }

    stat_struct file_info;
    if(fstat(fileno(fp), &file_info)) {
        goto READ_FAIL;
    }

    file_size = file_info.st_size;

    if(file_size <= 0) {
        goto READ_FAIL;
    }

    buffer = malloc(file_size);

    if(!buffer) {
        goto READ_FAIL;
    }

    bytes_read = fread(buffer, 1, file_size, fp);

    if(bytes_read != file_size) {
        free(buffer);
        goto READ_FAIL;
    }

    (*length) = bytes_read;

    fclose(fp);
    return buffer;

READ_FAIL:
    fclose(fp);
    return NULL;
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
static int reset(lua_State* L);

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
