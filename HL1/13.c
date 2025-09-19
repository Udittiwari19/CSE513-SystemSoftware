/*
============================================================================
Name : 13.c
Author : Udit Tiwari
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 25th Aug, 2025.
============================================================================
*/

#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

int main(int argc,char* argv[]){
    fd_set readfds;
    struct timeval time;

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO,&readfds);

    time.tv_sec=10;
    time.tv_usec=0;

    printf("You have 10 seconds to type something :\n");
    int ret;
    ret=select(STDIN_FILENO+1,&readfds,NULL,NULL,&time);
    if(ret==-1){
        perror("select");
        return 0;
    }
    else if(ret==0){
        printf("No input within 10 seconds\n");
    }
    else{
        if(FD_ISSET(STDIN_FILENO,&readfs)){
            char buffer[100];
            int n=read(STDIN_FILENO,buffer,sizeof(buffer)-1);
            buffer[n]='\0';
            printf("%s\n",buffer);
        }
    }
    return 0;
}