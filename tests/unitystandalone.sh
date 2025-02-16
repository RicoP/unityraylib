echo "stb build"
time gcc -I../include/unityraylib/raylib \
    fps.c \
    unity.c \
    -lm \
    -o stb.out

echo "unity build"
time gcc -I../include/unityraylib/raylib \
    -I../include/unityraylib/raylib/external/glfw/include \
    ../src/unityraylib.c \
    fps.c \
    -lm \
    -o unity.out

echo "regular build"
time gcc -D_GLFW_X11 \
    -DPLATFORM_DESKTOP_GLFW \
    -I../include/unityraylib/raylib \
    -I../include/unityraylib/raylib/external/glfw/include \
    ../include/unityraylib/raylib/*.c \
    fps.c \
    -lm \
    -o regular.out

echo "stb build optimzied size"
time gcc -Os -Wno-unused-result -fvisibility=hidden -ffunction-sections -fdata-sections \
    -I../include/unityraylib/raylib \
    fps.c \
    unity.c \
    -lm \
    -o stbOs.out

echo "unity build optimzied size"
time gcc -Os -Wno-unused-result -fvisibility=hidden -ffunction-sections -fdata-sections \
    -I../include/unityraylib/raylib \
    -I../include/unityraylib/raylib/external/glfw/include \
    ../src/unityraylib.c \
    fps.c \
    -lm \
    -o unityOs.out

echo "regular build optimzied size"
time gcc -Os -Wno-unused-result -fvisibility=hidden -ffunction-sections -fdata-sections \
    -D_GLFW_X11 \
    -DPLATFORM_DESKTOP_GLFW \
    -I../include/unityraylib/raylib \
    -I../include/unityraylib/raylib/external/glfw/include \
    ../include/unityraylib/raylib/*.c \
    fps.c \
    -lm \
    -o regularOs.out

strip --strip-all *Os.out
