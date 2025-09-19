/*
============================================================================
Name : 21.c
Author : Udit Tiwari
Description : Write a program, call fork and print the parent and child process id.
Date: 29th Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    if(!fork()){
        printf("Child process PID : %d,Parent process PID : %d\n",getpid(),getppid());
    }
    return 0;
}