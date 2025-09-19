/*
============================================================================
Name : 22.c
Author : Udit Tiwari
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the parent processes. Check output of the file
Date: 1st Sept, 2025.
============================================================================
*/
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>

int main(int argc,char* argv[]){
    if(argc<0){
        printf("Enter file name\n");
        return 0;
    }
    int fd;
    if((fd=open(argv[1],O_CREAT | O_WRONLY | O_TRUNC))<0){
        perror("open");
        return 0;
    }
    if(fork()){
        write(fd,"PARENT\n",7);
    }
    else{
        write(fd,"CHILD\n",6);
    }
    close(fd);
    return 0;
}