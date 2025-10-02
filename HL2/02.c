/*
============================================================================
Name : 02.c
Author : Udit Tiwari
Description :  Write a program to print the system resource limits. Use getrlimit system call.
Date: 30th Sep, 2025.
============================================================================
*/


#include<stdio.h>
#include<sys/resource.h>

void print_limit(int resource,const char *name) {
    struct rlimit rlim;
    if (getrlimit(resource, &rlim) == 0) {
        printf("%s: soft limit = %llu, hard limit = %llu\n",name,(unsigned long long)rlim.rlim_cur,(unsigned long long)rlim.rlim_max);
    } else {
        perror("getrlimit");
    }
}

int main() {
    print_limit(RLIMIT_CPU,"CPU time (seconds)");
    print_limit(RLIMIT_FSIZE,"Max file size (bytes)");
    print_limit(RLIMIT_DATA,"Data segment size (bytes)");
    print_limit(RLIMIT_STACK,"Stack size (bytes)");
    print_limit(RLIMIT_CORE,"Core file size (bytes)");
    print_limit(RLIMIT_NOFILE,"Max open files");
    print_limit(RLIMIT_AS,"Virtual memory (bytes)");
    return 0;
}

/*
./02
CPU time (seconds): soft limit = 18446744073709551615, hard limit = 18446744073709551615
Max file size (bytes): soft limit = 18446744073709551615, hard limit = 18446744073709551615
Data segment size (bytes): soft limit = 18446744073709551615, hard limit = 18446744073709551615
Stack size (bytes): soft limit = 8388608, hard limit = 18446744073709551615
Core file size (bytes): soft limit = 0, hard limit = 18446744073709551615
Max open files: soft limit = 1024, hard limit = 1048576
Virtual memory (bytes): soft limit = 18446744073709551615, hard limit = 18446744073709551615
*/