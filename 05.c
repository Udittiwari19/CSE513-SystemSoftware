/*
============================================================================
Name : 05.c
Author : Udit Tiwari
Description : Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd.
Date: 23rd Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    int i = 0;
    char filename[50];
    while (1) {
        sprintf(filename, "test_%d.txt", i);
        int fd = creat(filename, S_IRWXU);
        if (fd == -1) {
            perror("creat");
            exit(1);
        }
        printf("Opened %s with FD = %d\n", filename, fd);
        i++;
        sleep(2);
    }
    return 0;
}