/*
	Shukrithi Rathna
	21-09-18
	Redirecting stdout to file using dup2
*/

/*	Output file name is taken as command line
	argument.
	Example: out.txt
	Command to be executed can be changed by
	changing values of cmd[]
*/

#include <stdlib.h> 
#include<unistd.h>
#include <stdio.h> 
#include <fcntl.h>
 
int main(int argc, char *argv[])
{
	int pid;
	int fd; 
	char *cmd[] = { "ls",NULL };
	if (argc != 2) //No output file; argv[0] contains program name; argv[1] contains output file name
	{
		fprintf(stderr, "\nOutput file name not given\n");
		exit(1); 
	}
	
	fd=open(argv[1], O_CREAT|O_TRUNC|O_WRONLY, 0644);
	if (fd < 0)//File not opened
	{
		perror(argv[1]); 
		exit(1);
	}
	printf("\n Output of the command %s  has been written to %s\n", cmd[0], argv[1]);

	//dup2(fd, 1);
	dup2(fd, STDOUT_FILENO);
	execvp(cmd[0], cmd); 
	exit(1); 
} 
