/*
============================================================================
Name : 20.c
Author : Udit Tiwari
Description : Write two programs so that both can communicate by FIFO - Use one way communication.
Date: 30th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    // int res = mkfifo("myFifo", S_IFIFO | 0666);

    int choice = 0;
    printf("1.\t write (program 1)\n2.\t read (program 2)\n\t Enter choice: ");
    scanf("%d", &choice);
    int fd = -1;

    switch (choice)
    {
    case 1:
        fd = open("text.txt", O_WRONLY, 0666);
        write(fd, "Hello from writer\n", sizeof("Hello from writer\n"));
        close(fd);
        break;
    case 2:
        fd = open("text.txt", O_RDONLY, 0666);
        char buf[100];
        read(fd, buf, sizeof(buf));
        printf("Message from writer: %s", buf);
        close(fd);
        break;

    default:
        printf("Choose a valid choice\n");
        break;
    }

    return (0);
}

/*
udit@Udit-Victus:~/1st Sem/Software Systems/HL2$ touch text.txt
udit@Udit-Victus:~/1st Sem/Software Systems/HL2$ ./20
1.	 write (program 1)
2.	 read (program 2)
	 Enter choice: 1
udit@Udit-Victus:~/1st Sem/Software Systems/HL2$ ./20
1.	 write (program 1)
2.	 read (program 2)
	 Enter choice: 2
Message from writer: Hello from writer
*/