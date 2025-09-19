/*
============================================================================
Name : 04.c
Author : Udit Tiwari
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 23rd Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<errno.h>

int main(int argc,char* argv[]){
    if(argc!=2){
        printf("Write file name in your command\n");
        return 0;
    }
    char* filename=argv[1];
    int fd=open(filename,O_RDWR);
    if(fd==-1){
        perror("open with O_RDWR");
    }
    else{
        printf("FIle successfully opended in read-write mode and FD=%d\n",fd);
        close(fd);
    }
    fd=open(filename,O_CREAT|O_EXCL|O_RDWR,0700);
    if(fd==-1){
        if(errno==EEXIST){
            printf("Error:file already exists\n");
        }
        else perror("open with O_CREAT|O_EXCL|O_RDWR");
    }
    else{
        printf("FIle successfully created with FD=%d\n",fd);
        close(fd);
    }
    return 0;
}