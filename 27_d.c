/*
============================================================================
Name : 27_a.c
Author : Udit Tiwari
Description : Write a program to execute `ls -Rl` by the following system calls 
    a. `execv` 
Date: 3rd Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-Rl", NULL};

    printf("Running ls -Rl using execv...\n");
    execv("/bin/ls", args);

    perror("execv failed");
    return 1;
}