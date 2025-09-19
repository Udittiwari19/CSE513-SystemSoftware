/*
============================================================================
Name : 23.c
Author : Udit Tiwari
Description : Write a program to create a Zombie state of the running program
Date: 2nd Sept, 2025.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    if(!fork()){
        printf("Child process(PID = %d)exiting..\n",getpid());
        exit(0);
    }
    else{
        printf("Parent process (PID = %d) sleeping..(child becomes zombie)\n",getpid());
        sleep(30); //parent doesn't call wait(),child becomes zombie
    }
    return 0;
}