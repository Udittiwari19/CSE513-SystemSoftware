/*
============================================================================
Name : 03.c
Author : Udit Tiwari
Description : Write a program to create a file and print the file descriptor value. Use creat() system call
Date: 22nd Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc,char* argv[]){
    if(argc!=2) {
        printf("Enter file name in the command\n");
        return 0;
    }
    char* filename=argv[1];
    int fd=creat("filename",S_IRWXU);
    if(fd==-1){
        perror("file creation failed\n");
    }
    else{
        printf("%s successfully created and file descriptor value is %d\n",filename,fd);
    }
    return 0;
}