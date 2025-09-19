/*
============================================================================
Name : 06.c
Author : Udit Tiwari
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 23rd Aug, 2025.
============================================================================
*/

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
    char buffer[1024];
    int bytesRead;
    while((bytesRead=read(0,buffer,sizeof(buffer)))>0){
        if(bytesRead!=write(1,buffer,bytesRead)){
            write(2,"Error wrting to STDOUT\n",24);
            exit(1);
        }
    }
    if(bytesRead<0){
        write(2,"Error reading from STDIN\n",25);
        exit(1);
    }
    return 0;
}

//instead of 0 u can use STDIN_FILENO and 1 use can use STDOUT_FILENO
