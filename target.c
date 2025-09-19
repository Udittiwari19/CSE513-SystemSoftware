#include <stdio.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <name>\n", argv[0]);
        return 1;
    }
    printf("Hello, %s! I am running inside a.out (PID=%d)\n", argv[1], getpid());
    return 0;
}