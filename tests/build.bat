cl /EHsc /nologo ^
    /I../include/unityraylib/raylib ^
    unity.c fps.c ^
    /FeC:stb.exe

cl /EHsc /nologo ^
    /I../include/unityraylib/raylib ^
    /I../include/unityraylib/raylib/external/glfw/include ^
    ../src/unityraylib.c fps.c ^
    /Fec:unity.exe

cl /EHsc /nologo ^
    /DPLATFORM_DESKTOP_GLFW ^
    /I../include/unityraylib/raylib ^
    /I../include/unityraylib/raylib/external/glfw/include ^
    ../include/unityraylib/raylib/*.c fps.c ^
    /Fec:regular.exe ^
    /link user32.lib gdi32.lib shell32.lib winmm.lib xinput.lib 

DEL *.obj