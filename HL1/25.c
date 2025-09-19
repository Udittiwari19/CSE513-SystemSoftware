/*
============================================================================
Name : 25.c
Author : Udit Tiwari
Description : Write a program to create three child processes. The parent should wait for a particular child (use `waitpid` system call).
Date: 3rd Sept, 2025.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    pid_t cpid1,cpid2,cpid3;
    //creates first child;
    if((cpid1=fork())==0){
        printf("Child 1 (PID=%d) running..\n",getpid());
        sleep(2);
        printf("Child 1 exiting..\n");
        exit(1);
    }
    //created second child
    if((cpid2=fork())==0){
        printf("Child 2 (PID=%d) running..\n",getpid());
        sleep(4);
        printf("Child 2 exiting..\n");
        exit(1);
    }
    //create third child
    if((cpid3=fork())==0){
        printf("Child 3 (PID=%d) running..\n",getpid());
        sleep(6);
        printf("Child 3 exiting..\n");
        exit(1);
    }
    int status;
    pid_t waited=waitpid(cpid3,&status,0);
    if(waited==-1){
        perror("waitpid failed");
        exit(1);
    }
    if(WIFEXITED(status)){
        printf("Parent collected Child 3(PID=%d) with exit code %d\n",waited,WEXITSTATUS(status));
    }
    wait(NULL);
    wait(NULL);
    return 0;
}