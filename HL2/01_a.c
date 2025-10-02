/*
============================================================================
Name : 01_a.c
Author : Udit Tiwari
Description :   Write a separate program (for each time domain) to set a interval timer in 10s and 10ms
                a. ITIMER_REAL
Date: 30th Sep, 2025.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/time.h>
#include<unistd.h>

void handler(int signum){
    printf("ITIMER_REAL expired!(SIGALRM)\n");
}

int main(){
    signal(SIGALRM,handler);

    struct itimerval timer;
    timer.it_value.tv_sec=10;
    timer.it_value.tv_usec=0;
    timer.it_interval.tv_sec=10;
    timer.it_interval.tv_usec=0;

    setitimer(ITIMER_REAL,&timer,NULL);

    while(1);
}

/*
udit@Udit-Victus:~/1st Sem/Software Systems/HL2$ ./01_a
ITIMER_REAL expired!(SIGALRM)
ITIMER_REAL expired!(SIGALRM)
ITIMER_REAL expired!(SIGALRM)
*/