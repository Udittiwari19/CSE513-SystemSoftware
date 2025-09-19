/*
============================================================================
Name : 19.c
Author : Udit Tiwari
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 26th Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<x86intrin.h>

int main(){
    unsigned long long start,end;
    pid_t pid;
    start=__rdtsc();
    pid=getpid();
    end=__rdtsc();
    printf("getpid() = %d\n",pid);
    printf("Time taken by getpid() system call: %llu CPU cycles\n",(end-start));
    return 0;
}