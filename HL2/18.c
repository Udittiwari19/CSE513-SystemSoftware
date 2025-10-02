/*
============================================================================
Name : 18.c
Author : Udit Tiwari
Description : Write a program to find out total number of directories on the pwd. Execute ls -l | grep ^d | wc. Use only dup2.
Date: 30th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    int fd1[2], fd2[2];
    pipe(fd1);
    pipe(fd2);

    if (!fork())
    {
        
        dup2(fd1[1], 1); 
        close(fd1[0]);
        close(fd2[0]);
        close(fd2[1]);
        execl("/bin/ls", "/bin/ls", "-l", NULL);
    }
    else
    {
        if (!fork())
        {
            
            dup2(fd1[0], 0); 
            dup2(fd2[1], 1); 
            close(fd1[1]);
            close(fd2[0]);
            execl("/bin/grep", "/bin/grep", "^d", NULL);
        }
        else
        {
            dup2(fd2[0], 0); 
            close(fd2[1]);
            close(fd1[0]);
            close(fd1[1]);
            execl("/bin/wc", "/bin/wc", "-l", NULL);
        }
    }

    return (0);
}
/*
udit@Udit-Victus:~/1st Sem/Software Systems/HL2$ ./18
0
*/