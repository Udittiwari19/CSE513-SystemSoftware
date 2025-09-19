/*
============================================================================
Name : 14.c
Author : Udit Tiwari
Description : Write a program to find the type of a file. 
    1. Input should be taken from command line. 
    2. Program should be able to identify any type of a file.
Date: 25th Aug, 2025.
============================================================================
*/


#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc,char* argv[]){
    struct stat fileStat;
    if(argc<2){
        printf("Enter the name of the file\n");
        exit(1);
    }
    int fd=open(argv[1],O_RDONLY);
    fstat(fd,&fileStat);
    if(S_ISREG(fileStat.st_mode)) printf("File type : Regular file\n");
    else if(S_ISDIR(fileStat.st_mode)) printf("File type : Directory\n");
    else if(S_ISCHR(fileStat.st_mode)) printf("File type : Character device\n");
    else if(S_ISBLK(fileStat.st_mode)) printf("File type : Block Device\n");
    else if(S_ISFIFO(fileStat.st_mode)) printf("File type : FIFO(named PIPE)\n");
    else if(S_ISLNK(fileStat.st_mode)) printf("File type : Socket\n");
    else printf("File type : Unknown\n");
    return 0;
}