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

#if defined(_WIN32)
/*
#   if !defined(WIN32_LEAN_AND_MEAN)
#        define WIN32_LEAN_AND_MEAN
#   endif

//from https://github.com/raylib-extras/extras-c/blob/main/raylib_win32.h
// move the windows functions to new names
// note that you can't call these functions or structures from your code, but you should not neeed to
#define CloseWindow CloseWindowWin32
#define Rectangle RectangleWin32
#define ShowCursor ShowCursorWin32
#define LoadImageA LoadImageAWin32
#define LoadImageW LoadImageWin32
#define DrawTextA DrawTextAWin32
#define DrawTextW DrawTextWin32
#define DrawTextExA DrawTextExAWin32
#define DrawTextExW DrawTextExWin32

// include windows
#include <windows.h>

// remove all our redfintions so that raylib can define them properly
#undef CloseWindow
#undef Rectangle
#undef ShowCursor
#undef LoadImage
#undef LoadImageA
#undef LoadImageW
#undef DrawText
#undef DrawTextA
#undef DrawTextW
#undef DrawTextEx
#undef DrawTextExA
#undef DrawTextExW

#undef ARRAYSIZE

// for raudio
#define WINGDI_ALREADY_INCLUDED
*/
#endif

#include "raylib.h"
#define RAYMATH_STATIC_INLINE
#include "raymath.h"

#include "rtextures.c"
#undef COLOR_EQUAL
#undef MIN

#include "rmodels.c"
#undef COLOR_EQUAL

#include "rtext.c"
#undef COLOR_EQUAL

#include "rshapes.c"

#include "utils.c"

#if defined(__linux__)
#   undef KEY_CAPS_LOCK
#   undef KEY_ESCAPE
#   undef KEY_KP_ADD
#   undef KEY_KP_SUBTRACT
#   undef KEY_LEFT_CONTROL
#   undef KEY_LEFT_CONTROL
#   undef KEY_NUM_LOCK
#endif
#include "rcore.c"
#undef GLFW_INCLUDE_NONE


#if defined(__linux__)
//  Avoid name conflict with X11
#   define Font Font_
#   undef KEY_APOSTROPHE
#   undef KEY_COMMA
#   undef KEY_LEFT_CONTROL
#   undef KEY_KP_SUBTRACT
#   undef KEY_KP_ADD
#   undef KEY_CAPS_LOCK
#   undef KEY_NUM_LOCK
#   undef KEY_ESCAPE
#   undef KEY_LEFT_CONTROL
#   undef KEY_MINUS

#   undef GL_VERSION
#   undef GL_EXTENSIONS
#   undef GL_NUM_EXTENSIONS
#   undef GL_CONTEXT_FLAGS
#endif



#include "rglfw.c"


#undef _unused
#include "raudio.c"
#undef L
#undef C
#undef R
