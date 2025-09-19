/*
============================================================================
Name : 30.c
Author : Udit Tiwari
Description : Write a program to run a script at a specific time using a Daemon process
Date: 7th Sept, 2025.
============================================================================
*/

#include <time.h>     
#include <stdio.h>     
#include <sys/types.h> 
#include <unistd.h>    
#include <stdlib.h>   

void runScript(){
    char *command_line = "./30.sh";
	
	execl(command_line,command_line,NULL);
}


int main(int argc, char *argv[])
{

    time_t currentEpoch, deadlineEpoch; // Current system time & deadline time in epoch
    struct tm *deadline;                // Deadline in user readable format

    pid_t child;

    if (argc < 2){
        printf("Pass at least one argument\n");
        return 0;
    }
    time(&currentEpoch); 
    deadline = localtime(&currentEpoch);

    deadline->tm_hour = atoi(argv[1]);
    deadline->tm_min = argv[2] == NULL ? 0 : atoi(argv[2]);
    deadline->tm_sec = argv[3] == NULL ? 0 : atoi(argv[3]);

    deadlineEpoch = mktime(deadline); 

    if((child = fork()) == 0)
    {
        setsid();

        if (difftime(deadlineEpoch, currentEpoch) <= 0){
            printf("TIME EXPIRED");
            return 0;
        }

        do
        {
            time(&currentEpoch);
        } while (difftime(deadlineEpoch, currentEpoch) > 0);
        printf("Executing ls command in Daemon Process in script!\n");
        runScript();
    }
    return 0;
}
