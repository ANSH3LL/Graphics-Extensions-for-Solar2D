// ----------------------------------------------------------------------------
// 
// PluginGfxe.cpp
// 
// ----------------------------------------------------------------------------

#define STB_IMAGE_IMPLEMENTATION
#define STBI_NO_STDIO

#define STBI_ONLY_JPEG
#define STBI_ONLY_PNG

#define QOI_IMPLEMENTATION
#define QOI_NO_STDIO

#include "PluginGfxe.h"

#define STATIC 1
#define ANIMATED 2
#define SCALABLE 3

#define animated_child static_cast<AnimatedTexture*>(texture->child)
#define scalable_child static_cast<ScalableTexture*>(texture->child)

// ----------------------------------------------------------------------------

CORONA_EXPORT int CoronaPluginLuaLoad_plugin_gfxe(lua_State*);

// ----------------------------------------------------------------------------

CORONA_EXPORT int luaopen_plugin_gfxe(lua_State* L) {
    lua_CFunction factory = Corona::Lua::Open<CoronaPluginLuaLoad_plugin_gfxe>;
    int result = CoronaLibraryNewWithFactory(L, factory, NULL, NULL);

    if(result) {
        const luaL_Reg kFunctions[] = {
            {"_newStaticTexture", newStaticTexture},
            {"_newScalableTexture", newScalableTexture},
            {"_newAnimatedTexture", newAnimatedTexture},
            {NULL, NULL}
        };

        luaL_register(L, NULL, kFunctions);
    }

    return result;
}

// ----------------------------------------------------------------------------

struct Texture {
    int width = 0;
    int height = 0;

    int trait = 0;
    void* child = NULL;

    unsigned char* pixels = NULL;
    CoronaExternalBitmapFormat format = kExternalBitmapFormat_Undefined;
};

struct ScalableTexture {
    resvg_options* opts;
    resvg_render_tree* tree = NULL;
};

struct AnimatedTexture {
    int elapsed = 0;
    int timestamp = 0;

    bool completed = false;
    bool should_loop = false;

    WebPData* data = NULL;
    WebPAnimInfo* info = NULL;
    WebPAnimDecoder* decoder = NULL;
};

// ----------------------------------------------------------------------------

static unsigned int GetWidth(void* context) {
    return ((Texture*)context)->width;
}

static unsigned int GetHeight(void* context) {
    return ((Texture*)context)->height;
}

static const void* GetImage(void* context) {
    return ((Texture*)context)->pixels;
}

static CoronaExternalBitmapFormat GetFormat(void* context) {
    return ((Texture*)context)->format;
}

// ----------------------------------------------------------------------------

static int GetField(lua_State* L, const char* field, void* context) {
    int result = 0;

    if(strcmp(field, "update") == 0) {
        result = PushCachedFunction(L, update);
    }
    else if(strcmp(field, "modify") == 0) {
        result = PushCachedFunction(L, modify);
    }

    else if(strcmp(field, "reset") == 0) {
        result = PushCachedFunction(L, reset);
    }

    else if(strcmp(field, "completed") == 0) {
        result = completed(L, context);
    }

    else if(strcmp(field, "frameCount") == 0) {
        result = frames(L, context);
    }
    else if(strcmp(field, "trait") == 0) {
        result = trait(L, context);
    }

    return result;
}

static void Dispose(void* context) {
    Texture* texture = (Texture*)context;

    if(texture->trait == ANIMATED) {
        AnimatedTexture* child = (AnimatedTexture*)texture->child;

        WebPAnimDecoderDelete(child->decoder);
        free((void*)child->data->bytes);

        delete child->data;
        delete child->info;

        delete child;
        goto EXIT;
    }

    if(texture->trait == SCALABLE) {
        ScalableTexture* child = (ScalableTexture*)texture->child;

        resvg_options_destroy(child->opts);
        resvg_tree_destroy(child->tree);

        delete child;
    }

    if(texture->pixels) {
        free(texture->pixels);
    }

EXIT:
    delete texture;
}

// ----------------------------------------------------------------------------

static int update(lua_State* L) {
    Texture* texture = (Texture*)CoronaExternalGetUserData(L, 1);

    if(texture->trait != ANIMATED) {
        return 0;
    }

    int delta = luaL_checkinteger(L, 2);

    if(delta > 0) {
        int now = animated_child->elapsed + delta;

        while(now > animated_child->timestamp) {
            if(WebPAnimDecoderHasMoreFrames(animated_child->decoder)) {
                uint8_t* pixels;

                WebPAnimDecoderGetNext(animated_child->decoder, &pixels, &animated_child->timestamp);
                texture->pixels = (unsigned char*)pixels;
            }
            else if(animated_child->should_loop) {
                now = 0;
                uint8_t* pixels;

                WebPAnimDecoderReset(animated_child->decoder);
                WebPAnimDecoderGetNext(animated_child->decoder, &pixels, &animated_child->timestamp);

                texture->pixels = (unsigned char*)pixels;
                break;
            }
            else {
                animated_child->completed = true;
                now = 0;
                break;
            }
        }

        animated_child->elapsed = now;
    }

    return 0;
}

static int modify(lua_State* L) {
    double multiplier = 0;
    bool should_crop = false;

    size_t length = 0;
    int width = 0, height = 0;

    const char* nodeID = NULL;
    const char* svg_data = NULL;

    Texture* texture = (Texture*)CoronaExternalGetUserData(L, 1);

    if(texture->trait != SCALABLE) {
        return 0;
    }

    int bpp = CoronaExternalFormatBPP(texture->format);

    resvg_transform transform = resvg_transform_identity();
    resvg_fit_to fit_to = { RESVG_FIT_TO_TYPE_ORIGINAL, 1 };

    if(lua_istable(L, 2)) {
        std::vector<double> r = asArray(L, 2, "render");

        std::vector<double> s = asArray(L, 2, "sizing");
        std::vector<double> t = asArray(L, 2, "transform");

        const char* res_path = asString(L, 2, "resourceDir");

        const char* languages = asString(L, 2, "languages");
        const char* font_family = asString(L, 2, "fontFamily");

        double font_size = asDouble(L, 2, "fontSize");

        size_t font_length = 0;
        const char* font_data = asString(L, 2, "fontData", &font_length);

        if(res_path) {
            resvg_options_set_resources_dir(scalable_child->opts, res_path);
        }

        if(languages) {
            resvg_options_set_languages(scalable_child->opts, languages);
        }

        if(font_family) {
            resvg_options_set_font_family(scalable_child->opts, font_family);
        }

        if(font_size > 0) {
            resvg_options_set_font_size(scalable_child->opts, font_size);
        }

        if(font_data) {
            resvg_options_load_font_data(scalable_child->opts, font_data, font_length);
        }

        nodeID = asString(L, 2, "nodeID");
        svg_data = asString(L, 2, "svgData", &length);

        should_crop = setupSVG(scalable_child->opts, &fit_to, &transform, &width, &height, &multiplier, r, s, t);
    }

    if(svg_data) {
        int result = resvg_parse_tree_from_data(svg_data, (int)length, scalable_child->opts, &scalable_child->tree);

        if(result != RESVG_OK) {
            goto MODIFY_FAIL;
        }
    }

    if(!resvg_is_image_empty(scalable_child->tree)) {
        goto MODIFY_FAIL;
    }

    if(nodeID && !resvg_node_exists(scalable_child->tree, nodeID)) {
        goto MODIFY_FAIL;
    }

    if(!nodeID && should_crop) {
        resvg_rect bbox;
        resvg_get_image_bbox(scalable_child->tree, &bbox);

        resvg_rect vbox = resvg_get_image_viewbox(scalable_child->tree);

        if(multiplier > 0) {
            transform.e -= (bbox.x - vbox.x) * multiplier;
            transform.f -= (bbox.y - vbox.y) * multiplier;

            texture->width = bbox.width * multiplier;
            texture->height = bbox.height * multiplier;
        }
        else {
            transform.e -= bbox.x - vbox.x;
            transform.f -= bbox.y - vbox.y;

            texture->width = bbox.width;
            texture->height = bbox.height;
        }
    }
    else {
        resvg_size size;

        if(nodeID) {
            resvg_path_bbox pbox;
            resvg_get_node_bbox(scalable_child->tree, nodeID, &pbox);

            size.width = pbox.width;
            size.height = pbox.height;
        }
        else {
            size = resvg_get_image_size(scalable_child->tree);
        }

        if(multiplier > 0) {
            width = size.width * multiplier;
            height = size.height * multiplier;
        }

        texture->width = width >= 1 ? width : size.width;
        texture->height = height >= 1 ? height : size.height;
    }

{
    char* pixels = (char*)calloc(texture->width * texture->height * 4, sizeof(char));

    if(!pixels) {
        goto MODIFY_FAIL;
    }

    if(texture->pixels) {
        free(texture->pixels);
    }

    if(nodeID) {
        resvg_render_node(scalable_child->tree, nodeID, fit_to, transform, texture->width, texture->height, pixels);
    }
    else {
        resvg_render(scalable_child->tree, fit_to, transform, texture->width, texture->height, pixels);
    }

    texture->pixels = stbi__convert_format((unsigned char*)pixels, 4, bpp, texture->width, texture->height);

    if(texture->pixels) {
        lua_pushboolean(L, true);
        return 1;
    }
}

MODIFY_FAIL:
    lua_pushboolean(L, false);
    return 1;
}

static int reset(lua_State* L) {
    Texture* texture = (Texture*)CoronaExternalGetUserData(L, 1);

    if(texture->trait != ANIMATED) {
        return 0;
    }

    animated_child->should_loop = lua_toboolean(L, 2);
    animated_child->completed = false;
    animated_child->elapsed = 0;

    uint8_t* pixels;

    WebPAnimDecoderReset(animated_child->decoder);
    WebPAnimDecoderGetNext(animated_child->decoder, &pixels, &animated_child->timestamp);

    texture->pixels = (unsigned char*)pixels;

    return 0;
}

// ----------------------------------------------------------------------------

static int frames(lua_State* L, void* context) {
    Texture* texture = (Texture*)context;

    switch(texture->trait) {
        case ANIMATED:
            lua_pushnumber(L, animated_child->info->frame_count);
            break;
        default:
            lua_pushnil(L);
            break;
    }

    return 1;
}

static int trait(lua_State* L, void* context) {
    Texture* texture = (Texture*)context;

    switch(texture->trait) {
        case STATIC:
            lua_pushstring(L, "static");
            break;
        case ANIMATED:
            lua_pushstring(L, "animated");
            break;
        case SCALABLE:
            lua_pushstring(L, "scalable");
            break;
        default:
            lua_pushstring(L, "unknown");
            break;
    }

    return 1;
}

static int completed(lua_State* L, void* context) {
    Texture* texture = (Texture*)context;

    switch(texture->trait) {
        case ANIMATED:
            lua_pushboolean(L, animated_child->completed);
            break;
        default:
            lua_pushnil(L);
            break;
    }

    return 1;
}

// ----------------------------------------------------------------------------

bool decodeSTBI(Texture* texture, unsigned char* data, int length) {
    int channels = 0;
    int width = 0, height = 0;
    int bpp = CoronaExternalFormatBPP(texture->format);

    unsigned char* pixels = stbi_load_from_memory(data, length, &width, &height, &channels, bpp);

    if(!pixels) {
        return false;
    }

    if(bpp == 4 && channels == 4) {
        size_t buffer_size = width * height;
        premultiplyAlpha((uint32_t*)pixels, buffer_size);
    }

    texture->width = width;
    texture->height = height;

    texture->pixels = pixels;

    return true;
}

bool decodeQOI(Texture* texture, unsigned char* data, int length) {
    qoi_desc info;
    int bpp = CoronaExternalFormatBPP(texture->format);

    unsigned char* pixels = (unsigned char*)qoi_decode(data, length, &info, 0);

    if(!pixels) {
        return false;
    }

    if(bpp == 4 && info.channels == 4) {
        size_t buffer_size = info.width * info.height;
        premultiplyAlpha((uint32_t*)pixels, buffer_size);
    }

    texture->pixels = stbi__convert_format(pixels, info.channels, bpp, info.width, info.height);

    if(texture->pixels) {
        texture->width = info.width;
        texture->height = info.height;

        return true;
    }

    return false;
}

bool decodeWEBP(Texture* texture, const uint8_t* data, size_t length) {
    WebPDecoderConfig config;
    int width = 0, height = 0;
    int bpp = CoronaExternalFormatBPP(texture->format);

    if(!WebPGetInfo(data, length, &width, &height)) {
        return false;
    }

    if(!WebPInitDecoderConfig(&config)) {
        return false;
    }

    size_t buffer_size = width * height * 4;
    unsigned char* pixels = (unsigned char*)malloc(buffer_size * sizeof(unsigned char));
    
    if(!pixels) {
        return false;
    }

    config.options.use_threads = 1;

    config.output.colorspace = MODE_rgbA;
    config.output.is_external_memory = 1;

    config.output.u.RGBA.size = buffer_size;
    config.output.u.RGBA.stride = width * 4;
    config.output.u.RGBA.rgba = (uint8_t*)pixels;

    if(WebPDecode(data, length, &config) != VP8_STATUS_OK) {
        free(pixels);
        return false;
    }

    WebPFreeDecBuffer(&config.output);

    texture->pixels = stbi__convert_format(pixels, 4, bpp, width, height);

    if(texture->pixels) {
        texture->width = width;
        texture->height = height;

        return true;
    }

    return false;
}

// ----------------------------------------------------------------------------

bool setupSVG(resvg_options* opts, resvg_fit_to* fit_to, resvg_transform* transform, int* width, int* height, double* multiplier, std::vector<double> r, std::vector<double> s, std::vector<double> t) {
    bool should_crop = false;

    // Render
    if(r.size() > 0) {
        resvg_options_set_dpi(opts, r[0]);
        resvg_options_set_shape_rendering_mode(opts, (resvg_shape_rendering)r[1]);

        resvg_options_set_text_rendering_mode(opts, (resvg_text_rendering)r[2]);
        resvg_options_set_image_rendering_mode(opts, (resvg_image_rendering)r[3]);
    }

    // Sizing
    if(s.size() > 0) {
        should_crop = (bool)s[4];

        switch((resvg_fit_to_type)s[2]) {
            case RESVG_FIT_TO_TYPE_WIDTH:
                if(s[0] >= 1) {
                    fit_to->type = RESVG_FIT_TO_TYPE_WIDTH;
                    fit_to->value = s[0];

                    (*width) = (int)s[0];
                    (*height) = (int)s[1];
                }
                break;
            case RESVG_FIT_TO_TYPE_HEIGHT:
                if(s[1] >= 1) {
                    fit_to->type = RESVG_FIT_TO_TYPE_HEIGHT;
                    fit_to->value = s[1];

                    (*width) = (int)s[0];
                    (*height) = (int)s[1];
                }
                break;
            case RESVG_FIT_TO_TYPE_ZOOM:
                if(s[3] > 0) {
                    fit_to->type = RESVG_FIT_TO_TYPE_ZOOM;
                    fit_to->value = s[3];

                    (*multiplier) = s[3];
                }
                break;
            default:
                fit_to->type = RESVG_FIT_TO_TYPE_ORIGINAL;
                fit_to->value = 1;
                break;
        }
    }

    // Transform
    if(t.size() > 0) {
        transform->a = t[0];
        transform->b = t[1];

        transform->c = t[2];
        transform->d = t[3];

        transform->e = t[4];
        transform->f = t[5];
    }

    return should_crop;
}

// ----------------------------------------------------------------------------

static int newTexture(lua_State* L, void* texture) {
    CoronaExternalTextureCallbacks callbacks = {};
    callbacks.size = sizeof(CoronaExternalTextureCallbacks);
    callbacks.getWidth = GetWidth;
    callbacks.getHeight = GetHeight;
    callbacks.onRequestBitmap = GetImage;
    callbacks.getFormat = GetFormat;
    callbacks.onGetField = GetField;
    callbacks.onFinalize = Dispose;

    return CoronaExternalPushTexture(L, &callbacks, texture);
}

// ----------------------------------------------------------------------------

static int newStaticTexture(lua_State* L) {
    size_t length = 0;
    Texture* texture = new Texture;

    const char* format = luaL_checkstring(L, 1);
    const char* data = luaL_checklstring(L, 2, &length);

    texture->trait = STATIC;
    texture->format = strToFmt(format);

    if(decodeQOI(texture, (unsigned char*)data, (int)length)) {
        return newTexture(L, texture);
    }
    if(decodeWEBP(texture, (const uint8_t*)data, length)) {
        return newTexture(L, texture);
    }
    if(decodeSTBI(texture, (unsigned char*)data, (int)length)) {
        return newTexture(L, texture);
    }

    delete texture;
    lua_pushnil(L);
    return 1;
}

// ----------------------------------------------------------------------------

static int newScalableTexture(lua_State* L) {
    size_t length = 0;
    double multiplier = 0;
    bool should_crop = false;

    int width = 0, height = 0;
    Texture* texture = new Texture;

    const char* format = luaL_checkstring(L, 1);
    const char* data = luaL_checklstring(L, 2, &length);

    texture->trait = SCALABLE;
    texture->format = strToFmt(format);

    texture->child = new ScalableTexture;
    scalable_child->opts = resvg_options_create();

    resvg_transform transform = resvg_transform_identity();
    resvg_fit_to fit_to = { RESVG_FIT_TO_TYPE_ORIGINAL, 1 };

    if(lua_istable(L, 3)) {
        std::vector<double> r = asArray(L, 3, "render");

        std::vector<double> s = asArray(L, 3, "sizing");
        std::vector<double> t = asArray(L, 3, "transform");

        const char* res_path = asString(L, 3, "resourceDir");

        const char* languages = asString(L, 3, "languages");
        const char* font_family = asString(L, 3, "fontFamily");

        double font_size = asDouble(L, 3, "fontSize");

        size_t font_length = 0;
        const char* font_data = asString(L, 3, "fontData", &font_length);

        if(res_path) {
            resvg_options_set_resources_dir(scalable_child->opts, res_path);
        }

        if(languages) {
            resvg_options_set_languages(scalable_child->opts, languages);
        }

        if(font_family) {
            resvg_options_set_font_family(scalable_child->opts, font_family);
        }

        if(font_size > 0) {
            resvg_options_set_font_size(scalable_child->opts, font_size);
        }

        if(asBoolean(L, 3, "systemFonts")) {
            resvg_options_load_system_fonts(scalable_child->opts);
        }

        if(font_data) {
            resvg_options_load_font_data(scalable_child->opts, font_data, font_length);
        }

        should_crop = setupSVG(scalable_child->opts, &fit_to, &transform, &width, &height, &multiplier, r, s, t);
    }

    int bpp = CoronaExternalFormatBPP(texture->format);
    int result = resvg_parse_tree_from_data(data, (int)length, scalable_child->opts, &scalable_child->tree);

    if(result != RESVG_OK) {
        goto SVG_FAIL;
    }

    if(!resvg_is_image_empty(scalable_child->tree)) {
        resvg_tree_destroy(scalable_child->tree);

        goto SVG_FAIL;
    }

    if(should_crop) {
        resvg_rect bbox;
        resvg_get_image_bbox(scalable_child->tree, &bbox);

        resvg_rect vbox = resvg_get_image_viewbox(scalable_child->tree);

        if(multiplier > 0) {
            transform.e -= (bbox.x - vbox.x) * multiplier;
            transform.f -= (bbox.y - vbox.y) * multiplier;

            texture->width = bbox.width * multiplier;
            texture->height = bbox.height * multiplier;
        }
        else {
            transform.e -= bbox.x - vbox.x;
            transform.f -= bbox.y - vbox.y;

            texture->width = bbox.width;
            texture->height = bbox.height;
        }
    }
    else {
        resvg_size size = resvg_get_image_size(scalable_child->tree);

        if(multiplier > 0) {
            width = size.width * multiplier;
            height = size.height * multiplier;
        }

        texture->width = width >= 1 ? width : size.width;
        texture->height = height >= 1 ? height : size.height;
    }

{
    char* pixels = (char*)calloc(texture->width * texture->height * 4, sizeof(char));

    if(!pixels) {
        resvg_tree_destroy(scalable_child->tree);
        goto SVG_FAIL;
    }

    resvg_render(scalable_child->tree, fit_to, transform, texture->width, texture->height, pixels);

    texture->pixels = stbi__convert_format((unsigned char*)pixels, 4, bpp, texture->width, texture->height);

    if(texture->pixels) {
        return newTexture(L, texture);
    }
    else {
        resvg_tree_destroy(scalable_child->tree);
    }
}

SVG_FAIL:
    resvg_options_destroy(scalable_child->opts);

    delete scalable_child;
    delete texture;

    lua_pushnil(L);
    return 1;
}

// ----------------------------------------------------------------------------

static int newAnimatedTexture(lua_State* L) {
    size_t length = 0;
    Texture* texture = new Texture;

    bool loop = lua_toboolean(L, 1);
    const char* data = luaL_checklstring(L, 2, &length);

    texture->trait = ANIMATED;
    texture->format = strToFmt("rgba");

    texture->child = new AnimatedTexture;
    animated_child->should_loop = loop;

    WebPAnimDecoderOptions opts;
    if(!WebPAnimDecoderOptionsInit(&opts)) {
        goto WEBP_FAIL;
    }

    opts.use_threads = 1;
    opts.color_mode = MODE_rgbA;

{
    void* bytes = malloc(length * sizeof(const char));

    if(!bytes) {
        goto WEBP_FAIL;
    }

    memcpy(bytes, data, length * sizeof(const char));

    animated_child->data = new WebPData;
    animated_child->data->size = length;
    animated_child->data->bytes = (const uint8_t*)bytes;

    animated_child->decoder = WebPAnimDecoderNew(animated_child->data, &opts);

    if(!animated_child->decoder) {
        free((void*)animated_child->data->bytes);
        delete animated_child->data;

        goto WEBP_FAIL;
    }

    animated_child->info = new WebPAnimInfo;
    WebPAnimDecoderGetInfo(animated_child->decoder, animated_child->info);

    texture->width = animated_child->info->canvas_width;
    texture->height = animated_child->info->canvas_height;
}

{
    uint8_t* pixels;

    int result = WebPAnimDecoderGetNext(animated_child->decoder, &pixels, &animated_child->timestamp);

    if(!result) {
        WebPAnimDecoderDelete(animated_child->decoder);

        free((void*)animated_child->data->bytes);
        delete animated_child->data;
        delete animated_child->info;

        goto WEBP_FAIL;
    }

    texture->pixels = (unsigned char*)pixels;

    return newTexture(L, texture);
}

WEBP_FAIL:
    delete animated_child;
    delete texture;

    lua_pushnil(L);
    return 1;
}
