/*
	Shukrithi Rathna
	21-09-18
	Redirecting stdout to file using dup2
	Using Pipes to execute two commands
*/

/*	Output file name is taken as command line
	argument.
	Example: out.txt
	Command to be executed can be changed by
	changing values of cmd1[] and cmd2[]
	Search value for grep is taken as user input 
	during execution
*/
/*
	NOTES:
	O_RDONLY: read only, O_WRONLY: write only, O_RDWR: read and write;
	O_CREAT: create file if it doesn’t exist;
	O_EXCL: prevent creation if it already exists C.
	O_TRUNC If the file exists, its length is truncated to 0
	0644 - read, write and exec permissions
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h> 
#include <sys/stat.h>
#include <fcntl.h>

#define BuffSize 25
#define REnd 0
#define WEnd 1

int main(int argc, char *argv[])
{
	int fd1[2], fd2;
	char ReadMsg[BuffSize];
	char WriteMsg[BuffSize];
	pid_t pid,cpid;
	int i;

	if (argc != 2) //No output file; argv[0] contains program name; argv[1] contains file name
	{
		fprintf(stderr, "\nOutput file name not given\n");
		exit(1); 
	}
// creating pipe
	if(pipe(fd1)<0)
		fprintf(stderr,"\nPipe creation unsuccessfull");
	printf("\nSearch:");
		gets(ReadMsg);
	pid=fork();
	if(pid<0)
		printf("\nFork unsuccessfull");
	else if(pid>0)
	{
		//printf("\nParent process\t Writing to pipe");
//Closing reading end
		close(fd1[REnd]);
		dup2(fd1[1], 1);
		char *cmd1[] = {"ps",NULL}; //holds command to be passed to execvp
   		execvp(cmd1[0],cmd1);
   		
//Closing writing end
		close(fd1[WEnd]);
	}
	else
	{
		//printf("Child process\tReading from pipe");
		dup2(fd1[0], STDIN_FILENO);  
//Close writing and reading end
		close(fd1[WEnd]);
		close(fd1[REnd]);
		
//open file to write output	

		fd2=open(argv[1], O_CREAT|O_TRUNC|O_WRONLY, 0644);
    	if (fd2 < 0)//File not opened
		{
			perror(argv[1]); 
			exit(1);
		}
		printf("\n Output of the command has been written to %s\n",  argv[1]);

		dup2(fd2, 1);//redirect from stdout to file
	
		char *cmd2[] = {"grep",ReadMsg,NULL};//holds command to be passed to execvp
   		execvp(cmd2[0], cmd2);
	}
	return(0);
}
