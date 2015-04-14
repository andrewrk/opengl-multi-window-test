#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

__attribute__ ((noreturn))
__attribute__ ((format (printf, 1, 2)))
static void panic(const char *format, ...) {
    va_list ap;
    va_start(ap, format);
    vfprintf(stderr, format, ap);
    fprintf(stderr, "\n");
    va_end(ap);
    abort();
}

static void panic_on_glfw_error(int error, const char* description) {
    panic("GLFW error: %s", description);
}

static int print_usage(char *arg0) {
    fprintf(stderr, "Usage: %s --windows <number-of-windows>\n", arg0);
    return 1;
}

int main(int argc, char **argv) {
    int window_count = 2;

    for (int i = 1; i < argc; i += 1) {
        char *arg = argv[i];
        if (arg[0] == '-' && arg[1] == '-') {
            arg += 2;
            if (++i < argc) {
                char *val = argv[i];
                if (strcmp(arg, "windows") == 0) {
                    window_count = atoi(val);
                } else {
                    return print_usage(argv[0]);
                }
            } else {
                return print_usage(argv[0]);
            }
        } else {
            return print_usage(argv[0]);
        }
    }


    glfwSetErrorCallback(panic_on_glfw_error);

    if (!glfwInit())
        panic("GLFW initialize");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_DEPTH_BITS, 0);
    glfwWindowHint(GLFW_STENCIL_BITS, 1);

    fprintf(stderr, "num: %d\n", window_count);

    glfwTerminate();
    return 0;
}
