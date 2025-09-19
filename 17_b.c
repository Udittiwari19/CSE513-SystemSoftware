/*
============================================================================
Name : 17_b.c
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
        printf("Enter file name");
        exit(1);
    }
    int fd=open(argv[1],O_RDWR);
    if(fd<0){
        perror("open");
        exit(1);
    }
    struct flock lock;
    lock.l_type=F_WRLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start=0;
    lock.l_len=0;
    fcntl(fd,F_SETLKW,&lock);
    int ticket;
    lseek(fd,0,SEEK_SET);
    if(read(fd,&ticket,sizeof(ticket))!=sizeof(ticket)){
        perror("write");
        close(fd);
        exit(1);
    }
    printf("Current ticket number: %d\n",ticket);
    ticket++;
    if(write(fd,&ticket,sizeof(ticket))!=sizeof(ticket)){
        perror("write");
        close(fd);
        exit(1);
    }
    printf("New ticket number: %d\n",ticket);
    lock.l_type=F_UNLCK;
    if(fcntl(fd,F_SETLK,&lock)==-1){
        perror("fcntl unlock");
    }
    close(fd);
    return 0;
}