/*
============================================================================
Name : 20.c
Author : Udit Tiwari
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 29th Aug, 2025.
============================================================================
*/

#include<unistd.h> 
#include<stdio.h> 
#include<sys/time.h>
#include<sys/resource.h>

int main(int argc, char *argv[]){
	int priority;
    priority = getpriority(PRIO_PROCESS, 0);
    printf("Current priority (nice value): %d\n", priority);
    nice(8);
    priority = getpriority(PRIO_PROCESS, 0);
    printf("New priority (after nice(5)): %d\n", priority);
    return 0;
}
