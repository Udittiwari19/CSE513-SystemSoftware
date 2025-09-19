/*
============================================================================
Name : 27_a.c
Author : Udit Tiwari
Description : Write a program to execute `ls -Rl` by the following system calls 
    a. `execl` 
Date: 3rd Sept, 2025.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    printf("Running ls -Rl using execl..\n");
    execl("/bin/ls","ls","-Rl",NULL);
    perror("execl failed");
    return 1;
}