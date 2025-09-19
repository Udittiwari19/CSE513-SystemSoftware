/*
============================================================================
Name : 08.c
Author : Udit Tiwari
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read. Close the file when end of file is reached.
Date: 24th Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc,char *argv[]){
    char line[4096];
    char buffer[1024];
    int bytesRead;
    if(argc!=2){
        printf("Enter source file\n");
        exit(1);
    }
    int fd=open(argv[1],O_RDONLY);
    if(fd==-1){
        perror("open source");
        exit(1);
    }
    int idx=0;
    while((bytesRead=read(fd,buffer,sizeof(buffer)))>0){
        for(int i=0;i<sizeof(buffer);i++){
            if(buffer[i]=='\n'){
                line[idx]='\0';
                write(1,line,strlen(line));
                write(1,"\n",1);
                idx=0;
            }
            else{
                line[idx++]=buffer[i];
            }
        }
    }
    if(idx>0){
        line[idx]='\0';
        write(1,line,strlen(line));
        write(1,"\n",1);
    }
    close(fd);
    return 0;
}