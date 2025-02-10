#if !defined(PLATFORM_DESKTOP_GLFW) && \
    !defined(PLATFORM_DESKTOP_SDL)  && \
    !defined(PLATFORM_DESKTOP_RGFW) && \
    !defined(PLATFORM_WEB) && \
    !defined(PLATFORM_DRM) && \
    !defined(PLATFORM_ANDROID)
    #define PLATFORM_DESKTOP_GLFW
#endif

#if defined(__linux__)
    #if !defined(_GLFW_WAYLAND) && !defined(_GLFW_X11)
        #define _GLFW_X11
    #endif
    #define _GNU_SOURCE
    #include <poll.h>
#endif

#include "raylib.h"
#define RAYMATH_STATIC_INLINE
#include "raymath.h"

//#define Font Font_

#include "rtextures.c"
#undef COLOR_EQUAL
#undef MIN


#include "raudio.c"

#undef L
#undef C
#undef R


#include "rmodels.c"
#undef COLOR_EQUAL

#include "rtext.c"
#undef COLOR_EQUAL

#include "rshapes.c"

#include "utils.c"

#undef KEY_CAPS_LOCK
#undef KEY_ESCAPE
#undef KEY_KP_ADD
#undef KEY_KP_SUBTRACT
#undef KEY_LEFT_CONTROL
#undef KEY_LEFT_CONTROL
#undef KEY_NUM_LOCK

#include "rcore.c"


#if defined(__linux__)
    // Avoid name conflict with X11
    #define Font Font_
#endif

#undef GLFW_INCLUDE_NONE

#undef KEY_APOSTROPHE
#undef KEY_COMMA
#undef KEY_LEFT_CONTROL
#undef KEY_KP_SUBTRACT
#undef KEY_KP_ADD
#undef KEY_CAPS_LOCK
#undef KEY_NUM_LOCK
#undef KEY_ESCAPE
#undef KEY_LEFT_CONTROL
#undef KEY_MINUS

#undef GL_VERSION
#undef GL_EXTENSIONS
#undef GL_NUM_EXTENSIONS
#undef GL_CONTEXT_FLAGS

#include "rglfw.c"
