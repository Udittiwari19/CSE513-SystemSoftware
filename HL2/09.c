/*
============================================================================
Name : 09.c
Author : Udit Tiwari
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - Use signal system call.
Date: 30th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {

    signal(SIGINT, SIG_IGN);
    printf("SIGINT is now ignored. Try pressing Ctrl+C (it won't stop the program).\n");

    sleep(10); 

    signal(SIGINT, SIG_DFL);
    printf("SIGINT reset to default. Now Ctrl+C will terminate the program.\n");

    while (1) {
        printf("Running... Press Ctrl+C to test.\n");
        sleep(2);
    }

    return 0;
}

/*
udit@Udit-Victus:~/1st Sem/Software Systems/HL2$ ./09
Ignoring SIGINT signal
^C^C^C^C^C^C
Default action of SIGINT signal
udit@Udit-Victus:~/1st Sem/Software Systems/HL2$ ./09
Ignoring SIGINT signal

Default action of SIGINT signal
^C
*/
