/*
============================================================================
Name : 12.c
Author : Udit Tiwari
Description : Write a program to find out the opening mode of a file. Use `fcntl`
Date: 25th Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char* argv[]){
    if(argc!=2){
        printf("Enter the name of the file\n");
        exit(1);
    }
    int fd=open(argv[1],O_RDWR);
    int flags=fcntl(fd,F_GETFL);
    int accessMode=flags & O_ACCMODE;
    switch(accessMode){
        case 0:
            printf("The file has been opened with the flags : O_RDONLY\n");
            break;
        case 1:
            printf("The file has been opened with the flags : O_WRONLY\n");
            break;
        case 2:
            printf("The file has been opened with the flags : O_RDWR\n");
            break;
        case 64:
            printf("The file has been opened with the flags : O_CREAT\n");
            break;
        case 512:
            printf("The file has been opened with the flags : O_TRUNC\n");
            break;
        case 1024:
            printf("The file has been opened with the flags : O_APPEND\n");
            break;
        case 577:
            printf("The file has been opened with the flags : O_WRONLY | O_CREAT | O_TRUNC\n");
            break;
        case 1089:
            printf("The file has been opened with the flags : O_WRONLY | O_CREAT | O_APPEND\n");
            break;
        case 578:
            printf("The file has been opened with the flags : O_RDWR   | O_CREAT | O_TRUNC\n");
        	break;
        case 1090:
            printf("The file has been opened with the flags : O_RDWR   | O_CREAT | O_APPEND\n");
            break;
        default:
            printf("Error!");
    }
    return 0;
}