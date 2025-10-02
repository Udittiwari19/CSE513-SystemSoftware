/*
============================================================================
Name : 06.c
Author : Udit Tiwari
Description :  Write a simple program to print the created thread ids.
Date: 30th Sep, 2025.
============================================================================
*/

#include <pthread.h>
#include <stdio.h>

void show_thread(void)
{
    printf("This is a thread: %ld\n", pthread_self());
}

int main()
{
    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL, (void *)show_thread, NULL);
    pthread_create(&t2, NULL, (void *)show_thread, NULL);
    pthread_create(&t3, NULL, (void *)show_thread, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    return 0;
}

/*
udit@Udit-Victus:~/1st Sem/Software Systems/HL2$ ./07
This is a thread: 135465004955328
This is a thread: 135464996562624
This is a thread: 135464988169920
*/