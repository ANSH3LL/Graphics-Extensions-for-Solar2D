LOCAL_PATH := $(call my-dir)

CORONA_NATIVE := C:\PROGRA~2\CORONA~1\Corona\Native
CORONA_ROOT := $(CORONA_NATIVE)/Corona
LUA_API_DIR := $(CORONA_ROOT)/shared/include/lua
LUA_API_CORONA := $(CORONA_ROOT)/shared/include/Corona

SRC_DIR := ../../shared

HEADER_DIR := $(SRC_DIR)/include

######################################################################

include $(CLEAR_VARS)
LOCAL_MODULE := liblua
LOCAL_SRC_FILES := ../corona-libs/jni/$(TARGET_ARCH_ABI)/liblua.so
LOCAL_EXPORT_C_INCLUDES := $(LUA_API_DIR)
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libcorona
LOCAL_SRC_FILES := ../corona-libs/jni/$(TARGET_ARCH_ABI)/libcorona.so
LOCAL_EXPORT_C_INCLUDES := $(LUA_API_CORONA)
include $(PREBUILT_SHARED_LIBRARY)

######################################################################

include $(CLEAR_VARS)
LOCAL_MODULE := libresvg
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libresvg.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libwebp
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libwebp.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libwebpdecoder_static
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libwebpdecoder_static.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libwebpdemux
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libwebpdemux.a
include $(PREBUILT_STATIC_LIBRARY)

######################################################################

include $(CLEAR_VARS)

LOCAL_MODULE := libplugin.gfxe

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(HEADER_DIR)

LOCAL_SRC_FILES := $(SRC_DIR)/PluginGfxe.cpp $(SRC_DIR)/generated/plugin_gfxe.c

LOCAL_CFLAGS := \
    -DANDROID_NDK \
    -DNDEBUG \
    -D_REENTRANT \
    -DRtt_ANDROID_ENV \
    -ffast-math \
    -finline-functions \
    -Ofast

LOCAL_LDLIBS := -s

LOCAL_SHARED_LIBRARIES := liblua libcorona

LOCAL_STATIC_LIBRARIES := libresvg libwebp libwebpdecoder_static libwebpdemux

ifeq ($(TARGET_ARCH), arm)
    LOCAL_CFLAGS+= -D_ARM_ASSEM_
endif

LOCAL_ARM_MODE := arm
include $(BUILD_SHARED_LIBRARY)
