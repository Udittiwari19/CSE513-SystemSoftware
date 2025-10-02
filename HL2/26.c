/*
============================================================================
Name : 26.c
Author : Udit Tiwari
Description : Write a program to send messages to the message queue. Check ipcs -q
Date: 30th Sep, 2025.
============================================================================
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

struct my_msg
{
    long mtype;
    char mtext[80];
};

int main()
{
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, IPC_CREAT | 0666);
    // printf("%d\n", msqid);

    struct my_msg msg;
    msg.mtype = 10;
    char text[80];
    printf("Enter message:\n");
    scanf("%[^\n]s", text);

    strcpy(msg.mtext, text);
    
    (msgsnd(msqid, (struct msgbuf *)&msg, 80, 0) == -1) ? printf("Message send failed.\n") : printf("Message sent successfully.\n");

    return (0);
}

/*
udit@Udit-Victus:~/1st Sem/Software Systems/HL2$ ./26 
Enter message:
HELLO
Message sent successfully.
udit@Udit-Victus:~/1st Sem/Software Systems/HL2$ ./26 ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x610200d4 0          ayyanpasha 666        240          3           

udit@Udit-Victus:~/1st Sem/Software Systems/HL2$ ./26
Enter message:
HELLO   
Message sent successfully.
udit@Udit-Victus:~/1st Sem/Software Systems/HL2$ ./26 ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x610200d4 0          ayyanpasha 666        320          4     
*/