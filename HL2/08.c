/*
============================================================================
Name : 08.c
Author : Ayyan Pasha
Description :  Write a separate program using signal system call to catch the following signals.
                i. SIGSEGV
                ii. SIGINT
                iii. SIGFPE
                iv. SIGALRM (use alarm system call)
                v. SIGALRM (use setitimer system call)
                vi. SIGVTALRM (use setitimer system call)
                vii. SIGPROF (use setitimer system call)
Date: 30th Sep, 2025.
============================================================================
*/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/time.h>
#include<stdlib.h>

void handler(int signum){
    switch(signum){
        case SIGSEGV:
            printf("Caught SIGSEGV (Segmentation fault)\n"); 
            break;
        case SIGINT:
            printf("Caught SIGINT (Ctrl+C)\n"); 
            break;
        case SIGFPE:
            printf("Caught SIGFPE (Floating-point exception)\n"); 
            break;
        case SIGALRM:
            printf("Caught SIGALRM (alarm)\n"); 
            break;
        case SIGVTALRM:
            printf("Caught SIGVTALRM (virtual timer)\n"); 
            break;
        case SIGPROF:
            printf("Caught SIGPROF (profiling timer)\n"); 
            break;
        default:
            printf("Caught signal %d\n", signum);
    }
}

int main(){
    signal(SIGSEGV,handler);
    signal(SIGINT,handler);
    signal(SIGFPE,handler);
    signal(SIGALRM,handler);
    signal(SIGVTALRM,handler);
    signal(SIGPROF,handler);

    //a. SIGSEGV
    //int *p=NULL; *p=42;

    //b.SIGINT
    //ctrl+c in terminal triggers this

    //c. SIGFPE
    //int x=5/0; // causes floating point exception

    // d. SIGALRM using alarm()
    alarm(2);

    struct itimerval timer;

    timer.it_value.tv_sec = 3;    
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 3; 
    timer.it_interval.tv_usec = 0;
    setitimer(ITIMER_REAL, &timer, NULL);

    timer.it_value.tv_sec = 0; timer.it_value.tv_usec = 100000; // 0.1 sec
    timer.it_interval.tv_sec = 0; timer.it_interval.tv_usec = 100000;
    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    timer.it_value.tv_sec = 0; timer.it_value.tv_usec = 200000; // 0.2 sec
    timer.it_interval.tv_sec = 0; timer.it_interval.tv_usec = 200000;
    setitimer(ITIMER_PROF, &timer, NULL);

    printf("Signal handlers installed. Press Ctrl+C or wait for timers...\n");
    while(1);

    return 0;
}

/*
udit@Udit-Victus:~/1st Sem/Software Systems/HL2$ ./08
Choose an option:
1.) SIGSEGV
2.) SIGINT
3.) SIGFPE
4.) SIGALRM (alarm system call)
5.) SIGALRM (setitimer system call)
6.) SIGVTALRM (setitimer system call)
7.) SIGPROF (setitimer system call)
=> 1
Segmentation fault caught
udit@Udit-Victus:~/1st Sem/Software Systems/HL2$ ./08
Choose an option:
1.) SIGSEGV
2.) SIGINT
3.) SIGFPE
4.) SIGALRM (alarm system call)
5.) SIGALRM (setitimer system call)
6.) SIGVTALRM (setitimer system call)
7.) SIGPROF (setitimer system call)
=> 2
Waiting 5 seconds for SIGINT
udit@Udit-Victus:~/1st Sem/Software Systems/HL2$ ./08
Choose an option:
1.) SIGSEGV
2.) SIGINT
3.) SIGFPE
4.) SIGALRM (alarm system call)
5.) SIGALRM (setitimer system call)
6.) SIGVTALRM (setitimer system call)
7.) SIGPROF (setitimer system call)
=> 3
0
No error
*/
