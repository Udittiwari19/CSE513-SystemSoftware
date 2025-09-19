/*
============================================================================
Name : 26.c
Author : Udit Tiwari
Description : Write a program to execute an executable program. 
    1. Use some executable program 
    2. Pass some input to an executable program. (for example execute an executable of `$./a.out name`)
Date: 3rd Sept, 2025.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    printf("This is the launcher program (PID=%d)\n",getpid());
    execl("./a.out","./a.out","Udit",NULL);
    perror("execl failed");
    return 1;
}