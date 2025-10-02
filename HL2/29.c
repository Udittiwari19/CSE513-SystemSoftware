/*
============================================================================
Name : 29.c
Author : Udit Tiwari
Description : Write a program to remove the message queue.
Date: 30th Sep, 2025.
============================================================================
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

// Remove a message queue.
int main()
{
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, 0);

    (msgctl(msqid, IPC_RMID, NULL) == -1) ? printf("Delete unsuccessful\n") : printf("Delete successful\n");
    
    return (0);
}

/*
udit@Udit-Victus:~/1st Sem/Software Systems/HL2$ ./29
Delete successful
*/