/*
============================================================================
Name : 01_b.c
Author : Udit Tiwari
Description : Create a hard link file using the `link` system call
Date: 22nd Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(int argc,char* argv[]){
    if(argc!=3){
        printf("Enter the name of the source and target file in the argument\n");
        return 0;
    }
    char* source=argv[1];
    char* target=argv[2];
    if(link(source,target)==-1){
        perror("link\n");
        printf("Link not created\n");
    }
    else printf("Link created successfully\n");
    return 0;
}