/*
============================================================================
Name : 10.c
Author : Udit Tiwari
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes. 
    1. Check the return value of `lseek` 
    2. Open the file with `od` and check the empty spaces in between the data.
Date: 24th Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(){
    char buf1[]="Softwareee";
    char buf2[]="Systemssss";

    int fd=open("newfile.txt",O_RDWR | O_CREAT,0700);
    if(fd<0){
        perror("open");
        exit(1);
    }
    if(write(fd,buf1,strlen(buf1))!=strlen(buf1)){
        perror("write buf 1");
        close(fd);
        exit(1);
    }
    lseek(fd,10,SEEK_CUR);
    if(write(fd,buf2,strlen(buf2))!=strlen(buf2)){
        perror("write buf2");
        close(fd);
        exit(1);
    }
    int offset=lseek(fd,0,SEEK_CUR);
    printf("Current file offset : %d\n",offset);
    return 0;
}