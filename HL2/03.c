/*
============================================================================
Name : 03.c
Author : Udit Tiwari
Description :  Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 30th Sep, 2025.
============================================================================
*/

#include<stdio.h>
#include<sys/resource.h>
#include<stdlib.h>

int main(){
    struct rlimit rlim;

    if(getrlimit(RLIMIT_NOFILE,&rlim)!=0){
        perror("getrlimit");
        exit(1);
    }
    printf("Before: soft limit = %llu, hard limit = %llu\n",(unsigned long long)rlim.rlim_cur,(unsigned long long)rlim.rlim_max);
    rlim.rlim_cur=2048;
    if(setrlimit(RLIMIT_NOFILE,&rlim)!=0) {
        perror("setrlimit");
        exit(1);
    }
    printf("After: soft limit = %llu, hard limit = %llu\n",(unsigned long long)rlim.rlim_cur,(unsigned long long)rlim.rlim_max);
}

/*
Before: soft limit = 1024, hard limit = 1048576
After: soft limit = 2048, hard limit = 1048576
*/