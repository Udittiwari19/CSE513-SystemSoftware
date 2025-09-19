/*
============================================================================
Name : 09.c
Author : Udit Tiwari
Description : Write a program to print the following information about a given file - 
    1. Inode 
    2. Number of hard links 
    3. UID 
    4. GID 
    5. Size 
    6. Block size 
    7. Number of blocks 
    8. Time of last access 
    9. Time of last modification 
    10. Time of last change
Date: 24th Aug, 2025.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h> //-->for exit()
#include<unistd.h> //---> for read(),write(),close(),fork(),..
#include<sys/stat.h> //-->for stat()
#include<time.h>

int main(int argc,char* argv[]){
    if(argc!=2){
        printf("Enter file name\n");
        exit(1);
    }
    struct stat fileStat;

    if(stat(argv[1],&fileStat)<0){
        perror("stat");
        exit(EXIT_FAILURE);
    }
    printf("Info of File : %s\n",argv[1]);
    printf("Inode number : %ld\n",(long)fileStat.st_ino);
    printf("Number of hard links : %ld\n",(long)fileStat.st_nlink);
    printf("UID : %d\n",fileStat.st_uid);
    printf("GID : %d\n",fileStat.st_gid);
    printf("Size : %ld bytes\n",(long)fileStat.st_size);
    printf("Block size : %ld bytes\n",(long)fileStat.st_blksize);
    printf("Number of blocks : %ld\n",(long)fileStat.st_blocks);
    printf("Time of last access : %s",ctime(&fileStat.st_atime));
    printf("Time of last modification : %s",ctime(&fileStat.st_mtime));
    printf("Time of last change : %s",ctime(&fileStat.st_ctime));

    return 0;
}