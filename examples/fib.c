#include <stdlib.h>
#include <stdio.h>

void printf_console(const char* fmt, ...);

int fib(int n)
{
    if (n <= 2)
        return 1;
    else
        return fib(n-1) + fib(n-2);
}

int main(int argc, char **argv)
{
    int n;
    if (argc < 2) {
        n = 42;
    } else {
        n = atoi(argv[1]);
    }

    printf_console("fib(%d) = %d\n", n, fib(n));
    return 0;
}
