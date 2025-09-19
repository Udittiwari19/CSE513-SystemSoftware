/*
============================================================================
Name : 11_a.c
Author : Udit Tiwari
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
			Using dup,dup2,fcntl.
Date: 25th Aug, 2025.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(){
    int fd,fd_dup1,fd_dup2,fd_fcntl;
    char *msg1="Writing using original fd\n";
    char *msg2="Writing using dup\n";
    char *msg3="Writing using dup2\n";
    char *msg4="Writing using fcntl\n";
    fd=open("testfile.txt",O_WRONLY | O_CREAT | O_APPEND,0744);
    if(fd<0){
        perror("open");
        exit(1);
    }
    fd_dup1=dup(fd);
    fd_dup2=dup2(fd,7);
    fd_fcntl=fcntl(fd,F_DUPFD,8);

    write(fd,msg1,strlen(msg1));
    write(fd_dup1,msg2,strlen(msg2));
    write(fd_dup2,msg3,strlen(msg3));
    write(fd_fcntl,msg4,strlen(msg4));

    return 0;
}