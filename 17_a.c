/*
============================================================================
Name : 17_a.c
Author : Udit Tiwari
Description : Write a program to simulate online ticket reservations. 
		a .Implement a write lock.  Write a program to open a file, store a ticket number, and exit. 
		b. Write a separate program, to open the file,  implement write lock, read the ticket number, increment the number, and print the new ticket number then close the file
Date: 29th Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char* argv[]){
    if(argc<2){
        printf("Enter file name\n");
        exit(1);
    }
    int fd=open(argv[1],O_RDWR | O_CREAT | O_TRUNC,0666);
    if(fd<0){
        perror("open");
        exit(1);
    }
    int ticket=1;
    if(write(fd,&ticket,sizeof(ticket))!=sizeof(ticket)){
        perror("write");
        close(fd);
        exit(1);
    }
    printf("Intitialized ticket number to %d in file: %s\n",ticket,argv[1]);
    close(fd);
    return 0;
}