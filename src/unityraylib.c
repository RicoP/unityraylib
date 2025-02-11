#if 0 && defined(__linux)
#define	_MATH_H	1

#define FORCE_INLINE __attribute__((always_inline)) inline

static FORCE_INLINE double my_acos(double x) { return __builtin_acos(x); }
static FORCE_INLINE float my_acosf(float x) { return __builtin_acosf(x); }
static FORCE_INLINE float my_asinf(float x) { return __builtin_asinf(x); }
static FORCE_INLINE float my_atan2f(float y, float x) { return __builtin_atan2f(y, x); }
static FORCE_INLINE float my_ceilf(float x) { return __builtin_ceilf(x); }
static FORCE_INLINE double my_cos(double x) { return __builtin_cos(x); }
static FORCE_INLINE float my_cosf(float x) { return __builtin_cosf(x); }
static FORCE_INLINE double my_exp(double x) { return __builtin_exp(x); }
static FORCE_INLINE double my_floor(double x) { return __builtin_floor(x); }
static FORCE_INLINE float my_floorf(float x) { return __builtin_floorf(x); }
static FORCE_INLINE double my_fmax(double x, double y) { return __builtin_fmax(x, y); }
static FORCE_INLINE float my_fmaxf(float x, float y) { return __builtin_fmaxf(x, y); }
static FORCE_INLINE double my_fmin(double x, double y) { return __builtin_fmin(x, y); }
static FORCE_INLINE float my_fminf(float x, float y) { return __builtin_fminf(x, y); }
static FORCE_INLINE double my_fmod(double x, double y) { return __builtin_fmod(x, y); }
static FORCE_INLINE float my_fmodf(float x, float y) { return __builtin_fmodf(x, y); }
static FORCE_INLINE double my_hypot(double x, double y) { return __builtin_hypot(x, y); }
static FORCE_INLINE float my_hypotf(float x, float y) { return __builtin_hypotf(x, y); }
static FORCE_INLINE double my_log(double x) { return __builtin_log(x); }
static FORCE_INLINE float my_logf(float x) { return __builtin_logf(x); }
static FORCE_INLINE double my_pow(double base, double exp) { return __builtin_pow(base, exp); }
static FORCE_INLINE float my_powf(float base, float exp) { return __builtin_powf(base, exp); }
static FORCE_INLINE double my_round(double x) { return __builtin_round(x); }
static FORCE_INLINE float my_roundf(float x) { return __builtin_roundf(x); }
static FORCE_INLINE double my_sin(double x) { return __builtin_sin(x); }
static FORCE_INLINE float my_sinf(float x) { return __builtin_sinf(x); }
static FORCE_INLINE double my_sqrt(double x) { return __builtin_sqrt(x); }
static FORCE_INLINE float my_sqrtf(float x) { return __builtin_sqrtf(x); }
static FORCE_INLINE double my_tan(double x) { return __builtin_tan(x); }
static FORCE_INLINE double my_trunc(double x) { return __builtin_trunc(x); }

#define acos my_acos
#define acosf my_acosf
#define asinf my_asinf
#define atan2f my_atan2f
#define ceilf my_ceilf
#define cos my_cos
#define cosf my_cosf
#define exp my_exp
#define floor my_floor
#define floorf my_floorf
#define fmax my_fmax
#define fmaxf my_fmaxf
#define fmin my_fmin
#define fminf my_fminf
#define fmod my_fmod
#define fmodf my_fmodf
#define hypot my_hypot
#define hypotf my_hypotf
#define log my_log
#define logf my_logf
#define pow my_pow
#define powf my_powf
#define round my_round
#define roundf my_roundf
#define sin my_sin
#define sinf my_sinf
#define sqrt my_sqrt
#define sqrtf my_sqrtf
#define tan my_tan
#define trunc my_trunc

#define NAN (__builtin_nanf (""))

static FORCE_INLINE double my_ceil(double x) { return __builtin_ceil(x); }
static FORCE_INLINE double my_fabs(double x) { return __builtin_fabs(x); }
static FORCE_INLINE double my_fabsf(float x) { return __builtin_fabsf(x); }
static FORCE_INLINE double my_frexp(double x, int* exp) { return __builtin_frexp(x, exp); }
static FORCE_INLINE double my_ldexp(double x, int exp) { return __builtin_ldexp(x, exp); }
static FORCE_INLINE double my_ldexpf(float x, int exp) { return __builtin_ldexpf(x, exp); }
static FORCE_INLINE double my_signbit(double x) { return __builtin_signbit(x); }
static FORCE_INLINE double my_signbitf(float x) { return __builtin_signbitf(x); }

#define ceil my_ceil
#define fabs my_fabs
#define fabsf my_fabsf
#define frexp my_frexp
#define ldexp my_ldexp
#define ldexpf my_ldexpf
#define signbit my_signbit
#define signbitf my_signbitf
#endif

#if !defined(PLATFORM_DESKTOP_GLFW) && \
    !defined(PLATFORM_DESKTOP_SDL)  && \
    !defined(PLATFORM_DESKTOP_RGFW) && \
    !defined(PLATFORM_WEB) && \
    !defined(PLATFORM_DRM) && \
    !defined(PLATFORM_ANDROID)
#   define PLATFORM_DESKTOP_GLFW
#endif

#if defined(__linux__)
#   define _GNU_SOURCE
#   include <poll.h> // for ppoll
#   if !defined(_GLFW_WAYLAND) && !defined(_GLFW_X11)
#       define _GLFW_X11
#   endif
#   if defined(_GLFW_X11)
//      rename X11 Font struct to not conflict with raylibs Font
#       define Font Font_
#       include <X11/Xlib.h>
#       include <X11/Xcursor/Xcursor.h>
#       include <linux/input.h>
#       undef Font
//      linux/input-event-codes.h defins a lot of key codes that conflict with raylib
#       undef KEY_APOSTROPHE
#       undef KEY_CAPS_LOCK
#       undef KEY_CAPSLOCK
#       undef KEY_ESCAPE
#       undef KEY_KP_ADD
#       undef KEY_KP_SUBTRACT
#       undef KEY_LEFT_CONTROL
#       undef KEY_LEFTCTRL
#       undef KEY_NUM_LOCK
#       undef KEY_NUMLOCK
#       undef KEY_PLAY
#       undef KEY_SCALE
#       undef KEY_CAPS_LOCK
#       undef KEY_COMMA
#       undef KEY_ESCAPE
#       undef KEY_FN_D
#       undef KEY_KP_ADD
#       undef KEY_KP_SUBTRACT
#       undef KEY_LEFT_CONTROL
#       undef KEY_NUM_LOCK
#       undef KEY_TAPE
#       undef KEY_MINUS
#       undef KEY_SLASH
#       undef KEY_SEMICOLON
#       undef KEY_EQUAL
#       undef KEY_BACKSLASH
#       undef KEY_GRAVE
#       undef KEY_SPACE
#       undef KEY_ENTER
#       undef KEY_TAB
#       undef KEY_BACKSPACE
#       undef KEY_INSERT
#       undef KEY_DELETE
#       undef KEY_RIGHT
#       undef KEY_LEFT
#       undef KEY_DOWN
#       undef KEY_UP
#       undef KEY_HOME
#       undef KEY_END
#       undef KEY_PAUSE
#       undef KEY_BACK
#       undef KEY_MENU
#       undef KEY_A
#       undef KEY_B
#       undef KEY_C
#       undef KEY_D
#       undef KEY_E
#       undef KEY_F
#       undef KEY_G
#       undef KEY_H
#       undef KEY_I
#       undef KEY_J
#       undef KEY_K
#       undef KEY_L
#       undef KEY_M
#       undef KEY_N
#       undef KEY_O
#       undef KEY_P
#       undef KEY_Q
#       undef KEY_R
#       undef KEY_S
#       undef KEY_T
#       undef KEY_U
#       undef KEY_V
#       undef KEY_W
#       undef KEY_X
#       undef KEY_Y
#       undef KEY_Z
#       undef KEY_F1
#       undef KEY_F2
#       undef KEY_F3
#       undef KEY_F4
#       undef KEY_F5
#       undef KEY_F6
#       undef KEY_F7
#       undef KEY_F8
#       undef KEY_F9
#       undef KEY_F10
#       undef KEY_F11
#       undef KEY_F12
#   endif
#endif

#if defined(_WIN32)
//  Before including window.h control naming conventions.
#   define CloseWindow CloseWindowWin32
#   define Rectangle RectangleWin32
#   define ShowCursor ShowCursorWin32
#endif

// rglfw.c will also include windows.h
#include "rglfw.c"
#undef GL_VERSION
#undef GL_EXTENSIONS
#undef GL_NUM_EXTENSIONS
#undef GL_CONTEXT_FLAGS

#if defined(_WIN32)
#   undef CloseWindow
#   undef Rectangle
#   undef ShowCursor
#   undef LoadImage
#   undef DrawText
#   undef DrawTextEx
#   undef PlaySound
#   undef ARRAYSIZE

#   define WINGDI_ALREADY_INCLUDED
#   define WINUSER_ALREADY_INCLUDED
#   define WINGDI_ALREADY_INCLUDED
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

#if defined(_WIN32)
#   define HWND HWND_
#endif
#include "rcore.c"
#undef GLFW_INCLUDE_NONE

#if defined(_WIN32)
//  use pragma linking directly for windows
#   pragma comment(lib, "gdi32.lib")
#   pragma comment(lib, "user32.lib")
#   pragma comment(lib, "shell32.lib")
#   pragma comment(lib, "winmm.lib")
#   pragma comment(lib, "xinput.lib")

//  HACK for raudio
#   undef _unused
#   include "external/miniaudio.h"
#   undef _WIN32
#   define dlsym GetProcAddress
#endif

#include "raudio.c"
