/*
============================================================================
Name : 29.c
Author : Udit Tiwari
Description : Write a program to get the scheduling policy and modify the scheduling policy (SCHED_FIFO, SCHED_RR).
Date: 7th Sept, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sched.h>

int main() {
    int currPolicy;
    pid_t pid;
    pid = getpid();
    currPolicy = sched_getscheduler(pid);
    struct sched_param priority;
    priority.sched_priority = 10;

    switch(currPolicy)
    {
    case SCHED_FIFO:
        printf("Current policy is FIFO\n");
        sched_setscheduler(pid, SCHED_RR, &priority);
        currPolicy = sched_getscheduler(pid);
        printf("Current policy is %d\n", currPolicy);
        break;
    case SCHED_RR:
        printf("Current policy is RR\n");
        sched_setscheduler(pid, SCHED_FIFO, &priority);
        currPolicy = sched_getscheduler(pid);
        printf("Current policy is %d\n", currPolicy);
        break;
    case SCHED_OTHER:
        printf("Current policy is OTHER\n");
        sched_setscheduler(pid, SCHED_RR, &priority);
        currPolicy = sched_getscheduler(pid);
        printf("Current policy is %d\n", currPolicy);
        break;
    default:
        perror("Error while getting current policy\n");
    }
    return 0;
}