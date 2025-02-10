echo "unity build"
time gcc -I../include/unityraylib/raylib \
    -I../include/unityraylib/raylib/external/glfw/include \
    ../src/unityraylib.c \
    fps.c \
    -J `nproc` \
    -lm \
    -o unity.out

echo "regular build"
time gcc -D_GLFW_X11 \
    -DPLATFORM_DESKTOP_GLFW \
    -I../include/unityraylib/raylib \
    -I../include/unityraylib/raylib/external/glfw/include \
    ../include/unityraylib/raylib/*.c \
    fps.c \
    -J `nproc` \
    -lm \
    -o regular.out
