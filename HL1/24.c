/*
============================================================================
Name : 24.c
Author : Udit Tiwari
Description : Write a program to create an orphan process
Date: 2nd Sept, 2025.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    if(!fork()){
        sleep(5);
        printf("Child (PID=%d), My Parent (PPID=%d)\n",getpid(),getppid());
    }
    else{
        printf("Parent (PID=%d) exiting...\n",getpid());
        exit(0);
    }
    return 0;
}