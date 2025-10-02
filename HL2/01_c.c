/*
============================================================================
Name : 01_c.c
Author : Udit Tiwari
Description :   Write a separate program (for each time domain) to set a interval timer in 10s and 10ms
                c. ITIMER_PROF
Date: 30th Sep, 2025.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int signum){
    printf("ITIMER_PROF expired! (SIGPROF)\n");
}

int main(){
    signal(SIGPROF,handler);

    struct itimerval timer;
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    setitimer(ITIMER_PROF,&timer,NULL);

    while(1);
}

/*
udit@Udit-Victus:~/1st Sem/Software Systems/HL2$ ./01_c
ITIMER_PROF expired! (SIGPROF)
ITIMER_PROF expired! (SIGPROF)
ITIMER_PROF expired! (SIGPROF)
ITIMER_PROF expired! (SIGPROF)
*/