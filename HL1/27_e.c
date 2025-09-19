/*
============================================================================
Name : 27_a.c
Author : Udit Tiwari
Description : Write a program to execute `ls -Rl` by the following system calls 
    a. `execvp` 
Date: 3rd Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-Rl", NULL};

    printf("Running ls -Rl using execvp...\n");
    execvp("ls", args);

    perror("execvp failed");
    return 1;
}