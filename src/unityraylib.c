#if !defined(PLATFORM_DESKTOP_GLFW) && \
    !defined(PLATFORM_DESKTOP_SDL)  && \
    !defined(PLATFORM_DESKTOP_RGFW) && \
    !defined(PLATFORM_WEB) && \
    !defined(PLATFORM_DRM) && \
    !defined(PLATFORM_ANDROID)
    #define PLATFORM_DESKTOP_GLFW
#endif

#if defined(__linux__)
    #define _GNU_SOURCE
    #include <poll.h> // for ppoll

    #if !defined(_GLFW_WAYLAND) && !defined(_GLFW_X11)
        #define _GLFW_X11
    #endif
    #if defined(_GLFW_X11)
        #define Font Font_
        #include <X11/Xlib.h>
        #include <X11/Xcursor/Xcursor.h>
        #include <linux/input.h>
        #undef Font
        // linux/input-event-codes.h defins a lot of key codes that conflict with raylib
        #undef KEY_APOSTROPHE
        #undef KEY_CAPS_LOCK
        #undef KEY_CAPSLOCK
        #undef KEY_ESCAPE
        #undef KEY_KP_ADD
        #undef KEY_KP_SUBTRACT
        #undef KEY_LEFT_CONTROL
        #undef KEY_LEFTCTRL
        #undef KEY_NUM_LOCK
        #undef KEY_NUMLOCK
        #undef KEY_PLAY
        #undef KEY_SCALE
        #undef KEY_CAPS_LOCK
        #undef KEY_COMMA
        #undef KEY_ESCAPE
        #undef KEY_FN_D
        #undef KEY_KP_ADD
        #undef KEY_KP_SUBTRACT
        #undef KEY_LEFT_CONTROL
        #undef KEY_NUM_LOCK
        #undef KEY_TAPE
        #undef KEY_MINUS
        #undef KEY_SLASH
        #undef KEY_SEMICOLON
        #undef KEY_EQUAL
        #undef KEY_A
        #undef KEY_B
        #undef KEY_C
        #undef KEY_D
        #undef KEY_E
        #undef KEY_F
        #undef KEY_G
        #undef KEY_H
        #undef KEY_I
        #undef KEY_J
        #undef KEY_K
        #undef KEY_L
        #undef KEY_M
        #undef KEY_N
        #undef KEY_O
        #undef KEY_P
        #undef KEY_Q
        #undef KEY_R
        #undef KEY_S
        #undef KEY_T
        #undef KEY_U
        #undef KEY_V
        #undef KEY_W
        #undef KEY_X
        #undef KEY_Y
        #undef KEY_Z
        #undef KEY_BACKSLASH
        #undef KEY_GRAVE
        #undef KEY_SPACE
        #undef KEY_ENTER
        #undef KEY_TAB
        #undef KEY_BACKSPACE
        #undef KEY_INSERT
        #undef KEY_DELETE
        #undef KEY_RIGHT
        #undef KEY_LEFT
        #undef KEY_DOWN
        #undef KEY_UP
        #undef KEY_HOME
        #undef KEY_END
        #undef KEY_PAUSE
        #undef KEY_F1
        #undef KEY_F2
        #undef KEY_F3
        #undef KEY_F4
        #undef KEY_F5
        #undef KEY_F6
        #undef KEY_F7
        #undef KEY_F8
        #undef KEY_F9
        #undef KEY_F10
        #undef KEY_F11
        #undef KEY_F12
        #undef KEY_BACK
        #undef KEY_MENU
    #endif
#endif

#if defined(__linux__)
//#   define Font Font_
#endif
#include "rglfw.c"
#undef GL_VERSION
#undef GL_EXTENSIONS
#undef GL_NUM_EXTENSIONS
#undef GL_CONTEXT_FLAGS

#if defined(_WIN32)
//*
#   if defined(WIN32_LEAN_AND_MEAN)
#        undef WIN32_LEAN_AND_MEAN
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
#define PlaySoundA WIN32PlaySoundA
#define PlaySoundW WIN32PlaySoundW

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

#undef PlaySoundA
#undef PlaySoundW
#undef PlaySound

#undef ARRAYSIZE

// for raudio
#define WINGDI_ALREADY_INCLUDED
#define WINUSER_ALREADY_INCLUDED
#define WINGDI_ALREADY_INCLUDED
//*/
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


//ignore windows for now
#if defined(__linux__)
#if defined(_WIN32)
#   define HWND HWND_
#endif
#include "rcore.c"
#undef GLFW_INCLUDE_NONE

#undef _unused
#include "raudio.c"
#undef L
#undef C
#undef R
#endif