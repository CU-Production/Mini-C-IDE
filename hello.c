#include <stdio.h>

void printf_console(const char* fmt, ...);

int main(int argc, char **argv) {
    printf("Hello World!\n");
    printf_console("Hello World!\n");
    printf_console("Hello %s\n", "World!");
    return 0;
}
