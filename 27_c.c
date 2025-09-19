/*
============================================================================
Name : 27_a.c
Author : Udit Tiwari
Description : Write a program to execute `ls -Rl` by the following system calls 
    a. `execle` 
Date: 3rd Sept, 2025.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    char *envp[]={"MYVAR=HELLOWORLD",NULL};
    printf("Running ls -Rl using execle..\n");
    execle("/bin/ls","ls","-Rl",NULL,envp);
    perror("execle failed");
    return 1;
}