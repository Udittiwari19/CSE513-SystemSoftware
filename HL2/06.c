/*
============================================================================
Name : 06.c
Author : Udit Tiwari
Description :  Write a simple program to create three threads.
Date: 30th Sep, 2025.
============================================================================
*/

#include<pthread.h>
#include<stdio.h>

void print_thread(void){
    printf("Thread Created!\n");
}

int main(){
    pthread_t t1,t2,t3;

    pthread_create(&t1,NULL,(void *)print_thread,NULL);
    pthread_create(&t2,NULL,(void *)print_thread,NULL);
    pthread_create(&t3,NULL,(void *)print_thread,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    return 0;
}

/*
udit@Udit-Victus:~/1st Sem/Software Systems/HL2$ ./06
Thread Created!
Thread Created!
Thread Created!
*/