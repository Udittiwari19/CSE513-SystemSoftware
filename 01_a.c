/*
============================================================================
Name : 01_a.c
Author : Udit Tiwari
Description : Create a soft link file using the `symlink` system call
Date: 22nd Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(int argc,char* argv[]){
	if(argc!=3){
		printf("Enter the name of source and target file in the argument\n");
		return 0;
	}
	char* source=argv[1];
	char *target=argv[2];
	if(symlink(source,target)==-1){
		perror("symlink");
		printf("Error while creating link\n");
	}
	else{
		printf("Link created successfully\n");
	}
	return 0;
}
