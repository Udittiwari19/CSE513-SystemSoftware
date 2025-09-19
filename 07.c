/*
============================================================================
Name : 07.c
Author : Udit Tiwari
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 24th Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char* argv[]){
    char buffer[1024];
    int bytesRead;
    if(argc!=3){
        printf("Enter source and destination files\n");
        exit(1);
    }
    int fd1=open(argv[1],O_RDONLY);
    if(fd1==-1){
        perror("open source");
        exit(1);
    }
    int fd2=open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,S_IRWXU);
    if(fd2==-1){
        perror("open destination");
        exit(1);
    }
    while((bytesRead=read(fd1,buffer,sizeof(buffer)))>0){
        if(write(fd2,buffer,bytesRead)!=bytesRead){
            perror("write");
            close(fd1);
            close(fd2);
            exit(1);
        }
    }
    close(fd1);
    close(fd2);
    return 0;
}