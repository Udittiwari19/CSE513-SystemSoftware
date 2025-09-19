/*
============================================================================
Name : 15.c
Author : Udit Tiwari
Description : Write a program to display the environmental variable of the user (use environ).
Date: 27th Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

extern char **environ; //environ is a pointer to an array of strings

int main(){
    int i=0;
    printf("Environmet variables of the user:\n");
    while(environ[i]!=NULL){
        printf("%s\n",environ[i]);
        i++;
    }
    return 0;
}