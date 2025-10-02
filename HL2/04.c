/*
============================================================================
Name : 04.c
Author : Udit Tiwari
Description :  Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.
Date: 30th Sep, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<x86intrin.h>

int main(){
    int i;
    unsigned long long start,end;
    pid_t pid;

    start=__rdtsc();

    for(i=0;i<100;i++) pid=getppid();

    printf("Parent PID: %d\n",pid);
    printf("CPU cycles for 100 getppid() calls: %llu\n",(unsigned long long)(end - start));
    printf("Average cycles per getppid(): %llu\n",(unsigned long long)((end - start)/100));
} 

/*
udit@Udit-Victus:~/1st Sem/Software Systems/HL2$ ./04
Parent PID: 3597
CPU cycles for 100 getppid() calls: 124622486802323
Average cycles per getppid(): 1246224868023
*/