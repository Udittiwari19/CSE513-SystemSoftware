/*
============================================================================
Name : 05.c
Author : Udit Tiwari
Description :  Write a program to print the system limitation of
				i. Maximum length of the arguments to the exec family of functions.
				ii. Maximum number of simultaneous process per user id.
				iii. Number of clock ticks (jiffy) per second.
				iv. Maximum number of open files
				v. Size of a page
				vi. Total number of pages in the physical memory
				vii. Number of currently available pages in the physical memory.
Date: 30th Sep, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>

int main(){
	struct rlimit rlim;
	printf("Maximum length of the arguments to the exec family of functions: %ld\n",sysconf(_SC_ARG_MAX));
	printf("Maximum number of simultaneous process per user id: %ld\n",sysconf(_SC_CHILD_MAX));
	printf("Maximum number of clock ticks(jiffy) per second: %ld\n",sysconf(_SC_CLK_TCK));
	printf("Maximum number of open files: %ld\n",sysconf(_SC_OPEN_MAX));
	printf("Maximum size of a page in bytes: %ld\n",sysconf(_SC_PAGE_SIZE));
	printf("Total number of pages in the physical memory: %ld\n", sysconf(_SC_PHYS_PAGES));
    printf("Number of currently available pages in the physical memory.: %ld\n", sysconf(_SC_AVPHYS_PAGES));
	return 0;
}

/*
udit@Udit-Victus:~/1st Sem/Software Systems/HL2$ ./05
Maximum length of the arguments to the exec family of functions: 2097152
Maximum number of simultaneous process per user id: 29551
Maximum number of clock ticks(jiffy) per second: 100
Maximum number of open files: 1024
Maximum size of a page in bytes: 4096
Total number of pages in the physical memory: 1939463
Number of currently available pages in the physical memory.: 785971
*/