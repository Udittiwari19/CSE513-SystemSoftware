/*
============================================================================
Name : 01_c.c
Author : Udit Tiwari
Description : Create a FIFO file using the `mkfifo` library function or `mknod` system call
Date: 22nd Aug, 2025.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
    if(mkfifo("myfifo",0666)==-1){
        perror("mkfifo failed\n");
        return 0;
    }
    printf("FIFO created successfully\n");
    return 0;
}