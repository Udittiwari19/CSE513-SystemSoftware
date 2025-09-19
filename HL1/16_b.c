/*
============================================================================
Name : 16_a.c
Author : Udit Tiwari
Description : Write a program to perform mandatory locking. 
    - Implement read lock 
Date: 26th Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc,char* argv[]){
    if(argc<2){
        printf("Enter file name\n");
        exit(1);
    }
    struct flock lock,lockStatus;
    lock.l_type=F_RDLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start=0;
    lock.l_len=0;
    int fd=open(argv[1],O_RDWR);
    fcntl(fd,F_GETLK,&lockStatus);
    if(lockStatus.l_type==F_RDLCK){
        printf("File has read lock\n");
    }
    else if(lockStatus.l_type==F_WRLCK){
        printf("File has write lock\n");
    }
    else{
        fcntl(fd,F_SETLK,lock);
        printf("File lock has been applied\n");
    }
    return 0;
}