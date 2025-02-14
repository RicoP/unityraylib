cl /EHsc /nologo ^
    /I../include/unityraylib/raylib ^
    unity.c fps.c ^
    /FeC:stb.exe

cl /EHsc /nologo ^
    /I../include/unityraylib/raylib ^
    /I../include/unityraylib/raylib/external/glfw/include ^
    ../src/unityraylib.c fps.c ^
    /Fec:unity.exe

DEL *.obj