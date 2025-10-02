/*
============================================================================
Name : 16.c
Author : Udit Tiwari
Description : Write a program to send and receive data from parent to child vice versa. Use two way communication.
Date: 30th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd_pc[2];
	int fd_cp[2];
	
	pipe(fd_cp);
	pipe(fd_pc);

	if(!fork()){
		// Child to parent send.
		int c_value = 123;
		close(fd_cp[0]);
		write(fd_cp[1], &c_value, sizeof(int));
		
		// Parent to child receive.
		int c_val;
		close(fd_pc[1]);
		read(fd_pc[0], &c_val, sizeof(int));
		printf("Data from parent to child: %d\n", c_val);
	}
	else{
		// Child to parent receive.
		int p_value;
		close(fd_cp[1]);
		read(fd_cp[0], &p_value, sizeof(int));
		printf("Data from child to parent: %d\n", p_value);
	
		// Parent to child send.
		int p_val = 987;
		close(fd_pc[0]);
		write(fd_pc[1], &p_val, sizeof(int));
	}

	return(0);
}

/*
udit@Udit-Victus:~/1st Sem/Software Systems/HL2$ ./16
Data from child to parent: 123
Data from parent to child: 987
*/