#include <stdarg.h>
#include <stdio.h>

static void cgs_trace_error(const char* fmt, ...) {
    va_list args;
    FILE* file = fopen("/tmp/cgs_webrtc.log", "a");
    if (file) {
        va_start(args, fmt);
        vfprintf(file, fmt, args);
        va_end(args);
        fclose(file);
    }
}

int main(int argc, char** argv) {
    cgs_trace_error("no args\n");
    cgs_trace_error("one arg: %d\n", 1);
    cgs_trace_error("two args: %d %d\n", 1, 2);
}

